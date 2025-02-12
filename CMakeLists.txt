cmake_minimum_required(VERSION 3.5)
project(test-db-servis CXX)


set(CMAKE_CXX_STANDARD 17)


# -fsanitize=address Это флаг компилятора, который включает AddressSanitizer.
# AddressSanitizer — это инструмент для обнаружения ошибок памяти, таких как
# переполнение буфера, использование после освобождения и т. д.

#-fsanitize=undefined Это флаг компилятора, который включает UndefinedBehaviorSanitizer.
# UndefinedBehaviorSanitizer — это инструмент для обнаружения неопределенного поведения в
# программе, такого как деление на ноль, переполнение знаковых целых чисел и т. д.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined")


set(SRC_FILES
    main.cc
    controllers/AuthController.cc
    controllers/auth.cc
)


aux_source_directory(controllers CTL_SRC_DIR)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/controllers
)


add_executable(${PROJECT_NAME} ${SRC_FILES} ${CTL_SRC_DIR})


add_subdirectory(External/jwt)


# find jwt
target_include_directories(${PROJECT_NAME} PUBLIC External/jwt/include)
target_link_libraries(${PROJECT_NAME} PUBLIC jwt-cpp::jwt-cpp)


# Find Drogon
find_package(Drogon CONFIG REQUIRED)

# Find PostgreSQL
find_package(PostgreSQL REQUIRED)

# Specify the path to libpqxx
set(PQXX_DIR "/usr/local/lib/cmake/libpqxx")
find_package(libpqxx REQUIRED)


# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon libpqxx::pqxx ${PostgreSQL_LIBRARIES})

