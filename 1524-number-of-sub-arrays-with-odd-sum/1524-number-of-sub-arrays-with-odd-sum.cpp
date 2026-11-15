class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int count=0;
        int oddcount=0,evencount=1;
        int prefixsum=0;
        int mod=1e9+7;
        for(int x:arr)
        {
            prefixsum+=x;
            if(prefixsum%2==0)
            {
                count+=oddcount;
                evencount++;
            }
            else
            {
                count+=evencount;
                oddcount++;
            }
            count%=mod;
        }
        return count;
    }
};