CC := gcc
CFLAGS := -ggdb -std=c99 -Wall -Wextra -Wpedantic -Wno-unused-parameter
LDFLAGS :=

SRC	:= src
BUILD := build
BIN	:= bin

SOURCES	:= \
	$(SRC)/doubly_linked_list.c \
	$(SRC)/main.c \
	$(SRC)/singly_linked_list.c
OBJECTS := $(SOURCES:$(SRC)/%.c=$(BUILD)/%.o)
DEPENDENCIES := $(OBJECTS:%.o=%.d)
INCLUDE :=
LIB :=
LIBRARIES :=
TARGET := $(BIN)/main

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(@D)
	$(CC) $^ -o $@ $(LDFLAGS) $(LIB) $(LIBRARIES)

$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(@D)
	$(CC) -c $< -o $@ -MMD -MF $(@:.o=.d) $(CFLAGS) $(INCLUDE)

-include $(DEPENDENCIES)

.PHONY: run
run: all
	./$(TARGET)

.PHONY: clean
clean:
	rm -rf $(BIN) $(BUILD)
