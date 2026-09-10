class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        // Get sum and count from left subtree
        auto left = dfs(root->left);

        // Get sum and count from right subtree
        auto right = dfs(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Check average
        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int count=0;
//     void subtree(TreeNode* root,int &sum,int &n)
//     {
//         if(root!=nullptr)
//         {
//             subtree(root->left,sum,n);
//             sum+=root->val;
//             n++;
//             subtree(root->right,sum,n);
//         }
//     }
//     void solve(TreeNode* root)
//     {
//         if(root!=nullptr)
//         {
//             solve(root->left);
//             int sum=0;
//             int n=0;
//             subtree(root,sum,n);
//             if(sum/n==root->val)
//             count++;
//             solve(root->right);
//         }
//     }
//     int averageOfSubtree(TreeNode* root) {
//         solve(root);
//         return count;
//     }
// };