class Solution {
public:
    const int MOD = 1e9 + 7;

    long long solve(int n, int r, vector<vector<long long>>& dp) {

        // Base cases
        if (r == 0 || r == n)
            return 1;

        if (r < 0 || r > n)
            return 0;

        if (dp[n][r] != -1)
            return dp[n][r];

        return dp[n][r] =
            (solve(n - 1, r - 1, dp) +
             solve(n - 1, r, dp)) % MOD;
    }

    int numberOfSets(int n, int k) {

        int N = n + k - 1;
        int R = 2 * k;

        vector<vector<long long>> dp(N + 1,
                                     vector<long long>(R + 1, -1));

        return solve(N, R, dp);
    }
};