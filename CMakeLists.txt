cmake_minimum_required(VERSION 3.7)

project(app1)

find_package(OGRE 1.11.2 REQUIRED COMPONENTS Bites RTShaderSystem Terrain)
find_package(OIS)
find_package(Bullet)
find_package(sdl2)


# copia resources.cfg
if(EXISTS ${PROJECT_SOURCE_DIR}/resources.cfg)
       file(COPY ${PROJECT_SOURCE_DIR}/resources.cfg DESTINATION ${CMAKE_BINARY_DIR})
else()
       file(COPY ${OGRE_CONFIG_DIR}/resources.cfg DESTINATION ${CMAKE_BINARY_DIR})
endif(EXISTS ${PROJECT_SOURCE_DIR}/resources.cfg)


include_directories(
                    ${OGRE_INCLUDE_DIRS}
                    ${SDL2_INCLUDE_DIRS}
                    ${OIS_INCLUDE_DIRS}
                    ${BULLET_INCLUDE_DIRS}
                    )

file(GLOB SRCS ${CMAKE_SOURCE_DIR}/*.cpp)
file(GLOB HDRS ${CMAKE_SOURCE_DIR}/*.h)

add_executable(${CMAKE_PROJECT_NAME}
                ${SRCS}
                ${HDRS}
               )

target_link_libraries( ${CMAKE_PROJECT_NAME}
                       ${OGRE_LIBRARIES}
                       ${OIS_LIBRARIES}
                       ${BULLET_LIBRARIES}
                       ${SDL2_LIBRARIES}
                      )

