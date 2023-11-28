add_library(cns)
target_sources(
    cns
    PUBLIC
        FILE_SET CXX_MODULES FILES
            cns.ixx
            math/cns.math.ixx
            math/cns.math-vector.ixx
            math/cns.math-matrix.ixx
    PRIVATE
        math/cns.math-vector.cxx
        math/cns.math-matrix.cxx
)
