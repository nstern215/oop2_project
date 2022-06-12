#file (MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/resources)

#font
configure_file ("Tower.ttf" ${CMAKE_BINARY_DIR} COPYONLY)

#images
configure_file ("bricks_background.jpg" ${CMAKE_BINARY_DIR} COPYONLY)

#sound
configure_file ("opening_track.wav" ${CMAKE_BINARY_DIR} COPYONLY)