class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2)return false;
        unordered_map<int,int>freq;
        freq[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(freq.count(rem))
            {
                if(i-freq[rem]>=2)
                return true;
            }
            else
            {
                freq[rem]=i;
            }
        }
        return false;
    }
};