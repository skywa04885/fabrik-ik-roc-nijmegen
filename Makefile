GPP 		:= g++

GPP_ARGS	+= -I./inc

GPP_ARGS 	+= -Wall
GPP_ARGS 	+= -Werror
GPP_ARGS 	+= -O3

%.o: %.cpp
	$(GPP) $(GPP_ARGS) -c $< -o $@

CPP_SOURCES	+= $(shell find . -name *.cpp)

OBJECTS		+= $(CPP_SOURCES:.cpp=.o)

all: $(OBJECTS)
	$(GPP) $(GPP_ARGS) $(OBJECTS) -o main.elf
clean:
	rm -rf $(OBJECTS) main.elf