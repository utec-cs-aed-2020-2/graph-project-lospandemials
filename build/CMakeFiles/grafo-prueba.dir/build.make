# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/cmake/715/bin/cmake

# The command to remove a file.
RM = /snap/cmake/715/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sebastian/projects/ASD/graph-project-lospandemials

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sebastian/projects/ASD/graph-project-lospandemials/build

# Include any dependencies generated for this target.
include CMakeFiles/grafo-prueba.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/grafo-prueba.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/grafo-prueba.dir/flags.make

CMakeFiles/grafo-prueba.dir/main.cpp.o: CMakeFiles/grafo-prueba.dir/flags.make
CMakeFiles/grafo-prueba.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/projects/ASD/graph-project-lospandemials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/grafo-prueba.dir/main.cpp.o"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/grafo-prueba.dir/main.cpp.o -c /home/sebastian/projects/ASD/graph-project-lospandemials/main.cpp

CMakeFiles/grafo-prueba.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grafo-prueba.dir/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/projects/ASD/graph-project-lospandemials/main.cpp > CMakeFiles/grafo-prueba.dir/main.cpp.i

CMakeFiles/grafo-prueba.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grafo-prueba.dir/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/projects/ASD/graph-project-lospandemials/main.cpp -o CMakeFiles/grafo-prueba.dir/main.cpp.s

# Object files for target grafo-prueba
grafo__prueba_OBJECTS = \
"CMakeFiles/grafo-prueba.dir/main.cpp.o"

# External object files for target grafo-prueba
grafo__prueba_EXTERNAL_OBJECTS =

grafo-prueba: CMakeFiles/grafo-prueba.dir/main.cpp.o
grafo-prueba: CMakeFiles/grafo-prueba.dir/build.make
grafo-prueba: CMakeFiles/grafo-prueba.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sebastian/projects/ASD/graph-project-lospandemials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable grafo-prueba"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/grafo-prueba.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/grafo-prueba.dir/build: grafo-prueba

.PHONY : CMakeFiles/grafo-prueba.dir/build

CMakeFiles/grafo-prueba.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/grafo-prueba.dir/cmake_clean.cmake
.PHONY : CMakeFiles/grafo-prueba.dir/clean

CMakeFiles/grafo-prueba.dir/depend:
	cd /home/sebastian/projects/ASD/graph-project-lospandemials/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sebastian/projects/ASD/graph-project-lospandemials /home/sebastian/projects/ASD/graph-project-lospandemials /home/sebastian/projects/ASD/graph-project-lospandemials/build /home/sebastian/projects/ASD/graph-project-lospandemials/build /home/sebastian/projects/ASD/graph-project-lospandemials/build/CMakeFiles/grafo-prueba.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/grafo-prueba.dir/depend

