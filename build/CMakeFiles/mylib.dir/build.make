# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/keusa/calc/der-Kalkulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keusa/calc/der-Kalkulator/build

# Include any dependencies generated for this target.
include CMakeFiles/mylib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mylib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mylib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mylib.dir/flags.make

CMakeFiles/mylib.dir/src/math.cpp.o: CMakeFiles/mylib.dir/flags.make
CMakeFiles/mylib.dir/src/math.cpp.o: /home/keusa/calc/der-Kalkulator/src/math.cpp
CMakeFiles/mylib.dir/src/math.cpp.o: CMakeFiles/mylib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/keusa/calc/der-Kalkulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mylib.dir/src/math.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mylib.dir/src/math.cpp.o -MF CMakeFiles/mylib.dir/src/math.cpp.o.d -o CMakeFiles/mylib.dir/src/math.cpp.o -c /home/keusa/calc/der-Kalkulator/src/math.cpp

CMakeFiles/mylib.dir/src/math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/math.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keusa/calc/der-Kalkulator/src/math.cpp > CMakeFiles/mylib.dir/src/math.cpp.i

CMakeFiles/mylib.dir/src/math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/math.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keusa/calc/der-Kalkulator/src/math.cpp -o CMakeFiles/mylib.dir/src/math.cpp.s

CMakeFiles/mylib.dir/src/matrix.cpp.o: CMakeFiles/mylib.dir/flags.make
CMakeFiles/mylib.dir/src/matrix.cpp.o: /home/keusa/calc/der-Kalkulator/src/matrix.cpp
CMakeFiles/mylib.dir/src/matrix.cpp.o: CMakeFiles/mylib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/keusa/calc/der-Kalkulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mylib.dir/src/matrix.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mylib.dir/src/matrix.cpp.o -MF CMakeFiles/mylib.dir/src/matrix.cpp.o.d -o CMakeFiles/mylib.dir/src/matrix.cpp.o -c /home/keusa/calc/der-Kalkulator/src/matrix.cpp

CMakeFiles/mylib.dir/src/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keusa/calc/der-Kalkulator/src/matrix.cpp > CMakeFiles/mylib.dir/src/matrix.cpp.i

CMakeFiles/mylib.dir/src/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keusa/calc/der-Kalkulator/src/matrix.cpp -o CMakeFiles/mylib.dir/src/matrix.cpp.s

# Object files for target mylib
mylib_OBJECTS = \
"CMakeFiles/mylib.dir/src/math.cpp.o" \
"CMakeFiles/mylib.dir/src/matrix.cpp.o"

# External object files for target mylib
mylib_EXTERNAL_OBJECTS =

libmylib.a: CMakeFiles/mylib.dir/src/math.cpp.o
libmylib.a: CMakeFiles/mylib.dir/src/matrix.cpp.o
libmylib.a: CMakeFiles/mylib.dir/build.make
libmylib.a: CMakeFiles/mylib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/keusa/calc/der-Kalkulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libmylib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mylib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mylib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mylib.dir/build: libmylib.a
.PHONY : CMakeFiles/mylib.dir/build

CMakeFiles/mylib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mylib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mylib.dir/clean

CMakeFiles/mylib.dir/depend:
	cd /home/keusa/calc/der-Kalkulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keusa/calc/der-Kalkulator /home/keusa/calc/der-Kalkulator /home/keusa/calc/der-Kalkulator/build /home/keusa/calc/der-Kalkulator/build /home/keusa/calc/der-Kalkulator/build/CMakeFiles/mylib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mylib.dir/depend

