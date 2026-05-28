cmake_minimum_required(VERSION 4.2)
project(EcoMision)

set(CMAKE_CXX_STANDARD 14)

add_executable(EcoMision
        main.cpp
        EcoMision.cpp
        EcoMision.h
        ObjetoInteractuable.cpp
        ObjetoInteractuable.h
        Zona.cpp
        Zona.h
        AnimalHerido.cpp
        AnimalHerido.h
        PlantaMedicinal.cpp
        PlantaMedicinal.h
        ResiduoContaminante.cpp
        ResiduoContaminante.h
        Explorador.cpp
        Explorador.h
        LaboratorioAmbiental.cpp
        LaboratorioAmbiental.h
        CentroRecuperacionAnimal.cpp
        CentroRecuperacionAnimal.h
        VivideroRestauracion.cpp
        VivideroRestauracion.h
        ReservaNatural.cpp
        ReservaNatural.h
        BosqueHumedo.cpp
        BosqueHumedo.h

        # ¡AQUÍ DEBES AGREGAR LOS QUE FALTAN!
        FuenteContaminada.cpp
        FuenteContaminada.h
        Obstaculo.cpp
        Obstaculo.h
        Portal.cpp
        Portal.h
        RioContaminado.cpp
        RioContaminado.h
        SemillaNativa.cpp
        SemillaNativa.h
        SenderoMontania.cpp
        SenderoMontania.h
)