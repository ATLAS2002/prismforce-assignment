CXX = g++
CXXFLAGS = -Wall -g

TARGET_DIR = target

TARGET = $(TARGET_DIR)/solution

SRC = solution.cpp

INPUT = input.txt
OUTPUT = output.txt

compile: $(TARGET_DIR) $(TARGET)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET) < $(INPUT) > $(OUTPUT)

clean:
	rm -rf $(TARGET_DIR) $(OUTPUT)
