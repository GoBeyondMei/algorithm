# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion\CLion 2017.3.5\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion 2017.3.5\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLion\Projects\algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLion\Projects\algorithm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algorithm.dir/flags.make

CMakeFiles/algorithm.dir/Binary_tree.cpp.obj: CMakeFiles/algorithm.dir/flags.make
CMakeFiles/algorithm.dir/Binary_tree.cpp.obj: ../Binary_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLion\Projects\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algorithm.dir/Binary_tree.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\algorithm.dir\Binary_tree.cpp.obj -c D:\CLion\Projects\algorithm\Binary_tree.cpp

CMakeFiles/algorithm.dir/Binary_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algorithm.dir/Binary_tree.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLion\Projects\algorithm\Binary_tree.cpp > CMakeFiles\algorithm.dir\Binary_tree.cpp.i

CMakeFiles/algorithm.dir/Binary_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algorithm.dir/Binary_tree.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLion\Projects\algorithm\Binary_tree.cpp -o CMakeFiles\algorithm.dir\Binary_tree.cpp.s

CMakeFiles/algorithm.dir/Binary_tree.cpp.obj.requires:

.PHONY : CMakeFiles/algorithm.dir/Binary_tree.cpp.obj.requires

CMakeFiles/algorithm.dir/Binary_tree.cpp.obj.provides: CMakeFiles/algorithm.dir/Binary_tree.cpp.obj.requires
	$(MAKE) -f CMakeFiles\algorithm.dir\build.make CMakeFiles/algorithm.dir/Binary_tree.cpp.obj.provides.build
.PHONY : CMakeFiles/algorithm.dir/Binary_tree.cpp.obj.provides

CMakeFiles/algorithm.dir/Binary_tree.cpp.obj.provides.build: CMakeFiles/algorithm.dir/Binary_tree.cpp.obj


# Object files for target algorithm
algorithm_OBJECTS = \
"CMakeFiles/algorithm.dir/Binary_tree.cpp.obj"

# External object files for target algorithm
algorithm_EXTERNAL_OBJECTS =

algorithm.exe: CMakeFiles/algorithm.dir/Binary_tree.cpp.obj
algorithm.exe: CMakeFiles/algorithm.dir/build.make
algorithm.exe: CMakeFiles/algorithm.dir/linklibs.rsp
algorithm.exe: CMakeFiles/algorithm.dir/objects1.rsp
algorithm.exe: CMakeFiles/algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLion\Projects\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algorithm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algorithm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algorithm.dir/build: algorithm.exe

.PHONY : CMakeFiles/algorithm.dir/build

CMakeFiles/algorithm.dir/requires: CMakeFiles/algorithm.dir/Binary_tree.cpp.obj.requires

.PHONY : CMakeFiles/algorithm.dir/requires

CMakeFiles/algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algorithm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/algorithm.dir/clean

CMakeFiles/algorithm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLion\Projects\algorithm D:\CLion\Projects\algorithm D:\CLion\Projects\algorithm\cmake-build-debug D:\CLion\Projects\algorithm\cmake-build-debug D:\CLion\Projects\algorithm\cmake-build-debug\CMakeFiles\algorithm.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algorithm.dir/depend

