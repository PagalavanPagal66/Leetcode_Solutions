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
    TreeNode* searchBST(TreeNode* root, int target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int level_size=q.size();
            while(level_size!=0){
                level_size--;
                TreeNode* currnode=q.front();
                if(currnode->left != nullptr){
                    q.push(currnode->left);
                } 
                if(currnode->right!=nullptr){
                    q.push(currnode->right);
                }
                q.pop();
                if(currnode->val == target){
                    return currnode;
                }
            }
        }
        return nullptr;
    }
};