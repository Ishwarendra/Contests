#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

using i64 = long long;

const i64 inf = 7e18;

class SparseTable
{
    vector<vector<int>> mat;
    vector<int> p2;

    int power_of_two_less(int n)
    {
        int i = 1, cnt = 0;
        while (i < n)
            i = (i << 1), cnt++;

        return --cnt;
    }

    void build_min(int n, int m, const vector<int> &a)
    {
        mat.resize(n, vector<int>(m, inf));
        // mat[i][j] => min ele in range (i, i + 2^j);

        // Base case when range is of length-1
        for (int i = 0; i < n; i++)
            mat[i][0] = a[i];

        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int start_1 = i;
                int start_2 = i + (1 << (j - 1));

                if (start_2 >= n or 2 * start_2 - i - 1 >= n)
                    break;

                mat[i][j] = min(mat[start_1][j - 1], mat[start_2][j - 1]);
            }
        }
    }

    void build_max(int n, int m, const vector<int> &a)
    {
        mat.resize(n, vector<int>(m, -inf));
        // mat[i][j] => min ele in range (i, i + 2^j);

        // Base case when range is of length-1
        for (int i = 0; i < n; i++)
            mat[i][0] = a[i];

        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int start_1 = i;
                int start_2 = i + (1 << (j - 1));

                if (start_2 >= n or 2 * start_2 - i - 1 >= n)
                    break;

                mat[i][j] = max(mat[start_1][j - 1], mat[start_2][j - 1]);
            }
        }
    }

    void build_sum(int n, int m, const vector<int> &a)
    {
        mat.resize(n, vector<int>(m));
        // mat[i][j] => min ele in range (i, i + 2^j);

        // Base case when range is of length-1
        for (int i = 0; i < n; i++)
            mat[i][0] = a[i];

        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int start_1 = i;
                int start_2 = i + (1 << (j - 1));

                if (start_2 >= n or 2 * start_2 - i - 1 >= n)
                    continue;

                mat[i][j] = mat[start_1][j - 1] + mat[start_2][j - 1];
            }
        }
    }

    

public:
    SparseTable(const vector<int> &a, int mx = 0)
    {
        int n = a.size();
        p2.resize(n + 1);

        for (int i = 1; i <= n; i++)
            p2[i] = p2[i / 2] + 1;

        int m = p2[n] + 1;

        // build_min(n, m, a);
        if (mx)
	        build_max(n, m, a);
	    else
	        build_sum(n, m, a);
    }

    void print_sparse()
    {
        for (int i = 0; i < mat.size(); i++)
        {
            for (int ele : mat[i])
                cout << ele << '\t';
            cout << '\n';
        }
    }

    int range_min(int l, int r)
    {
        int len = p2[r - l + 1];
        len--;

        int start_1 = l;
        int start_2 = r - (1 << len) + 1;

        return min(mat[start_1][len], mat[start_2][len]);
    }

    int range_max(int l, int r)
    {
        int len = p2[r - l + 1];
        len--;

        int start_1 = l;
        int start_2 = r - (1 << len) + 1;

        return max(mat[start_1][len], mat[start_2][len]);
    }

    ll range_sum(int l, int r)
    {
        ll sum = 0LL;
        int n = r - l + 1;
        int start = l;

        while(n != 0)
        {
            int len = p2[n];
            len--;

            sum += mat[start][len];
            
            start += (1 << len);
            n -= (1 << len);
        } 

        return sum;
    }
};


void solve()
{
	int n;
	std::cin >> n;

	std::vector<i64> a(n);

	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	
	SparseTable st(a);
	SparseTable stm(a, 1);
	
	std::vector<int> pos;
	
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			pos.push_back(i);

	
	for (int i = 1; i < pos.size(); i++)
	{
		if (1LL * st.range_sum(pos[i - 1], pos[i]) > 1LL * stm.range_max(pos[i - 1], pos[i]))
		{
			std::cout << "NO\n";
			return;
		}
	}
	
	std::cout << "YES\n"; 
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
}