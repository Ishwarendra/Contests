#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(x...) 1;
#endif

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    auto b = a;
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n && b[i] <= m; ++i) {
      m -= b[i];
      ++ans;
    }
    if (ans != 0 && ans != n && m + b[ans - 1] >= a[ans]) ++ans;
    
    cout << n + 1 - ans << '\n';
  }
}