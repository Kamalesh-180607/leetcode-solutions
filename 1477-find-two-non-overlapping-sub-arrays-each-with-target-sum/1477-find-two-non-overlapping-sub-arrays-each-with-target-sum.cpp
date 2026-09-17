class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> dp(n,INT_MAX);

        int left=0;
        int ans=INT_MAX;
        int sum=0;
        int best=INT_MAX;
        for(int right=0;right<n;right++)
        {
            sum+=arr[right];
            while(sum>target)
            {
                sum-=arr[left++];
            }
            if(sum==target)
            {
                int len=right-left+1;
                if(left>0 && dp[left-1]!=INT_MAX)
                ans=min(ans,dp[left-1]+len);

                best=min(best,len);
            }
            dp[right]=best;
        }
        return ans==INT_MAX?-1:ans;
    }
};