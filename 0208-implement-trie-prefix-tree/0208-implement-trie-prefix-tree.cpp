struct Node{
    Node* links[26];
    bool end = false;
    bool isend(){
        return end;
    }
    void endit(){
        end = true;
    }
    Node* traverse(char ch){
        return links[ch-'a'];
    }
    bool isnext(char ch){
        return (links[ch-'a']!=NULL);
    }
    void add(char ch,Node* node){
        links[ch-'a'] = node;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();  
    }
    
    void insert(string word) {
        Node* temp = root;
        for(auto i:word){
            if(!(temp->isnext(i))){
                temp->add(i,new Node());
            }
            temp = temp->traverse(i);
        }
        temp->endit();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto i:word){
            if(!temp->isnext(i)){
                return false;
            }
            temp = temp->traverse(i);
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto i:prefix){
            if(!temp->isnext(i)){
                return false;
            }
            temp = temp->traverse(i);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */