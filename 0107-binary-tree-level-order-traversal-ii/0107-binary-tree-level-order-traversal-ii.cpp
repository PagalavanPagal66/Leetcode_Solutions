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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int level_size=q.size();
            vector<int>temp;
            while(level_size!=0){
                level_size--;
                TreeNode* currnode=q.front();
                q.pop();
                if(currnode->left != nullptr){
                    q.push(currnode->left);
                }
                if(currnode->right != nullptr){
                    q.push(currnode->right);
                }
                temp.push_back(currnode->val);
            }
            res.push_back(temp);
        }
        vector<vector<int>>r;
        int n=res.size()-1;
        while(n>=0){
            r.push_back(res[n]);
            n--;
        }
        return r;
    }
};