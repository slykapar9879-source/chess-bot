# === Project Settings ===
TARGET := build/app.exe
SRC_DIR := src
BUILD_DIR := build

# === Toolchain ===
CC := x86_64-w64-mingw32-gcc

# === Compiler Flags ===
CFLAGS := -Wall -O2 -I$(SRC_DIR)
LDFLAGS := -lmingw32 -lSDL2main -lSDL2 -mwindows

# === SDL2 Cross-Compile Paths (adjust if needed) ===
# Example if SDL2 for Windows is installed via MinGW in /usr/x86_64-w64-mingw32
SDL2_PATH := /usr/x86_64-w64-mingw32
CFLAGS += -I$(SDL2_PATH)/include/SDL2
LDFLAGS += -L$(SDL2_PATH)/lib

# === Files ===
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# === Rules ===
all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean run
