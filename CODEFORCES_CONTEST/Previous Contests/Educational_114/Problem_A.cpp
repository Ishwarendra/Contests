#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        for (int i = n - j; i > 0; i--)
        {
            cout << "(";
        }
        for (int i = n - j; i > 0; i--)
        {
            cout << ")";
        }
        for (int i = 0; i < j; i++)
        {
            cout << "()";
        }
        cout << "\n";
    }
}


int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}