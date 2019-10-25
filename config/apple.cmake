# Apple stuff

function(AddAppleSupport addonName)
    find_library(
        APPKIT_LIBRARY
        AppKit
    )

    find_path(
        APPKIT_INCLUDE_DIR
        AppKit/AppKit.h
    )

    target_include_directories(${addonName} PRIVATE 
        "${APPKIT_INCLUDE_DIR}"
    ) 
    target_link_libraries(${PLUGIN_ADDON_NAME} PRIVATE
        "${APPKIT_LIBRARY}"
    )
endfunction(AddAppleSupport addonName)

 