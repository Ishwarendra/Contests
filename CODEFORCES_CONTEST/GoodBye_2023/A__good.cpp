#include <iostream>
#include <cstdio>

using namespace std;

void solve() {
    int n, k;
    int sum = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        sum *= x;
    }

    // int to = 7;
    // long long m = INT_MAX + 2147483648 - (to - 1);
    // int m2 = m;
    // sum = m;
    // // while (m2 != -2023)
    // // {
    // //     m++, m2++;

    // // }
    // cout << m << " " << m2 << "\n";
    if (2023 % sum == 0) {
        cout << "YES\n";
        cout << 2023 / sum << " ";
        for (int i = 1; i < k; i++) {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}