class Solution {
public:
    TreeNode* buildTree(vector<int>& ino, vector<int>& post) {
        int ps = 0,is =0,pe = post.size()-1,ie = ino.size()-1;
        return solve(ino,post,is,ie,ps,pe);
    }
    TreeNode* solve(vector<int>& ino,vector<int>& post,int is,int ie,int ps,int pe){
        if(ps>pe || is>ie){
            return nullptr;
        }
        TreeNode* root = new TreeNode(post[pe]);
        int cutter = 0;
        for(int i=is;i<=ie;i++){
            if(ino[i] == post[pe]){
                cutter = i;
                break;
            }
        }
        int lsize = cutter-is;
        int rsize = ie-cutter;
        root->left = solve(ino,post,is,cutter-1,ps,ps+lsize-1);
        root->right = solve(ino,post,cutter+1,ie,ps+lsize,pe-1);
        return root;
    }
};