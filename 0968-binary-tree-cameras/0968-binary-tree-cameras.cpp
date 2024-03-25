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
    int solve(TreeNode* root,int& ans){
        int k;
        if(root==NULL){
            return -1;
        }
        int l = solve(root->left,ans);
        int r = solve(root->right,ans);
        if(l==0){
            ans++;
            k=1;
        }
        else if(l== -1){
            if(r==-1){
               // cout<<"BOTH"<<endl;
                k=0;
            }
            else if(r==0){
                k=1;
               // cout<<"YES"<<endl;
                ans++;
            }
            else{
                k=-1;
               // cout<<"YES1"<<endl;
            }
            
        }
        else{
            if(r==-1){
                k = -1;
            }
            else if(r==0){
                k=1;
                ans++;
            }
            else{
                k = -1;
            }
        }
        return k;
    }
    int minCameraCover(TreeNode* root) {
        int ans=0;
        int val = solve(root,ans);
        //cout<<ans<<endl;
        if(val==0){
            return ans+1;
        }
        return ans;
    }
};