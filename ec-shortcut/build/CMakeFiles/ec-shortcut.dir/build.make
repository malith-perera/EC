# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /snap/cmake/549/bin/cmake

# The command to remove a file.
RM = /snap/cmake/549/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/malith/EC/ec-shortcut

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/malith/EC/ec-shortcut/build

# Include any dependencies generated for this target.
include CMakeFiles/ec-shortcut.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ec-shortcut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ec-shortcut.dir/flags.make

CMakeFiles/ec-shortcut.dir/src/main.c.o: CMakeFiles/ec-shortcut.dir/flags.make
CMakeFiles/ec-shortcut.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/ec-shortcut/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ec-shortcut.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec-shortcut.dir/src/main.c.o -c /home/malith/EC/ec-shortcut/src/main.c

CMakeFiles/ec-shortcut.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec-shortcut.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/ec-shortcut/src/main.c > CMakeFiles/ec-shortcut.dir/src/main.c.i

CMakeFiles/ec-shortcut.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec-shortcut.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/ec-shortcut/src/main.c -o CMakeFiles/ec-shortcut.dir/src/main.c.s

# Object files for target ec-shortcut
ec__shortcut_OBJECTS = \
"CMakeFiles/ec-shortcut.dir/src/main.c.o"

# External object files for target ec-shortcut
ec__shortcut_EXTERNAL_OBJECTS =

ec-shortcut: CMakeFiles/ec-shortcut.dir/src/main.c.o
ec-shortcut: CMakeFiles/ec-shortcut.dir/build.make
ec-shortcut: CMakeFiles/ec-shortcut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/malith/EC/ec-shortcut/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ec-shortcut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ec-shortcut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ec-shortcut.dir/build: ec-shortcut

.PHONY : CMakeFiles/ec-shortcut.dir/build

CMakeFiles/ec-shortcut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ec-shortcut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ec-shortcut.dir/clean

CMakeFiles/ec-shortcut.dir/depend:
	cd /home/malith/EC/ec-shortcut/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/malith/EC/ec-shortcut /home/malith/EC/ec-shortcut /home/malith/EC/ec-shortcut/build /home/malith/EC/ec-shortcut/build /home/malith/EC/ec-shortcut/build/CMakeFiles/ec-shortcut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ec-shortcut.dir/depend

