cmake_minimum_required(VERSION 3.16)
project(src/TrabalhoBaseDefenseEXE LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(TrabalhoBaseDefenseEXE src/TrabalhoBaseDefense/TrabalhoBaseDefense.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Heroi.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Heroi.hpp
        src/TrabalhoBaseDefense/Util/VectorUtils.cpp
        src/TrabalhoBaseDefense/Util/VectorUtils.hpp
        src/TrabalhoBaseDefense/Util/DrawUtils.cpp
        src/TrabalhoBaseDefense/Util/DrawUtils.hpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Projetil.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Projetil.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Inimigo.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Inimigo.h
        src/TrabalhoBaseDefense/Game/Variables/Variables.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Base.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Base.hpp
        src/TrabalhoBaseDefense/Game/GameEntities/GameEntity.h
        src/TrabalhoBaseDefense/Game/Game.cpp
        src/TrabalhoBaseDefense/Game/Game.h
        src/TrabalhoBaseDefense/Game/GameEntities/Actions/Shooting/HeroShooting.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/Actions/Shooting/HeroShooting.h
        src/TrabalhoBaseDefense/Game/GameEntities/Actions/Spawning/EnemySpawn.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/Actions/Spawning/EnemySpawn.hpp
        src/TrabalhoBaseDefense/Logger/Logger.cpp
        src/TrabalhoBaseDefense/Logger/Logger.hpp
        src/TrabalhoBaseDefense/Logger/LogLevel.h
        src/TrabalhoBaseDefense/Game/GameEntities/Actions/Shooting/EnemyShooting.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/Actions/Shooting/EnemyShooting.h
        src/TrabalhoBaseDefense/Game/Colisoes/Colisoes.cpp
        src/TrabalhoBaseDefense/Game/Colisoes/Colisoes.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Inimigos/InimigoComum.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Inimigos/InimigoComum.h
        src/TrabalhoBaseDefense/Game/Variables/EnemyVariables.hpp
        src/TrabalhoBaseDefense/Game/Variables/HeroVariables.h
        src/TrabalhoBaseDefense/Game/Variables/WindowConstants.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Inimigos/InimigoRapido.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Inimigos/InimigoRapido.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Inimigos/InimigoFortificado.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Inimigos/InimigoFortificado.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Inimigos/InimigoBoss.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Inimigos/InimigoBoss.h
        src/TrabalhoBaseDefense/Game/Telas/TelaMenu.cpp
        src/TrabalhoBaseDefense/Game/Telas/TelaMenu.h
        src/TrabalhoBaseDefense/Game/Telas/TelaGameOver.cpp
        src/TrabalhoBaseDefense/Game/Telas/TelaGameOver.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropavel.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropavel.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/DropavelMunicao.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/DropavelMunicao.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/DropavelVidaHeroi.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/DropavelVidaHeroi.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/DropavelVidaBase.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/DropavelVidaBase.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/DropavelContext.hpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/IDropavelStrategy.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/DropavelMunicaoStrategy.h
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/DropavelVidaHeroiStrategy.hpp
        src/TrabalhoBaseDefense/Game/GameEntities/impl/Dropaveis/DropavelVidaBaseStrategy.h
        src/TrabalhoBaseDefense/Game/GameEntities/Actions/Spawning/DropavelSpawn.cpp
        src/TrabalhoBaseDefense/Game/GameEntities/Actions/Spawning/DropavelSpawn.h
        src/TrabalhoBaseDefense/Game/GameUtils/GameEnemyUtils.cpp
        src/TrabalhoBaseDefense/Game/GameUtils/GameEnemyUtils.h
        src/TrabalhoBaseDefense/Util/FileUtils.cpp
        src/TrabalhoBaseDefense/Util/FileUtils.h
)
target_link_libraries(TrabalhoBaseDefenseEXE PRIVATE sfml-graphics)
target_compile_features(TrabalhoBaseDefenseEXE PRIVATE cxx_std_17)

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

if(WIN32)
    add_custom_command(
            TARGET TrabalhoBaseDefenseEXE
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:TrabalhoBaseDefense>
            VERBATIM)
endif()

install(TARGETS TrabalhoBaseDefenseEXE)
