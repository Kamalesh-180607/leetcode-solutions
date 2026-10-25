class Solution {
public:
    int m,n;
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        grid[i][j]=1;
        for(auto d:dir)
        {
            int ni=d[0]+i;
            int nj=d[1]+j;

            if(ni<0 || ni>=m || nj<0 || nj>=n || grid[ni][nj]==1)
            continue;

            dfs(ni,nj,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0)
            dfs(i,0,grid);
            if(grid[i][n-1]==0)
            dfs(i,n-1,grid);
        }
        for(int j=0;j<n;j++)
        {
            if(grid[0][j]==0)
            dfs(0,j,grid);
            if(grid[m-1][j]==0)
            dfs(m-1,j,grid);
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};