class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        unordered_set<int>st;
        for(int i=0;i<nums1.size();i++)
        {
            st.insert(nums1[i]%2);
        }
        bool odd=true;
        bool even=true;
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]%2==0 && !st.count(1))
            {
                odd=false;
                break;
            }
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]%2==1 && !st.count(0))
            {
                even=false;
                break;
            }
        }
        return odd |even;
    }
};