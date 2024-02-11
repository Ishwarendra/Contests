#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
typedef vector<int> vi;

int main()
{
    FIO

    int t;
    cin >> t;
    while(t--)
    {
        int xa, ya, xf, yf, xb, yb;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;

        int ans = abs(xa - xb) + abs(ya - yb);

    if ((min(xa, xb) <= xf and xf <= max(xa, xb) and yf == ya and ya == yb) or (min(ya, yb) <= yf and yf <= max(ya, yb) and xf == xa and xa == xb))
		cout << (ans + 2) << '\n';
	else
		cout << (ans) << '\n';
    }
    return 0;
}