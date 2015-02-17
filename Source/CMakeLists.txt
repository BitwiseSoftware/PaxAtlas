set(SOURCE
	${SOURCE}
	${CMAKE_CURRENT_SOURCE_DIR}/FrameRate.cc
	${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp.cc
	${CMAKE_CURRENT_SOURCE_DIR}/Map.cc
)

set(EXECUTABLE_NAME PaxAtlas)

add_subdirectory(Army)
add_subdirectory(Country)
add_subdirectory(Mikan)
add_subdirectory(Province)

add_executable(${EXECUTABLE_NAME} Main.cc)

include_directories(/usr/include/SFML/)

add_library(
 	${LIBRARY_NAME}
	SHARED
	${SOURCE}
)

target_link_libraries(
	${LIBRARY_NAME}
	sfml-graphics
	sfml-window
	sfml-system
)

target_link_libraries(
	${EXECUTABLE_NAME}
	${LIBRARY_NAME}
	sfml-graphics
	sfml-window
	sfml-system
)

ADD_DEFINITIONS(
	-std=c++11
)

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_EXE_LINKER_FLAGS "-pthread")
