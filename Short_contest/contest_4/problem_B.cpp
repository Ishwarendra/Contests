#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if (a[0] == 1)
    {   
        cout << n + 1 << " ";   
        for(int i = 1; i <= n; i++)
            cout << i << " "; 
        cout << "\n"; 
        return;
    } 

    if (a[n - 1] == 0)
    {
        for(int i = 1; i <= n + 1; i++)
            cout << i << " ";
        cout << "\n";
        return;
    }

    int good_pos = 0;
    for(int i = 0; i < n; i++)
    {
        if (a[i] == 0 and a[i + 1] == 1)
        {
            good_pos = i;
            break;
        }   
    }

    for(int i = 0; i < n; i++)
    {
        if (i == good_pos)
        {
            cout << i + 1 << " ";
            cout << n + 1 << " ";    
        }
        else
            cout << i + 1 << " ";
    }

    cout << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}