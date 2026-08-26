class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int m,n;
    int fish=0;
    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        fish+=grid[i][j];
        grid[i][j]=0;
        for(auto d:dir)
        {
            int ni=i+d[0];
            int nj=j+d[1];

            if(ni<0 || ni>=m || nj<0 || nj>=n || grid[ni][nj]==0)
            continue;

            dfs(ni,nj,grid);
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int maxi=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0)
                {
                    fish=0;
                    dfs(i,j,grid);
                    maxi=max(maxi,fish);
                }
            }
        }
        return maxi;
    }
};