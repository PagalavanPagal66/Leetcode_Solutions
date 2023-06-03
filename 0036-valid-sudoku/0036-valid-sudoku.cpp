class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       
        for(int i=0 ; i<9 ; i++){   
            unordered_map<char,int> mp; 
            for(int j=0 ; j<9 ; j++){
                if(board[i][j] != '.'){
                    mp[board[i][j]]++ ;
                }
                if(mp[board[i][j]] > 1){
                    return false;
                }
            }
        }

        for(int i=0 ; i<9 ; i++){ 
            unordered_map<char,int> mp; 
            for(int j=0 ; j<9 ; j++){
                if(board[j][i] != '.'){
                        mp[board[j][i]]++ ;
                    }
                if(mp[board[j][i]] > 1){
                    return false;
                }
            }
        }
        
        int k = 0;
        while(k < 9){        
            unordered_map<char,int> mp; 
            for(int i=k ; i<k+3 ; i++){    
                for(int j=0 ; j<=2 ; j++){
                    if(board[i][j] != '.'){
                        mp[board[i][j]]++ ;
                    }
                    if(mp[board[i][j]] > 1){
                        return false;
                    }
                }
            }
            mp.clear();
            for(int i=k ; i<k+3 ; i++){   
                for(int j=3 ; j<=5 ; j++){
                    if(board[i][j] != '.'){
                        mp[board[i][j]]++ ;
                    }
                    if(mp[board[i][j]] > 1){
                        return false;
                    }
                }
            }
            mp.clear();

            for(int i=k ; i<k+3 ; i++){    
                for(int j=6 ; j<=8 ; j++){
                    if(board[i][j] != '.'){
                        mp[board[i][j]]++ ;
                    }
                    if(mp[board[i][j]] > 1){
                        return false;
                    }
                }
            }
            mp.clear();
            k = k + 3;
        }
        return true;
    }
};