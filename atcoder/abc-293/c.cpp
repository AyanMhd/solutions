#include <bits/stdc++.h>
using namespace std;
int ans = 0;

vector<vector<int>>dir = {{0,1}, {1, 0}}
bool valid(int row, int col){ 
    return row >= 0 && row <= h - 1 && col >= 0 && col <= w - 1;
}

void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){ 
    
    if(vis[grid[row][col]]){ 
        return;
    }
    
    if(row == h - 1 && col == w - 1){ 
        ans++;
    }

    vis[grid[row][col]] = 1;
    for(int x = 0; x < 2; ++x){ 

        int nx = row + dir[x][0];
        int ny = col + dir[x][1];
        
        if(valid(nx, ny)){ 
            dfs(nx, ny, grid, vis);
        }
    }

    vis[grid[row][col]] = 0; //backtrack step
}

int main() {
	// your code goes here
    //there will be atmost 2*10 - 1 = 19 moves
    //every start choice has 2 moves
    //so 2^19 moves
    int h, w;

    cin >> h >> w;

    vector<vector<int>>grid(h, vector<int>(w));
    int m = 0;

    for(int x = 0; x < h; ++x){ 
        for(int y = 0; y < w; ++y){ 
            cin >> grid[x][y];
            m = max(m, grid[x][y]);
        }
    }

    vector<int>vis(m + 1);
    dfs(0, 0, grid[0][0], vis);

    cout << ans << "\n";

}
