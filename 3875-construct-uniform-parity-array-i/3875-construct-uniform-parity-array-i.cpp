class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //unordered_set<int>st;
        bool isOdd=false;
        bool isEven=false;
        for(int i=0;i<nums1.size();i++)
        {
            //st.insert(nums1[i]%2);
            if(nums1[i]%2==0)
            isEven=true;
            else 
            isOdd=true;
        }
        bool odd=true;
        bool even=true;
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]%2==0 && !isOdd)
            {
                odd=false;
                //break;
            }
            if(nums1[i]%2==1 && !isEven)
            {
                even=false;
                //break;
            }
        }
        // for(int i=0;i<nums1.size();i++)
        // {
        //     if(nums1[i]%2==1 && ! isEven)
        //     {
        //         even=false;
        //         break;
        //     }
        // }
        return odd |even;
    }
};