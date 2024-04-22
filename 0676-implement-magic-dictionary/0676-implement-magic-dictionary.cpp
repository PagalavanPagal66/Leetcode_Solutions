class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd = false;
};

class MagicDictionary {
private:
    TrieNode* root;
    void insertWord(string word){
        TrieNode* current = root;
        for(int i = 0; i < word.length(); i++){
            if(current->children[word[i] - 'a'] == NULL){
                current->children[word[i] - 'a'] = new TrieNode();
            }
            current = current->children[word[i] - 'a'];
        }
        current->isEnd = true;
    }

    bool dfs(TrieNode* current, string str, int index, bool isFlipped){
        if(current == NULL){
            return false;
        }
        if(index == str.length()){
            return current->isEnd && isFlipped;
        }
        if(current->children[str[index] - 'a'] == NULL){
            if(isFlipped){
                return false;
            }
            for(int i = 0; i < 26; i++){
                if(dfs(current->children[i], str, index + 1, true)){
                    return true;
                }
            }
            return false;
        }
        else{
            if(dfs(current->children[str[index] - 'a'], str, index + 1, isFlipped)){
                return true;
            }
            if(!isFlipped){
                for(int i = 0; i < 26; i++){
                    if(str[index] - 'a' == i){
                        continue;
                    }
                    if(dfs(current->children[i], str, index + 1, true)){
                        return true;
                    }
                }
            }
            return false;
        }
    }

public:
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word : dictionary){
            insertWord(word);
        }
    }
    
    bool search(string searchWord) {
        return dfs(root, searchWord, 0, false);
    }
};


/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */