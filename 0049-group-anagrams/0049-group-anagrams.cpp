class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string,vector<string>>mp;
     for(string str:strs)
     {
        vector<int>freq(26);
        for(char ch:str)
        freq[ch-'a']++;

        string key="";
        for(int x:freq)
        key+=to_string(x)+"#";

        mp[key].push_back(str);
     }
     vector<vector<string>>res;
     for(auto x:mp)
     {
        vector<string> temp=x.second;
        res.push_back(temp);
     }
     return res;
    }
};