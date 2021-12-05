cmake_minimum_required (VERSION 3.0)
project ("Project_SDL_sub")

IF(WIN32)
  message(STATUS "Building for windows")

  set(SDL2_INCLUDE_DIRS "SDL2/include")
  set(SDL2IMAGE_INCLUDE_DIRS "SDL2_image/include")

  # Support both 32 and 64 bit builds
  if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    message(STATUS "Building for 64bit")
    set(SDL2_LINK_DIRS "SDL2/lib/x64")
    set(SDL2IMAGE_LINK_DIRS "SDL2_image/lib/x64")
  else ()
    message(STATUS "Building for 32bit")
    set(SDL2_LINK_DIRS "SDL2/lib/x86")
    set(SDL2IMAGE_LINK_DIRS "SDL2_image/lib/x86")
  endif ()

  include_directories(${SDL2_INCLUDE_DIRS})
  include_directories(${SDL2IMAGE_INCLUDE_DIRS})
  link_directories(${SDL2_LINK_DIRS}, ${SDL2IMAGE_LINK_DIRS})

  add_executable(SDL_final main.cpp Project_SDL1.cpp "animal.h" "animal.cpp" "sheep.h" "sheep.cpp" "wolf.h" "wolf.cpp" "interacting_object.h" "interacting_object.cpp" "rendered_object.h" "rendered_object.cpp" "moving_object.h" "moving_object.cpp" "application.h" "application.cpp" "declaration.h" "ground.h" "ground.cpp" "playable_character.h" "playable_character.cpp" "shepherd.h" "shepherd_dog.h" "shepherd_dog.cpp" "shepherd.cpp")
  target_link_libraries(SDL_final PUBLIC SDL2 SDL2main SDL2_image)
ELSE()
  message(STATUS "Building for Linux or Mac")

  find_package(SDL2 REQUIRED)
  find_package(SDL2_IMAGE REQUIRED)
  include_directories(${SDL2_INCLUDE_DIRS})
  include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

  add_executable(SDL_final main.cpp Project_SDL1.cpp "animal.h" "animal.cpp" "sheep.h" "sheep.cpp" "wolf.h" "wolf.cpp" "interacting_object.h" "interacting_object.cpp" "rendered_object.h" "rendered_object.cpp" "moving_object.h" "moving_object.cpp" "application.h" "application.cpp" "declaration.h" "ground.h" "ground.cpp" "playable_character.h" "playable_character.cpp" "shepherd.h" "shepherd_dog.h" "shepherd_dog.cpp" "shepherd.cpp")
  target_link_libraries(SDL_final ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
ENDIF()