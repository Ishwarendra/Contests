#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;
using namespace std;

long long getMaximumQuantity(vector<int> power, vector<int> quantity, int maxPower)
{
    int n = size(power);
    if (n == 1)
        return power[0] > maxPower ? 0 : quantity[0];

    auto get = [&](vector<int> &p, vector<int> &w)
    {
        int n = size(p);
        map<int, long long> m;

        for (int mask = 1; mask < (1 << n); mask++)
        {
            long long w_sum = 0;
            long long qty = 0;
            for (int i = 0; i < n; i++)
            {
                if (mask >> i & 1)
                {
                    w_sum += w[i];
                    qty += p[i];
                }
            }


            if (w_sum <= maxPower)
            {
                if (m.count(w_sum))
                    m[w_sum] = max(m[w_sum], qty);
                else
                    m[w_sum] = qty;
            }
        }


        long long max_qty = 0;
        for (auto &[w_sum, qty] : m)
        {
            qty = max(qty, max_qty);
            max_qty = max(max_qty, qty);
        }

        return m;
    };

    auto m = get(quantity, power);
    long long ans = 0;
    for (auto &[_, f] : m)
        ans = std::max(ans, f);

    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, max;
    cin >> n >> max;

    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> q[i];

    cout << getMaximumQuantity(p, q, max);


    return 0;
}