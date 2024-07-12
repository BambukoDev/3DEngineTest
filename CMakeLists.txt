macro(c_b arg state)
    set(${arg} ${state} CACHE BOOL "" FORCE)
endmacro()

cmake_minimum_required(VERSION 3.14)

cmake_policy(SET CMP0048 NEW)

project(TestEngine VERSION 0.0.1 LANGUAGES CXX C)

# setup C++17
set(CMAKE_CXX_STANDARD_DEFAULT 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
set(CMAKE_CXX_EXTENSIONS 0)

c_b(BUILD_SHARED_LIBS 0)

set(TestEngine_SDL_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/submodules/SDL/include")
c_b(SDL2_DISABLE_INSTALL 1)
c_b(SDL2_DISABLE_UNINSTALL 1)
c_b(SDL_SHARED 0)
add_subdirectory(submodules/SDL)

add_library(imgui 
    submodules/imgui/imgui.cpp
    submodules/imgui/imgui_draw.cpp
    submodules/imgui/imgui_tables.cpp
    submodules/imgui/imgui_widgets.cpp
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(
    TestEngine
    source/main.cpp
)
target_compile_features(TestEngine INTERFACE cxx_std_17)
target_link_libraries(TestEngine SDL3::SDL3-static)
target_include_directories(
    TestEngine
    PUBLIC submodules/imgui
    PUBLIC ${QWP_SDL_HEADER_DIR}
    PUBLIC submodules/bgfx/src
)
