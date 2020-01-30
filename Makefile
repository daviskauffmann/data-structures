CC := gcc
CFLAGS := -ggdb -std=c99 -Wall -Wextra -Wpedantic -Wno-unused-parameter
CPPFLAGS :=
LDFLAGS :=
LDLIBS :=

SRC	:= \
	src/doubly_linked_list.c \
	src/main.c \
	src/singly_linked_list.c
OBJ := $(SRC:src/%.c=build/%.o)
DEP := $(OBJ:%.o=%.d)
TGT := bin/main

.PHONY: all
all: $(TGT)

$(TGT): $(OBJ)
	mkdir -p $(@D)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

build/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) -c $< -o $@ -MMD -MF $(@:.o=.d) $(CFLAGS) $(CPPFLAGS)

-include $(DEP)

.PHONY: run
run: all
	./$(TGT)

.PHONY: clean
clean:
	rm -rf bin build
