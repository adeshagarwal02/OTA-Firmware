cmake_minimum_required(VERSION 3.10)
project(OTA_Firmware)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Gather all .cpp files from src directory
file(GLOB SRC_FILES src/*.cpp)

# Create the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Include header directory
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/header
)

# Find and link libcurl
find_package(CURL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE CURL::libcurl)

# Find and link OpenSSL (for SHA256)
find_package(OpenSSL REQUIRED)
if(OpenSSL_FOUND)
    message(STATUS "Found OpenSSL version: ${OPENSSL_VERSION}")
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::Crypto)
else()
    message(FATAL_ERROR "OpenSSL not found!")
endif()

# Optional: Print out what files are being compiled
message(STATUS "Source files: ${SRC_FILES}")

