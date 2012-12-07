#Minimum version required for CMake
cmake_minimum_required (VERSION 2.6)
 
#Name of the project
project (carcasa_MDM31)
 
#Compile in Debug Mode. Allows to make debug.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb")
SET(CMAKE_BUILD_TYPE "debugfull" )
 
#Set a variable with the directory path.
SET(OOM_TRUNK_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
#Set a variable with the path of the application.
SET(EXECUTABLE_OUTPUT_PATH ${OOM_TRUNK_DIR}/bin)
 
#In Linux and Mac OS/X the Path is /usr/include/ooml
INCLUDE_DIRECTORIES("/usr/include/ooml")
 
#Set a variable with the name of the cpp source files of your application
SET(CARCASA_FILES carcasa_MDM31.cpp)

#Set a variable with the name of your application
SET(CARCASA_NAME carcasa_MDM31)
 
#Create and link the executable
ADD_EXECUTABLE(${CARCASA_NAME} ${CARCASA_FILES})

TARGET_LINK_LIBRARIES(${CARCASA_NAME} OOMLCore OOMLComponents OOMLParts)

