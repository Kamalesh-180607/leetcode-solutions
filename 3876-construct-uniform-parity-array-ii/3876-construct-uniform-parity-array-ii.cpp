class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_even=INT_MAX;
        int min_odd=INT_MAX;
        for(int x:nums1)
        {
            if(x%2==0)
            min_even=min(min_even,x);

            else
            min_odd=min(min_odd,x);
        }
        if(min_odd==INT_MAX || min_even==INT_MAX)
        return true;

        bool can_odd=true;
        bool can_even=true;
        for(int x:nums1)
        {
            if(x%2==0 && x-min_odd<1)
            can_odd=false;

            if(x%2==1 && x-min_odd<1)
            can_even=false;
        }
        return can_odd | can_even;
    }
};