#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

bool is_sorted(string &s)
{
    bool one_start = false;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' and one_start)
            return false;
        if (s[i] == '1')
            one_start = true;
    }
    return true;
}

int zero_from_last(string &s, int start, int end)
{
    for (int i = start; i > end; i--)
    {
        if (s[i] == '0')
            return i;
    }

    return -1;
}

int one_from_last(string &s, int start, int end)
{
    for (int i = start; i > end; i--)
    {
        if (s[i] == '1')
            return i;
    }

    return -1;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (is_sorted(s))
    {
        cout << "0\n";
        return;
    }

    int i = 0, j = n - 1;
    // bool zero_se_nhi_hoga = false;
    vector<int> idx;
    while (i < j)
    {
        if (s[i] == '1')
        {
            int corres_zero = zero_from_last(s, j, i);
            if (corres_zero == -1)
                break;

            idx.push_back(i + 1);
            idx.push_back(j + 1);
        }
        i++, j--;
    }

    sort(idx.begin(), idx.end());
    cout << "1\n";
    for(int i : idx)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}