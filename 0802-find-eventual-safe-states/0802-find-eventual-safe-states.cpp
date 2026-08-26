class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> list(n);
        vector<int>indeg(n);
        for(int i=0;i<n;i++)
        {
            for(auto adj:graph[i])
            {
                list[adj].push_back(i);
                indeg[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            q.push(i);
        }
        vector<int>res;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res.push_back(node);

            for(auto adj:list[node])
            {
                indeg[adj]--;
                if(indeg[adj]==0)
                q.push(adj);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }

    //THIS IS THE DFS SOLUTION 

    // bool dfs(int v,vector<vector<int>>& graph,vector<int>& vis,vector<int>& path,vector<int>& check)
    // {
    //     check[v]=0;
    //     vis[v]=1;
    //     path[v]=1;

    //     for(auto adj:graph[v])
    //     {
    //         if(!vis[adj])
    //         {
    //             if(dfs(adj,graph,vis,path,check))
    //             {
    //                 return true;
    //             }
    //         }
    //         else if(path[adj])
    //         {
    //             return true;
    //         }
    //     }
    //     check[v]=1;
    //     path[v]=0;
    //     return false;
    // }
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     int n=graph.size();
    //     vector<int> vis(n);
    //     vector<int> path(n);
    //     vector<int> check(n);
    //     for(int i=0;i<n;i++)
    //     {
    //         if(!vis[i])
    //         {
    //             dfs(i,graph,vis,path,check);
    //         }
    //     }
    //     vector<int>res;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(check[i]==1)
    //         res.push_back(i);
    //     }
    //     return res;
    // }
};