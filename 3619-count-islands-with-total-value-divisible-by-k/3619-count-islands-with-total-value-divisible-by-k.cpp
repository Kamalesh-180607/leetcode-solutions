class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int m,n;
    int k;
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        long long sum=grid[i][j];
        grid[i][j]=0;
        for(auto d:dir)
        {
            int ni=d[0]+i;
            int nj=d[1]+j;

            if(ni<0 || ni>=m || nj<0 || nj>=n || grid[ni][nj]==0)
            continue;

            sum=(sum+dfs(grid,ni,nj))%k;
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int K) {
        k=K;
        m=grid.size();
        n=grid[0].size();

        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                {
                    long long res=dfs(grid,i,j);
                    if(res%k==0)
                    count++;
                }
            }
        }
        return count;
    }
};