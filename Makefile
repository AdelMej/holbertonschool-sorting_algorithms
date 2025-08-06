CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89 -IUnity
UNITY_CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu99 -IUnity

BUILD = build
OBJDIR = obj

MAIN_SRCS = $(wildcard *-main.c)
MAIN_BINS = $(patsubst %.c, $(BUILD)/%, $(MAIN_SRCS))

SRC_ALL = $(wildcard *.c)
SRC = $(filter-out %-main.c, $(SRC_ALL))
OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))
UNITY_OBJ = $(OBJDIR)/unity.o
UNITY_SRC = Unity/unity.c
TESTS = $(wildcard tests/test_*.c)
TEST_BINS = $(strip $(patsubst tests/%.c, $(BUILD)/%, $(TESTS)))

.PHONY: all clean test run-tests run-% help

all: $(MAIN_BINS) test


test:
	@if [ -z "$(TESTS)" ]; then \
		echo "⚠️  No test files found. Only built main binaries."; \
	else \
		$(MAKE) run-tests; \
	fi

run-tests: $(TEST_BINS)
	@for bin in $(TEST_BINS); do \
		echo "Running $$bin..."; \
		if ./$$bin; then \
			echo "✅ $$bin passed"; \
		else \
			echo "❌ $$bin failed"; \
			exit 1; \
		fi; \
	done

#generating binaries for mains
$(BUILD)/%: %.c $(OBJS) | $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@

# build test binaries
$(BUILD)/%: tests/%.c $(OBJS) $(UNITY_OBJ) | $(BUILD)
	$(CC) $(UNITY_CFLAGS) $^ -o $@

#generating .o files for unity
$(UNITY_OBJ): $(UNITY_SRC) | $(OBJDIR)
	$(CC) $(UNITY_CFLAGS) -c $< -o $@

#generating .o files for mains
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

#sepecific test run
run-%: $(BUILD)/%
	./$<

#create a obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

#create build directory if it doesn't exist
$(BUILD):
	mkdir -p $(BUILD)

#delete the binary directory if it doesn't exist
clean:
	rm -rf $(BUILD) $(OBJDIR)

help:
	@echo "Available targets:"
	@echo "  all    - Build all binaries"
	@echo "  clean  - Remove build files"
	@echo "  test   - Run unit tests"
	@echo "  run-%  - Run a specific test"

debug:
	@echo "SRC = $(SRC)"
	@echo "TESTS = $(TESTS)"
	@echo "TEST_BINS=[$(TEST_BINS)]"

