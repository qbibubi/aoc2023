CC=clang++
CFLAGS= -Wall -Wextra -std=c++17

SRC=main.cpp
TARGET=ans

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(TARGET)
