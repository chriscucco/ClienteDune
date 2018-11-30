cmake_minimum_required(VERSION 2.8)

project(sdl)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror -Wall -pedantic -pthread -lSDL2_ttf -lSDL2_image -lSDL2 -O0 -ggdb")

add_library(sdldemo
 src/Animation.cpp
 src/Animation.h
 src/Button_CentroDeConstruccion.cpp
 src/Button_CentroDeConstruccion.h
 src/Button_Cosechadora.cpp
 src/Button_Cosechadora.h
 src/Button_CuartelAtreides.cpp
 src/Button_CuartelAtreides.h
 src/Button_CuartelHarkonnen.cpp
 src/Button_CuartelHarkonnen.h
 src/Button_CuartelOrdos.cpp
 src/Button_CuartelOrdos.h
 src/Button_Desviador.cpp
 src/Button_Desviador.h
 src/Button_Devastador.cpp
 src/Button_Devastador.h
 src/Button_FabricaLigera.cpp
 src/Button_FabricaLigera.h
 src/Button_FabricaPesada.cpp
 src/Button_FabricaPesada.h
 src/Button_Fremen.cpp
 src/Button_Fremen.h
 src/Button_InfanteriaLigera.cpp
 src/Button_InfanteriaLigera.h
 src/Button_InfanteriaPesada.cpp
 src/Button_InfanteriaPesada.h
 src/Button_Palacio.cpp
 src/Button_Palacio.h
 src/Button_Raider.cpp
 src/Button_Raider.h
 src/Button_Refineria.cpp
 src/Button_Refineria.h
 src/Button_Sardaukar.cpp
 src/Button_Sardaukar.h
 src/Button_Silo.cpp
 src/Button_Silo.h
 src/Button_SonicTank.cpp
 src/Button_SonicTank.h
 src/Button_Tanque.cpp
 src/Button_Tanque.h
 src/Button_TrampaDeAire.cpp
 src/Button_TrampaDeAire.h
 src/Button_Trike.cpp
 src/Button_Trike.h
 src/Button_Money.cpp
 src/Button_Money.h
 src/Button.cpp
 src/Button.h
 src/CentroDeConstruccion.cpp
 src/CentroDeConstruccion.h
 src/Cima.cpp
 src/Cima.h
 src/Cosechadora.cpp
 src/Cosechadora.h
 src/CuartelAtreides.cpp
 src/CuartelAtreides.h
 src/CuartelHarkonnen.cpp
 src/CuartelHarkonnen.h
 src/CuartelOrdos.cpp
 src/CuartelOrdos.h
 src/Cycle.cpp
 src/Cycle.h
 src/Desviador.cpp
 src/Desviador.h
 src/Devastador.cpp
 src/Devastador.h
 src/Duna.cpp
 src/Duna.h
 src/EspeciaFuerte.cpp
 src/EspeciaFuerte.h
 src/EspeciaSuave.cpp
 src/EspeciaSuave.h
 src/ExplosionFuerte.cpp
 src/ExplosionFuerte.h
 src/ExplosionPersonaje.cpp
 src/ExplosionPersonaje.h
 src/ExplosionTanque.cpp
 src/ExplosionTanque.h
 src/FabricaLigera.cpp
 src/FabricaLigera.h
 src/FabricaPesada.cpp
 src/FabricaPesada.h
 src/Fremen.cpp
 src/Fremen.h
 src/Game.cpp
 src/Game.h
 src/Gusano.cpp
 src/Gusano.h
 src/InfanteriaLigera.cpp
 src/InfanteriaLigera.h
 src/InfanteriaPesada.cpp
 src/InfanteriaPesada.h
 src/Lock.cpp
 src/Lock.h
 src/main.cpp
 src/MasterSurface.cpp
 src/MasterSurface.h
 src/Moveable.cpp
 src/Moveable.h
 src/Palacio.cpp
 src/Palacio.h
 src/Precipicio.cpp
 src/Precipicio.h
 src/Raider.cpp
 src/Raider.h
 src/Refineria.cpp
 src/Refineria.h
 src/Renderer.cpp
 src/Renderer.h
 src/Roca.cpp
 src/Roca.h
 src/Sardaukar.cpp
 src/Sardaukar.h
 src/SDLerror.cpp
 src/SDLerror.h
 src/Silo.cpp
 src/Silo.h
 src/Socket.cpp
 src/Socket.h
 src/SocketParameterError.cpp
 src/SocketParameterError.h
 src/SonicTank.cpp
 src/SonicTank.h
 src/Static.cpp
 src/Static.h
 src/Surface.cpp
 src/Surface.h
 src/Tanque.cpp
 src/Tanque.h
 src/Terrain.cpp
 src/Terrain.h
 src/Text.cpp
 src/Text.h
 src/Texture.cpp
 src/Texture.h
 src/Thread.cpp
 src/Thread.h
 src/Timer.cpp
 src/Timer.h
 src/TrampaDeAire.cpp
 src/TrampaDeAire.h
 src/Trike.cpp
 src/Trike.h
 src/Vehicle.cpp
 src/Vehicle.h
 src/Warrior.cpp
 src/Warrior.h
 src/Window.cpp
 src/Window.h
 src/Editor.cpp
 src/Editor.h
 src/Creator.cpp
 src/Creator.h
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

file(COPY ${CMAKE_SOURCE_DIR}/imgs DESTINATION ./)
file(COPY ${CMAKE_SOURCE_DIR}/terrain DESTINATION ./)
file(COPY ${CMAKE_SOURCE_DIR}/AmaticBold.ttf DESTINATION ./)
target_link_libraries(main SDL2 SDL2_image SDL2_ttf)

