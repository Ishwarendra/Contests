#include <cassert>
#include <iostream>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    i64 C;
    std::cin >> a >> b >> C;

    i64 X = 0, Y = 0;
    auto getBit = [&](i64 x, int pos) { return x >> pos & 1LL; };

    int extras = 0;
    for (int pos = 0; pos < 60; pos++)
    {
        if (getBit(C, pos))
        {
            if (a > b)
                X |= (1LL << pos), a--;
            else
                Y |= (1LL << pos), b--;
        }
        else
            extras++;
    }

    if (a < 0 || b < 0)
        std::cout << -1;
    else
    {
        for (int pos = 0; pos < 60; pos++)
        {
            if (!getBit(C, pos) and a and b)
                extras--, X |= (1LL << pos), Y |= (1LL << pos), a--, b--;
        }

        if (a == 0 and b == 0)
            std::cout << X << " " << Y;
        else
            std::cout << -1;
    }
}
