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
CMAKE_SOURCE_DIR = /home/faustojh41014/EstructurasDeDatos/arreglos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/faustojh41014/EstructurasDeDatos/arreglos/build

# Include any dependencies generated for this target.
include tst/CMakeFiles/arreglos_tst.dir/depend.make

# Include the progress variables for this target.
include tst/CMakeFiles/arreglos_tst.dir/progress.make

# Include the compile flags for this target's objects.
include tst/CMakeFiles/arreglos_tst.dir/flags.make

tst/CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.o: tst/CMakeFiles/arreglos_tst.dir/flags.make
tst/CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.o: ../tst/test/c++/mx/test/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/faustojh41014/EstructurasDeDatos/arreglos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tst/CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.o"
	cd /home/faustojh41014/EstructurasDeDatos/arreglos/build/tst && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.o -c /home/faustojh41014/EstructurasDeDatos/arreglos/tst/test/c++/mx/test/Main.cpp

tst/CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.i"
	cd /home/faustojh41014/EstructurasDeDatos/arreglos/build/tst && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/faustojh41014/EstructurasDeDatos/arreglos/tst/test/c++/mx/test/Main.cpp > CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.i

tst/CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.s"
	cd /home/faustojh41014/EstructurasDeDatos/arreglos/build/tst && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/faustojh41014/EstructurasDeDatos/arreglos/tst/test/c++/mx/test/Main.cpp -o CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.s

# Object files for target arreglos_tst
arreglos_tst_OBJECTS = \
"CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.o"

# External object files for target arreglos_tst
arreglos_tst_EXTERNAL_OBJECTS =

tst/arreglos_tst: tst/CMakeFiles/arreglos_tst.dir/test/c++/mx/test/Main.cpp.o
tst/arreglos_tst: tst/CMakeFiles/arreglos_tst.dir/build.make
tst/arreglos_tst: src/libarreglos_lib.a
tst/arreglos_tst: lib/libgtest.a
tst/arreglos_tst: tst/CMakeFiles/arreglos_tst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/faustojh41014/EstructurasDeDatos/arreglos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable arreglos_tst"
	cd /home/faustojh41014/EstructurasDeDatos/arreglos/build/tst && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arreglos_tst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tst/CMakeFiles/arreglos_tst.dir/build: tst/arreglos_tst

.PHONY : tst/CMakeFiles/arreglos_tst.dir/build

tst/CMakeFiles/arreglos_tst.dir/clean:
	cd /home/faustojh41014/EstructurasDeDatos/arreglos/build/tst && $(CMAKE_COMMAND) -P CMakeFiles/arreglos_tst.dir/cmake_clean.cmake
.PHONY : tst/CMakeFiles/arreglos_tst.dir/clean

tst/CMakeFiles/arreglos_tst.dir/depend:
	cd /home/faustojh41014/EstructurasDeDatos/arreglos/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/faustojh41014/EstructurasDeDatos/arreglos /home/faustojh41014/EstructurasDeDatos/arreglos/tst /home/faustojh41014/EstructurasDeDatos/arreglos/build /home/faustojh41014/EstructurasDeDatos/arreglos/build/tst /home/faustojh41014/EstructurasDeDatos/arreglos/build/tst/CMakeFiles/arreglos_tst.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tst/CMakeFiles/arreglos_tst.dir/depend

