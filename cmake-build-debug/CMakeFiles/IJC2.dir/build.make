# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\CRAJKOG\Desktop\IJC2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CRAJKOG\Desktop\IJC2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/IJC2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IJC2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IJC2.dir/flags.make

CMakeFiles/IJC2.dir/tail.c.obj: CMakeFiles/IJC2.dir/flags.make
CMakeFiles/IJC2.dir/tail.c.obj: ../tail.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CRAJKOG\Desktop\IJC2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/IJC2.dir/tail.c.obj"
	C:\MinGW-W64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\IJC2.dir\tail.c.obj -c E:\CRAJKOG\Desktop\IJC2\tail.c

CMakeFiles/IJC2.dir/tail.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IJC2.dir/tail.c.i"
	C:\MinGW-W64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\CRAJKOG\Desktop\IJC2\tail.c > CMakeFiles\IJC2.dir\tail.c.i

CMakeFiles/IJC2.dir/tail.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IJC2.dir/tail.c.s"
	C:\MinGW-W64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\CRAJKOG\Desktop\IJC2\tail.c -o CMakeFiles\IJC2.dir\tail.c.s

# Object files for target IJC2
IJC2_OBJECTS = \
"CMakeFiles/IJC2.dir/tail.c.obj"

# External object files for target IJC2
IJC2_EXTERNAL_OBJECTS =

IJC2.exe: CMakeFiles/IJC2.dir/tail.c.obj
IJC2.exe: CMakeFiles/IJC2.dir/build.make
IJC2.exe: CMakeFiles/IJC2.dir/linklibs.rsp
IJC2.exe: CMakeFiles/IJC2.dir/objects1.rsp
IJC2.exe: CMakeFiles/IJC2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CRAJKOG\Desktop\IJC2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable IJC2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\IJC2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IJC2.dir/build: IJC2.exe

.PHONY : CMakeFiles/IJC2.dir/build

CMakeFiles/IJC2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\IJC2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/IJC2.dir/clean

CMakeFiles/IJC2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CRAJKOG\Desktop\IJC2 E:\CRAJKOG\Desktop\IJC2 E:\CRAJKOG\Desktop\IJC2\cmake-build-debug E:\CRAJKOG\Desktop\IJC2\cmake-build-debug E:\CRAJKOG\Desktop\IJC2\cmake-build-debug\CMakeFiles\IJC2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IJC2.dir/depend

