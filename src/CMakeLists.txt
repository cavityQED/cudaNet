cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CUDA_ARCHITECTURES "61")
project(cudaNet LANGUAGES CUDA CXX)

include_directories(/home/mike/externalLibraries/boost)

find_package(CUDA REQUIRED)
if(CUDA_FOUND)
	message("Found Cuda")
endif()

add_subdirectory(math)

set(LINKED_LIBRARIES	math)

set(SOURCE_FILES	cudaNet.cpp)

add_library				(cudaNet	SHARED		${SOURCE_FILES})
set_target_properties	(cudaNet	PROPERTIES	CUDA_SEPARABLE_COMPILATION ON)
target_link_libraries	(cudaNet	PUBLIC		${LINKED_LIBRARIES})

add_executable(netTest	netTest.cpp)
target_link_libraries(netTest	PUBLIC	cudaNet)