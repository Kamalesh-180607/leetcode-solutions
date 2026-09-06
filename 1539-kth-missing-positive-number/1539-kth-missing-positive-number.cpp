class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        /*
        //WORKS BUT NOT EFFICIENT
        int count=0;
        unordered_set<int>st(arr.begin(),arr.end());int i=1;
        while(count<k)
        {
            if(!st.count(i))
            {
                count++;
            }
            i++;
        }
        return i-1;*/
        int left=0;
        int right=arr.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int missing=arr[mid]-(mid+1);
            if(missing>=k)right=mid-1;
            else
            left=mid+1;
        }
        return right+1+k;
        //or return left+k;
    }
};