cmake_minimum_required (VERSION 2.6)
project (PaxAtlas)

set(LIBRARY_NAME PaxAtlasLibrary)

include_directories(opt/mikan/include)
add_subdirectory(Source)
add_subdirectory(opt/mikan)

