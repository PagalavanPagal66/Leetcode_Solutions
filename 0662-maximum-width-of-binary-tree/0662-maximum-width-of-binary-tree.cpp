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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long res=INT_MIN;

        while(!q.empty()){

int n=size(q);
long long val=q.back().second-q.front().second+1;
res=max(res,val);
for(int i=0;i<n;i++){
    TreeNode* node=q.front().first;
    long long lv=q.front().second;
    q.pop();
    
    if(node->left){
        q.push({node->left,(2*lv+1)});
    }
    if(node->right){
        q.push({node->right,(2*lv+2)});
    }
}
        }
        return res;
    }
};
