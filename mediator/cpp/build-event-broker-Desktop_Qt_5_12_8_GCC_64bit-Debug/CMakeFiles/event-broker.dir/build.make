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
CMAKE_COMMAND = /opt/cmake-3.19.2/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.19.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andreiz/git/learn/design-patterns/mediator/cpp/event-broker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andreiz/git/learn/design-patterns/mediator/cpp/build-event-broker-Desktop_Qt_5_12_8_GCC_64bit-Debug

# Include any dependencies generated for this target.
include CMakeFiles/event-broker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/event-broker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/event-broker.dir/flags.make

CMakeFiles/event-broker.dir/event-broker.cpp.o: CMakeFiles/event-broker.dir/flags.make
CMakeFiles/event-broker.dir/event-broker.cpp.o: /home/andreiz/git/learn/design-patterns/mediator/cpp/event-broker/event-broker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreiz/git/learn/design-patterns/mediator/cpp/build-event-broker-Desktop_Qt_5_12_8_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/event-broker.dir/event-broker.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/event-broker.dir/event-broker.cpp.o -c /home/andreiz/git/learn/design-patterns/mediator/cpp/event-broker/event-broker.cpp

CMakeFiles/event-broker.dir/event-broker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/event-broker.dir/event-broker.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreiz/git/learn/design-patterns/mediator/cpp/event-broker/event-broker.cpp > CMakeFiles/event-broker.dir/event-broker.cpp.i

CMakeFiles/event-broker.dir/event-broker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/event-broker.dir/event-broker.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreiz/git/learn/design-patterns/mediator/cpp/event-broker/event-broker.cpp -o CMakeFiles/event-broker.dir/event-broker.cpp.s

# Object files for target event-broker
event__broker_OBJECTS = \
"CMakeFiles/event-broker.dir/event-broker.cpp.o"

# External object files for target event-broker
event__broker_EXTERNAL_OBJECTS =

event-broker: CMakeFiles/event-broker.dir/event-broker.cpp.o
event-broker: CMakeFiles/event-broker.dir/build.make
event-broker: CMakeFiles/event-broker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andreiz/git/learn/design-patterns/mediator/cpp/build-event-broker-Desktop_Qt_5_12_8_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable event-broker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/event-broker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/event-broker.dir/build: event-broker

.PHONY : CMakeFiles/event-broker.dir/build

CMakeFiles/event-broker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/event-broker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/event-broker.dir/clean

CMakeFiles/event-broker.dir/depend:
	cd /home/andreiz/git/learn/design-patterns/mediator/cpp/build-event-broker-Desktop_Qt_5_12_8_GCC_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andreiz/git/learn/design-patterns/mediator/cpp/event-broker /home/andreiz/git/learn/design-patterns/mediator/cpp/event-broker /home/andreiz/git/learn/design-patterns/mediator/cpp/build-event-broker-Desktop_Qt_5_12_8_GCC_64bit-Debug /home/andreiz/git/learn/design-patterns/mediator/cpp/build-event-broker-Desktop_Qt_5_12_8_GCC_64bit-Debug /home/andreiz/git/learn/design-patterns/mediator/cpp/build-event-broker-Desktop_Qt_5_12_8_GCC_64bit-Debug/CMakeFiles/event-broker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/event-broker.dir/depend

