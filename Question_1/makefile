CC = g++

TARGET = ass4.out

BUILD_FOLDER = build

TA_FILE := TAs.txt

SRC := $(wildcard src/*.cpp)
OBJ := $(patsubst src/%.cpp,$(BUILD_FOLDER)/%.o,$(SRC))

LDFLAGS := -fsanitize=address,undefined
CFLAGS := -c -O0 -g3 -fsanitize=address,undefined -Iinclude

default: $(TARGET) $(TA_FILE)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

$(BUILD_FOLDER)/%.o: src/%.cpp | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_FOLDER):
	mkdir -p $@

$(TA_FILE):
	cp NO_TOUCH_TAs.txt TAs.txt

clean:
	rm -f $(TARGET)
	rm -rf $(BUILD_FOLDER)
