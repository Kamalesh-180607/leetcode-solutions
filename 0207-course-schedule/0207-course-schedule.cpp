class Solution {
public:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
    int count=0;
    while(!q.empty())
    {
        count++;
        int node=q.front();
        q.pop();
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
    return count==numCourses;
}
    // bool dfs(int node,vector<vector<int>> &list,vector<int>& vis)
    // {
    //     vis[node]+=2;//it means visited + pathvisited (instead of using two visited array this is single visted array concept)

    //     for(int adj:list[node])
    //     {
    //         if(vis[adj]==0)
    //         {
    //             if(dfs(adj,list,vis))
    //             return true;
    //         }
    //         else if(vis[adj]==2)
    //         return true;
    //     }
    //     vis[node]-=1;
    //     return false;
    // }
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     int n=prerequisites.size();
    //     vector<int>vis(numCourses,0);
    //     vector<vector<int>> graph(numCourses);
    //     for(int i=0;i<n;i++)
    //     {
    //         graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    //     }

    //     for(int i=0;i<numCourses;i++)
    //     {
    //         if(!vis[i])
    //         {
    //             if(dfs(i,graph,vis)==true)
    //             return false;
    //         }
    //     }
    //     return true;
    // }
};