cmake_minimum_required(VERSION 3.23)

project(spear_graphic_interface
	VERSION 0.0.1 
    LANGUAGES C CXX
    HOMEPAGE_URL "https://github.com/IntSoftware/spear_graphic_interface"
)

add_library(spear_graphic_interface INTERFACE)

target_compile_features(spear_graphic_interface INTERFACE
    cxx_std_17
)

# public headers
target_include_directories(spear_graphic_interface INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# namespaced alias
add_library(spear::graphic_interface ALIAS spear_graphic_interface)
