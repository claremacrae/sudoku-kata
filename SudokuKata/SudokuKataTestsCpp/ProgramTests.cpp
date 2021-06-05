#include "ProgramTests.h"

#include "catch2/catch.hpp"
#include "ApprovalTests.hpp"

#include "Program.h"
#include "Utilities/FileReadingRandomNumber.h"
#include "Utilities/WStringHelpers.h"
#include "TestHelpers/FirstNFailuresReporter.h"

#include <iostream>
#include <regex>

using namespace ApprovalTests;
using namespace SudokuKata;

namespace SudokuKataTests
{

    TEST_CASE("TestSeed")
    {
        auto firstN = std::make_shared<FirstNFailuresReporter>(5, new DiffReporter);
        auto defaultReporterDisposer = Approvals::useAsDefaultReporter(firstN);
        auto errors = 0;
        for (int seed = 0; seed < 20; seed++)
        {
            // var randomValueGenerator = new FileWritingRandomNumber(seed);
            auto randomValueGenerator = new FileReadingRandomNumber();

            std::string section = ProgramTests::SeedSectionName(seed);
            auto sectionDisposer = NamerFactory::appendToOutputFilename(section);

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
                    std::cout << "ERROR: " << e.what() << std::endl << std::endl;
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

    std::string ProgramTests::SeedSectionName(int seed)
    {
        std::stringstream s;
        s << std::setfill('0') << std::setw(4) << seed;
        return s.str();
    }

    void ProgramTests::VerifySudokuForSeed(SudokuKata::IRandomValueGenerator* randomValueGenerator)
    {
        std::stringstream console;
        try
        {
            Program::Play(console, randomValueGenerator);
            std::string s = console.str();
        }
        catch (const std::exception& e)
        {
            console << "ERROR: " << e.what() << std::endl;
        }
        Approvals::verify(console.str());
    }

    std::string ProgramTests::GetSeedsFileName()
    {
        auto namer = Approvals::getDefaultNamer();
        auto seedsFile = toWString(namer->getApprovedFile(".seeds.txt"));
        return std::regex_replace(seedsFile, std::regex("\\.approved"), "");
    }
}
