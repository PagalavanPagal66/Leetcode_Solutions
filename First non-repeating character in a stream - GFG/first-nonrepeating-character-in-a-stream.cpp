//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
string FirstNonRepeating(string A){
    // Code here
    queue<char> queue_chars;
    long repeataion_array[26]{0};
    string output;
    for(auto c : A)
    {
    repeataion_array[c-'a']++;
    queue_chars.push(c);
    while(!queue_chars.empty())
    {
    if(repeataion_array[queue_chars.front() - 'a'] == 1)
    {
       output.push_back(queue_chars.front()); 
       break;
    }
    else
    {
       queue_chars.pop();
    }
    } 
    if(queue_chars.empty())
    {
      output.push_back('#'); 
    }
    }
    
    return output;
}
 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends