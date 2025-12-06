# === Project Settings ===
TARGET := build/app.exe
SRC_DIR := src
BUILD_DIR := build

# === Toolchain ===
CC := x86_64-w64-mingw32-gcc

# === Compiler Flags ===
CFLAGS := -Wall -O2 -I$(SRC_DIR)

# === SDL2 Cross-Compile Paths (adjust if needed) ===
SDL2_PATH := /usr/x86_64-w64-mingw32

CFLAGS += -I$(SDL2_PATH)/include/SDL2
LDFLAGS := -L$(SDL2_PATH)/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows

# === Collect all .c files recursively ===
SRC := $(shell find $(SRC_DIR) -name "*.c")
OBJ := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# === Default Build ===
all: $(TARGET)

# === Create build directory structure ===
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# === Link executable ===
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# === Clean ===
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean run
