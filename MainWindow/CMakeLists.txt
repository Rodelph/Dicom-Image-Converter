add_library(
            MainWindow
            src/MainWindow/mainwindow.cpp
            src/MainWindow/mainwindow.ui
            src/MainWindow/header/mainwindow.h
            )            

target_include_directories(ImageProc PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

if(${Qt5_FOUND})
    message("Found Qt version : " ${Qt5_VERSION} " for ImageProc folder !")
    target_link_libraries(MainWindow  Qt5::Widgets Qt5::Core Qt5::Gui)
    message("Linked Qt version : " ${Qt5_VERSION} " for ImageProc folder !")
elseif(!${Qt5_FOUND})
    message("Coudn't find a Qt installation on this computer !")
endif()