//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        int n = wordList.size();
        int m = wordList[0].size();
        set<char> adj[m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                adj[i].insert(wordList[j][i]);
            }
        }
        
        set<string> dict;
        
        for (int i = 0; i < n; i++) {
            dict.insert(wordList[i]);
        }
        
        set<string> currSet;
        string currString = startWord;
        
        currSet.insert(currString);
        queue<pair<string, int>> q;
        q.push({currString, 1});
        
        while(!q.empty()) {
                pair<string, int> p = q.front();
                currString = p.first;
                int l = p.second;
                q.pop();
                currSet.insert(currString);
                if (currString == targetWord) {
                    return l;
                }
                for (int i = 0; i < m; i++) {
                    for (char c : adj[i]) {
                        char temp = currString[i];
                        currString[i] = c;
                        if (dict.find(currString) != dict.end() && currSet.find(currString) == currSet.end() && temp != c) {
                            q.push({currString, l+1});
                        }
                        currString[i] = temp;
                    }
                }
        }
        
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends