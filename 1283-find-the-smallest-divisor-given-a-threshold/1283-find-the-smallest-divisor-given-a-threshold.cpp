class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans;
        int n=nums.size();
        while(low<=high)
        {
            int mid=(low+high)/2;
            int res=0;
            for(int i=0;i<n;i++)
            {
                res+=((nums[i]+mid-1)/mid);
            }
            if(res>threshold)
            low=mid+1;
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        return low;
        /* //TIME LIMIT EXCEEDED
        int i=1;
        while(true)
        {
            int sum=0;
            for(int x:nums)
            {
                sum+=ceil((double)x/i);
            }
            if(sum<=threshold)return i;
            i++;
        }
        return 0;
        */

        
        // int low=1;
        // int high=*max_element(nums.begin(),nums.end());
        // while(low<=high)
        // {
        //     int mid=(low+high)/2;
        //     int sum=0;
        //     for(int x:nums)
        //     {
        //         sum+=ceil((double)x/mid);
        //     }
        //     if(sum<=threshold)high=mid-1;
        //     else low=mid+1;
        // }
        // return low;
        
        
    }
};