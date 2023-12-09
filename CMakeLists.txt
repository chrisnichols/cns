cmake_minimum_required(VERSION 3.28)

project(CNS VERSION 0.0.1.4)

set(CMAKE_CXX_STANDARD 20)

include(CTest)

add_compile_options(-Wall -Wextra -pedantic -Werror)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_compile_options(
        -fsanitize=undefined
        -fsanitize=address
        -fno-omit-frame-pointer
        --coverage
    )

    add_link_options(
        -fsanitize=undefined
        -fsanitize=address
        -fno-omit-frame-pointer
        --coverage
    )
endif()

# Custom build target that is always out of date (and will always be built)
# that deletes old gcda files. If they are left around, clang may error out
# during build
add_custom_target(
    cleanup ALL
    COMMAND ${PROJECT_SOURCE_DIR}/coverage_delete_gcda.sh ${PROJECT_SOURCE_DIR}
)

add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(tests)

find_package(Doxygen REQUIRED doxygen)

set(DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/docs")
set(DOXYGEN_FILE_PATTERNS *.ixx *.hxx)

set(DOXYGEN_ALPHABETICAL_INDEX YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
set(DOXYGEN_CASE_SENSE_NAMES NO)
set(DOXYGEN_CLASS_DIAGRAMS YES)
set(DOXYGEN_DISTRIBUTE_GROUP_DOC YES)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_GENERATE_TREEVIEW YES)
set(DOXYGEN_HIDE_FRIEND_COMPOUNDS YES)
set(DOXYGEN_HIDE_IN_BODY_DOCS YES)
set(DOXYGEN_HIDE_UNDOC_CLASSES YES)
set(DOXYGEN_HIDE_UNDOC_MEMBERS YES)
set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
set(DOXYGEN_QUIET YES)
set(DOXYGEN_RECURSIVE YES)
set(DOXYGEN_REFERENCED_BY_RELATION YES)
set(DOXYGEN_REFERENCES_RELATION YES)
set(DOXYGEN_SORT_BY_SCOPE_NAME YES)
set(DOXYGEN_SORT_MEMBER_DOCS NO)
set(DOXYGEN_SOURCE_BROWSER YES)
set(DOXYGEN_STRIP_CODE_COMMENTS NO)

doxygen_add_docs(
    docs
    "${PROJECT_SOURCE_DIR}/src"
    ALL
    COMMENT "Generate HTML documentation"
)