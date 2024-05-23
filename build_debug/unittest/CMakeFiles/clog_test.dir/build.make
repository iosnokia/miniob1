# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/miniob2/miniob

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/miniob2/miniob/build_debug

# Include any dependencies generated for this target.
include unittest/CMakeFiles/clog_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include unittest/CMakeFiles/clog_test.dir/compiler_depend.make

# Include the progress variables for this target.
include unittest/CMakeFiles/clog_test.dir/progress.make

# Include the compile flags for this target's objects.
include unittest/CMakeFiles/clog_test.dir/flags.make

unittest/CMakeFiles/clog_test.dir/clog_test.cpp.o: unittest/CMakeFiles/clog_test.dir/flags.make
unittest/CMakeFiles/clog_test.dir/clog_test.cpp.o: ../unittest/clog_test.cpp
unittest/CMakeFiles/clog_test.dir/clog_test.cpp.o: unittest/CMakeFiles/clog_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/miniob2/miniob/build_debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unittest/CMakeFiles/clog_test.dir/clog_test.cpp.o"
	cd /root/miniob2/miniob/build_debug/unittest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT unittest/CMakeFiles/clog_test.dir/clog_test.cpp.o -MF CMakeFiles/clog_test.dir/clog_test.cpp.o.d -o CMakeFiles/clog_test.dir/clog_test.cpp.o -c /root/miniob2/miniob/unittest/clog_test.cpp

unittest/CMakeFiles/clog_test.dir/clog_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clog_test.dir/clog_test.cpp.i"
	cd /root/miniob2/miniob/build_debug/unittest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/miniob2/miniob/unittest/clog_test.cpp > CMakeFiles/clog_test.dir/clog_test.cpp.i

unittest/CMakeFiles/clog_test.dir/clog_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clog_test.dir/clog_test.cpp.s"
	cd /root/miniob2/miniob/build_debug/unittest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/miniob2/miniob/unittest/clog_test.cpp -o CMakeFiles/clog_test.dir/clog_test.cpp.s

# Object files for target clog_test
clog_test_OBJECTS = \
"CMakeFiles/clog_test.dir/clog_test.cpp.o"

# External object files for target clog_test
clog_test_EXTERNAL_OBJECTS =

bin/clog_test: unittest/CMakeFiles/clog_test.dir/clog_test.cpp.o
bin/clog_test: unittest/CMakeFiles/clog_test.dir/build.make
bin/clog_test: lib/libcommon.a
bin/clog_test: lib/libobserver.a
bin/clog_test: lib/libcommon.a
bin/clog_test: /usr/lib/x86_64-linux-gnu/libreadline.so
bin/clog_test: /usr/local/lib/libevent_pthreads.a
bin/clog_test: /usr/local/lib/libevent_core.a
bin/clog_test: unittest/CMakeFiles/clog_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/miniob2/miniob/build_debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/clog_test"
	cd /root/miniob2/miniob/build_debug/unittest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clog_test.dir/link.txt --verbose=$(VERBOSE)
	cd /root/miniob2/miniob/build_debug/unittest && /usr/bin/cmake -D TEST_TARGET=clog_test -D TEST_EXECUTABLE=/root/miniob2/miniob/build_debug/bin/clog_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/root/miniob2/miniob/build_debug/unittest -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=clog_test_TESTS -D CTEST_FILE=/root/miniob2/miniob/build_debug/unittest/clog_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
unittest/CMakeFiles/clog_test.dir/build: bin/clog_test
.PHONY : unittest/CMakeFiles/clog_test.dir/build

unittest/CMakeFiles/clog_test.dir/clean:
	cd /root/miniob2/miniob/build_debug/unittest && $(CMAKE_COMMAND) -P CMakeFiles/clog_test.dir/cmake_clean.cmake
.PHONY : unittest/CMakeFiles/clog_test.dir/clean

unittest/CMakeFiles/clog_test.dir/depend:
	cd /root/miniob2/miniob/build_debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/miniob2/miniob /root/miniob2/miniob/unittest /root/miniob2/miniob/build_debug /root/miniob2/miniob/build_debug/unittest /root/miniob2/miniob/build_debug/unittest/CMakeFiles/clog_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unittest/CMakeFiles/clog_test.dir/depend

