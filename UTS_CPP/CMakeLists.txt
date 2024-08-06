cmake_minimum_required(VERSION 3.10)

# Project name
project(UTS_CPP)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCE_FILES
	    src/main.cpp
	        # Remove src/some_other_file.cpp if it doesn't exist
		)

	# Add GoogleTest
	add_subdirectory(googletest)
	include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

	# Add the executable for your project
	add_executable(UTS_CPP ${SOURCE_FILES})

	# Link GoogleTest to your project
	target_link_libraries(UTS_CPP gtest gtest_main)

	# Add test files
	set(TEST_FILES
		    tests/test_main.cpp
		        # Remove tests/test_some_other_file.cpp if it doesn't exist
			)

		# Add executable for tests
		add_executable(runTests ${TEST_FILES})

		# Link GoogleTest to test executable
		target_link_libraries(runTests gtest gtest_main)

		# Enable testing
		enable_testing()

		# Discover tests in the runTests executable
		add_test(NAME runTests COMMAND runTests)

