add_subdirectory(cns)

add_executable(main main.cxx)
target_link_libraries(main PRIVATE cns)