SRC_DIR = src
BIN_DIR = bin
INC_DIR = include

CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0` -I$(INC_DIR) -Wall -g
LDFLAGS = `pkg-config --libs gtk+-3.0`

TARGET = $(BIN_DIR)/timer

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)
	@echo "Build complete: $(TARGET)"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)/*.o $(TARGET)
	@echo "Clean complete."

.PHONY: all clean

