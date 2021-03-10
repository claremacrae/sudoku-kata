using ApprovalTests;
using Newtonsoft.Json;

namespace SudokuKataTests.TestHelpers
{
    internal static class ApprovalsHelpers
    {
        public static void VerifyAsJson<T>(T objectUnderTest, string description)
        {
            var asJson = JsonConvert.SerializeObject(objectUnderTest, Formatting.Indented);
            Approvals.Verify(description + asJson);
        }
    }
}