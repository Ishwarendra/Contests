#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int main()
{
    int n; cin >> n;

    vector<vi> a(n);
    for(int i = 0; i < n; i++)
    {
        int sz; cin >> sz;
        vi c(sz);
        for(int j = 0; j < sz; j++)
            cin >> c[j];
        
        a[i] = c;
    }

    int m; cin >> m;
    set<vi> banned;
    for(int i = 0; i < m; i++)
    {
        vi tmp(n);
        for(int j = 0; j < n; j++)
            cin >> tmp[j];
        
        banned.insert(tmp);
    }

    

    return 0;
}