#pragma once

#include <string>
#include "../disposable_interface.h"

namespace SudokuKataTests::TestHelpers
{
    class ConsoleUtilities
    {
        // From http://www.vtrifonov.com/2012/11/getting-console-output-within-unit-test.html
    public:
        class ConsoleOutput : public Disposable
        {
        private:
            StringWriter* stringWriter;
            TextWriter* originalOutput;

        public:
            virtual ~ConsoleOutput()
            {
                delete stringWriter;
                delete originalOutput;
            }

            ConsoleOutput();

            std::wstring GetOuput();

            void Dispose() override;
        };
    };
}
