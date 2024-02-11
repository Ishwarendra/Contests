#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

char common_char(string &a, string &b, string &c, int p1, int p2, int p3)
{
    unordered_map<char, int> m;
    m[a[p1]]++, m[b[p2]]++, m[c[p3]]++;

    if (m['1'] > m['0'])
        return '1';
    return '0';
}

int exhausted(int p1, int p2, int p3, int n)
{
    if (p1 == n)
        return 1;
    if (p2 == n)
        return 2;
    if (p3 == n)
        return 3;
}

void copy(string &ans, string &a, string &b, int st1, int st2)
{
    if (st1 > st2)
    {
        while(st1 < a.length())
            ans += a[st1++];
    }

    else
    {
        while(st2 < b.length())
            ans += b[st2++];
    }
}

void solve()
{
    int n; cin >> n;
    string a, b, c, ans;
    cin >> a >> b >> c;

    int p1 = 0, p2 = 0, p3 = 0;
    while (p1 < 2*n and p2 < 2*n and p3 < 2*n)
    {
        char common = common_char(a, b, c, p1, p2, p3);
        if (a[p1] == common) p1++;
        if (b[p2] == common) p2++;
        if (c[p3] == common) p3++;

        ans += common;
    }

    int ex = exhausted(p1, p2, p3, n*2);

    if (ex == 1)
        copy(ans, b, c, p2, p3);
    else if (ex == 2)
        copy(ans, a, c, p1, p3);
    else if (ex == 3)
        copy(ans, a, b, p1, p2);

    cout << ans << endl;
 
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}