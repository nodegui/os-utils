cmake_minimum_required(VERSION 3.1)

include("./config/napi.cmake")
set(PLUGIN_ADDON_NAME "nodegui_plugin_macos_utils")

project(${PLUGIN_ADDON_NAME})

add_library(${PLUGIN_ADDON_NAME} SHARED  
    "${CMAKE_JS_SRC}"
    "${PROJECT_SOURCE_DIR}/src/cpp/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/Dock/dock_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/Dock/dock.hpp"
) 

AddNapiSupport(${PLUGIN_ADDON_NAME})

target_include_directories(${PLUGIN_ADDON_NAME} PRIVATE 
    "${PROJECT_SOURCE_DIR}"
    "${CMAKE_JS_INC}" 
)

target_link_libraries(${PLUGIN_ADDON_NAME} PRIVATE
    "${CMAKE_JS_LIB}"
)

target_compile_features(${PLUGIN_ADDON_NAME} PRIVATE
    cxx_inheriting_constructors
    cxx_lambdas
    cxx_auto_type
    cxx_variadic_templates
    cxx_variable_templates
)