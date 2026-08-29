class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        if(nums.size()==0)
        return res;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            int start=nums[i];
            int end=nums[i];
            int j=i+1;
            while(j<n && nums[j]==end+1)
            {
                end=nums[j];
                j++;
            }
            if(start==end)
            res.push_back(to_string(start));
            else
            res.push_back(to_string(start)+"->"+to_string(end));
            i=j-1;
        }
        return res;
    }
};