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
    int mx = INT_MIN;
    int getM(TreeNode *root) {
        if (!root)
            return 0;
        int l = getM(root->left);
        int r = getM(root->right);
        int path = root->val + max(l, r);
        return max(0, path);
    }
    void dfs(TreeNode *root) {
        if (!root)
            return;
        int l = getM(root->left);
        int r = getM(root->right);
        mx = max(mx, root->val + l + r);
        dfs(root->left);
        dfs(root->right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};
