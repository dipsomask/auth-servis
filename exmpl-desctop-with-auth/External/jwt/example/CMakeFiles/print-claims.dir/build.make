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
include External/jwt/example/CMakeFiles/print-claims.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include External/jwt/example/CMakeFiles/print-claims.dir/compiler_depend.make

# Include the progress variables for this target.
include External/jwt/example/CMakeFiles/print-claims.dir/progress.make

# Include the compile flags for this target's objects.
include External/jwt/example/CMakeFiles/print-claims.dir/flags.make

External/jwt/example/CMakeFiles/print-claims.dir/print-claims.cpp.o: External/jwt/example/CMakeFiles/print-claims.dir/flags.make
External/jwt/example/CMakeFiles/print-claims.dir/print-claims.cpp.o: /home/dipsomask/Документы/nounv_prog/auth-servis/External/jwt/example/print-claims.cpp
External/jwt/example/CMakeFiles/print-claims.dir/print-claims.cpp.o: External/jwt/example/CMakeFiles/print-claims.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object External/jwt/example/CMakeFiles/print-claims.dir/print-claims.cpp.o"
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT External/jwt/example/CMakeFiles/print-claims.dir/print-claims.cpp.o -MF CMakeFiles/print-claims.dir/print-claims.cpp.o.d -o CMakeFiles/print-claims.dir/print-claims.cpp.o -c /home/dipsomask/Документы/nounv_prog/auth-servis/External/jwt/example/print-claims.cpp

External/jwt/example/CMakeFiles/print-claims.dir/print-claims.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/print-claims.dir/print-claims.cpp.i"
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dipsomask/Документы/nounv_prog/auth-servis/External/jwt/example/print-claims.cpp > CMakeFiles/print-claims.dir/print-claims.cpp.i

External/jwt/example/CMakeFiles/print-claims.dir/print-claims.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/print-claims.dir/print-claims.cpp.s"
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dipsomask/Документы/nounv_prog/auth-servis/External/jwt/example/print-claims.cpp -o CMakeFiles/print-claims.dir/print-claims.cpp.s

# Object files for target print-claims
print__claims_OBJECTS = \
"CMakeFiles/print-claims.dir/print-claims.cpp.o"

# External object files for target print-claims
print__claims_EXTERNAL_OBJECTS =

External/jwt/example/print-claims: External/jwt/example/CMakeFiles/print-claims.dir/print-claims.cpp.o
External/jwt/example/print-claims: External/jwt/example/CMakeFiles/print-claims.dir/build.make
External/jwt/example/print-claims: /usr/lib/x86_64-linux-gnu/libssl.so
External/jwt/example/print-claims: /usr/lib/x86_64-linux-gnu/libcrypto.so
External/jwt/example/print-claims: External/jwt/example/CMakeFiles/print-claims.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable print-claims"
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/print-claims.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
External/jwt/example/CMakeFiles/print-claims.dir/build: External/jwt/example/print-claims
.PHONY : External/jwt/example/CMakeFiles/print-claims.dir/build

External/jwt/example/CMakeFiles/print-claims.dir/clean:
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example && $(CMAKE_COMMAND) -P CMakeFiles/print-claims.dir/cmake_clean.cmake
.PHONY : External/jwt/example/CMakeFiles/print-claims.dir/clean

External/jwt/example/CMakeFiles/print-claims.dir/depend:
	cd /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dipsomask/Документы/nounv_prog/auth-servis /home/dipsomask/Документы/nounv_prog/auth-servis/External/jwt/example /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example /home/dipsomask/Документы/nounv_prog/auth-servis/exmpl-desctop-with-auth/External/jwt/example/CMakeFiles/print-claims.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : External/jwt/example/CMakeFiles/print-claims.dir/depend

