class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;int next=0;string res="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')st.push(s[i]);
            else st.pop();
            if(st.empty())
            {
                res+=s.substr(next+1,i-next-1);
                next=i+1;
            }
        }
        return res;
    }
};