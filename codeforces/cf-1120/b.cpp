#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) { 
        
        int n, k;
        cin >> n >> k;
        
        vector<vector<int>> ans(n + 1, vector<int>(n + 1));
        
        if(k < n || k == 2*n) { 
            cout << "-1\n";
            continue;
        }
        
        int extra = 2*n - 1 - k;
        
        int val = 1;
        for(int j = 1; j <= n; ++j) {
            for(int i = 1; i <= n; ++i) {
                ans[i][j] = val++;
            }
        }
        
        for(int x = 2; x <= n; ++x) {
            swap(ans[x][1], ans[x][x]);
        }
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }
}