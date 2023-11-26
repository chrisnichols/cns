find_package(Catch2 REQUIRED)

add_executable(
    tests
    cns/math/cns.math-vector.cxx
)

target_include_directories(tests PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(
    tests
    Catch2::Catch2WithMain
    cns
)

include(Catch)
catch_discover_tests(tests)
