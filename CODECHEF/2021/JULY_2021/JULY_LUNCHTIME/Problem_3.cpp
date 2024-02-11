#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<long long>;
using ll = long long;


int main()
{
    // int t; cin >> t;
    // while(t--)
    // {
    //     ll n, k, s;
    //     cin >> n >> k >> s;
    //     vi a(n), prefix(n);
        
    //     cin >> a[0];
    //     prefix[0] = a[0];

    //     for(int i = 1; i < n; i++)
    //     {
    //         cin >> a[i];
    //         prefix[i] += (prefix[i - 1] + a[i]);

    //         if (prefix[i] > (k * s))
    //         {
    //             cout << i + 1 << '\n';
    //             break;
    //         }
        // }
    // }

    vi a{1, 2, 3}, b{2, 1, 3};
    cout << (a < b) << ' ' << (a > b) << '\n';
    return 0;
}