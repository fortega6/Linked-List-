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
include CMakeFiles/todo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/todo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/todo.dir/flags.make

CMakeFiles/todo.dir/main.cpp.obj: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/todo.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\todo.dir\main.cpp.obj -c "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\main.cpp"

CMakeFiles/todo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\main.cpp" > CMakeFiles\todo.dir\main.cpp.i

CMakeFiles/todo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\main.cpp" -o CMakeFiles\todo.dir\main.cpp.s

CMakeFiles/todo.dir/todo.cpp.obj: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/todo.cpp.obj: ../todo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/todo.dir/todo.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\todo.dir\todo.cpp.obj -c "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\todo.cpp"

CMakeFiles/todo.dir/todo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/todo.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\todo.cpp" > CMakeFiles\todo.dir\todo.cpp.i

CMakeFiles/todo.dir/todo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/todo.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\todo.cpp" -o CMakeFiles\todo.dir\todo.cpp.s

# Object files for target todo
todo_OBJECTS = \
"CMakeFiles/todo.dir/main.cpp.obj" \
"CMakeFiles/todo.dir/todo.cpp.obj"

# External object files for target todo
todo_EXTERNAL_OBJECTS =

todo.exe: CMakeFiles/todo.dir/main.cpp.obj
todo.exe: CMakeFiles/todo.dir/todo.cpp.obj
todo.exe: CMakeFiles/todo.dir/build.make
todo.exe: CMakeFiles/todo.dir/linklibs.rsp
todo.exe: CMakeFiles/todo.dir/objects1.rsp
todo.exe: CMakeFiles/todo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable todo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\todo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/todo.dir/build: todo.exe

.PHONY : CMakeFiles/todo.dir/build

CMakeFiles/todo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\todo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/todo.dir/clean

CMakeFiles/todo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-" "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-" "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw" "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw" "C:\Users\fran_\Documents\C++ for Complete Beginners\UPF Projects\Final_P3\Linked-List-\cmake-build-debug-mingw\CMakeFiles\todo.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/todo.dir/depend

