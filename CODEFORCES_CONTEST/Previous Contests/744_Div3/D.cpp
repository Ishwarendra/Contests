#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    // priority_queue<pair<int, int>> mx;                                                  // max-heap
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn; // min-heap

    set<pair<int, int>> mxmn;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            mxmn.emplace(a[i], i + 1);
    }

    vector<pair<int, int>> ans;
    while (true)
    {
        if (mxmn.empty())
            break;

        pair<int, int> p1 = *(mxmn.begin()); // min
        pair<int, int> p2 = *(mxmn.rbegin()); // max

        if (p1 == p2)
            break;

        mxmn.erase(p1); mxmn.erase(p2);
        p1.first--, p2.first--;

        ans.push_back({p1.second, p2.second});

        if (p1.first > 0)
            mxmn.insert(p1);
        if (p2.first > 0)
            mxmn.insert(p2);
    }

    cout << ans.size() << "\n";
    for(auto i : ans)
        cout << i.first << " " << i.second << "\n"; 
}

int main()
{
    FIO
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}