cmake_minimum_required(VERSION 3.13)
project(tesseract-test)

set(CMAKE_CXX_STANDARD 17)

# update to your installation, on arch linux simply install the tesseract package
set(tesseract_lib /usr/lib/libtesseract.so)
set(tesseract_include /usr/include)
set(leptonica_lib /usr/lib/liblept.so)
set(leptonica_include /usr/include)

find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    ${tesseract_lib}
    ${leptonica_lib}
    ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME} PUBLIC
    ${tesseract_include}
    ${leptonica_include})

