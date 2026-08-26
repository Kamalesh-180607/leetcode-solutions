class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> list(n+1);
        vector<int>indeg(n+1);
        for(int i=0;i<relations.size();i++)
        {
            list[relations[i][1]].push_back(relations[i][0]);
            indeg[relations[i][0]]++;
        }

        queue<int> q;
        vector<int>finish(n+1);
        vector<int>vis(n+1);
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                finish[i]=time[i-1];
                vis[i]=1;
            }
        }
        int months=0;
        while(!q.empty())
        {
            int course=q.front();
            q.pop();
            months=max(months,finish[course]);

            for(auto adj:list[course])
            {
                finish[adj]=max(finish[adj],finish[course]+time[adj-1]);
                indeg[adj]--;
                if(indeg[adj]==0 && !vis[adj])
                {
                    vis[adj]=1;
                    q.push(adj);
                }
            }
        }
        return months;
    }
};