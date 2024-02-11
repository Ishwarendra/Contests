    #include <bits/stdc++.h>
    using namespace std;

    #define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    using vi = vector<int>;
    using ll = long long;

    vector<int> xors(300010);

    void make_xors(vector<int> &xors)
    {
        xors[0] = 0;
        for(int i = 1; i < xors.size(); i++)
        {
            xors[i] = (xors[i - 1] ^ i);
        }
    }

    void solve()
    {
        int a, b;
        cin >> a >> b;

        if (b == xors[a - 1])
        {
            cout << a << "\n";
            return;
        }
        else if(b == xors[a])
        {
            cout << a + 2 << "\n";
            return;
        }

        else
        {
            cout << a + 1<< "\n";
            return;
        }

        cout << a + 1 << "\n";
    }

    int main()
    {
        make_xors(xors);
        ll t; cin >> t;
        while(t--)
            solve();
        return 0;
    }