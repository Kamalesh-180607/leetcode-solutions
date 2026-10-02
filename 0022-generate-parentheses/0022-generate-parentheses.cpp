class Solution {
public:
    void solve(int open,int close,int n,string curr,vector<string> &res)
    {
        if(curr.length()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n)
        solve(open+1,close,n,curr+"(",res);
        if(close<open)
        solve(open,close+1,n,curr+")",res);
    }
     vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};
//TIME LIMIT EXCEEDED
// class Solution {
//     set<string>res;
// public:
// bool validate(string ds)
// {
//     stack<char> st;

//     for(int i = 0; i < ds.size(); i++)
//     {
//         if(ds[i] == '(')
//         {
//             st.push('(');
//         }
//         else if(ds[i] == ')')
//         {
//             if(st.empty()) return false;
//             st.pop();
//         }
//     }

//     return st.empty();
// }
//     void function(string A,string ds,int index)
//     {
//         if(ds.length()==A.length() && validate(ds))
//         {   res.insert(ds);
//             return;
//         }
//         for(int i=index;i<A.length();i++)
//         {
//             ds.push_back(A[i]);
//             function(A,ds,index+1);
//             ds.pop_back();
//             function(A,ds,index+1);
//         }
//     }
//     vector<string> generateParenthesis(int n) {
//         string A="";
//         for(int i=0;i<n;i++)
//         A+="()";
//         string ds;
//         function(A,ds,0);
//         vector<string>result(res.begin(),res.end());
//         return result;
//     }
// };