# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/aleksandrgrigorev/Desktop/Учеба/Операционные сисемы/Tanks"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/aleksandrgrigorev/Desktop/Учеба/Операционные сисемы/Tanks"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/aleksandrgrigorev/Desktop/Учеба/Операционные сисемы/Tanks/CMakeFiles" "/Users/aleksandrgrigorev/Desktop/Учеба/Операционные сисемы/Tanks/CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/aleksandrgrigorev/Desktop/Учеба/Операционные сисемы/Tanks/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Tanks

# Build rule for target.
Tanks: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Tanks
.PHONY : Tanks

# fast build rule for target.
Tanks/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/build
.PHONY : Tanks/fast

bullet.o: bullet.c.o

.PHONY : bullet.o

# target to build an object file
bullet.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/bullet.c.o
.PHONY : bullet.c.o

bullet.i: bullet.c.i

.PHONY : bullet.i

# target to preprocess a source file
bullet.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/bullet.c.i
.PHONY : bullet.c.i

bullet.s: bullet.c.s

.PHONY : bullet.s

# target to generate assembly for a file
bullet.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/bullet.c.s
.PHONY : bullet.c.s

main.o: main.c.o

.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i

.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s

.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/main.c.s
.PHONY : main.c.s

network.o: network.c.o

.PHONY : network.o

# target to build an object file
network.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/network.c.o
.PHONY : network.c.o

network.i: network.c.i

.PHONY : network.i

# target to preprocess a source file
network.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/network.c.i
.PHONY : network.c.i

network.s: network.c.s

.PHONY : network.s

# target to generate assembly for a file
network.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/network.c.s
.PHONY : network.c.s

tank.o: tank.c.o

.PHONY : tank.o

# target to build an object file
tank.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/tank.c.o
.PHONY : tank.c.o

tank.i: tank.c.i

.PHONY : tank.i

# target to preprocess a source file
tank.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/tank.c.i
.PHONY : tank.c.i

tank.s: tank.c.s

.PHONY : tank.s

# target to generate assembly for a file
tank.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Tanks.dir/build.make CMakeFiles/Tanks.dir/tank.c.s
.PHONY : tank.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Tanks"
	@echo "... bullet.o"
	@echo "... bullet.i"
	@echo "... bullet.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... network.o"
	@echo "... network.i"
	@echo "... network.s"
	@echo "... tank.o"
	@echo "... tank.i"
	@echo "... tank.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
