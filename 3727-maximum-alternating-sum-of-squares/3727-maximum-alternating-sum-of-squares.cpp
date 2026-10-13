class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b)
        {
            return abs(a)<abs(b);
        });
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
        long long small=0;
        for(int i=0;i<n/2;i++)
        {
            small+=(nums[i]*nums[i]);
        }
        long long big=0;
        for(int i=n/2;i<n;i++)
        big+=(nums[i]*nums[i]);

        return big-small;
    }
};