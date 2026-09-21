class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            
            int x = num % k;

            vector<long long> newDp(k, 0);

            // Subarray containing only num
            newDp[x]++;

            // Extend all previous subarrays by num
            for (int r = 0; r < k; r++) {
                
                if (dp[r] == 0)
                    continue;

                int newRemainder = (r * x) % k;

                newDp[newRemainder] += dp[r];
            }

            dp = newDp;

            // All subarrays ending at current position
            // are now counted in dp
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};