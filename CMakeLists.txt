cmake_minimum_required(VERSION 3.10)
project(TiendaEcologica)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        main.cpp
        Producto.cpp
        Cliente.cpp
        Venta.cpp
        Tienda.cpp
)

set(HEADERS
        Producto.h
        Cliente.h
        Venta.h
        Tienda.h
)

add_executable(TiendaEcologica ${SOURCES} ${HEADERS})

if(MSVC)
    target_compile_options(TiendaEcologica PRIVATE /W4)
else()
    target_compile_options(TiendaEcologica PRIVATE -Wall -Wextra -pedantic)
endif()