add_library(SudokuKataCpp
        Utilities/GridStringifier.cpp
        Utilities/GridStringifier.h
        Utilities/WStringHelpers.cpp
        Utilities/WStringHelpers.h
        CellGroups.cpp
        CellGroups.h
        GroupsWithNMasks.cpp
        GroupsWithNMasks.h
        Program.cpp
        Program.h
        TwoDigitMaskGroups.cpp
        TwoDigitMaskGroups.h
        Utilities/FileReadingRandomNumber.cpp
        Utilities/FileReadingRandomNumber.h
        )
target_compile_features(SudokuKataCpp PUBLIC cxx_std_17)
target_include_directories(SudokuKataCpp
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        )
target_link_libraries(SudokuKataCpp PUBLIC fmt::fmt)
