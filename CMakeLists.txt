# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMakeProject5")

# Include sub-projects.
# add_subdirectory ("CMakeProject5")
# add_subdirectory ("src")

# Build googletest
add_subdirectory(
	"${CMAKE_CURRENT_SOURCE_DIR}/googletest"
	"googletest"
)

# Main target
add_executable(
	demo
    src/main.cpp
    src/list.hpp
)

# Test target
add_executable(
	test_list
	test/test_list.cpp
)


target_include_directories(
	test_list PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/CMakeProject5"
)

target_link_libraries(
	test_list PRIVATE
	gtest gtest_main
)

if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

	target_compile_options(
		demo PRIVATE
		/W4
	)
	target_compile_options(
		test_list PRIVATE
		/W4
	)
else ()
	target_compile_options(
		demo PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
	target_compile_options(
		test_list PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
endif()