#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int step_count(vi &a, ll &sum, int zeroes)
{
    int steps = 0;
    while (zeroes)
    {
        bool start_from_2 = false;
        if (a[0] != 0)
        {
            sum += 2;
            if (a[0] != 0 and a.back() == 0 and a[1] == 0)
                zeroes -= 2, a[1] = 1, a.back() = 1;
            else if (a.back() == 0)
                zeroes -= 1, a.back() = 1;
            else if (a[1] == 0)
                zeroes -= 1, a[1] = 1, start_from_2 = true;
        }
        int i, n = a.size();
        for (i = 1; i < n - 1;)
        {
            if (start_from_2)
            {
                i++;
                continue;
            }
            if (a[i] != 0)
            {
                sum += 2;

                if (a[i + 1] == 0 and a[i - 1] == 0)
                    zeroes -= 2, a[i + 1] = 1, a[i - 1] = 1, i += 2;

                else if (a[i - 1] == 0)
                    zeroes -= 1, a[i - 1] = 1, i++;

                else if (a[i + 1] == 0)
                    zeroes -= 1, a[i + 1] = 1, i += 2;
            }
        }

        if (a.back() != 0)
        {
            sum += 2;

            if (a[0] == 0 and a[a.size() - 2] == 0)
                zeroes -= 2, a[0] = 1, a[a.size() - 2] = 1;
            else if (a[0] == 0)
                zeroes -= 1, a[0] = 1;
            else if (a[a.size() - 2] == 0)
                zeroes -= 1, a[a.size() - 2] = 1;
        }
        steps++;

        if (zeroes == 0)
            return steps;
    }
    return steps;
}

void solve()
{
    // FIO
    ll n, k;
    cin >> n >> k;

    vi a(n);

    int positive = 0;
    ll sum = 0;
    for (int &x : a)
    {
        cin >> x;
        if (x > 0)
            positive++;
        sum += x;
    }

    if (positive == 0)
        cout << sum << "\n";
    else if (positive == 1)
        cout << sum + 2 * (k - 1) * (k - 1) << "\n";
    else if (positive == n)
        cout << sum + (n * 2 * k) << "\n";
    else
    {
        // int steps = step_count(a, sum, n - positive);
        // sum += (n * 2 * (k - steps));
        // cout << sum << "\n";
    }
}

int main()
{
    // int t = 1;
    // cin >> t;
    // while (t--)
    //     solve();
    vi a{0, 1, 0, 1, 0, 0, 0};
    ll s = 0;
    int z = 4;
    int step = step_count(a, s, z);
    cout << step;
    return 0;
}