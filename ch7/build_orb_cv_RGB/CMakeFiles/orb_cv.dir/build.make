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
CMAKE_SOURCE_DIR = /home/leo/slambook2_learning/ch7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leo/slambook2_learning/ch7/build_orb_cv_RGB

# Include any dependencies generated for this target.
include CMakeFiles/orb_cv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/orb_cv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/orb_cv.dir/flags.make

CMakeFiles/orb_cv.dir/orb_cv.cpp.o: CMakeFiles/orb_cv.dir/flags.make
CMakeFiles/orb_cv.dir/orb_cv.cpp.o: ../orb_cv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/slambook2_learning/ch7/build_orb_cv_RGB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/orb_cv.dir/orb_cv.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/orb_cv.dir/orb_cv.cpp.o -c /home/leo/slambook2_learning/ch7/orb_cv.cpp

CMakeFiles/orb_cv.dir/orb_cv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/orb_cv.dir/orb_cv.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/slambook2_learning/ch7/orb_cv.cpp > CMakeFiles/orb_cv.dir/orb_cv.cpp.i

CMakeFiles/orb_cv.dir/orb_cv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/orb_cv.dir/orb_cv.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/slambook2_learning/ch7/orb_cv.cpp -o CMakeFiles/orb_cv.dir/orb_cv.cpp.s

# Object files for target orb_cv
orb_cv_OBJECTS = \
"CMakeFiles/orb_cv.dir/orb_cv.cpp.o"

# External object files for target orb_cv
orb_cv_EXTERNAL_OBJECTS =

orb_cv: CMakeFiles/orb_cv.dir/orb_cv.cpp.o
orb_cv: CMakeFiles/orb_cv.dir/build.make
orb_cv: /usr/local/lib/libopencv_dnn.so.3.4.15
orb_cv: /usr/local/lib/libopencv_highgui.so.3.4.15
orb_cv: /usr/local/lib/libopencv_ml.so.3.4.15
orb_cv: /usr/local/lib/libopencv_objdetect.so.3.4.15
orb_cv: /usr/local/lib/libopencv_shape.so.3.4.15
orb_cv: /usr/local/lib/libopencv_stitching.so.3.4.15
orb_cv: /usr/local/lib/libopencv_superres.so.3.4.15
orb_cv: /usr/local/lib/libopencv_videostab.so.3.4.15
orb_cv: /usr/local/lib/libopencv_calib3d.so.3.4.15
orb_cv: /usr/local/lib/libopencv_features2d.so.3.4.15
orb_cv: /usr/local/lib/libopencv_flann.so.3.4.15
orb_cv: /usr/local/lib/libopencv_photo.so.3.4.15
orb_cv: /usr/local/lib/libopencv_video.so.3.4.15
orb_cv: /usr/local/lib/libopencv_videoio.so.3.4.15
orb_cv: /usr/local/lib/libopencv_imgcodecs.so.3.4.15
orb_cv: /usr/local/lib/libopencv_imgproc.so.3.4.15
orb_cv: /usr/local/lib/libopencv_core.so.3.4.15
orb_cv: CMakeFiles/orb_cv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leo/slambook2_learning/ch7/build_orb_cv_RGB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable orb_cv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/orb_cv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/orb_cv.dir/build: orb_cv

.PHONY : CMakeFiles/orb_cv.dir/build

CMakeFiles/orb_cv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/orb_cv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/orb_cv.dir/clean

CMakeFiles/orb_cv.dir/depend:
	cd /home/leo/slambook2_learning/ch7/build_orb_cv_RGB && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leo/slambook2_learning/ch7 /home/leo/slambook2_learning/ch7 /home/leo/slambook2_learning/ch7/build_orb_cv_RGB /home/leo/slambook2_learning/ch7/build_orb_cv_RGB /home/leo/slambook2_learning/ch7/build_orb_cv_RGB/CMakeFiles/orb_cv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/orb_cv.dir/depend

