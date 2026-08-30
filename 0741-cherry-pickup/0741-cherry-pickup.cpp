class Solution {
public:
    int n;
    int solve(vector<vector<int>>& grid,int r1,int c1,int r2,vector<vector<vector<int>>>& dp)
    {
        int c2=r1+c1-r2;
        if(r1>=n || c1>=n || r2>=n || c2>=n || c2<0)
        return -1e9;

        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
        return -1e9;

        if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];

        if (r1 == n - 1 && c1 == n - 1)
        return grid[r1][c1];

        int cherries=grid[r1][c1];
        if(r1!=r2 || c1!=c2)
        cherries+=grid[r2][c2];

        int best=max({solve(grid,r1+1,c1,r2+1,dp),
        solve(grid,r1,c1+1,r2+1,dp),
        solve(grid,r1+1,c1,r2,dp),
        solve(grid,r1,c1+1,r2,dp)});

        best+=cherries;
        return dp[r1][c1][r2]=best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,solve(grid,0,0,0,dp));
    }
};