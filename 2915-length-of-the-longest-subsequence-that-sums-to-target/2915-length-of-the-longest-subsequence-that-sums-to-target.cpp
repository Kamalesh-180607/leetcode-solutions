class Solution {
public:
    int maxi=-1;
    vector<vector<int>>dp;
    int solve(int index,int target,vector<int>& nums)
    {
        if(index<0)
        {
            if(target==0)
            return 0;
            else
            return -1e9;
        }
        if(dp[index][target]!=-1)
        return dp[index][target];
        int pick=-1e9;
        if(nums[index]<=target)
        pick=1+solve(index-1,target-nums[index],nums);
        int not_pick=solve(index-1,target,nums);
        return dp[index][target]=max(pick,not_pick);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(n,vector<int>(target+1,-1));
        int ans=solve(n-1,target,nums);
        return ans<0?-1:ans;
    }
};