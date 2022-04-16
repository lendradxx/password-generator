# configuration cmake and compiler
cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)

# project information
project(
    password-generator 
    VERSION 0.0.1 
    LANGUAGES C
    HOMEPAGE_URL "https://github.com/lendradxx/password-generator.git"
    DESCRIPTION "Tool for create a random password"
)

# project configuration
set(PROJECT_HP )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_PATH ${PROJECT_SOURCE_DIR}/build)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# project compiling
add_executable(password-generator ${SRC_DIR}/main.c ${CMAKE_CURRENT_BINARY_DIR}/res/res.c)
add_dependencies(password-generator resources)
add_definitions(${GTK_CFLAGS_OTHER})
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
target_link_libraries(password-generator ${GTK_LIBRARIES})

# Install command
install(
    TARGETS password-generator
    RUNTIME
        DESTINATION $ENV{HOME}/.local/bin
)

# Uninstall command
add_custom_target("uninstall" COMMENT "Uninstall installed files")
add_custom_command(
    TARGET "uninstall"
    POST_BUILD
    COMMENT "Uninstalling files..."
    COMMAND xargs rm -f < install_manifest.txt || echo "Nothing in install_manifest.txt to be uninstalled"
)

# Embedding the resource files
message(STATUS "Embedding resource files...")
make_directory(${CMAKE_CURRENT_BINARY_DIR}/res)
add_custom_command(
    OUTPUT res/res.c
    WORKING_DIRECTORY ${SRC_DIR}
    COMMAND ${GLIB_COMPILE_RESOURCES}
    ARGS
        --target=${CMAKE_CURRENT_BINARY_DIR}/res/res.c
        --generate-source ${SRC_DIR}/res.xml
    VERBATIM
    MAIN_DEPENDENCY ${SRC_DIR}/res.xml
    DEPENDS
        ${SRC_DIR}/ui/app.ui
)

add_custom_target(
    resources
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/res/res.c
)