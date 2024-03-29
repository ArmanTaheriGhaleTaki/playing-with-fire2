cmake_minimum_required(VERSION 3.22)
project(plying_with_fire2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(
    Qt6 COMPONENTS
        Core
        Gui        Widgets
        Multimedia
        REQUIRED)
add_executable(plying_with_fire2 main.cpp src/Home/Home.cpp src/Home/Home.h src/views/TextField.cpp src/views/TextField.h src/views/Label.cpp src/views/Label.h src/views/Button.cpp src/views/Button.h resources.qrc src/Home/Game.cpp src/Home/Game.h src/views/block.h src/views/block.cpp src/views/wall.h src/views/wall.cpp src/Player/Player.cpp src/Player/Player.h src/Player/Bomb.cpp src/Player/Bomb.h src/views/Brick.cpp src/views/Brick.h src/Home/Result.cpp src/Home/Result.h)
target_link_libraries(plying_with_fire2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
        )

if (WIN32)
    set(CMAKE_PREFIX_PATH C:/Qt/6.2.4/mingw_64)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
else()
    set(CMAKE_PREFIX_PATH /home/arman/Qt/6.2.4/gcc_x64)
endif ()

