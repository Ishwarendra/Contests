#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;


void run_case() {
    int N;
    cin >> N;

    if (N % 7 == 0) {
        cout << N << '\n';
    } else {
        N -= N % 10;

        while (N % 7 != 0){
            N++;
        }

        cout << N << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
