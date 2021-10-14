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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/build

# Include any dependencies generated for this target.
include src/lib/myLaws/CMakeFiles/myLaws.dir/depend.make

# Include the progress variables for this target.
include src/lib/myLaws/CMakeFiles/myLaws.dir/progress.make

# Include the compile flags for this target's objects.
include src/lib/myLaws/CMakeFiles/myLaws.dir/flags.make

src/lib/myLaws/CMakeFiles/myLaws.dir/Law.cpp.o: src/lib/myLaws/CMakeFiles/myLaws.dir/flags.make
src/lib/myLaws/CMakeFiles/myLaws.dir/Law.cpp.o: ../src/lib/myLaws/Law.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/lib/myLaws/CMakeFiles/myLaws.dir/Law.cpp.o"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myLaws.dir/Law.cpp.o -c /data/src/lib/myLaws/Law.cpp

src/lib/myLaws/CMakeFiles/myLaws.dir/Law.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myLaws.dir/Law.cpp.i"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/src/lib/myLaws/Law.cpp > CMakeFiles/myLaws.dir/Law.cpp.i

src/lib/myLaws/CMakeFiles/myLaws.dir/Law.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myLaws.dir/Law.cpp.s"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/src/lib/myLaws/Law.cpp -o CMakeFiles/myLaws.dir/Law.cpp.s

src/lib/myLaws/CMakeFiles/myLaws.dir/SeparationLaw.cpp.o: src/lib/myLaws/CMakeFiles/myLaws.dir/flags.make
src/lib/myLaws/CMakeFiles/myLaws.dir/SeparationLaw.cpp.o: ../src/lib/myLaws/SeparationLaw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/lib/myLaws/CMakeFiles/myLaws.dir/SeparationLaw.cpp.o"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myLaws.dir/SeparationLaw.cpp.o -c /data/src/lib/myLaws/SeparationLaw.cpp

src/lib/myLaws/CMakeFiles/myLaws.dir/SeparationLaw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myLaws.dir/SeparationLaw.cpp.i"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/src/lib/myLaws/SeparationLaw.cpp > CMakeFiles/myLaws.dir/SeparationLaw.cpp.i

src/lib/myLaws/CMakeFiles/myLaws.dir/SeparationLaw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myLaws.dir/SeparationLaw.cpp.s"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/src/lib/myLaws/SeparationLaw.cpp -o CMakeFiles/myLaws.dir/SeparationLaw.cpp.s

src/lib/myLaws/CMakeFiles/myLaws.dir/CohesionLaw.cpp.o: src/lib/myLaws/CMakeFiles/myLaws.dir/flags.make
src/lib/myLaws/CMakeFiles/myLaws.dir/CohesionLaw.cpp.o: ../src/lib/myLaws/CohesionLaw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/lib/myLaws/CMakeFiles/myLaws.dir/CohesionLaw.cpp.o"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myLaws.dir/CohesionLaw.cpp.o -c /data/src/lib/myLaws/CohesionLaw.cpp

src/lib/myLaws/CMakeFiles/myLaws.dir/CohesionLaw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myLaws.dir/CohesionLaw.cpp.i"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/src/lib/myLaws/CohesionLaw.cpp > CMakeFiles/myLaws.dir/CohesionLaw.cpp.i

src/lib/myLaws/CMakeFiles/myLaws.dir/CohesionLaw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myLaws.dir/CohesionLaw.cpp.s"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/src/lib/myLaws/CohesionLaw.cpp -o CMakeFiles/myLaws.dir/CohesionLaw.cpp.s

src/lib/myLaws/CMakeFiles/myLaws.dir/AlignmentLaw.cpp.o: src/lib/myLaws/CMakeFiles/myLaws.dir/flags.make
src/lib/myLaws/CMakeFiles/myLaws.dir/AlignmentLaw.cpp.o: ../src/lib/myLaws/AlignmentLaw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/lib/myLaws/CMakeFiles/myLaws.dir/AlignmentLaw.cpp.o"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myLaws.dir/AlignmentLaw.cpp.o -c /data/src/lib/myLaws/AlignmentLaw.cpp

src/lib/myLaws/CMakeFiles/myLaws.dir/AlignmentLaw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myLaws.dir/AlignmentLaw.cpp.i"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/src/lib/myLaws/AlignmentLaw.cpp > CMakeFiles/myLaws.dir/AlignmentLaw.cpp.i

src/lib/myLaws/CMakeFiles/myLaws.dir/AlignmentLaw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myLaws.dir/AlignmentLaw.cpp.s"
	cd /data/build/src/lib/myLaws && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/src/lib/myLaws/AlignmentLaw.cpp -o CMakeFiles/myLaws.dir/AlignmentLaw.cpp.s

# Object files for target myLaws
myLaws_OBJECTS = \
"CMakeFiles/myLaws.dir/Law.cpp.o" \
"CMakeFiles/myLaws.dir/SeparationLaw.cpp.o" \
"CMakeFiles/myLaws.dir/CohesionLaw.cpp.o" \
"CMakeFiles/myLaws.dir/AlignmentLaw.cpp.o"

# External object files for target myLaws
myLaws_EXTERNAL_OBJECTS =

src/lib/myLaws/libmyLaws.a: src/lib/myLaws/CMakeFiles/myLaws.dir/Law.cpp.o
src/lib/myLaws/libmyLaws.a: src/lib/myLaws/CMakeFiles/myLaws.dir/SeparationLaw.cpp.o
src/lib/myLaws/libmyLaws.a: src/lib/myLaws/CMakeFiles/myLaws.dir/CohesionLaw.cpp.o
src/lib/myLaws/libmyLaws.a: src/lib/myLaws/CMakeFiles/myLaws.dir/AlignmentLaw.cpp.o
src/lib/myLaws/libmyLaws.a: src/lib/myLaws/CMakeFiles/myLaws.dir/build.make
src/lib/myLaws/libmyLaws.a: src/lib/myLaws/CMakeFiles/myLaws.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libmyLaws.a"
	cd /data/build/src/lib/myLaws && $(CMAKE_COMMAND) -P CMakeFiles/myLaws.dir/cmake_clean_target.cmake
	cd /data/build/src/lib/myLaws && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myLaws.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/lib/myLaws/CMakeFiles/myLaws.dir/build: src/lib/myLaws/libmyLaws.a

.PHONY : src/lib/myLaws/CMakeFiles/myLaws.dir/build

src/lib/myLaws/CMakeFiles/myLaws.dir/clean:
	cd /data/build/src/lib/myLaws && $(CMAKE_COMMAND) -P CMakeFiles/myLaws.dir/cmake_clean.cmake
.PHONY : src/lib/myLaws/CMakeFiles/myLaws.dir/clean

src/lib/myLaws/CMakeFiles/myLaws.dir/depend:
	cd /data/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data /data/src/lib/myLaws /data/build /data/build/src/lib/myLaws /data/build/src/lib/myLaws/CMakeFiles/myLaws.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/lib/myLaws/CMakeFiles/myLaws.dir/depend
