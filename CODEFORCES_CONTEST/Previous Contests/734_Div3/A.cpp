#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;


int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n; cin >> n;
        int min_diff = 0;

        if (n % 3 == 0)
            min_diff = 0;
        else if (n % 3 == 1)
            min_diff = -1;
        else    
            min_diff = 1;

        ll coin2 = (n + min_diff)/3;
        ll coin1 = n - 2*coin2;

        cout << coin1 << ' ' << coin2 << '\n';
    }
    return 0;
}