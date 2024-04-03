class Solution {
public:
    bool bfs(vector<vector<char>>& b, string word,int row,int col,int count){
        if(count==word.size()){
            return true;
        }
        if(row<0 || col<0 || row>=b.size() || col>=b[0].size() || b[row][col]!=word[count]){
            return false;
        }
        char temp=b[row][col];
        b[row][col]=' ';
        bool a= bfs(b,word,row-1,col,count+1) || bfs(b,word,row,col-1,count+1) || bfs(b,word,row,col+1,count+1) ||       bfs(b,word,row+1,col,count+1);
        
        b[row][col]=temp;
        
        return a;
    }
    bool exist(vector<vector<char>>& b, string word) {
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(b[i][j]==word[0]){
                    if(bfs(b,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};