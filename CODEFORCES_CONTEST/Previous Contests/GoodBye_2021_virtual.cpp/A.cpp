    #include <bits/stdc++.h>
    using namespace std;

    #define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    #define all(a) ((a).begin()), ((a).end())
    #define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
    #define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
    #define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

    using vi = vector<int>;
    using vll = vector<long long>;
    using ll = long long;
    using ld = long double;

    void err(istream_iterator<string> it){};
    template <typename T, typename... Args>
    void err(istream_iterator<string> it, T a, Args... args)
    {
        cout << a << " ";
        err(++it, args...);
    };

    void solve()
    {
        int n; cin >> n;
        map<int, int> mp, mn;
        int zero = 0;

        for(int i = 0; i < n; i++)
        {
            int x; cin >> x;
            if (x > 0)
                mp[x]++;
            else if (x < 0)
                mn[x]++;
            else    
                zero++;
        }
        
        int ans = 0;
        for(auto pr : mp)
        {
            if (pr.second > 1)
                ans += 2, mn.erase(-pr.first);
            else if (pr.second == 1)
                ans++;
        }

        for(auto pr : mn)
        {
            // Negative ka positive counterparrt doesn't exist if positive had freq >= 2;
            if (pr.second > 1 and mp[-pr.first] == 1)    
                ans++;
            else if (pr.second == 1)
                ans++;
            else if (pr.second > 1 and mp[-pr.first] == 0)
                ans += 2;
        }

        (zero > 0 ? ans++ : ans += 0);

        cout << ans << "\n";
    }

    int main()
    {
        FIO;
        int t = 1;
        cin >> t;
        while(t--)
            solve();
    }