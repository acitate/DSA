#
# 'make'        build executable file 'main'
# 'make clean'  removes all .o and executable files
#

# define the C++ compiler to use
CXX = g++

# define the C compiler to use
CC = clang

# define any compile-time flags
CXXFLAGS := -std=c++17 -Wall -Wextra -g
CFLAGS   := -std=c11 -Wall -Wextra -g

# define library paths in addition to /usr/lib
LFLAGS =

# define output directory
OUTPUT := output

# define source directory
SRC := src

# define include directory
INCLUDE := include

# define lib directory
LIB := lib

ifeq ($(OS),Windows_NT)
MAIN := main.exe
SOURCEDIRS := $(SRC)
INCLUDEDIRS := $(INCLUDE)
LIBDIRS := $(LIB)
FIXPATH = $(subst /,\,$1)
RM := del /q /f
MD := mkdir
else
MAIN := main
SOURCEDIRS := $(shell find $(SRC) -type d)
INCLUDEDIRS := $(shell find $(INCLUDE) -type d)
LIBDIRS := $(shell find $(LIB) -type d)
FIXPATH = $1
RM = rm -f
MD := mkdir -p
endif

# define any directories containing header files other than /usr/include
INCLUDES := $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))

# define the libs
LIBS := $(patsubst %,-L%, $(LIBDIRS:%/=%))

# define the C++ source files
CXX_SOURCES := $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))

# define the C source files
C_SOURCES := $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))

# define the C++ object files
CXX_OBJECTS := $(CXX_SOURCES:.cpp=.o)

# define the C object files
C_OBJECTS := $(C_SOURCES:.c=.o)

# combine all object files
OBJECTS := $(CXX_OBJECTS) $(C_OBJECTS)

# define the dependency output files
DEPS := $(OBJECTS:.o=.d)

OUTPUTMAIN := $(call FIXPATH,$(OUTPUT)/$(MAIN))

all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

$(OUTPUT):
	$(MD) $(OUTPUT)

$(MAIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)

# include all .d files
-include $(DEPS)

# suffix replacement rule for building .o's and .d's from .cpp files
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -MMD $< -o $@

# suffix replacement rule for building .o's and .d's from .c files
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -MMD $< -o $@

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	$(RM) $(call FIXPATH,$(DEPS))
	@echo Cleanup complete!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete!