find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

add_test(Tester tesdcm)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(CPACK_PROJECT_NAME tesdcm)
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(tesdcm main.cpp)

target_link_libraries(tesdcm PRIVATE MainWindow)
