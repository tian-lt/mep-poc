project(console)

add_executable(console
    main.cpp
)

target_link_libraries(console PRIVATE meppoc::mep)

