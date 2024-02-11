#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

ll gcd(vll &a, bool odd = true)
{
    int id = (odd) ? 1 : 0;
    ll g = 0;
    for(int i = id; i < a.size(); i += 2)
        g = __gcd(g, a[i]);
    return g;
}   

void solve()
{
    int n; cin >> n;
    vll a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    // test odd indexes with even index gcd
    ll g = gcd(a, false);
    bool possible = true;
    for(int i = 1; i < n; i += 2)
    {
        if (a[i] % g == 0)
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        cout << g << "\n";
        return;
    }

    g = gcd(a, true);
    possible = true;
    for(int i = 0; i < n; i+= 2)
    {
        if (a[i] % g == 0)
        {
            possible = false; break;
        }   
    }

    if (possible)
        cout << g << "\n";
    else
        cout << "0\n";

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