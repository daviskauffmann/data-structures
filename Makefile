CC := gcc
CFLAGS := -ggdb -std=c99 -Wall -Wextra -Wpedantic -Wno-unused-parameter
CPPFLAGS :=
LDFLAGS :=
LDLIBS :=

SRC	:= \
	src/doubly_linked_list.c \
	src/main.c \
	src/singly_linked_list.c
TARGET := bin/main

.PHONY: all
all: $(TARGET)

$(TARGET): $(SRC:src/%.c=build/%.o)
	mkdir -p $(@D)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

build/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) -c $< -o $@ -MMD -MF $(@:.o=.d) $(CFLAGS) $(CPPFLAGS)

-include $(SRC:src/%.c=build/%.d)

.PHONY: run
run: all
	./$(TARGET)

.PHONY: clean
clean:
	rm -rf bin build
