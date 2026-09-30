class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth=0;
        vector<int>res;
        for(char x:seq)
        {
            if(x=='(')
            {
                depth++;
                res.push_back(depth%2);
            }
            else
            {
                res.push_back(depth%2);
                depth--;
            }
        }
        return res;
    }
};