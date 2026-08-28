class Solution {
public:
int n;
    int solve(int index,vector<int>& nums,vector<int>& dp)
    {
        if(index==n)
        return 0;
        if(dp[index]!=-1)return dp[index];
        int upIndex=upper_bound(nums.begin(),nums.end(),nums[index])-nums.begin();
        int nxtIndex=upper_bound(nums.begin(),nums.end(),nums[index]+1)-nums.begin();
        int pick=nums[index]*(upIndex-index)+solve(nxtIndex,nums,dp);
        int not_pick=solve(upIndex,nums,dp);
        return dp[index]=max(pick,not_pick);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};