class Solution {
public:
    int ans=0;
    int possible(string &s, unordered_map<char, int>& map, vector<int>& score ){
        int sc=0;
        for(char c: s){
            if(map.count(c)){
                if(map[c]>0){
                    sc+=score[c-'a'];
                    map[c]--;
                }else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        return sc;
    }
    void helper(int i, vector<string>& words, vector<int>& score, unordered_map<char, int> map, int val){
        if(i==words.size()){
            ans=max(ans, val);
            return;
        }
        helper(i+1, words, score, map, val);
        
        int s=possible(words[i], map, score);
        if(s>0){
            helper(i+1, words, score, map, val+s);
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> map;
        for(char c: letters){
            map[c]++;
        }
        helper(0,words,score,map, 0);
        return ans;
    }
};