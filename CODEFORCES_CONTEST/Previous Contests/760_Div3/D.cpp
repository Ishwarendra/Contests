#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

int just_small(vi &a, int id, vector<bool> &vis)
{
    int n = a.size() - 1;
    for (int i = id - 1; i >= 0; i--)
    {
        if (!vis[i] and a[i] < a[id])
            return i;
    }

    for (int i = id - 1; i >= 0; i--)
    {
        if (not vis[i])
            return i;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);

    int best_sum = 0, best_score = 0;
    for (int &x : a)
    {
        cin >> x;
        best_sum += x;
    }

    sort(all(a));
    int score = 0;

    for(int i = n - 2*k; i < n - k; i++)
    {
        if (a[i] == a[i + k])
            score++;
    }

    for(int i = 0; i < n - 2*k; i++)
        score += a[i];

    cout << score << "\n";
}

int main()
{
    FIO int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}