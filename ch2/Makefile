# Generic Makefile
###############################
# Project Settings
BIN_NAME := ch2 
# Compiler used
CXX ?= g++

#Extension of source files used in project
SRC_EXT = cpp

#Path to source dir relative to Makefile
SRC_PATH = .

#Space-separated pkg-config libraries used by this project
LIBS = 

#general compile flags
COMPILE_FLAGS = -Wall -g -O

#Additional release-specific flags
RCOMPILE_FLAGS = -D NDEBUG

#Additional debug specific flags
DCOMPILE_FLAGS = -D DEBUG
# Additional include paths
INCLUDES = -I $(SRC_PATH)
# General linker settings
LINK_FLAGS = 
# Additional release-specific linker settings
RLINK_FLAGS = 
#Additional debug-specific linker settings
DLINK_FLAGS = 
# Destination directory, like a jail or mounted system
DESTDIR = /
# Install path (bin/ is appended automatically
INSTALL_PREFIX = usr/local
# End Project Settings
###################################

# Probably don't need to edit below:
# obtain OS type

UNAME_S:=$(shell uname -s)

# function used to check variables. Use on command line:
# make print-VARNAME
# useful for debugging and adding features
print-%: ; @echo $*=$($*)

SHELL = /usr/local/bin/bash
.SUFFIXES:
# Programs for installation
INSTALL = install
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL) -m 644

# Append pkg-config specific libraries if need be
ifneq ($(LIBS),)
	COMPILE_FLAGS += $(shell pkg-config --cflags $(LIBS))
	LINK_FLAGS += $(shell pkg-config --libs $(LIBS))
endif

# verbose option, to output compile and link commands
export V := false
export CMD_PREFIX := @
ifeq ($(V),true)
	CMD_PREFIX :=
endif

# Combine compiler and linker flags
release: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS) $(RCOMPILE_FLAGS)
release: export LDFLAGS := $(LDFLAGS) $(LINK_FLAGS) $(RLINK_FLAGS)
debug: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS) $(DCOMPILE_FLAGS)
debug: export LDFLAGS := $(LDFLAGS) $(LINK_FLAGS) $(DLINK_FLAGS)

# Build and output paths
release: export BUILD_PATH := build/release
release: export BIN_PATH := bin/release
debug: export BUILD_PATH := bin/debug
debug: export BIN_PATH := bin/debug
install: export BIN_PATH := bin/release

#find all source files in source directory, sorted by most recently modified
ifeq ($(UNAME_S),Darwin)
	SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
else
	SOURCES $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' -printf '%T@\t%p\n' \ | sort -k 1nr | cut -f2-)
endif

#fallback in case above fails
rwildcard = $(foreach d, $(wildcard $1*), $(call rwildcard,$d/,$2) \ $(filter $(subst *,%,$2),$d))

ifeq ($(SOURCES),)
	SOURCES := $(call rwildcard, $(SRC_PATH), *.$(SRC_EXT))
endif

#set obj file names, with src dir stripped
# from path, and build path prepended in its place
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)

# set dependency files to be used to add header dependencies
DEPS = $(OBJECTS:.o=.d)

# Macros for timing compilation
ifeq ($(UNAME_S),Darwin)
	CUR_TIME = awk 'BEGIN{srand(); print srand()}'
	TIME_FILE = $(dir $@).$(notdir $@)_time
	START_TIME = $(CUR_TIME) > $(TIME_FILE)
	END_TIME = read st < $(TIME_FILE) ; \
			   $(RM) $(TIME_FILE) ; \
			   st=$$((`$(CUR_TIME)` - $$st)) ; \
			   echo $$st
else
	TIME_FILE = $(dir $@).$(notdir $@)_time
	START_TIME = date '+%s' > $(TIME_FILE)
	END_TIME = read st < $(TIME_FILE) ; \
			   $(RM) $(TIME_FILE) ; \
			   st=$$((`date '+%s'` - $$st - 86400)) ; \
			   echo `date -u -d @$$st '+%H:%M:%S'`
endif

# Version macros
# to cancel versioning, comment/remove this section
USE_VERSION := false
# if not git repo or repo has no tags, git describe will return non-zero
ifeq ($(shell git describe > /dev/null 2>&1 ; echo $$?),0)
	USE_VERSION := true
	VERSION := $(shell git describe --tags --long --dirty --always | \ sed 's/v\([0-9]*\)\.\([0-9]*\)\.\([0-9]*\)-\?.*-\([0-9]*\)-\(.*\)/\1 \2 \3 \4 \5/g')
	VERSION_MAJOR := $(word 1, $(VERSION))
	VERSION_MINOR := $(word 2, $(VERSION))
	VERSION_PATCH := $(word 3, $(VERSION))
	VERSION_REVISION := $(word 4, $(VERSION))
	VERSION_HASH := $(word 5, $(VERSION))
	VERSION_STRING := \
		"$(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH).$(VERSION_REVISION)-$(VERSION_HASH)"
	override CXXFLAGS := $(CXXFLAGS) \
		-D VERSION_MAJOR=$(VERSION_MAGOR) \
		-D VERSION_MINOR=$(VERSION_PATCH) \
		-D VERSION_REVISION=$(VERSION_REVISION) \
		-D VERSION_HASH=\"$(VERSION_HASH)\"
endif

#standard non-optimized release build
.PHONY: release
release: dirs
ifeq ($(USE_VERSION),true)
	@echo "Beginning release build v$(VERSION_STRING)"
else
	@echo "Beginning release build"
endif
	@$(START_TIME)
	@$(MAKE) all --no-print-directory
	@echo -n "Total build time: "
	@$(END_TIME)

# Debug build for gdb debugging
.PHONY: debug
debug: dirs
ifeq ($(USE_VERSION),true)
	@echo "Beginning debug build v$(VERSION_STRING)"
else
	@echo "Beginning debug build"
endif
	@$(START_TIME)
	@$(MAKE) all --no-print-directory
	@echo -n "Total build time: "
	@$(END_TIME)

# create directories used in the build
dirs:
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(BIN_PATH)

#Install to set path
.PHONY: install
install:
	@echo "Installing to $(DESTDIR)$(INSTALL_PREFIX)/bin"
	@$(INSTALL_PROGRAM) $(BIN_PATH/$(BIN_NAME) $(DESTDIR)$(INSTALL_PREFIX)/bin

#uninstall the program
.PHONY: uninstall
uninstall:
	@echo "Removing $(DESTDIR)$(INSTALL_PREFIX)/bin/$(BIN_NAME)"
	@$(RM) $(DESTDIR)$(INSTALL_PREFIX)/bin/$(BIN_NAME)

# removes all build files
.PHONY: clean
clean:
	@echo "Deleting $(BIN_NAME) symlink"
	@$(RM) $(BIN_NAME)
	@echo "Deleting directories"
	@$(RM) -r build
	@$(RM) -r bin

#Mian rule, checkes executable and symlinks to output
all: $(BIN_PATH)/$(BIN_NAME)
	@echo "Making symlink: $(BIN_NAME) -> $<"
	@$(RM) $(BIN_NAME)
	@ln -s $(BIN_PATH)/$(BIN_NAME) $(BIN_NAME)

#link the executable
$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
	@echo "Linking: $@"
	@$(START_TIME)
	$(CMD_PREFIX)$(CXX) $(OBJECTS) $(LDFLAGS) -o $@
	@echo -en "\t Link time: "
	@$(END_TIME)

#add dependency files, if they exist
-include $(DEPS)

#source file rules
#after first compilation they will be joined with the rules from the dependency files to provide #header dependencies
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	@$(START_TIME)
	$(CMD_PREFIX)$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@
	@echo -en "\t Compile time: "
	@$(END_TIME)

	



#CXX=g++
#CXXFlAGS= -c -Wall -Werror -g -O
#LDFLAGS= 
#SOURCES=hello.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
#EXECUTABLE=hello

#all: $(SOURCES) $(EXECUTABLE)

#$(EXECUTABLE): $(OBJECTS)
#	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

#.cpp.o:
#	$(CXX) $(CXXFLAGS) $< -o $@ 

#.PHONY: clean
#clean:
#	rm -f *.o $(EXECUTABLE)
