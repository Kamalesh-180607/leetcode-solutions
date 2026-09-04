class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>p_greater(n);
        vector<int>n_smaller(n);
        p_greater[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            p_greater[i]=max(nums[i],p_greater[i-1]);
        }
        n_smaller[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            n_smaller[i]=min(nums[i],n_smaller[i+1]);
        }
        for(int i=0;i<n;i++)
        {
            if(p_greater[i]-n_smaller[i] <=k)
            return i;
        }
        return -1;
    }
};