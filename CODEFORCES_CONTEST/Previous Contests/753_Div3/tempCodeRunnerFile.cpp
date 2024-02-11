#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

bool cmp(const pair<ll, char> &a, const pair<ll, char> &b)
{
    if (a.second != b.second)
        return (a.second == 'B' and b.second == 'R');

    return (a.first < b.first);
}

bool possible(vector<pair<ll, char>> &a, int n)
{
    int count = 1;
    for(int i = 0; i < n; i++)
    {
        if (a[i].second == 'B')
        {
            if (a[i].first >= count)
                count++;
            else
                return false;
        }

        else
        {
            if (a[i].first >= count)
                count++;
            else
                return false;
        }
    }

    return true;
}

void solve()
{
    int n; cin >> n;
    vector<pair<ll, char>> a(n);
    string s;

    for(int i = 0; i < n; i++)
        cin >> a[i].first;
    cin >> s;

    for(int i = 0; i < n; i++)
        a[i].second = s[i];

    sort(a.begin(), a.end(), cmp);

    if (possible(a, n))
        cout << "YES\n";
    else    
        cout << "NO\n";
    
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}