#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {        
    	
        vector<vector<int>> vis(n, vector<int>(m));
        vector<vector<int>> good(n, vector<int>(m));
        
        for (auto wall : walls)
        	vis[wall[0]][wall[1]] = 1, good[wall[0]][wall[1]] = 1;
        
        for (auto guard : guards)
        	vis[guard[0]][guard[1]] = 1, good[guard[0]][guard[1]] = 1;
        
        auto can_go = [&](int i, int j)
        {
        	return (i >= 0 and j >= 0 and i < n and j < m);		
        };
        
        auto check = [&](int i, int j)
        {
        	int up = i - 1, down = i + 1;
        	
        	// top 
        	while (up >= 0)
        	{
        		if (can_go(up, j))
        		{
        			if (vis[up][j])
        				break;
        			
        			good[up][j] = 1;
        			up--;
        		}
        		else
        			break;
        	}
        	
        	// down 
        	while (down < n)
        	{
        		if (can_go(down, j))
        		{
        			if (vis[down][j])
        				break;
        			
        			good[down][j] = 1;
        			down++;	
        		}
        		else
        			break;
        	}
        	
        	int right = j + 1, left = j - 1;
        	
        	// right
        	while (right < m)
        	{
        		if (can_go(i, right))
        		{
        			if (vis[i][right])
        				break;
        			
        			good[i][right] = 1;
        			right++;
        		}
        		else
        			break;
        	}
        	
        	// left
        	while (left >= 0)
        	{
        		if (can_go(i, left))
        		{
        			if (vis[i][left])
        				break;
        			
        			good[i][left] = 1;
        			left--;
        		}
        		else
        			break;
        	}
        };
        
        for (auto guard : guards)
        	check(guard[0], guard[1]);
        
        int cnt = 0;
        
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; j++)
        	{
        		if (not good[i][j])
        			cnt++;
        	}
        }
        
        return cnt;
    }
};

int main()
{
	
	return 0; 
}    