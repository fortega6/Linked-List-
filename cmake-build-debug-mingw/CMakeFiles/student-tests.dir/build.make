# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw"

# Include any dependencies generated for this target.
include CMakeFiles/student-tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/student-tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/student-tests.dir/flags.make

CMakeFiles/student-tests.dir/test_list.cpp.obj: CMakeFiles/student-tests.dir/flags.make
CMakeFiles/student-tests.dir/test_list.cpp.obj: ../test_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/student-tests.dir/test_list.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\student-tests.dir\test_list.cpp.obj -c "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\test_list.cpp"

CMakeFiles/student-tests.dir/test_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/student-tests.dir/test_list.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\test_list.cpp" > CMakeFiles\student-tests.dir\test_list.cpp.i

CMakeFiles/student-tests.dir/test_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/student-tests.dir/test_list.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\test_list.cpp" -o CMakeFiles\student-tests.dir\test_list.cpp.s

# Object files for target student-tests
student__tests_OBJECTS = \
"CMakeFiles/student-tests.dir/test_list.cpp.obj"

# External object files for target student-tests
student__tests_EXTERNAL_OBJECTS =

student-tests.exe: CMakeFiles/student-tests.dir/test_list.cpp.obj
student-tests.exe: CMakeFiles/student-tests.dir/build.make
student-tests.exe: CMakeFiles/student-tests.dir/linklibs.rsp
student-tests.exe: CMakeFiles/student-tests.dir/objects1.rsp
student-tests.exe: CMakeFiles/student-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable student-tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\student-tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/student-tests.dir/build: student-tests.exe

.PHONY : CMakeFiles/student-tests.dir/build

CMakeFiles/student-tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\student-tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/student-tests.dir/clean

CMakeFiles/student-tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-" "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-" "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw" "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw" "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw\CMakeFiles\student-tests.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/student-tests.dir/depend

