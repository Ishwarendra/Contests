#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)              \
    for (int _i = (start); _i < (end); _i++) \
        cout << (v[_i]) << " ";              \
    cout << "\n";
#define log(v)                                                \
    for (auto __i = ((v).begin()); __i != ((v).end()); __i++) \
        cout << *(__i) << " ";                                \
    cout << "\n";
#define print(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cout << "\n";                            \
    };

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

int get(int i)
{
    cout << "? " << i << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void solve()
{
    int n;
    cin >> n;
    vi p(n + 1);
    vector<bool> checked(n + 1);

    for (int i = 1; i <= n; i++)
    {
        vi curc;
        if (checked[i])
            continue;
        int x = get(i);
        curc.push_back(x);
        checked[x] = true;

        while (true)
        {
            int tmp = get(i);
            checked[tmp] = true;
            curc.push_back(tmp);
            if (curc.back() == curc[0])
            {
                curc.pop_back();
                break;
            }
        }

        for (int j = 0; j < curc.size(); j++)
        {
            p[curc[j]] = curc[(j + 1) % (curc.size())];
            // print(curc[j], p[curc[j]]);
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << p[i] << " ";
    cout << endl;
    cout.flush();
}

int main()
{
    // FIO;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}