#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

void solve()
{
    // int n; cin >> n;
    vll b(7);
    for(auto &x : b) cin >> x;
    vll a(3);
    a[0] = b[0];
    a[1] = b[1];

    cout << b[0] << " " << b[1] << " ";
    if (a[0] + a[1] == b[2])
        cout << b[3] << "\n";
    else
        cout << b[2] << "\n";
    
    // for(int i = 0; i < 3; i++)
    //     cout << a[i] << " ";
    // cout << "\n";
}

int main()
{
    FIO
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}