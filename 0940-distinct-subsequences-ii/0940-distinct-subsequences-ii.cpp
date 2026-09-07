class Solution {
public:
    int mod=1e9+7;
    vector<int>dp;
    string str;

    int solve(int index)
    {
        if(index==0)
            return 1;

        if(dp[index-1]!=-1)
            return dp[index-1];

        int ans=(2*solve(index-1))%mod;

        int prev=-1;

        for(int j=index-2;j>=0;j--)
        {
            if(str[index-1]==str[j])
            {
                prev=j+1;
                break;
            }
        }

        if(prev!=-1)
            ans=(ans-solve(prev)+mod)%mod;

        return dp[index-1]=ans;
    }

    int distinctSubseqII(string s) {
        //int n=s.length();
        long long dp=1;
        vector<long long>last(26,0);
        for(char ch:s)
        {
            int c=ch-'a';
            long long newDp=(2*dp - last[c] + mod)%mod;
            last[c]=dp;
            dp=newDp;
        }
        return (dp-1+mod)%mod;
    }
};