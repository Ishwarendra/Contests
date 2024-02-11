#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

const ll mod = 998244353;

void take_prefix(vector<int> &arr)
{
    for(int i = 1; i < arr.size() - 1; i++)
        arr[i] += arr[i - 1];
}

void gib_back_d(set<int> &m, vector<int> &arr)
{
    for(int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] != 0) 
            m.insert(i);
    }
}

void solve()
{
    int n, k; 
    cin >> n >> k;

    vector<int> s(n + 2); // if s[i] != 0 then that d can be that
    for(int i = 0; i < k; i++)
    {
        int start, end;
        cin >> start >> end;
        s[start]++, s[end + 1]--;
    }
    take_prefix(s);
    set<int> possible_d;
    gib_back_d(possible_d, s);

    vector<ll> dp(n + 1);
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(auto d : possible_d)
        {
            if (i - d <= 0)
                break;
            // if (i == 2)
            //     cout << i << " " << d << "\n";
            dp[i] = (dp[i] + dp[i - d]) % mod;
        }
    }

    // for(auto i : possible_d)
    //     cout << i << " ";
    cout << (dp[n] % mod) << "\n";
}

int main()
{
    FIO
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}