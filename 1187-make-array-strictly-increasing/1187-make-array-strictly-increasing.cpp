#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size(), m = arr2.size();
    int ans = 10000;
    vector<vector<int>> f(n, vector<int>(m + 10, 10000));
    f[0][m] = 0;
    for (int i = 0; i < m; ++i) f[0][i] = i + 1;
    sort(arr2.begin(), arr2.end());
    m = unique(arr2.begin(), arr2.end()) - arr2.begin();

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j != 0) f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        if (arr1[i - 1] < arr2[j]) f[i][j] = min(f[i][j], f[i - 1][m] + 1);
      }
      for (int j = 0; j < m; ++j) {
        if (arr1[i] > arr2[j]) f[i][m] = min(f[i][m], f[i - 1][j]);
      }
      if (arr1[i] > arr1[i - 1]) f[i][m] = min(f[i][m], f[i - 1][m]);
    }
    for (int i = 0; i <= m; ++i) {
      ans = min(ans, f[n - 1][i]);
    }
    if (ans == 10000)
      return -1;
    else
      return ans;
  }
};