BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include

CCFLAGS = -Wall -Werror -std=c++17 -g

SRCS = $(SRC_DIR)/main.cc
BIN = crop

.PHONY : all $(BIN) dummy clean

all : $(BIN) dummy

$(BIN) : Makefile
	@mkdir -p $(BUILD_DIR)
	g++ $(CCFLAGS) -I$(INCLUDE_DIR) -o $(BUILD_DIR)/$(BIN) $(SRCS)

dummy : Makefile
	g++ $(CCFLAGS) -fno-stack-protector -o dummy dummy.cc

clean :
	rm -rf $(BUILD_DIR)
	rm -f dummy
