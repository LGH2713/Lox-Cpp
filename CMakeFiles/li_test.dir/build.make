# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/code/Lox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/code/Lox

# Include any dependencies generated for this target.
include CMakeFiles/li_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/li_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/li_test.dir/flags.make

CMakeFiles/li_test.dir/test/main.cc.o: CMakeFiles/li_test.dir/flags.make
CMakeFiles/li_test.dir/test/main.cc.o: test/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/Lox/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/li_test.dir/test/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/li_test.dir/test/main.cc.o -c /home/code/Lox/test/main.cc

CMakeFiles/li_test.dir/test/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/li_test.dir/test/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/code/Lox/test/main.cc > CMakeFiles/li_test.dir/test/main.cc.i

CMakeFiles/li_test.dir/test/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/li_test.dir/test/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/code/Lox/test/main.cc -o CMakeFiles/li_test.dir/test/main.cc.s

# Object files for target li_test
li_test_OBJECTS = \
"CMakeFiles/li_test.dir/test/main.cc.o"

# External object files for target li_test
li_test_EXTERNAL_OBJECTS =

bin/li_test: CMakeFiles/li_test.dir/test/main.cc.o
bin/li_test: CMakeFiles/li_test.dir/build.make
bin/li_test: libLI.so
bin/li_test: CMakeFiles/li_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/code/Lox/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/li_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/li_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/li_test.dir/build: bin/li_test

.PHONY : CMakeFiles/li_test.dir/build

CMakeFiles/li_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/li_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/li_test.dir/clean

CMakeFiles/li_test.dir/depend:
	cd /home/code/Lox && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/code/Lox /home/code/Lox /home/code/Lox /home/code/Lox /home/code/Lox/CMakeFiles/li_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/li_test.dir/depend
