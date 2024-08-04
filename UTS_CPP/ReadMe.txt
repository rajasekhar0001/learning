-> There are two ways to setup googletest
1) Using command to install and setup googletest -> not tried
2) By pulling code from github using commands -> tried

Follow belo video link for googletest framework configuration:
https://www.youtube.com/watch?v=6dqFqh3UbPY

--> git clone git_link_google_test -b branch/tag
commands:
   cd googletest
   cmake -Bbuild 
   cd ..
   mkdir build

   cmake --build build
   cmake --build build --target install

For CMakefile.txt outside of googletest, copy from path and change accordingly if needed

cd Project

mkdir build
cd build

To create the build for googletest along with sorce code and tests
--> cmake ..  (To create the build based on CMakefiles.txt in the previous directory)
    generates all file in build directory

To compile source code and tests which genartes the executable
--> make   (To compile the source code along with tests)

To execute all the tests (to run ALL TESTS)
--> ctest    -> shows brief like all passed (if any failed only failed count)
   (need to check log file to see detailed report)
   path: build/Testing/Temporary

--> ctest -V (verbose level logs) -> shows the detailed test report in command line as well





