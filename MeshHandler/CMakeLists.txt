set(SRC_FILES MeshHandler.C Vector.C Vector2D.C Field.C)
add_library(MeshHandler ${SRC_FILES})
include_directories(${CMAKE_SOURCE_DIR}/SetupFile)
include_directories(${CMAKE_SOURCE_DIR})
