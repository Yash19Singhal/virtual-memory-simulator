# Makefile for Virtual Memory Simulator

CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = main.cpp fifo.cpp lru.cpp optimal.cpp utils.cpp
TARGET = virtualmemory

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
