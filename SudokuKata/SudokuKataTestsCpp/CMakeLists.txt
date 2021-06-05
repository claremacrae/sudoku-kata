add_executable(SudokuKataTestsCpp
        main.cpp
        GridStringifierTests.cpp
        ProgramTests.cpp
        ProgramTests.h
        WStringHelpersTests.cpp
        TestHelpers/FirstNFailuresReporter.h
        )

target_link_libraries(SudokuKataTestsCpp SudokuKataCpp ApprovalTests::ApprovalTests Catch2::Catch2)

add_test(NAME SudokuKataTestsCpp COMMAND SudokuKataTestsCpp)
