add_library(
            ImageProc
            src/ImageProc/imgproc.cpp
            src/ImageProc/header/imgproc.hpp
            )            

target_include_directories(ImageProc PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

find_package(DCMTK REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

if(${Qt5_FOUND})
    message("Found Qt version : " ${Qt5_VERSION} " for ImageProc folder !")
    target_link_libraries(ImageProc  Qt5::Widgets Qt5::Core Qt5::Gui)
    message("Linked Qt version : " ${Qt5_VERSION} " for ImageProc folder !")
elseif(!${Qt5_FOUND})
    message("Coudn't find a Qt installation on this computer !")
endif()

if(${DCMTK_FOUND})
    message("Found DCMTK version : " ${DCMTK_VERSION} " for ImageProc folder !")
    include_directories(${DCMTK_INCLUDE_DIRS})
    target_link_libraries(ImageProc ${DCMTK_LIBS})
    message("Linked DCMTK version : " ${DCMTK_VERSION} " for ImageProc folder !")
elseif(!${DCMTK_FOUND})
    message("Coudn't find a DCMTK installation on this computer !")
endif()

if(${Boost_FOUND})
    message("Found Boost version : " ${Boost_VERSION} " for ImageProc folder !")
    include_directories( ${Boost_INCLUDE_DIR} )
    target_link_libraries(ImageProc LINK_PUBLIC ${Boost_LIBRARIES} )
    message("Linked Boost version : " ${Boost_VERSION} " for ImageProc folder !")
elseif(!${Boost_FOUND})
    message("Couldn't find a Boost installation on this computer !")
endif()

if(${OpenCV_FOUND})
    message("Found Opencv version :" ${OpenCV_VERSION} " for ImageProc folder !")
    include_directories(${OpenCV_INCLUDE_DIRS})
    target_link_libraries(ImageProc ${OpenCV_LIBS})
    message("Linked Opencv version :" ${OpenCV_VERSION} " for ImageProc folder !")
elseif(!${OpenCV_FOUND})
    message("Couldn't find an OpenCV installation on this computer !")
endif()