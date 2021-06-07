add_library(SudokuKataCpp
        CellGroup.cpp
        CellGroup.h
        GroupsWithNMasks.cpp
        GroupsWithNMasks.h
        Program.cpp
        Program.h
        Puzzle.cpp
        Puzzle.h
        TwoDigitMaskGroups.cpp
        TwoDigitMaskGroups.h
#        NotYetPorted/program_main.cpp    # TODO Does not yet compile - and should not be in a library
        rectangularvectors.h
        Utilities/CandidatesStringifier.cpp
        Utilities/CandidatesStringifier.h
        Utilities/FileReadingRandomNumber.cpp
        Utilities/FileReadingRandomNumber.h
#        NotYetPorted/FileWritingRandomNumber.cpp  # TODO Needs C++ equivalent of C#'s Random
#        NotYetPorted/FileWritingRandomNumber.h    # TODO Needs C++ equivalent of C#'s Random
        Utilities/GridStringifier.cpp
        Utilities/GridStringifier.h
        Utilities/IRandomValueGenerator.h
#        NotYetPorted/RandomNumber.cpp # TODO Needs C++ equivalent of C#'s Random
#        NotYetPorted/RandomNumber.h   # TODO Needs C++ equivalent of C#'s Random
        )
target_compile_features(SudokuKataCpp PUBLIC cxx_std_17)
target_include_directories(SudokuKataCpp
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        )
target_link_libraries(SudokuKataCpp PUBLIC fmt::fmt)
