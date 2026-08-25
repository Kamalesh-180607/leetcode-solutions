class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int i=1;
        while(true)
        {
            if(st.count(i*k)==0)
            return i*k;
            i++;
        }
        return -1;
    }
};