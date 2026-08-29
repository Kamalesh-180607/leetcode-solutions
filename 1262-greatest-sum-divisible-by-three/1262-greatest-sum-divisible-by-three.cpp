class Solution {
public:
    int solve(int index, vector<int>& nums, int num, vector<vector<int>>& dp)
    {
        if(index == nums.size())
        {
            if(num == 0)
                return 0;

            return -1e9;
        }

        if(dp[index][num] != -1)
            return dp[index][num];

        int not_pick = solve(index + 1, nums, num, dp);

        int newrem = (num + nums[index]) % 3;

        int pick = nums[index] + solve(index + 1, nums, newrem, dp);

        return dp[index][num] = max(pick, not_pick);
    }

    int maxSumDivThree(vector<int>& nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(3, -1));

        return solve(0, nums, 0, dp);
    }
};