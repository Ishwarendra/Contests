#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

bool num2(string s)
{
    int cnt = 0;
    for(auto i : s)
    {
        if (i == '2')
            cnt++;
    }

    return (cnt >= 3 or cnt == 0);
}
void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    vector<bool> one_win(n, false);
    // if (n == 2)
    // {
    //     if (s == "11")
    //     {
    //         cout << "YES\n" << "X=\n=X" << "\n";
    //         return;
    //     }
    //     else
    //     {
    //         cout << "NO\n";
    //         return;
    //     }
    // }

    vector<vector<string>> ans(n, vector<string>(n, ""));

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if (i == j){
                ans[i][j] = "X";
                continue;
            }

            else if (s[i] == '1' or s[j] == '1')
                ans[i][j] = "=", ans[j][i] = "=";
            
            else 
            {
                if (one_win[i])
                    ans[i][j] = "-", ans[j][i] = "+", one_win[j] = true;
                else
                    ans[i][j] = "+", ans[j][i] = "-" ,one_win[i] = true;
            }
        }
    }

    if (!num2(s))
    {
        cout << "NO\n";
        return;
    }

    else
    {
        cout << "YES\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << ans[i][j] << "";
            }
            cout << "\n";
        }
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