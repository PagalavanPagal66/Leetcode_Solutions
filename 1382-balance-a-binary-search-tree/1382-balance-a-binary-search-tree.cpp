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
    void values(vector<int>&v,TreeNode* root){
        if(root!=NULL){
            values(v,root->left);
            v.push_back(root->val);
            values(v,root->right);
        }
    }
    TreeNode* construct(TreeNode* root, vector<int>& v,int l, int r){
        if(l>r){
            return NULL;
        }
        int mid=(l+r)/2;
        TreeNode* temp = new TreeNode(v[mid]);
        temp->left = construct(temp,v,l,mid-1);
        temp->right = construct(temp,v,mid+1,r);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        values(v,root);
        return construct(root,v,0,v.size()-1);
    }
};