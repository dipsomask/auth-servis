cmake_minimum_required(VERSION 3.5)
project(test-db-servis CXX)


set(CMAKE_CXX_STANDARD 17)



set(SRC_FILES
    main.cc
    controllers/AuthController.cc
    controllers/auth.cc
    controllers/ServisConfig.cc
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
target_link_libraries(${PROJECT_NAME} PRIVATE 
    Drogon::Drogon 
    libpqxx::pqxx
    ${PostgreSQL_LIBRARIES}
)


set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_DEBIAN_PACKAGE_MAINTAINER DM)
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_HOMEPAGE_URL https://github.com/dipsomask/test-db-servis.git)
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27), gcc, g++, cmake, pkg-config, libpqxx-dev, libjsoncpp-dev, uuid-dev, zlib1g-dev, openssl, libssl-dev, libmariadb3, libyaml-cpp0.8, postgresql-all")
install(TARGETS ${PROJECT_NAME} DESTINATION /usr/bin)

include(CPack)
