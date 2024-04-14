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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        int sum=0;
        q.push({root,0});
        while(!q.empty()){
            int s=q.size();
            while(s--){
                TreeNode* temp=q.front().first;
                int flag=q.front().second;
                q.pop();
                if(temp->left==NULL && temp->right==NULL && flag==1){
                    sum+=temp->val; 
                }
                if(temp->left){
                    q.push({temp->left,1});
                }
                if(temp->right){
                    q.push({temp->right,0});
                }
            }
        }
        return sum;
    }
};