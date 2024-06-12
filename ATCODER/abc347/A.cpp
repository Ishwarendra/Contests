#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;

        if (a % k == 0)
            std::cout << a / k << " ";
    }
}
