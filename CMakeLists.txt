cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/stm32_gcc.cmake)
set (CMAKE_CXX_STANDARD 23)

project(zhele_template CXX C ASM)

# Populate CMSIS using stm32-cmake project
stm32_fetch_cmsis(F1)
find_package(CMSIS COMPONENTS STM32F1 REQUIRED)

# Add zhele
# You can download zhele and use add_subdirectory instead:
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/Zhele)
include(FetchContent)
FetchContent_Declare(Zhele
    GIT_REPOSITORY https://github.com/azhel12/Zhele.git
    GIT_TAG        master
)
FetchContent_MakeAvailable(Zhele)

# Project sources. Add other cpp if needed
set(PROJECT_SOURCES
    src/main.cpp
)

# Add executable (firmware) target
add_executable(zhele_template ${PROJECT_SOURCES})

# Link CMSIS and Zhele. Add other dependences here
target_link_libraries(zhele_template zhele::zhele CMSIS::STM32::F103C8 STM32::NoSys STM32::Nano)
# Recommended options for stm32 dev
target_compile_options(zhele_template PRIVATE -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections)

# Print size
stm32_print_size_of_target(zhele_template)
# Generate bin file
stm32_generate_binary_file(zhele_template)
