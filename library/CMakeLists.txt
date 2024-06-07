# These are the depedencies
set(LIBRARIES VarAPI PrinterAPI)

api2_add_library(
	NAME UnitsAPI
	DEPENDENCIES ${LIBRARIES}
	TARGETS TARGET_LIST)

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


foreach(TARGET ${TARGET_LIST})
  add_type_option(${TARGET})
  add_type_option(${TARGET})
endforeach()


