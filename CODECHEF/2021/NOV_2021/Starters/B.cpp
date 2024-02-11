#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> b(n);
    bool not_possible = false;
    cin >> b[0];
    for(int i = 1; i < n; i++)
    {
        cin >> b[i];
        if (b[i - 1] % b[i] != 0)   
            not_possible = true;
    }
    if (not_possible)
    {
        cout << "-1\n";
        return;
    }

    // vector<ll> a(n);
    
    for(int i = 0; i < n; i++)
    {
        cout << b[i] << ' ';
    }       
    cout << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}