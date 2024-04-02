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
    unordered_map<int,int>heights,levels;
    map<int,priority_queue<int,vector<int>,greater<int>>>mp;
    int solve(int level,TreeNode* root){
        if(root==nullptr){
            return -1;
        }
        int l = solve(level+1,root->left);
        int r = solve(level+1,root->right);
        int height = max(l+1,r+1);
        heights[root->val] = height;
        levels[root->val] = level;
        mp[level].push(height);
        if(mp[level].size() > 2){
            mp[level].pop();
        }
        return height;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int m=queries.size();
        int tot = solve(0,root);
        //cout<<tot<<endl;
        vector<int>ans(m,0);
        for(int i=0;i<m;i++){
            int node = queries[i];
            int h = heights[node];
            int l = levels[node];
            if(mp[l].size()==1){
                ans[i] = tot -h - 1;
            }
            else{
                int t1 = mp[l].top();
                mp[l].pop();
                int t2 = mp[l].top();
                mp[l].pop();
                if(h == t2){
                    ans[i] = t1+l;
                }
                else{
                    ans[i] = tot;
                }
                //cout<<node<<" "<<t1<<" "<<t2<<endl;
                mp[l].push(t1);
                mp[l].push(t2);
            }
        }
        return ans;
    }
};