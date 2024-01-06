#include<bits/stdc++.h>

using namespace std;


bool check(int x, int y, int m, int n) {
    if(x >= 0 && y >= 0 && x < m && y < n) {
        return true;
    }
    return false;
}


int calculate_time (vector<vector<int>>& grid) {
    int time = 0;
    
    queue<pair<int,int>> q;
    int m = grid.size(), n = grid[0].size();
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }

    int cur_queue_size = q.size(), next_queue_size = 0;

    while (q.size() != 0)
    {
        
        for (int i = 0; i < cur_queue_size; i++)
        {
            pair<int,int> coord = q.front();
            q.pop();
            int x = coord.first, y = coord.second;
            //Checking up, down, left and right
            if (check(x, y, m, n) && check(x-1, y, m, n) && grid[x-1][y] == 1)
            {
                q.push({x-1,y});
                next_queue_size++;
                grid[x-1][y] = 2;
            }
            if (check(x, y, m, n) && check(x+1, y, m, n) && grid[x+1][y] == 1)
            {
                q.push({x+1,y});
                next_queue_size++;
                grid[x+1][y] = 2;
            }
            if (check(x, y, m, n) && check(x, y-1, m, n) && grid[x][y-1] == 1)
            {
                q.push({x,y-1});
                next_queue_size++;
                grid[x][y-1] = 2;
            }
            if (check(x, y, m, n) && check(x, y+1, m, n) && grid[x][y+1] == 1)
            {
                q.push({x,y+1});
                next_queue_size++;
                grid[x][y+1] = 2;
            }
        }
       
        if (next_queue_size == 0)
            break;
        cur_queue_size = next_queue_size;
        next_queue_size = 0;
        time++;

    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return time;
}

int main()
{
    vector<vector<int>> grid {{2,2,0,1}};
    cout << calculate_time(grid) << endl;
    return 0;
}
