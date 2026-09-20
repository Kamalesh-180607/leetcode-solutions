class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int ans=0;
        // unordered_map<char,int>mp;
        // int rnk=26;
        // for(int i=0;i<26;i++)
        // {
        //     mp['a'+i]=rnk--;
        // }
        for(int i=1;i<=n;i++)
        {
            ans+=((26 - (s[i-1] - 'a')) * i);
        }
        return ans;
    }
};