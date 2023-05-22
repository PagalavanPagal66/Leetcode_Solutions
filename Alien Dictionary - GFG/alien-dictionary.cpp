//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void addEdge(vector<int> adj[], string s, string t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length() && s[i] == t[j]) {
            i++;
            j++;
        }
        if (i < s.length() && j < t.length()) {
            adj[s[i] - 'a'].push_back(t[j] - 'a');
        }
    }
    
    void topologicalSortUtil(int v, vector<int> adj[], vector<bool>& visited, stack<int>& s) {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            if (!visited[u]) {
                topologicalSortUtil(u, adj, visited, s);
            }
        }
        s.push(v);
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++) {
            addEdge(adj, dict[i], dict[i + 1]);
        }
        vector<bool> visited(K, false);
        stack<int> s;
        for (int i = 0; i < K; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, adj, visited, s);
            }
        }
        string ans = "";
        while (!s.empty()) {
            ans += (char)(s.top() + 'a');
            s.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends