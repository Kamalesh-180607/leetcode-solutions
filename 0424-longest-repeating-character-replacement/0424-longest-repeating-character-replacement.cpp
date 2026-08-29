class Solution {
public:
    int characterReplacement(string s, int k) {
         vector<int> freq(26, 0);
        int l = 0, maxFreq = 0, maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // If window is invalid
            while((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
        //THIS WORKS FINE O(2N*26)
        // int left=0,right=0,maxlen=0,maxfreq=0;
        // unordered_map<char,int>mp;
        // int n=s.length();
        // while(right<n)
        // {
        //     mp[s[right]]++;
        //     maxfreq=max(maxfreq,mp[s[right]]);
        //     while((right-left+1)-maxfreq>k)
        //     {
        //         mp[s[left]]--;
        //         maxfreq=0;
        //         for(auto &p:mp)
        //         {
        //             maxfreq=max(maxfreq,p.second);
        //         }
        //         left++;
        //     }
        //     maxlen=max(maxlen,right-left+1);
        //     right++;
        // }
        // return maxlen;

        // BRUTE FORCE O(N^2) TIME LIMIT EXCEEDED
        //int n=s.length();
        // int maxlen=0;
        // for(int i=0;i<n;i++)
        // {
        //     unordered_map<char,int>mp;
        //     int maxfreq=0;
        //     for(int j=i;j<n;j++)
        //     {
        //         mp[s[j]]++;
        //         maxfreq=max(maxfreq,mp[s[j]]);
        //         int changes=j-i+1 -maxfreq;
        //         if(changes<=k)
        //         maxlen=max(maxlen,j-i+1);
        //         else
        //         break;
        //     }
        // }
        // return maxlen;
    }
};