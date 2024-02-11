#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

// for even prefix (1st, 1st, 2, 2, ..., (n + 1)/2, (n+1)/2)
// for odd prefix last one alone
// for even suffix (last, 2nd last, 2nd last, 3rd last, )
// for odd suffix (last, 2nd l, 2nd l, ... , )

bool all_freq_2(map<int, int> &m)
{
    for (auto i : m)
    {
        if (i.second != 2)
            return false;
    }
    return true;
}

pair<int, set<int>> median(vector<int> &b)
{
    set<int> a;
    for(int i : b)
        a.insert(i);
    
    int pos = 0, n = a.size();
    if (n % 2 == 0)
        pos = (n - 1)/2;
    else 
        pos = n/2;
    int cnt = 0, median_ = -1;
    for(int i : a)
    {
        if (cnt == pos)
        {
            median_ = i;
            break;
        }
        cnt++;
    }

    return {median_, a};
    
}

void solve()
{
    int n;
    cin >> n;
    vector<int> b(2 * n);
    // map<int, int> freq;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> b[i];
        // freq[b[i]]++;
    }
    sort(b.begin(), b.end());
    set<int> a;

    if (n == 1)
    {
        if (b[0] == b[1])
            cout << b[0] << "\n";
        else
            cout << "-1\n";
        return;
    }

    if (b[2 * n - 1] == b[2 * n - 2])
    {
        cout << "-1\n"; // last ele one time
        return;
    }
    else
    {
        pair<int, set<int>> pis = median(b);
        int median = pis.first;
        a = pis.second;
        // int median_count = 0;
        int pos = 0;
        for (int i = 0; i < (2 * n - 1); i = pos)
        {
            if (b[i] == median)
            {
                if (b[i] == b[i + 1] and b[i + 1] == b[i + 2])
                    pos += 3;
                else
                {
                    cout << "-1\n";
                    return;
                }
            }
            else if (b[i] == b[i + 1])
                pos += 2;
            else
            {
                cout << "-1\n";
                return;
            }
        }

        if (a.size() != n)
        {
            cout << "-1\n";
            return;
        }
        for (int i : a)
            cout << i << " ";
        cout << "\n";
    }
    // cout << "-1\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}