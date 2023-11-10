cmake_minimum_required(VERSION 3.23)
project(oop_trabalho)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop_trabalho main.cpp Zona.cpp Zona.h Propriedade.cpp Propriedade.h Sensor.cpp Sensor.h Regra.cpp Regra.h Processador.cpp Processador.h)
