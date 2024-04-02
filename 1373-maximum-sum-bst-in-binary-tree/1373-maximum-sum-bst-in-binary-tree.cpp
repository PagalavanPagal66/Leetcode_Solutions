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
    int sumans=INT_MIN;
    unordered_map<TreeNode*,int>minner;
    unordered_map<TreeNode*,int>maxer;
    unordered_map<TreeNode*,bool>yesser;
    int summer(TreeNode* root){
        if(root==nullptr){
            minner[root] = INT_MAX;
            maxer[root] = INT_MIN;
            yesser[root] = true;
            return 0;
        }
        int l = summer(root->left);
        int r = summer(root->right);
        if((minner[root->right]> root->val) 
            && 
            (maxer[root->left] < root->val) && yesser[root->left] && yesser[root->right]){
            sumans = max(sumans,l+r+root->val); 
            yesser[root] = true;
        }
        else
            yesser[root] = false;
        
        minner[root] = min({minner[root->right],minner[root->left],root->val});
        maxer[root] = max({maxer[root->left],maxer[root->right],root->val});
        return l+r+root->val;
    }

    int maxSumBST(TreeNode* root) {
        sumans = INT_MIN;
        int sum=0;
        // minner.clear();
        // maxer.clear();
        // yesser.clear();
        summer(root);
        return max(0,sumans);
    }
};