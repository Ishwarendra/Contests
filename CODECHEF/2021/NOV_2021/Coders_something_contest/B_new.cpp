#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

int longest_path_1(vi &a)
{
    int n = a.size();
    int cur_path = 0, best_path = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            cur_path = 0;
        }
        else
        {
            cur_path++;
            best_path = max(cur_path, best_path);
        }
    }

    return best_path;
}

int longest_path_2(vi &a)
{
    int n = a.size();
    int zero_start = -1, zero_end = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zero_start = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            zero_end = i;
            break;
        }
    }

    int best_path = zero_start + (n - zero_end - 1);
    return best_path;
}

int longest_path(vi &a)
{
    return max(longest_path_1(a), longest_path_2(a));
}

void reduce(vi &a, int k)
{
    for (int i = 0; i < a.size(); i++)
        a[i] -= k;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1)
    {
        cout << a[0] << "\n";
        return;
    }

    int mini = *min_element(a.begin(), a.end());
    ll time = 0;
    reduce(a, mini);
    time += (mini * n);
    // for(int &i : a)
    //     cout << i << " ";
    for (int i : a)
    {
        if (i)
            time++;
    }
    // time += longest_path(a);
    // // cout << longest_path(a) << " ";
    cout << time << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    // vi a {1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1};
    // cout << longest_path_1(a) << " " << longest_path_2(a);
    return 0;
}