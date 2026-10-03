class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>>dist(m,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            if(x==m-1 && y==n-1)
            return dis;

            for(auto d:dir)
            {
                int ni=x+d[0];
                int nj=y+d[1];

                if(ni<0 || ni>=m || nj<0 || nj>=n)
                continue;

                int newdis=max(dis,abs(heights[x][y]-heights[ni][nj]));
                if(dist[ni][nj]>newdis)
                {
                    dist[ni][nj]=newdis;
                    pq.push({newdis,{ni,nj}});
                }
            }
        }
        return 0;
    }
};