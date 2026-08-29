class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxfreq=0;
        int t_count=0;
        int f_count=0;
        int left=0;
        int ans=0;
        for(int right=0;right<answerKey.size();right++)
        {
            if(answerKey[right]=='T')
            t_count++;
            else
            f_count++;
            maxfreq=max(t_count,f_count);
            while((right-left+1)-maxfreq>k)
            {
                if(answerKey[left]=='T')
                t_count--;
                else
                f_count--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};