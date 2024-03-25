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
    int dist;
    int dfs(TreeNode* root){
        if(root){
            int left = dfs(root->left);
            int right = dfs(root->right);
            dist += abs(left)+abs(right);
            return left+right+root->val-1;
        }
        return 0;
    }
    int distributeCoins(TreeNode* root) {
        dist = 0;
        dfs(root);
        return dist;
    }
};