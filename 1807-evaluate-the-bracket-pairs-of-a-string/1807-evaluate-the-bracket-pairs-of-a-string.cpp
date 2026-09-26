class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res="";
        unordered_map<string,string>mp;
        for(auto x:knowledge)
        mp[x[0]]=x[1];

        int n=s.length();
        int i=0;
        while(i<n)
        {
            if(s[i]!='(')
            res+=s[i];
            else
            {
                string temp="";
                i++;
                while(s[i]!=')')
                {
                    temp+=s[i++];
                }
                if(mp.count(temp))
                {
                    res+=mp[temp];
                }
                else
                res+="?";
            }
            i++;
        }
        return res;
    }
};