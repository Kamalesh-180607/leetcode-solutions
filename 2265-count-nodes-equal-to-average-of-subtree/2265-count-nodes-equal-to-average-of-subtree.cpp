/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    void subtree(TreeNode* root,int &sum,int &n)
    {
        if(root!=nullptr)
        {
            subtree(root->left,sum,n);
            sum+=root->val;
            n++;
            subtree(root->right,sum,n);
        }
    }
    void solve(TreeNode* root)
    {
        if(root!=nullptr)
        {
            solve(root->left);
            int sum=0;
            int n=0;
            subtree(root,sum,n);
            if(sum/n==root->val)
            count++;
            solve(root->right);
        }
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};