class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<tuple<int,int,int>>q;
        if(grid[0][0]==1)
        k--;
        q.push({0,0,k});
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> best(m,vector<int>(n,-1));
        best[0][0]=k;
        while(!q.empty())
        {
             int size=q.size();
             while(size--)
             {
                auto [i,j,rem]=q.front();
                q.pop();
                if(i==m-1 && j==n-1)
                return count;
                for(auto d:dir)
                {
                    int ni=i+d[0];
                    int nj=j+d[1];
                    if(ni<0 || ni>=m || nj<0 || nj>=n)
                    continue;
                    
                    int bal=rem;
                    if(grid[ni][nj]==1 && bal==0)
                    continue;

                    if(grid[ni][nj]==1)
                    {
                        bal--;
                    }
                    if(best[ni][nj]>=bal)
                    continue;
                    best[ni][nj]=bal;
                    q.push({ni,nj,bal});
                }
             }
             count++;
        }
        return -1;
    }
};