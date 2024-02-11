#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;


void solve()
{
    int n; cin >> n;
    vector<int> b(n), p(n), w(n);

    for(int i = 0; i < n; i++) // b -> parent
    {
        cin >> b[i]; b[i]--;
    }
    for(int i = 0; i < n; i++) // p -> permutation
    {
        cin >> p[i]; p[i]--;
    }

    for(int i = 0; i < n; i++)
        w[p[i]] = i; // parents gets lesser value
    
    vector<int> ans(n);

    for(int i = 0; i < n; i++)
    {
        ans[i] = w[i] - w[b[i]];
        // negative weight not allowed as simple path will pass through it's parent
        if (ans[i] < 0)
        {
            cout << "-1\n";
            return;
        } 
    }

    for(int &i : ans)
        cout << i << " ";
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