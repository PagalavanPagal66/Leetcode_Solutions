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
    string smallest = "|";
    void findSmallest(TreeNode* node, string current) {
        if (!node)
            return;
        current.insert(0, 1,char('a' + node->val));// Insert current character atthe beginning of the string
        if (!node->left && !node->right) {
            if (current < smallest) // Compare current string with smallest found so far
                smallest = current;
            return;
        }
        if(node->left){
          findSmallest(node->left, current);  // Recur for left child  
        }
        if(node->right){
          findSmallest(node->right, current); // Recur for right child  
        }
        
    }

    string smallestFromLeaf(TreeNode* root) {
        findSmallest(root,""); // Start the recursive function with an empty string          
        return smallest;
    }
};