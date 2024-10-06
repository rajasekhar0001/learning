=============================================================================Boost.Asio INstallation=======================================
==> Install Boost.Asio library beacuse someip needs it.
linkL: https://www.boost.org/users/history/version_1_61_0.html

# To unzip the file from .gz format
gunzip boost_1_61_0.tar.gz;
# To untar a file
tar xvf boost_1_61_0.tar;

cd boost_1_61_0;
sudo apt-get update;
sudo apt-get install build-essential g++ python-dev autotools-dev libicu-dev libbz2-dev libboost-all-dev;

./bootstrap.sh --prefix=/usr/
./b2

==> To develop code and to work with client and server programs
refer page: https://github.com/COVESA/vsomeip/wiki/vsomeip-in-10-minutes

[[[[[[[[[[[[[[[[  Follow above URL  or below set of statements]]]]]]]]]]]]]]]]

Commands to use to run client or server:

cd vsomeip
cmake -Bbuild -DCMAKE_INSTALL_PREFIX=../install_folder -DENABLE_SIGNAL_HANDLING=1 .
cmake --build build --target install

#  The ENABLE_SIGNAL_HANDLING parameter ensures that you can kill your vsomeip application without any problems 
# (otherwise it might be that the shared memory segment /dev/shm/vsomeip is not be correctly removed when you stop the application with Ctrl-C).


mkdir test-example
cd test-example

create CMakeLists.txt
------------------------------------------------------------------Basic CMakeLists.txt------------------------
cmake_minimum_required (VERSION 3.13)

set (CMAKE_CXX_FLAGS "-g -std=c++0x")

find_package (vsomeip3 3.4.10 REQUIRED)
find_package( Boost 1.55 COMPONENTS system thread log REQUIRED )

include_directories (
    ${Boost_INCLUDE_DIR}
    ${VSOMEIP_INCLUDE_DIRS}
)

add_executable(service-example ../src/service-example.cpp)
target_link_libraries(service-example vsomeip3 ${Boost_LIBRARIES})

add_executable(client-example ../src/client-example.cpp)
target_link_libraries(client-example vsomeip3 ${Boost_LIBRARIES})
-----------------------------------------------------------------------------------------------------------------

# Create build directory, run CMake and build. Then start it (service-example)

cmake -Bbuild -DCMAKE_INSTALL_PREFIX=../../install_folder -DCMAKE_PREFIX_PATH=../../install_folder .
cmake --build build/

# Run below commands in different terminals
LD_LIBRARY_PATH=../../install_folder/lib/:$PWD/build/ ./build/service-example

LD_LIBRARY_PATH=../../install_folder/lib/:$PWD/build/ ./build/client-example

