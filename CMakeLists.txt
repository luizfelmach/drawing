# this is the build file for project 
# it is autogenerated by the xmake build system.
# do not edit by hand.

# project
cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0091 NEW)
project(brownian_motion LANGUAGES CXX C)

# target
add_executable(brownian_motion "")
set_target_properties(brownian_motion PROPERTIES OUTPUT_NAME "brownian_motion")
set_target_properties(brownian_motion PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/linux/x86_64/release")
add_dependencies(brownian_motion library)
target_include_directories(brownian_motion PRIVATE
    include
)
target_compile_options(brownian_motion PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-m64>
    $<$<COMPILE_LANGUAGE:CXX>:-m64>
)
if(MSVC)
    set_property(TARGET brownian_motion PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
target_link_libraries(brownian_motion PRIVATE
    xd
    glad
    glfw3
    rt
    m
    dl
    X11
    pthread
    library
)
target_link_directories(brownian_motion PRIVATE
    lib
    build/linux/x86_64/release
)
target_link_options(brownian_motion PRIVATE
    -m64
)
target_sources(brownian_motion PRIVATE
    src/brownian_motion.cpp
)

# target
add_library(library STATIC "")
set_target_properties(library PROPERTIES OUTPUT_NAME "library")
set_target_properties(library PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/linux/x86_64/release")
target_include_directories(library PRIVATE
    include
)
target_compile_options(library PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-m64>
    $<$<COMPILE_LANGUAGE:CXX>:-m64>
)
if(MSVC)
    set_property(TARGET library PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
target_sources(library PRIVATE
    lib/object.cpp
    lib/particle.cpp
    lib/vector3d.cpp
)

# target
add_executable(newtons_cannon "")
set_target_properties(newtons_cannon PROPERTIES OUTPUT_NAME "newtons_cannon")
set_target_properties(newtons_cannon PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/linux/x86_64/release")
add_dependencies(newtons_cannon library)
target_include_directories(newtons_cannon PRIVATE
    include
)
target_compile_options(newtons_cannon PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-m64>
    $<$<COMPILE_LANGUAGE:CXX>:-m64>
)
if(MSVC)
    set_property(TARGET newtons_cannon PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
target_link_libraries(newtons_cannon PRIVATE
    xd
    glad
    glfw3
    rt
    m
    dl
    X11
    pthread
    library
)
target_link_directories(newtons_cannon PRIVATE
    lib
    build/linux/x86_64/release
)
target_link_options(newtons_cannon PRIVATE
    -m64
)
target_sources(newtons_cannon PRIVATE
    src/newtons_cannon.cpp
)

# target
add_executable(particles "")
set_target_properties(particles PROPERTIES OUTPUT_NAME "particles")
set_target_properties(particles PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/linux/x86_64/release")
add_dependencies(particles library)
target_include_directories(particles PRIVATE
    include
)
target_compile_options(particles PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-m64>
    $<$<COMPILE_LANGUAGE:CXX>:-m64>
)
if(MSVC)
    set_property(TARGET particles PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
target_link_libraries(particles PRIVATE
    xd
    glad
    glfw3
    rt
    m
    dl
    X11
    pthread
    library
)
target_link_directories(particles PRIVATE
    lib
    build/linux/x86_64/release
)
target_link_options(particles PRIVATE
    -m64
)
target_sources(particles PRIVATE
    src/particles.cpp
)

