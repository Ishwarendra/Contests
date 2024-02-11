#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

//Gives TLE

bool lessT(string a, string b)
{
    if (a.length() != b.length())
        return (a.length() < b.length());

    for(int i = 0; i < a.length(); i++)
    {
        if ((a[i] - '0') < (b[i] - '0'))
            return true;
        if ((a[i] - '0') > (b[i] - '0'))
            return false;
    }
    return false;
}   

void solve()
{
    char small = '<', big = '>', equal = '=';
    int x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;

    string num1, num2, zero;

    if (p1 > p2)
    {
        p1 -= p2, p2 = 0;
        for (int i = 0; i < p1; i++)
            zero += '0';
        num1 = to_string(x1) + zero;
        num2 = to_string(x2);
    }
    else
    {
        p2 -= p1, p1 = 0;
        for (int i = 0; i < p2; i++)
            zero += '0';
        num2 = to_string(x2) + zero;
        num1 = to_string(x1);
    }
    
    if (lessT(num1, num2))
        cout << "<\n";
    else if (lessT(num2, num1))
        cout << ">\n";
    else
        cout << "=\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}