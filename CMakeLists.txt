cmake_minimum_required(VERSION 3.23)

project(spear-graphic-interface
	VERSION 0.0.1 
    LANGUAGES C CXX
    HOMEPAGE_URL "https://github.com/IntSoftware/spear-graphic-interface"
)

add_library(spear-graphic-interface INTERFACE)

target_compile_features(spear-graphic-interface INTERFACE
    cxx_std_17
)

# public headers
target_include_directories(spear-graphic-interface INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# namespaced alias
add_library(spear::graphic-interface ALIAS spear-graphic-interface)
