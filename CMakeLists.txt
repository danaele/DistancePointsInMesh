cmake_minimum_required(VERSION 2.8)
 
PROJECT(DistanceNeighborInMesh)
option(BUILD_TESTING "Build the testing tree" OFF)


# Find SlicerExecutionModel
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})

#Find VTK 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})


set(DistanceNeighborInMesh_SOURCE DistanceNeighborInMesh.cxx)

set(DistanceNeighborInMesh_HEADER DistanceNeighborInMesh.h)

SEMMacroBuildCLI(
  NAME DistanceNeighborInMesh
  EXECUTABLE_ONLY
  ADDITIONAL_SRCS ${DistanceNeighborInMesh_SOURCE}
  TARGET_LIBRARIES ${VTK_LIBRARIES}
  )

if(BUILD_TESTING)
 include(CTest)
 add_subdirectory(Testing)
endif()

