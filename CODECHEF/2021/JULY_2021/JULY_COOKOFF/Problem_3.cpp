#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

// bitset<30> a(1023);
// cout << a.count() << '\n';

int getBit(ll x, int pos)
{
    return ((x & (1 << pos)) != 0);
}

ll setBit(ll x, int pos)
{
    return (x | (1 << pos));
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, pos;
        cin >> n;

        vector<ll> a(n);
        vi setbit_count(30);

        for(int i = 0; i < n; i++)
        {
            pos = 0;
            int x; cin >> x;
            a[i] = x;

            while (pos < 30)
            {
                if (getBit(x, pos) == 1) 
                    setbit_count[pos]++; 
                pos++;
            }
        }

        ll num = 0, ans = 0;

        for(int i = 0; i < 30; i++)
        {
            if (setbit_count[i] > 0)
                num = setBit(num, i);
        }


        for(int i = 0; i < n; i++)
            ans |= (a[i] ^ num);

        cout << num << " " << ans << '\n';
    }
    return 0;
}