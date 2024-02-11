#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vi a(n);
    
    for(int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    int pos = 1;
    for(int i = 0; i < n/2; i++)
    {
        cout << a[pos] << " " << a[0] << "\n";
        pos++;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}