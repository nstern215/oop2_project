file (MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/resources)

#font
configure_file ("Tower.ttf" ${CMAKE_BINARY_DIR} COPYONLY)

#images
configure_file ("bricks_background.jpg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("icytower_sprite.png" ${CMAKE_BINARY_DIR} COPYONLY)

#sound
configure_file ("opening_track.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("100_floors.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("alarm.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("game_over.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("new_high_score.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("new_record_claps.wav" ${CMAKE_BINARY_DIR} COPYONLY)

#other
configure_file ("tutorial.txt" ${CMAKE_BINARY_DIR} COPYONLY)