CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2 -g3
LDFLAGS = -lm

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

default: main

main: $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I .$(INCLUDE_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean clear
clean:
ifeq ($(OS),Windows_NT)
	del /Q $(subst /,\,$(OBJ_DIR)\*.o) main.exe
else
	rm -f $(OBJ_DIR)/*.o main
endif

clear: clean