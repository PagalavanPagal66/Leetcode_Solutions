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
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&mp){
        if(root!=nullptr){
            int a=0,b=0,c=0,d=0;
            if(mp.find(root)!=mp.end()){
                return mp[root];
            }
            if(root->right){
                a = solve(root->right->right,mp);
                b = solve(root->right->left,mp);
            }
            if(root->left){
                c = solve(root->left->right,mp);
                d = solve(root->left->left,mp);
            }
            int take= root->val + a+b+c+d;
            int nottake = solve(root->left,mp) + solve(root->right,mp);
            mp[root] = max(take,nottake);
            return mp[root];
        }
        return 0;
     }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        return solve(root,mp);
    }
};