#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n ; string s;
    cin >> n >> s;
    int op = 0;
    vi non_zero;
    for(int i = n - 1; i >= 0; i--)
    {
        if (s[i] - '0' != 0)
            non_zero.push_back(i);
    }

    for(auto i : non_zero)
    {
        if (i == n - 1)
        {
            op += s[i] - '0';
        }
        else
        {
            op += s[i] - '0';
            op++;
        }
    }

    cout << op << endl;

}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}