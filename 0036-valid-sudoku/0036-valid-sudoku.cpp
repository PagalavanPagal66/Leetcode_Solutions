class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> mp;
        
        for(int i=0 ; i<9 ; i++){    
            for(int j=0 ; j<9 ; j++){
                if(board[i][j] != '.'){
                        mp[board[i][j]]++ ;
                    }
                if(mp[board[i][j]] > 1){
                    return false;
                }
            }
            mp.clear();
        }

        for(int i=0 ; i<9 ; i++){ 
            for(int j=0 ; j<9 ; j++){
                if(board[j][i] != '.'){
                        mp[board[j][i]]++ ;
                    }
                if(mp[board[j][i]] > 1){
                    return false;
                }
            }
            mp.clear();
        }
        mp.clear();
        int k = 0;

        while(k < 9){        
            for(int i=k ; i<k+3 ; i++){    
                for(int j=0 ; j<3 ; j++){
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
                for(int j=3 ; j<6 ; j++){
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
                for(int j=6 ; j<9 ; j++){
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