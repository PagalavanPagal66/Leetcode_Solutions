class Solution {
public:
// struct Node {
// 	Node *links[26];
// 	bool flag = false;
//     int mini_ind = INT_MAX;
//     int mini_len = INT_MAX;
//     int ans_ind = INT_MAX;
// 	bool isend() {
// 		return flag;
// 	}
// 	void setend() {
// 		flag = true;
// 	}
// 	bool containskey(char ch) {
// 		return links[ch - 'a'] != NULL;
// 	}
// 	Node* traverse(char ch) {
// 		return links[ch - 'a'];
// 	}
// 	void add(char ch, Node* node,int ind,int len) {
// 		links[ch - 'a'] = node;
//         if(len<mini_len){
//             mini_len = len;
//             ans_ind = ind;
//             mini_ind = ind;
//         }
//         if(len == mini_len){
//             if(ind<mini_ind){
//                 mini_ind = ind;
//                 ans_ind=ind;
//             }
//         }
// 	}
//     int ans_ret(){
//         return ans_ind;
//     }
// };

// class Trie {
// private:
// 	Node* root;
// public:
// 	Trie() {
// 		root = new Node();
// 	}
// 	void insert(string& str,int ind,int len) {
// 		Node *node = root;
// 		for (int i = 0; i < str.size(); i++) {
// 			if (!node->containskey(str[i])) {
// 				node->add(str[i], new Node(),ind,len);
// 			}
//             //cout<<str[i];
// 			node = node->traverse(str[i]);
// 		}
//         //cout<<endl;
// 		node->setend();
// 	}
// 	bool search(string& str) {
// 		Node *node = root;
// 		for (int i = 0; i < str.length(); i++) {
// 			if (!node->containskey(str[i])) {
// 				return false;
// 			}
// 			node = node->traverse(str[i]);
// 		}
// 		return (node->isend());
// 	}
// 	int startswith(string& prefix) {
// 		Node *node = root;
// 		for (int i = 0; i < prefix.length(); i++) {
// 			if (!node->containskey(prefix[i])) {
// 				return -1;
// 			}
// 			node = node->traverse(prefix[i]);
// 		}
// 		return node->ans_ret();
// 	}
// };
const long long prime = 28;
const long long mod = 1e12+7;
    
    vector<int> stringIndices(vector<string>& wc, vector<string>& q) {
        //int n=wordsContainer.size();
        // Trie trie;
        // for(int i=0;i<n;i++){
        //     reverse(wordsContainer[i].begin(),wordsContainer[i].end());
        //     int curlen = wordsContainer[i].size();
        //     trie.insert(wordsContainer[i],i,curlen);
        // }
        // int m=wordsQuery.size();
        // vector<int>ans(m);
        // int ind=0;
        // for(auto& i:wordsQuery){
        //     reverse(i.begin(),i.end());
        //     ans[ind] = trie.startswith(i);
        //     ind++;
        // }
        // return ans;
        int n=wc.size();
        int m=q.size();
        map<int,pair<int,int>>mp;
        map<int,int>best_len;
        map<int,int>curr_ind;
        int stind=0;
        int mini_len = INT_MAX;
        int mini_len_ind = INT_MAX;
        for(auto& i:wc){
            reverse(i.begin(),i.end());
            int cursize = i.size();
            if(cursize<mini_len){
                mini_len = cursize;
                mini_len_ind = stind;
            }
            long long hashval = 0;
            for(int ind=0;ind<cursize;ind++){
                hashval = (prime*hashval + (i[ind]-'a'+1))%mod;
                //cout<<hashval<<" ";
                if(mp.find(hashval)!=mp.end()){
                    int best = mp[hashval].first;
                    int siz = mp[hashval].second;
                    if(cursize<siz){
                        mp[hashval] = {stind,cursize};
                    }
                } 
                else{
                    mp[hashval] = {stind,cursize};
                }
            }
            stind++;
        }
        
        vector<int>ans(m);
        int ind=0;
        for(auto& i:q){
            reverse(i.begin(),i.end());
            int siz = i.size();
            long long hash=0;
            int f=0;
            for(int in=0;in<siz;in++){
                hash = (prime* hash +(i[in]-'a'+1))%mod;
                if(mp.find(hash)!=mp.end()){
                    ans[ind] = mp[hash].first;
                    f++;
                }
                else{
                    break;
                }
            }
            if(f==0){
                ans[ind] = mini_len_ind;
            }
            ind++;
        }
        return ans;
    }
};