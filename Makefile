BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include

CCFLAGS = -Wall -Werror -std=c++17 -g -I$(INCLUDE_DIR)

SRCS = $(SRC_DIR)/main.cc
BIN = $(BUILD_DIR)/crop

.PHONY : all $(BIN) clean

all : $(BIN)

$(BIN) : Makefile
	@mkdir -p $(BUILD_DIR)
	g++ $(CCFLAGS) -o $(BIN) $(SRCS)

clean :
	rm -rf $(BUILD_DIR)
