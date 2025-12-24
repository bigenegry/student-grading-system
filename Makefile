CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

TARGET = student_grading_system
SRC = src/main.cpp src/Person.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

