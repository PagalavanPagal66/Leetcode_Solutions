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
    int ans = 0;
    void rec(int no,TreeNode* root)
    {
        if(!root)
        return;
        no = no*10 + root->val;
        if(root->left==NULL&&root->right==NULL)
        {
            ans+=no;
            return;
        }
        rec(no,root->left);
        rec(no,root->right);
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        rec(0,root);
        return ans;
    }
};