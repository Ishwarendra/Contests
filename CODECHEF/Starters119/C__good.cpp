#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <typename T = int, class F = std::function<T(const T&, const T&)>>
class SparseTable
{
public:
    const int n;
    std::vector<std::vector<T>> mat;
    F func;
 
    SparseTable(const std::vector<T>& a, const F& f) : n(std::size(a)), func(f)
    {
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++)
        {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++)
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
 
        }
    }
 
    T get(int from, int to) const
    {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get(),
    (uint32_t)__builtin_ia32_rdtsc()
};
std::mt19937 rng(seed);

template<class T = int> 
T get_rand(T l, T r) 
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

void solve()
{
    int n = 6;
    // std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
    {
        // std::cin >> a[i];
        a[i] = get_rand(1, 7);
    }

    print(a)
    SparseTable<int> st(a, [&](int x, int y) { return (x & y); });
    std::vector<int> pxor(n);
    pxor[0] = a[0];
    for (int i = 1; i < n; i++)
        pxor[i] ^= pxor[i - 1] ^ a[i];

    i64 ans = 0;
    std::set<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xr = pxor[j] ^ (i ? pxor[i - 1] : 0);
            if (xr == st.get(i, j))
            {
                ans++;
                print(i, j, xr)
                s.emplace(xr);
            }
        }
    }

    print(s);
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}