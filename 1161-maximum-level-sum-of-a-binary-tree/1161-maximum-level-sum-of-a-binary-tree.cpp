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
    int maxLevelSum(TreeNode* root) {
        int level=0,ans=INT_MIN;
        if(root==NULL)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int k=1,i=0;
        while(q.empty()==false){
            int temp=0;
            int k=q.size();
            while(q.empty()==false && k--){
                TreeNode*curr=q.front();
                q.pop();
                temp+=curr->val;
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            if(temp>ans){
                level=i+1;
                ans=temp;
            }
            i++;
        }
        return level;
    }
};