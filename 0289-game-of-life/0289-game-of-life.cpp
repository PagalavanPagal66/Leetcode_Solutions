class Solution {
public:
    int cal(vector<vector<int>>board,int i,int j)
    {
        int n=board.size(),m=board[0].size();
        int sum=0;
        if(i>0)  sum+=board[i-1][j];
        if(i<n-1) sum+=board[i+1][j];
        if(j>0) sum+=board[i][j-1];
        if(j<m-1) sum+=board[i][j+1];
        if(i>0 && j>0) sum+=board[i-1][j-1];
        if(i<n-1 && j>0) sum+=board[i+1][j-1];
        if(i>0 && j<m-1) sum+=board[i-1][j+1];
        if(i<n-1 && j<m-1) sum+=board[i+1][j+1];
        return sum;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
      vector<vector<int>> ans(n,vector<int>(m));
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              int sum=cal(board,i,j);
              if(board[i][j]==0 && sum==3)
              ans[i][j]=1;
              else
              ans[i][j]=0;
              if(board[i][j]==1 &&sum<2)
              ans[i][j]=0;
              else if(board[i][j]==1 && sum==2 ||sum==3)
              ans[i][j]=1;
              else
              ans[i][j]=0;
          }
      }
        board=ans; 
    }
};