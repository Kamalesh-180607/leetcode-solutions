class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n=points.size();
        set<pair<int,int>>st;
        for(auto x:points)
        st.insert({x[0],x[1]});
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                if (x1 == x2 || y1 == y2)
                    continue;
                if(st.count({x1,y2}) && st.count({x2,y1}))
                {
                    ans=min(ans,abs(x1-x2)*abs(y1-y2));
                }
            }
        }
        return ans==INT_MAX?0:ans;
        //return 0;
    }
};