cmake_minimum_required(VERSION 3.13)
set(PICO_BOARD pico_w)
include(pico_sdk_import.cmake)

project(ble_client C CXX ASM)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
pico_sdk_init()

 
add_executable(${PROJECT_NAME}
main.c
)
add_subdirectory(bluetooth)
target_link_libraries(${PROJECT_NAME}
pico_stdlib
ble_tools
hardware_adc
    )
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    )

target_compile_definitions(${PROJECT_NAME} PRIVATE
    RUNNING_AS_CLIENT=1
)

pico_add_extra_outputs(${PROJECT_NAME})
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
