class Solution {
public:
    struct Node{
      Node*links[2];
      bool containsKey(int bit){
          return (links[bit]!=NULL);
      }
      Node * get(int bit){
          return links[bit];      
        }
    void put(int bit , Node *node){
        links[bit] = node;
    }
};
class Trie{
    
private :
    Node * root;
public :
    Trie(){
       root =new Node() ;
    }
public :
    void insert(int num){
        Node * node = root ;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
public : 
    int getMax(int num){
        Node * node = root;
        int maxi =  0;
        for(int i = 31;i >=0 ;i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit)){
                maxi = maxi | (1<<i);
                node = node->get(!bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxi;
    }
    
};
int findMaximumXOR(vector<int>& arr1) {
      Trie trie;
    for(auto &it :arr1){
        trie.insert(it);
    }
    
    int maxim = 0 ;
    for(auto  &it : arr1){
      maxim = max(maxim , trie.getMax(it));
    }
    return maxim;
    }
};