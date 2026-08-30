class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int count1=0;
        int n=nums.size();
        bool min_vis=false,max_vis=false;
        for(int i=0;i<n;i++)
        {
            count1++;
            if(nums[i]==mini)
            min_vis=true;
            if(nums[i]==maxi)
            max_vis=true;
            if(min_vis && max_vis)
            break;
        }
        int count2=0;
        min_vis=false;
        max_vis=false;
        for(int i=n-1;i>=0;i--)
        {
            count2++;
            if(nums[i]==mini)
            min_vis=true;
            if(nums[i]==maxi)
            max_vis=true;
            if(min_vis && max_vis)
            break;
        }
        int i=0;
        int j=n-1;
        int count3=0;
        min_vis=false;
        max_vis=false;
        while(i<=j)
        {
             if(min_vis || max_vis)
             count3++;
             else
             count3+=2;
            if(nums[i]==mini || nums[j]==mini)
            min_vis=true;
            if(nums[i]==maxi || nums[j]==maxi)
            max_vis=true;
            if(min_vis && max_vis)
            break;
            i++;
            j--;
        }
        return min({count1,count2,count3});
    }
};