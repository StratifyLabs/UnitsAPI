
if(NOT DEFINED API_IS_SDK)
	include(API)
	sos_sdk_include_target(UnitsAPI "${API_CONFIG_LIST}")
endif()
