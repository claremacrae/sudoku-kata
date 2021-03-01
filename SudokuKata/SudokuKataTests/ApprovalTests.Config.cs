using ApprovalTests.Reporters;
using ApprovalTests.Namers;

[assembly: UseReporter(typeof(AraxisMergeReporter))]
// [assembly: UseReporter(typeof(AllFailingTestsClipboardReporter))]
[assembly: UseApprovalSubdirectory("approval_tests")]
