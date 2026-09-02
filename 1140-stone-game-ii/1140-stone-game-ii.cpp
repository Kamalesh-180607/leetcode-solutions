class Solution {
public:
    int solve(int index,int M,vector<int>& piles,vector<vector<int>>& dp)
    {
        if(index>=piles.size())
        return 0;

        if(index==piles.size()-1)
        return piles[index];

        if(dp[index][M]!=-1)return dp[index][M];
        int ans=INT_MIN;
        int take=0;
        for(int x=0;x<2*M;x++)
        {
            if(index+x>=piles.size())
            break;
            take+=piles[index+x];
            int curr=take-solve(index+x+1,max(x+1,M),piles,dp);
            ans=max(ans,curr);
        }
        return dp[index][M]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int total=0;
        for(int x:piles)
        total+=x;
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(2*n,-1));
        int diff=solve(0,1,piles,dp);
        return (total+diff)/2;
    }
};