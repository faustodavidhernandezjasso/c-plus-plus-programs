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
CMAKE_SOURCE_DIR = /home/faustojh41014/EstructurasDeDatos/lista

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/faustojh41014/EstructurasDeDatos/lista/build

# Include any dependencies generated for this target.
include tst/CMakeFiles/lista_tst.dir/depend.make

# Include the progress variables for this target.
include tst/CMakeFiles/lista_tst.dir/progress.make

# Include the compile flags for this target's objects.
include tst/CMakeFiles/lista_tst.dir/flags.make

tst/CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.o: tst/CMakeFiles/lista_tst.dir/flags.make
tst/CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.o: ../tst/test/c++/mx/test/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/faustojh41014/EstructurasDeDatos/lista/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tst/CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.o"
	cd /home/faustojh41014/EstructurasDeDatos/lista/build/tst && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.o -c /home/faustojh41014/EstructurasDeDatos/lista/tst/test/c++/mx/test/Main.cpp

tst/CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.i"
	cd /home/faustojh41014/EstructurasDeDatos/lista/build/tst && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/faustojh41014/EstructurasDeDatos/lista/tst/test/c++/mx/test/Main.cpp > CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.i

tst/CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.s"
	cd /home/faustojh41014/EstructurasDeDatos/lista/build/tst && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/faustojh41014/EstructurasDeDatos/lista/tst/test/c++/mx/test/Main.cpp -o CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.s

# Object files for target lista_tst
lista_tst_OBJECTS = \
"CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.o"

# External object files for target lista_tst
lista_tst_EXTERNAL_OBJECTS =

tst/lista_tst: tst/CMakeFiles/lista_tst.dir/test/c++/mx/test/Main.cpp.o
tst/lista_tst: tst/CMakeFiles/lista_tst.dir/build.make
tst/lista_tst: src/liblista_lib.a
tst/lista_tst: lib/libgtest.a
tst/lista_tst: tst/CMakeFiles/lista_tst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/faustojh41014/EstructurasDeDatos/lista/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lista_tst"
	cd /home/faustojh41014/EstructurasDeDatos/lista/build/tst && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lista_tst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tst/CMakeFiles/lista_tst.dir/build: tst/lista_tst

.PHONY : tst/CMakeFiles/lista_tst.dir/build

tst/CMakeFiles/lista_tst.dir/clean:
	cd /home/faustojh41014/EstructurasDeDatos/lista/build/tst && $(CMAKE_COMMAND) -P CMakeFiles/lista_tst.dir/cmake_clean.cmake
.PHONY : tst/CMakeFiles/lista_tst.dir/clean

tst/CMakeFiles/lista_tst.dir/depend:
	cd /home/faustojh41014/EstructurasDeDatos/lista/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/faustojh41014/EstructurasDeDatos/lista /home/faustojh41014/EstructurasDeDatos/lista/tst /home/faustojh41014/EstructurasDeDatos/lista/build /home/faustojh41014/EstructurasDeDatos/lista/build/tst /home/faustojh41014/EstructurasDeDatos/lista/build/tst/CMakeFiles/lista_tst.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tst/CMakeFiles/lista_tst.dir/depend

