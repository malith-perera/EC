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
CMAKE_SOURCE_DIR = /home/malith/EC/eclib/tools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/malith/EC/eclib/tools/build

# Include any dependencies generated for this target.
include CMakeFiles/ec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ec.dir/flags.make

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.o: /home/malith/EC/eclib/src/ec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.o   -c /home/malith/EC/eclib/src/ec.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.o: /home/malith/EC/eclib/src/ec_array.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.o   -c /home/malith/EC/eclib/src/ec_array.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_array.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_array.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.o: /home/malith/EC/eclib/src/ec_bench.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.o   -c /home/malith/EC/eclib/src/ec_bench.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_bench.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_bench.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.o: /home/malith/EC/eclib/src/ec_bits.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.o   -c /home/malith/EC/eclib/src/ec_bits.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_bits.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_bits.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.o: /home/malith/EC/eclib/src/ec_bool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.o   -c /home/malith/EC/eclib/src/ec_bool.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_bool.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_bool.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.o: /home/malith/EC/eclib/src/ec_class.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.o   -c /home/malith/EC/eclib/src/ec_class.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_class.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_class.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.o: /home/malith/EC/eclib/src/ec_error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.o   -c /home/malith/EC/eclib/src/ec_error.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_error.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_error.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.o: /home/malith/EC/eclib/src/ec_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.o   -c /home/malith/EC/eclib/src/ec_file.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_file.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_file.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.o: /home/malith/EC/eclib/src/ec_garbage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.o   -c /home/malith/EC/eclib/src/ec_garbage.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_garbage.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_garbage.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.o: /home/malith/EC/eclib/src/ec_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.o   -c /home/malith/EC/eclib/src/ec_list.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_list.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_list.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.o: /home/malith/EC/eclib/src/ec_object.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.o   -c /home/malith/EC/eclib/src/ec_object.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_object.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_object.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.o: /home/malith/EC/eclib/src/ec_os.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.o   -c /home/malith/EC/eclib/src/ec_os.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_os.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_os.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.o: /home/malith/EC/eclib/src/ec_print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.o   -c /home/malith/EC/eclib/src/ec_print.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_print.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_print.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.o: /home/malith/EC/eclib/src/ec_string.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.o   -c /home/malith/EC/eclib/src/ec_string.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_string.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_string.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.o: /home/malith/EC/eclib/src/ec_syntax.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.o   -c /home/malith/EC/eclib/src/ec_syntax.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_syntax.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_syntax.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.o: /home/malith/EC/eclib/src/ec_sys.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.o   -c /home/malith/EC/eclib/src/ec_sys.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_sys.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_sys.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.o: /home/malith/EC/eclib/src/ec_tokenize_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.o   -c /home/malith/EC/eclib/src/ec_tokenize_file.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_tokenize_file.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_tokenize_file.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.s

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.o: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.o: /home/malith/EC/eclib/src/ec_vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.o   -c /home/malith/EC/eclib/src/ec_vector.c

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malith/EC/eclib/src/ec_vector.c > CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.i

CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malith/EC/eclib/src/ec_vector.c -o CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.s

# Object files for target ec
ec_OBJECTS = \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.o" \
"CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.o"

# External object files for target ec
ec_EXTERNAL_OBJECTS =

libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_array.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bench.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bits.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_bool.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_class.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_error.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_file.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_garbage.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_list.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_object.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_os.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_print.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_string.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_syntax.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_sys.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_tokenize_file.c.o
libec.so: CMakeFiles/ec.dir/home/malith/EC/eclib/src/ec_vector.c.o
libec.so: CMakeFiles/ec.dir/build.make
libec.so: CMakeFiles/ec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/malith/EC/eclib/tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking C shared library libec.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ec.dir/build: libec.so

.PHONY : CMakeFiles/ec.dir/build

CMakeFiles/ec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ec.dir/clean

CMakeFiles/ec.dir/depend:
	cd /home/malith/EC/eclib/tools/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/malith/EC/eclib/tools /home/malith/EC/eclib/tools /home/malith/EC/eclib/tools/build /home/malith/EC/eclib/tools/build /home/malith/EC/eclib/tools/build/CMakeFiles/ec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ec.dir/depend

