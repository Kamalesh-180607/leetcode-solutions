class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int count=0;
        for(char x:s)
        {
            if(x=='(')
            {
                count++;
                maxi=max(maxi,count);
            }
            if(x==')')
            count--;
        }
        return maxi;
        // int maxd=0;
        // int count=0;
        // stack<char> st;
        // for(int i=0;i<s.length();i++)
        // {
        //     if(s[i]=='('){count++;st.push(s[i]);}
        //     else if(s[i]==')'){maxd=max(maxd,count);count--;st.pop();}

        //     if(st.empty())
        //     {
        //         count=0;
        //     }
        // }
        // return maxd;
    }
};