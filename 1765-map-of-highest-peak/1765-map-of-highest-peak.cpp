class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>res(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j])
                {
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(auto d:dir)
            {
                int ni=x+d[0];
                int nj=y+d[1];
                if(ni<0 || nj<0 || ni>=m || nj>=n || res[ni][nj]!=-1)
                continue;

                res[ni][nj]=res[x][y]+1;
                q.push({ni,nj});
            }
        }
        return res;
    }
};