#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<long long>;
using ll = long long;
#define int long long

bool less_than(vi a, vi b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < b[i])    
            return true;
        if (a[i] > b[i])    
            return false;
    }
    return false;
}

void print_vec(vi a)
{
    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
}
int32_t main()
{
    FIO

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n), b(n);
        // unordered_map<int, vector<int>> m;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        long long maxi = 999999999LL;
        vi idx;
        for(int i = 0; i < n; i++)
        {
            int val = (a[0] + b[i]) % n;
            if (val < maxi)
            {
                maxi = val;
                idx = {i};
            }
            else if (val == maxi)
                idx.push_back(i);
        }

        // vi idx;
        // for(int i = 0; i < n; i++)
        // {
        //     if (maxi == (a[0] + b[i]) % n)
        //         idx.push_back(i);
        // }

        vi ans(n, 999999999LL);
        for(int &p : idx)
        {
            vi tmp;
            for(int i = 0; i < n; i++)
            {
                int j = (p + i) % n;
                tmp.push_back((a[i] + b[j]) % n);
            }

            if (tmp < ans)
                ans = tmp;

        }
        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << '\n';

    }
    return 0;
}