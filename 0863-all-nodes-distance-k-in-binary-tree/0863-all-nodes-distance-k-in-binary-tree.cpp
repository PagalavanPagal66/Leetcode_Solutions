/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int>ans;
    unordered_map<TreeNode*, TreeNode*>v;
    queue<TreeNode*>q;
    TreeNode* r=root;
    q.push(r);
    int cnt=0;
    while(!q.empty()){
        r=q.front();
        q.pop();
        if(r->left!=NULL){v[r->left]=r; q.push(r->left);}
        if(r->right!=NULL){v[r->right]=r; q.push(r->right);}
    }
    unordered_map<TreeNode*, bool>v1;
    v1[target]=true;
    queue<TreeNode*>q1;
    q1.push(target);
    while(!q1.empty()){
        int l=q1.size();
        if(cnt==k){break;}
        cnt++;
        for(int i=0; i<l; i++){
            TreeNode* t=q1.front();
            q1.pop();
            if(t->left!=NULL && !v1[t->left]){v1[t->left]=true; q1.push(t->left);}
            if(t->right!=NULL && !v1[t->right]){v1[t->right]=true; q1.push(t->right);}
            if(v[t]!=NULL && !v1[v[t]]){v1[v[t]]=true; q1.push(v[t]);}
        }
    }
    while(!q1.empty()){
        TreeNode* x=q1.front();
        ans.push_back(x->val);
        q1.pop();
    }
    return ans;
}
};