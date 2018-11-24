cmake_minimum_required(VERSION 2.8)

project(sdl)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror -Wall -pedantic -pthread -lSDL2_ttf -lSDL2_image -lSDL2 -O0 -ggdb")

add_library(sdldemo
    src/Renderer.cpp
    src/SDLerror.cpp
    src/Surface.cpp
    src/Texture.cpp
    src/Window.cpp
    src/main.cpp
    src/Animation.cpp
    src/Cycle.cpp
    src/Cycle.h
    src/Gusano.cpp
    src/CentroDeConstruccion.cpp
    src/CuartelAtreides.cpp
    src/CuartelHarkonnen.cpp
    src/CuartelOrdos.cpp
    src/FabricaLigera.cpp
    src/FabricaPesada.cpp
    src/Palacio.cpp
    src/Refineria.cpp
    src/Silo.cpp
    src/TrampaDeAire.cpp
    src/Lock.cpp
    src/Lock.h
    src/Moveable.cpp
    src/Game.cpp
    src/Cosechadora.cpp
    src/Vehicle.cpp
    src/Trike.cpp
    src/Tanque.cpp
    src/SonicTank.cpp
    src/Raider.cpp
    src/Devastador.cpp
    src/Desviador.cpp
    src/Duna.cpp
    src/Cima.cpp
    src/Warrior.cpp
    src/Fremen.cpp
    src/InfanteriaLigera.cpp
    src/InfanteriaPesada.cpp
    src/Sardaukar.cpp
    src/ExplosionTanque.cpp
    src/ExplosionPersonaje.cpp
    src/ExplosionFuerte.cpp
    src/EspeciaSuave.cpp
    src/EspeciaFuerte.cpp
    src/Precipicio.cpp
    src/Roca.cpp    
    src/Socket.cpp
    src/Socket.h
    src/SocketParameterError.cpp
    src/SocketParameterError.h
    src/Static.cpp
    src/Thread.cpp
    src/Thread.h
    src/Button_CentroDeConstruccion.cpp
    src/Button_Cosechadora.cpp
    src/Button_CuartelAtreides.cpp
    src/Button_CuartelHarkonnen.cpp
    src/Button_CuartelOrdos.cpp
    src/Button_Desviador.cpp
    src/Button_Devastador.cpp
    src/Button_FabricaLigera.cpp
    src/Button_FabricaPesada.cpp
    src/Button_Fremen.cpp
    src/Button_InfanteriaLigera.cpp
    src/Button_InfanteriaPesada.cpp
    src/Button_Palacio.cpp
    src/Button_Refineria.cpp
    src/Button_Raider.cpp
    src/Button_Sardaukar.cpp
    src/Button_Silo.cpp
    src/Button_Tanque.cpp
    src/Button_SonicTank.cpp
    src/Button_TrampaDeAire.cpp
    src/Button_Trike.cpp
    src/Timer.cpp
    src/AmaticBold.ttf
)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})

add_executable (main
  src/main.cpp  
)


target_link_libraries(main SDL2 SDL2_image SDL2_ttf)

