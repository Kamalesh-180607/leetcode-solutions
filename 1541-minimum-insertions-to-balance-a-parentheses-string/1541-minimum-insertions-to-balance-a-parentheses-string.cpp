class Solution {
public:
    int minInsertions(string s) {
        int res=0;
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            st.push('(');
            else
            {
                if(st.empty())
                {
                    if(i+1<n && s[i+1]==')')
                    i++;
                    else
                    res++;

                    res++;
                }
                else
                {
                    if(i+1<n && s[i+1]==')')
                    i++;
                    else
                    res++;

                    st.pop();
                }
            }
        }
        return res+2*st.size();
    }
};