
api2_add_library(
  NAME UnitsAPI
  DEPENDENCIES VarAPI PrinterAPI
  TARGETS TARGET_LIST)

foreach(target ${TARGET_LIST})
  if(UNITS_API_IS_DOUBLE)
    set(USE_DOUBLE 1)
  else()
    set(USE_DOUBLE 0)
  endif()

  target_compile_definitions(${target}
    PUBLIC
    UNITS_API_IS_DOUBLE=${USE_DOUBLE})
endforeach()



