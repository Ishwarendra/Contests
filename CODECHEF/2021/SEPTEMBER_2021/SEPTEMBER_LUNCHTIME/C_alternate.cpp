#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int num_of_moves(ll n)
{
    if (n == 0)
        return 0;

    int mask = 1, cnt = 0;
    while((mask & n) == 0)
        cnt++, mask <<= 1;
    
    if (cnt == 0)
        return 1 + num_of_moves(n - 1);
    else
        return 1 + num_of_moves(n >> cnt);
}

int main()
{
    ll n; cin >> n;
    cout << num_of_moves(20);
    cout << ((num_of_moves(n) & 1) ? "Bob\n" : "Alice\n");
    
    return 0;
}