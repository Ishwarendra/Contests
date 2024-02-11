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
    
    int maxi = *max_element(a.begin(), a.end()); 

    // check if max at last or beg
    if (not (a[0] == maxi or a[n - 1] == maxi))
        cout << "-1\n";
    else
    {
        for(int i = n - 1; i >= 0; i--)
            cout << a[i] << " ";
        cout << "\n";
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