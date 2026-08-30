class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& interval) {
        vector<vector<int>>intervals;
        for(int i=0;i<interval.size();i++)
        {
            intervals.push_back({interval[i][0],interval[i][1],i});
        }
        sort(intervals.begin(),intervals.end());
        vector<int>res(intervals.size(),-1);
        cout<<"size of the result is: "<<res.size();
        for(int i=0;i<intervals.size();i++)
        {
            auto lower=lower_bound(intervals.begin(),intervals.end(),intervals[i][1],
            [](vector<int>& a,int val){
                return a[0]<val;
            });
            if(lower!=intervals.end())
            res[intervals[i][2]]= (*lower)[2];
        }
        return res;
    }
};