add_executable(SudokuKataTestsCpp
        main.cpp
        )

# -------------------------------------------------------------------
include(FetchContent)

# ApprovalTests.cpp
FetchContent_Declare(ApprovalTests
        GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
        GIT_TAG master)
FetchContent_MakeAvailable(ApprovalTests)

# Catch2
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.11.1)
FetchContent_MakeAvailable(Catch2)
# -------------------------------------------------------------------

target_link_libraries(SudokuKataTestsCpp ApprovalTests::ApprovalTests Catch2::Catch2)

add_test(NAME SudokuKataTestsCpp COMMAND SudokuKataTestsCpp)
