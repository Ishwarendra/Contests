#include "bits/stdc++.h"

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int a = 10;
class A
{
public:
    A(int, int = a);
};

A::A(int y, int x)
{
    std::cout << x << std::endl;
}

int main()
{
    A a(1);

    return 0; 
}    