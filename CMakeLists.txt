# Usage
# mkdir build; cd build; cmake .. ; make (if only a library needs to be built)
# mkdir build; cd build; cmake .. -DBUILDMAIN=TRUE; make (if library and also the test application is to be built)

cmake_minimum_required ( VERSION 3.10 )

# Verbosity
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_RULE_MESSAGES OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# General flags
set( CMAKE_CXX_STANDARD 11 )
set( CXX_STANDARD_REQUIRED true )
set( CMAKE_CXX_EXTENSIONS off )
set(CMAKE_BUILD_TYPE "RELEASE")

# The name of the project
project(
        FancySquareRoot
        VERSION 0.1
        LANGUAGES CXX
      )
      
# get all sources required to build
file( GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp )

if ( SOURCE_FILES )
    # The name of the library that should be built, and the sources necessary
    add_library(FancySquareRoot STATIC ${SOURCE_FILES})                   
    
    # The headers etc required to successfully compile the sources in this library       
    target_include_directories(
                                FancySquareRoot
                                PUBLIC
                                $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc> # Public Header
                              )

endif( SOURCE_FILES )

if ( BUILDMAIN )

# Tell CMake that we want to create an executable "TestFanySquareRoot" to be composed from main.cpp
ADD_EXECUTABLE( 
                TestFancySquareRoot 
                ${PROJECT_SOURCE_DIR}/test/main.cpp 
              )

# Tell CMake that the executable requires the headers in inc/ to compile successfully.
INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/inc )

# Tell CMake that the executable depends on the library libFancySquareRoot.
TARGET_LINK_LIBRARIES (
                         TestFancySquareRoot   
                         FancySquareRoot
                      )
                      
endif()
