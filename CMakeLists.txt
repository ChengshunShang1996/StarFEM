cmake_minimum_required(VERSION 3.10)

project(StarFEM VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories( ${STAR_SOURCE}/Constitutive)
include_directories( ${STAR_SOURCE})

## generate variables with the sources
set(STAR_FEM_CORE
    Starfem/Constitutive/mytest.cpp
)

set(STAR_FEM_PYTHON_INTERFACE
    python_interface/add_constitutive_laws_to_python.cpp
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(StarFEMCore SHARED ${STAR_FEM_CORE})

add_subdirectory(external_library/pybind11)
pybind11_add_module(StarFEM ${STAR_FEM_PYTHON_INTERFACE})
#pybind11_add_module(StarFEM Constitutive/mytest.cpp)
target_link_libraries(StarFEM PUBLIC StarFEMCore)
set_target_properties(StarFEM PROPERTIES PREFIX "")

#install(TARGETS StarFEMCore DESTINATION libs )
