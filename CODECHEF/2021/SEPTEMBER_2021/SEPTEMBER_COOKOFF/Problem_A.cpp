#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vi even, odd;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x % 2 != 0)
            odd.push_back(x);
        else
            even.push_back(x);
    }
    int e = even.size(), o = odd.size();
    if (abs(e - o) > 1)
    {
        cout << -1 << endl;
        return;
    }
    else if (odd.size() > even.size())
    {
        for(int i = 0; i < even.size(); i++)
            cout << odd[i] << " " << even[i] << " ";
        
        cout << odd.back() << endl;
        return;
    }

    else if (even.size() > odd.size())
    {
        for(int i = 0; i < odd.size(); i++)
            cout << even[i] << " " << odd[i] << " ";
        
        cout << even.back() << endl;
        return;
    }
    else
    {
        for(int i = 0; i < odd.size(); i++)
            cout << even[i] << " " << odd[i] << " ";
        cout << endl;
        return;
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}