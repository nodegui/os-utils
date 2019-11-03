cmake_minimum_required(VERSION 3.1)

include("./config/napi.cmake")
include("./config/apple.cmake")
set(PLUGIN_ADDON_NAME "nodegui_os_utils")

project(${PLUGIN_ADDON_NAME})

set(OS_SPECIFIC_SRC "")
if(APPLE)
    set(OS_SPECIFIC_SRC 
        "${PROJECT_SOURCE_DIR}/src/cpp/Dock/dock.mm"
        "${PROJECT_SOURCE_DIR}/src/cpp/AboutPanel/about_panel.mm"
    )
else()
    set(OS_SPECIFIC_SRC 
        "${PROJECT_SOURCE_DIR}/src/cpp/Dock/dock.cpp"
        "${PROJECT_SOURCE_DIR}/src/cpp/AboutPanel/about_panel.cpp"
    )
endif()

add_library(${PLUGIN_ADDON_NAME} SHARED  
    "${CMAKE_JS_SRC}"
    "${PROJECT_SOURCE_DIR}/src/cpp/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/Dock/dock_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/AboutPanel/about_panel_wrap.cpp"
    "${OS_SPECIFIC_SRC}"
) 

AddNapiSupport(${PLUGIN_ADDON_NAME})
if (APPLE) 
    AddAppleSupport(${PLUGIN_ADDON_NAME})
endif()

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