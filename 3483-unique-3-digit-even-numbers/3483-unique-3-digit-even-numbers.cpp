class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10,0);
        int count=0;
        for(int x:digits)
        freq[x]++;

        for(int i=100;i<=998;i++)
        {
            if(i%2==1)
            continue;
            int num=i;
            int a=num%10;
            num/=10;
            int b=num%10;
            num/=10;
            int c=num%10;

            freq[a]--;
            freq[b]--;
            freq[c]--;
            if(freq[a]>=0 && freq[b]>=0 && freq[c]>=0)
            count++;

            freq[a]++;
            freq[b]++;
            freq[c]++;
        }
        return count;
    }
};