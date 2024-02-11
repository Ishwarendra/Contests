#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

vector<int> get_bits(unsigned long long c)
{
    vector<int> res;
    while (c != 0)
    {
        int cur_bit = (c & 1);
        res.push_back(cur_bit);
        c >>= 1;
    }

    return res;
}

bool all_one(vi &a)
{
    for (int i : a)
    {
        if (i == 0)
            return false;
    }
    return true;
}

bool isPowerOfTwo(int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x & (x - 1)));
}

void solve()
{
    unsigned long long c;
    cin >> c;

    if (c == 2)
    {
        cout << "2\n1 3\n";
        return;
    }

    vi bits = get_bits(c);
    int n = bits.size();

    // if all bits-1
    unsigned long long first = 1;
    first = (first << n) - 1;

    if (all_one(bits))
    {
        cout << 1 << "\n"
             << first << "\n";
        return;
    }

    if (isPowerOfTwo(c))
    {
        cout << 2 << "\n";
        cout << first << " " << ((first) >> 1) << "\n";
        return;
    }

    vector<unsigned long long> res;

    res.push_back(first);
    int id = -1;
    for (int j = n - 2; j >= 0; j--)
    {
        if (bits[j] != bits[0])
        {
            id = j;
            break;
        }
    }

    for (int j = id; j >= 0; j--)
    {
        bits[j] = 1 - bits[j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        int cur_bit = bits[i];
        unsigned long long tmp = 1;
        if (cur_bit == 0)
        {
            tmp = (tmp << i) - 1;
            if (tmp == 0)
                tmp++;

            res.push_back(tmp);
            id = -1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (bits[j] != bits[i])
                {
                    id = j;
                    break;
                }
            }

            for (int j = id; j >= 0; j--)
            {
                bits[j] = 1 - bits[j];
            }
        }
    }

    cout << res.size() << "\n";
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    // vi a = get_bits(25);
    // for(auto i : a)
    //     cout << i << " ";
    return 0;
}