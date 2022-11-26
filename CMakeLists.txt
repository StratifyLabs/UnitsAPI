cmake_minimum_required (VERSION 3.12)

project(UnitsAPI CXX)
include(CTest)

add_subdirectory(library)

option(UNITS_API_IS_DOUBLE "Use type double for calculations" ${CMSDK_IS_LINK})

option(UNITS_API_IS_TEST "Enable test builds for UnitsAPI" OFF)
if(UNITS_API_IS_TEST)
	add_subdirectory(tests)
endif()

