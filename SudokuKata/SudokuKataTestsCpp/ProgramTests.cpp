﻿#include "ProgramTests.h"

#include "catch2/catch.hpp"
#include "ApprovalTests.hpp"

#include "Program.h"
#include "Utilities/FileReadingRandomNumber.h"
#include "Utilities/WStringHelpers.h"
#include "stringhelper.h"

using namespace ApprovalTests;
using namespace SudokuKata;

namespace SudokuKataTests
{

    TEST_CASE("TestSeed")
    {
        auto errors = 0;
        for (int seed = 0; seed < 20; seed++)
        {
            // var randomValueGenerator = new FileWritingRandomNumber(seed);
            auto randomValueGenerator = new FileReadingRandomNumber();

            std::wstring section = ProgramTests::SeedSectionName(seed);
            const std::string string = toString(section);
            auto sectionDisposer = NamerFactory::appendToOutputFilename(string);

            {
                // std::cout << "=============================================================" << std::endl;
                randomValueGenerator->ReadValuesFromFile(ProgramTests::GetSeedsFileName());
            }

            {
                try
                {
                    //                    auto defaultReporterDisposer =
                    //                        Approvals::useAsDefaultReporter(std::make_shared<QuietReporter>());

                    ProgramTests::VerifySudokuForSeed(randomValueGenerator);
                }
                catch (const std::exception& e)
                {
                    // The Approval Test failed - log the output on the console, and continue.
                    // so that we can review all failures in one session:
                    std::wcout << "ERROR: " << e.what() << std::endl << std::endl;
                    errors += 1;
                }
            }

            // {
            //     var seedsFile = GetSeedsFileName(seed);
            //     randomValueGenerator.WriteValuesToFile(seedsFile);
            // }
        }
        CHECK(0 == errors);
    }

    std::wstring ProgramTests::SeedSectionName(int seed)
    {
        std::wstringstream s;
        s << std::setfill(L'0') << std::setw(4) << seed;
        return s.str();
    }

    void ProgramTests::VerifySudokuForSeed(SudokuKata::IRandomValueGenerator* randomValueGenerator)
    {
        std::wstringstream console;
        try
        {
            Program::Play(console, randomValueGenerator);
            std::wstring s = console.str();
        }
        catch (const std::exception& e)
        {
            console << "ERROR: " << e.what() << std::endl;
        }
        Approvals::verify(toString(console.str()));
    }

    std::wstring ProgramTests::GetSeedsFileName()
    {
        auto namer = Approvals::getDefaultNamer();
        auto seedsFile = toWString(namer->getApprovedFile(".seeds.txt"));
        return StringHelper::replace(seedsFile, L".approved", L"");
    }
}
