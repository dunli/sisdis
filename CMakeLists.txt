cmake_minimum_required(VERSION 3.5)
project(http_server LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(http_server main.cpp httpserver.cpp httpserver.h utils.cpp utils.h pruebastub.cpp pruebastub.h mpi_manager.h mpi_manager.cpp remotefile_stub.h remotefile_stub.cpp)
LINK_DIRECTORIES(/usr/lib/x86_64-linux-gnu/)
target_link_libraries(http_server mysqlcppconn mysqlclient pthread z m rt atomic dl)


set(PROJECT_PRUEBACLASE rpc_pruebaclase)
set(PROJECT_REMOTEFILE rpc_remotefile)
set(PROJECT_HTTPSERVER http_server)

project(${PROJECT_PRUEBACLASE})
add_executable(${PROJECT_PRUEBACLASE} "main_slave.cpp" "pruebaclase.cpp" "pruebaclase.h" "pruebaimpl.cpp"
                                        "pruebaimpl.h" "mpi_manager.h" "mpi_manager.cpp" "pruebastub.h")

project(${PROJECT_REMOTEFILE})
add_executable(${PROJECT_REMOTEFILE} "main_remotefile.cpp" "mpi_manager.h" "mpi_manager.cpp" "remotefile_stub.h"
                                        "remotefile.h" "remotefile.cpp" "remotefile_imp.cpp" "remotefile_imp.h")

find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})
target_link_libraries(${PROJECT_HTTPSERVER} ${MPI_LIBRARIES})
target_link_libraries(${PROJECT_PRUEBACLASE} ${MPI_LIBRARIES})
target_link_libraries(${PROJECT_REMOTEFILE} ${MPI_LIBRARIES})
