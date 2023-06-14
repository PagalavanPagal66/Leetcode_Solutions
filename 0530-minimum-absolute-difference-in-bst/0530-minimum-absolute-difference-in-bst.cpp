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
    void inor(TreeNode* root,vector<int>&res){
        if(root!=nullptr){
            inor(root->left,res);
            res.push_back(root->val);
            inor(root->right,res);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>res;
        inor(root,res);
        int mindif=INT_MAX;
        for(int i=1;i<res.size();i++){
            mindif=min(mindif,res[i]-res[i-1]);
        }
        return mindif;
    }
};