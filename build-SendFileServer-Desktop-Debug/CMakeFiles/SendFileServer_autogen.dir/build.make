# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /home/mrx_ovo/Programs/qt5/SendFileServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrx_ovo/Programs/qt5/build-SendFileServer-Desktop-Debug

# Utility rule file for SendFileServer_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/SendFileServer_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SendFileServer_autogen.dir/progress.make

CMakeFiles/SendFileServer_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mrx_ovo/Programs/qt5/build-SendFileServer-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target SendFileServer"
	/usr/bin/cmake -E cmake_autogen /home/mrx_ovo/Programs/qt5/build-SendFileServer-Desktop-Debug/CMakeFiles/SendFileServer_autogen.dir/AutogenInfo.json Debug

SendFileServer_autogen: CMakeFiles/SendFileServer_autogen
SendFileServer_autogen: CMakeFiles/SendFileServer_autogen.dir/build.make
.PHONY : SendFileServer_autogen

# Rule to build all files generated by this target.
CMakeFiles/SendFileServer_autogen.dir/build: SendFileServer_autogen
.PHONY : CMakeFiles/SendFileServer_autogen.dir/build

CMakeFiles/SendFileServer_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SendFileServer_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SendFileServer_autogen.dir/clean

CMakeFiles/SendFileServer_autogen.dir/depend:
	cd /home/mrx_ovo/Programs/qt5/build-SendFileServer-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrx_ovo/Programs/qt5/SendFileServer /home/mrx_ovo/Programs/qt5/SendFileServer /home/mrx_ovo/Programs/qt5/build-SendFileServer-Desktop-Debug /home/mrx_ovo/Programs/qt5/build-SendFileServer-Desktop-Debug /home/mrx_ovo/Programs/qt5/build-SendFileServer-Desktop-Debug/CMakeFiles/SendFileServer_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SendFileServer_autogen.dir/depend
