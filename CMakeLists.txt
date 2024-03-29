cmake_minimum_required(VERSION 3.7...3.23)
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# ---- Project ----

project(metaf_example LANGUAGES CXX)

# ---- Fetch CPM ----

set(CPM_DOWNLOAD_VERSION 0.27.2) 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
  message(STATUS "Downloading CPM.cmake v${CPM_DOWNLOAD_VERSION}")
  file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for details and examples

CPMAddPackage(
  NAME metaf
  GIT_REPOSITORY https://gitlab.com/sthagen/metaf.git
  VERSION 5.6.2                                 
  # 5.6.2 is not released yet by Nick Naumenko (upstream), so use the latest approved commit
  GIT_TAG de0268e41b0097eb782e7ae6cf14fc04e4525d5d 
)

if(metaf_ADDED)
  add_library(metaf INTERFACE)
  target_include_directories(metaf INTERFACE ${metaf_SOURCE_DIR}/include/)
  message("Added ${metaf_SOURCE_DIR}/include/ as include")
endif()

# ---- Create executable ----

add_executable(metaf_example main.cpp)
set_target_properties(metaf_example PROPERTIES CXX_STANDARD 17)

target_link_libraries(metaf_example metaf)
