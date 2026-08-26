class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> list(numCourses);
        vector<int>inDeg(numCourses);
        for(auto &c:prerequisites)
        {
            inDeg[c[1]]++;
            list[c[0]].push_back(c[1]);
        }   
        queue<int>q;
        vector<int>vis(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            if(inDeg[i]==0)
            q.push(i);
        }
        vector<int>res;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res.insert(res.begin(),node);
            for(int adj:list[node])
            {
                inDeg[adj]--;
                if(inDeg[adj]==0 && !vis[adj])
                {
                    q.push(adj);
                    vis[adj]=1;
                }
            }
        }
        if(res.size()==numCourses)
        return res;
        else 
        return {};
    }
};