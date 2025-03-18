# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/dipsomask/Документы/nounv_prog/auth-servis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth

# Include any dependencies generated for this target.
include External/jwt/example/CMakeFiles/es256k.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include External/jwt/example/CMakeFiles/es256k.dir/compiler_depend.make

# Include the progress variables for this target.
include External/jwt/example/CMakeFiles/es256k.dir/progress.make

# Include the compile flags for this target's objects.
include External/jwt/example/CMakeFiles/es256k.dir/flags.make

External/jwt/example/CMakeFiles/es256k.dir/es256k.cpp.o: External/jwt/example/CMakeFiles/es256k.dir/flags.make
External/jwt/example/CMakeFiles/es256k.dir/es256k.cpp.o: /home/dipsomask/Документы/nounv_prog/auth-servis/External/jwt/example/es256k.cpp
External/jwt/example/CMakeFiles/es256k.dir/es256k.cpp.o: External/jwt/example/CMakeFiles/es256k.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object External/jwt/example/CMakeFiles/es256k.dir/es256k.cpp.o"
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT External/jwt/example/CMakeFiles/es256k.dir/es256k.cpp.o -MF CMakeFiles/es256k.dir/es256k.cpp.o.d -o CMakeFiles/es256k.dir/es256k.cpp.o -c /home/dipsomask/Документы/nounv_prog/auth-servis/External/jwt/example/es256k.cpp

External/jwt/example/CMakeFiles/es256k.dir/es256k.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/es256k.dir/es256k.cpp.i"
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dipsomask/Документы/nounv_prog/auth-servis/External/jwt/example/es256k.cpp > CMakeFiles/es256k.dir/es256k.cpp.i

External/jwt/example/CMakeFiles/es256k.dir/es256k.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/es256k.dir/es256k.cpp.s"
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dipsomask/Документы/nounv_prog/auth-servis/External/jwt/example/es256k.cpp -o CMakeFiles/es256k.dir/es256k.cpp.s

# Object files for target es256k
es256k_OBJECTS = \
"CMakeFiles/es256k.dir/es256k.cpp.o"

# External object files for target es256k
es256k_EXTERNAL_OBJECTS =

External/jwt/example/es256k: External/jwt/example/CMakeFiles/es256k.dir/es256k.cpp.o
External/jwt/example/es256k: External/jwt/example/CMakeFiles/es256k.dir/build.make
External/jwt/example/es256k: /usr/lib/x86_64-linux-gnu/libssl.so
External/jwt/example/es256k: /usr/lib/x86_64-linux-gnu/libcrypto.so
External/jwt/example/es256k: External/jwt/example/CMakeFiles/es256k.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable es256k"
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/es256k.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
External/jwt/example/CMakeFiles/es256k.dir/build: External/jwt/example/es256k
.PHONY : External/jwt/example/CMakeFiles/es256k.dir/build

External/jwt/example/CMakeFiles/es256k.dir/clean:
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example && $(CMAKE_COMMAND) -P CMakeFiles/es256k.dir/cmake_clean.cmake
.PHONY : External/jwt/example/CMakeFiles/es256k.dir/clean

External/jwt/example/CMakeFiles/es256k.dir/depend:
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dipsomask/Документы/nounv_prog/auth-servis /home/dipsomask/Документы/nounv_prog/auth-servis/External/jwt/example /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example/CMakeFiles/es256k.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : External/jwt/example/CMakeFiles/es256k.dir/depend

