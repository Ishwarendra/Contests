#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;


int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k, cnt = 0;
        cin >> n >> k;
        map<int, vi> m;

        for(int i = 0; i < n; i++)
        {
            int x; cin >> x;
            if (m[x].size() < k)
                m[x].push_back(i), cnt++;
        }

        cnt = (cnt / k);
        vi ans(n);

        for(int i = 0; i < cnt; i++)
        {
            int paint = 0;
            while (paint < k)
            {
                auto itr = m.begin();

                if (itr->second.empty())
                {
                    m.erase(itr);
                    continue;
                }

                paint++;

                ans[itr->second.back()] = paint;
                itr->second.pop_back();
            }
        }

        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';

        cout << '\n';
    }
    return 0;
}