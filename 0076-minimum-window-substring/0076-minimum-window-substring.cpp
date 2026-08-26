class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> s_map;
        unordered_map<char,int> t_map;
        for(int i=0;i<t.length();i++)
        {
            t_map[t[i]]++;
        }
        int required=t_map.size();
        int minlen=INT_MAX;
        int left=0;
        int minstart=0;
        int current=0;
        for(int right=0;right<s.length();right++)
        {
            char ch=s[right];
            s_map[ch]++;
            if(t_map.count(ch) && t_map[ch]==s_map[ch])
            current++;

            while(current==required)
            {
                if(right-left+1 <minlen)
                {
                    minstart=left;
                    minlen=right-left+1;
                }
                s_map[s[left]]--;
                if(t_map.count(s[left]) && s_map[s[left]]<t_map[s[left]])
                current--;

                left++;
            }
        }
        return minlen==INT_MAX?"":s.substr(minstart,minlen);
    // int start=-1;
    // int count=0;
    // int left=0,right=0,minlen=INT_MAX;
    // int m=s.length();
    // int n=t.length();
    // unordered_map<char,int>mp;
    
    // for(int k=0;k<n;k++)
    // mp[t[k]]++;
    
    // while(right<m)
    // {
    //     if(mp[s[right]]>0)count+=1;
    //     mp[s[right]]--;
    //     while(count==n)
    //     {
    //         if(right-left+1<minlen)
    //         {
    //             start=left;
    //             minlen=right-left+1;
    //         }
    //         mp[s[left]]++;
    //         if(mp[s[left]]>0)
    //         {
    //             count-=1;
    //         }
    //         left++;
    //     }
    //     right++;
    // }
    // return start==-1?"":s.substr(start,minlen);
    // //BRUTE FORCE APPROACH
    // int start=-1,minlen=INT_MAX;
    // for(int i=0;i<s.length();i++)
    // {
    //     unordered_map<char,int>mp;
    //     for(int j=0;j<t.length();j++)
    //     mp[t[j]]++;
    //     int count=0;
    //     for(int j=i;j<s.length();j++)
    //     {
    //         if(mp[s[j]]>0)count+=1;
    //         mp[s[j]]--;
    //         if(count==t.length())
    //         {
    //             if(j-i+1<minlen)
    //             {
    //                 start=i;
    //                 minlen=j-i+1;
    //                 break;
    //             }
                
    //         }   
    //     }
    // }
    // return start==-1?"":s.substr(start,minlen);
    }
};