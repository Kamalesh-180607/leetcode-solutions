class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char ch:s)
        {
            if(ch=='(')
            st.push(0);
            else
            {
                int x=st.top();
                st.pop();
                st.top()+=max(1,2*x);
            }
        }
        return st.top();
    }
};