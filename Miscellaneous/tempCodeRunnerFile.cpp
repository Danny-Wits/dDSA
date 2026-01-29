  for (auto &t : tests)
    {
        assert(solve(t.expr) == t.expected && "Failed");
    }
    cout << "All tests passed\n";