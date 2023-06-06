class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>>temp;
      int flag=1;
      int n=numRows;
      vector<int>t;
      vector<int>copy;
      if(n==1){
          t.push_back(flag);
          temp.push_back(t);
          return temp;
      }
      t.push_back(flag);
      copy.push_back(1);
      copy.push_back(1);
      temp.push_back(t);
      temp.push_back(copy);
      if(n==2){  
        return temp;
      }
        
        
        
      while(n!=2){
          n--;
          vector<int>down;
          int num=copy.size();
          down.push_back(1); //first push of the current row
          for(int i=0;i<num-1;i++){
              down.push_back(copy[i]+copy[i+1]); //respective sum
          }
          down.push_back(1); //last push of the current row
          temp.push_back(down); //pushing current row into ans
          copy=down; //copying current row as past row for the next iteration
      }
        
        
        
      return temp;
    }
};