class Solution {
public:
    int solve(int i, string &s, int k, vector<int> &dp,
              vector<vector<bool>> &pal) {

        int n = s.size();

        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Option 1: skip current index
        int ans = solve(i + 1, s, k, dp, pal);

        // Option 2: take a palindrome starting at i
        for (int j = i + k - 1; j < n; j++) {
            if (pal[i][j]) {
                ans = max(ans, 1 + solve(j + 1, s, k, dp, pal));
            }
        }

        return dp[i] = ans;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();

        // Precompute palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n, -1);

        return solve(0, s, k, dp, pal);
    }
};