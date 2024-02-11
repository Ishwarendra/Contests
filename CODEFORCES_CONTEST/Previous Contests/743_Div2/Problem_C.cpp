#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<vi> a;
    for(int i = 0; i < n; i++)
    {
        int k; cin >> k;
        vi tmp;
        for(int i = 0; i < k; i++)
        {
            int x; cin >> x;
            tmp.push_back(x);
        }
        a.push_back(tmp);
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