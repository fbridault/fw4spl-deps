set(wxWidgets_LIB_DIR ${EXTERNAL_LIBRARIES}/lib)
set(wxWidgets_ROOT_DIR ${EXTERNAL_LIBRARIES})
set(wxWidgets_USE_DEBUG ON)
set(wxWidgets_USE_UNICODE ON)
set(wxWidgets_USE_UNIVERSAL OFF)
set(wxWidgets_USE_STATIC OFF)
set(wxWidgets_EXCLUDE_COMMON_LIBRARIES ON)

add_definitions("-DWXUSINGDLL")
if(WIN32)
    add_definitions("-D__WXMSW__")
else()
    add_definitions("-D__WXGTK__")
endif()
add_definitions("-D__WXDEBUG__")
