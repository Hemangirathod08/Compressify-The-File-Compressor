CXX = g++

CXXFLAGS = -I./include -Wall -Wextra -std=c++17

SRC_DIR = src
INC_DIR = include

HUFFMAN_EXEC = compressify.exe

HUFFMAN_SRCS = main.cpp $(SRC_DIR)/compressor.cpp $(SRC_DIR)/decompressor.cpp $(SRC_DIR)/tree.cpp

compressify: $(HUFFMAN_SRCS)
	$(CXX) $(CXXFLAGS) -o $(HUFFMAN_EXEC) $^

clean:
	rm -f compress decompress
