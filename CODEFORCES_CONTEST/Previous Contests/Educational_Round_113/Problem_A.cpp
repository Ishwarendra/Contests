#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

bool a_b(string s, int st, int e)
{
    int a = 0, b = 0;
    for(int i = st; i < (e + 1); i++)
    {
        if (s[i] == 'a') a++;
        else if (s[i] == 'b') b++;
    }

    return (a == b);
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if (a_b(s, i, j))
            {
                cout << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
    }

    cout << -1 << " " << - 1 << "\n";
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    // cout << a_b("aaabbba", 0, 5);
    return 0;
}