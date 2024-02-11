#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<string> inp(n - 2);
    for(int i = 0; i < n - 2; i++)
        cin >> inp[i];
    
    string ans;
    for(int i = 0; i < n - 3; i++)
    {
        ans += inp[i][0];
        if (inp[i][1] == inp[i + 1][0])
            continue;
        ans += inp[i][1];
        // cout << ans << "\n";
    }
    ans += inp.back()[0];
    ans += inp.back()[1];
    if (ans.length() < n)
        ans += 'b';
    cout << ans << "\n";
}

int main()
{
    FIO
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}