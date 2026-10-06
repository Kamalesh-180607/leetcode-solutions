class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count=0;
        for(char ch:s)
        {
            if(ch=='(')
            st.push(ch);
            else
            {
                if(!st.empty())
                st.pop();
                else
                count++;
            }
        }
        return st.size()+count;
        // stack<char> st;
        // int count=0;
        // for(char x:s)
        // {
        //     if(x=='(')
        //     st.push(x);
        //     else
        //     {
        //         if(!st.empty())
        //         {
        //             st.pop();
        //         }
        //         else
        //         count++;
        //     }
        // }
        // return st.size()+count;
    }
};