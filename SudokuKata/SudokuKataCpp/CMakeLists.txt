add_library(SudokuKataCpp
        Utilities/GridStringifier.cpp
        Utilities/GridStringifier.h
        Utilities/WStringHelpers.h
        Program.cpp
        Program.h
        )
target_compile_features(SudokuKataCpp PUBLIC cxx_std_17)
target_include_directories(SudokuKataCpp
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        )
