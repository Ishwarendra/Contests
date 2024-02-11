#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void print(vector<ll> &a)
{
    for(auto i : a)
        cout << i << " ";
    cout << "\n";
}
int get_idx(vector<ll> &a, ll x)
{
    for(int i = 0; i < a.size(); i++)
        if (a[i] == x)
            return i;
}
void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    vector<vi> ans;
    for(ll &x : a) cin >> x;

    for(int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
            continue;
        int j = i - 1;
        while (j >= 0 and a[j] > a[i])
            j--;
        j++; // j has position where a[i] should be inserted
        sort(a.begin() + j, a.begin() + i + 1);
        // print(a);
        ans.push_back({j + 1, i + 1, i - j});
    }

    cout << ans.size() << "\n";

    for(auto i : ans)
    {
        cout << i[0] << " " << i[1] << " " << i[2] << "\n";
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