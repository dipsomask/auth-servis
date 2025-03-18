cmake_minimum_required(VERSION 3.5)
project(exmpl-desctop-with-auth VERSION 0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined")


find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
qt_standard_project_setup()


set(UI_FILES
    mainwindow/mainwindow.ui
    signupwindow/signindialog.ui
    signinwindow/signupdialog.ui
)

# Генерируем код из .ui файлов
qt_wrap_ui(UI_GENERATED ${UI_FILES})



set(cpr_DIR "/usr/local/lib/cmake/cpr")
find_package(cpr REQUIRED)


set(SRC_FILES
    main.cpp
    mainwindow/mainwindow.cpp
    mainwindow/mainwindow.h
    mainwindow/mainwindow.ui
    signupwindow/signupdialog.cpp
    signupwindow/signupdialog.h
    signupwindow/signupdialog.ui
    signinwindow/signindialog.cpp
    signinwindow/signindialog.h
    signinwindow/signindialog.ui
    utils/Config.cpp
    utils/Config.h
    utils/token.cpp
    utils/token.h
)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/signupwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/signinwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

add_executable(${PROJECT_NAME}
    ${UI_GENERATED}
    ${SRC_FILES}
)


add_subdirectory(External/jwt)

# find jwt
target_include_directories(${PROJECT_NAME} PUBLIC External/jwt/include)
target_link_libraries(${PROJECT_NAME} PUBLIC jwt-cpp::jwt-cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    cpr::cpr
    Qt6::Core
    Qt6::Widgets 
    nlohmann_json::nlohmann_json
)
