add_library(cns)
target_sources(
    cns
    PUBLIC
        FILE_SET CXX_MODULES FILES
            cns.ixx            
            format/cns.format.ixx
            format/cns.format-math.ixx
            math/cns.math.ixx
            math/cns.math-vector.ixx
            math/cns.math-matrix.ixx
            numeric/cns.numeric.ixx
            numeric/cns.numeric-compare.ixx
    PRIVATE
        math/cns.math-vector.cxx
        math/cns.math-matrix.cxx
        numeric/cns.numeric-compare.cxx
)
