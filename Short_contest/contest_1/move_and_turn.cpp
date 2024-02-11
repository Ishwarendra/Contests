#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;


int main()
{
    int n; cin >> n;
    if (n & 1)
        cout << 2*(n/2)*(n/2 + 1);
    else
        cout << (n/2)*(n/2);
    return 0;
}