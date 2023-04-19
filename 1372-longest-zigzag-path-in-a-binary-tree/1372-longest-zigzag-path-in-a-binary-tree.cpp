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
    int maxC = 0;
    void count(TreeNode *node, int dir, int curr)
    {
        if(node == NULL)
            return;
        maxC = max(maxC, curr);

        if(dir == 1){
           count(node -> left, 0, curr + 1);
            count(node -> right, 1, 1);
        }
        else
        {
            count(node -> right, 1, curr + 1);
            count(node -> left, 0, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        count(root, 1, 0);
        count(root, 0, 0);
        return maxC;
    }
};