CC = g++

TARGET = question2.out

BUILD_FOLDER = build

SRC := $(wildcard src/*.cpp)
OBJ := $(patsubst src/%.cpp,$(BUILD_FOLDER)/%.o,$(SRC))

LDFLAGS := -fsanitize=address,undefined
CFLAGS := -c -O0 -g3 -fsanitize=address,undefined -Iinclude

default: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

$(BUILD_FOLDER)/%.o: src/%.cpp | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_FOLDER):
	mkdir -p $@

clean:
	rm -f $(TARGET)
	rm -rf $(BUILD_FOLDER)
