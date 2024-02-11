    #include <bits/stdc++.h>
    using namespace std;

    #define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    using vi = vector<int>;
    using ll = long long;
    using ull = unsigned long long;

    void solve()
    {
        ll a1, a2, a3;
        cin >> a1 >> a2 >> a3;

        ll n = abs(a1 + a3 - 2*a2);
        if ((n) % 3 == 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1 << "\n";
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