# These are the depedencies
set(LIBRARIES VarAPI PrinterAPI)

api_add_api_library(UnitsAPI "${LIBRARIES}")

function(add_type_option TARGET)

  if(UNITS_API_IS_DOUBLE)
    set(USE_DOUBLE 1)
  else()
    set(USE_DOUBLE 0)
  endif()

  target_compile_definitions(${TARGET}
    PUBLIC
    -DUNITS_API_IS_DOUBLE=${USE_DOUBLE}
    )
endfunction()

add_type_option(UnitsAPI_release_${SOS_ARCH})
add_type_option(UnitsAPI_debug_${SOS_ARCH})

foreach(ARCH ${SOS_ARCH_LIST})
  add_type_option(UnitsAPI_release_${ARCH})
  add_type_option(UnitsAPI_debug_${ARCH})
endforeach()


