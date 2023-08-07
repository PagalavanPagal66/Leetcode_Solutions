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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*>ans;
        for(auto i:nums){
            TreeNode* temp = new TreeNode(i);
            while(!ans.empty() && ans.back()->val <i){
                temp->left = ans.back();
                ans.pop_back();
            }
            if(!ans.empty()){
                ans.back()->right = temp;
            }
            ans.push_back(temp);
        }
        return ans.front();
    }
};