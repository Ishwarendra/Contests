#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long int;
#define print(a) cout << a << "\n";

int setBit(ll x, int pos)
{
    return (x | (1 << pos));
}

int set_bit_count(ll n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

void solve()
{
    ll n;
    cin >> n;
    vector<long long> a(n), b(n);

    for(ll i = 0; i < n; i++)
        cin >> a[i];

    for(ll i = 0; i < n; i++)
        cin >> b[i];

    ll cur = a[0];
    ll flips1 = 0;
    for(ll i = 1; i < n; i++)
    {
        if (set_bit_count(cur & a[i]) == set_bit_count(cur & b[i]))
        {
            if ((cur & a[i]) >= (cur & b[i]))
                cur = (cur & a[i]);
            else    
            {
                cur = (cur & b[i]);
                flips1++;
            }
        }
        else if (set_bit_count(cur & a[i]) > set_bit_count(cur & b[i]))
            cur = (cur & a[i]);
        else
        {
            cur = (cur & b[i]);
            flips1++;
        }
    }
    ll max1 = cur;

    cur = b[0];
    ll flips2 = 1;

    for(ll i = 1; i < n; i++)
    {
        if (set_bit_count(cur & a[i]) == set_bit_count(cur & b[i]))
        {
            if ((cur & a[i]) >= (cur & b[i]))
                cur = (cur & a[i]);
            else    
            {
                cur = (cur & b[i]);
                flips2++;
            }
        }
        else if (set_bit_count(cur & a[i]) > set_bit_count(cur & b[i]))
           { 
               cur = (cur & a[i]);
           }
        else
        {
            cur = (cur & b[i]);
            flips2++;
        // print(cur)
        }
    }

    ll max2 = cur;

    if (max1 == max2)
    {
        ll flips = min(flips1, flips2);
        cout << max1 << " " << flips << "\n";
    }

    else if (max1 > max2)
    {
        cout << max1 << " " << flips1 << "\n";
    }

    else if (max2 > max1)
    {
        cout << max2 << " " << flips2 << "\n";
    }

}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}