add_library(
            MainWindow
            src/MainWindow/mainwindow.cpp
            src/MainWindow/mainwindow.ui
            src/MainWindow/header/mainwindow.h
            )            

target_include_directories(MainWindow PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

if(${Qt5_FOUND})
    message("Found Qt version : " ${Qt5_VERSION} " for MainWindow folder !")
    target_link_libraries(MainWindow  Qt5::Widgets Qt5::Core Qt5::Gui)
    message("Linked Qt version : " ${Qt5_VERSION} " for MainWindow folder !")
elseif(!${Qt5_FOUND})
    message("Coudn't find a Qt installation on this computer !")
endif()

find_package(DCMTK REQUIRED)

if(${DCMTK_FOUND})
    message("Found DCMTK version : " ${DCMTK_VERSION} " for MainWindow folder !")
    include_directories(${DCMTK_DIRS})
    target_link_libraries(MainWindow ${DCMTK_LIBRARIES})
    message("Linked DCMTK version : " ${DCMTK_VERSION} " for MainWindow folder !")
elseif(!${DCMTK_FOUND})
    message("Coudn't find a DCMTK installation on this computer !")
endif()

find_package(OpenCV REQUIRED)

if(${OpenCV_FOUND})
    message("Found Opencv version :" ${OpenCV_VERSION} " for MainWindow folder !")
    include_directories(${OpenCV_INCLUDE_DIRS})
    target_link_libraries(MainWindow ${OpenCV_LIBS})
    message("Linked Opencv version :" ${OpenCV_VERSION} " for MainWindow folder !")
elseif(!${OpenCV_FOUND})
    message("Couldn't find an OpenCV installation on this computer !")
endif()
