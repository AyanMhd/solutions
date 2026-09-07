#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin >> n;

    vector<int>a(n + 1), vis(n + 1), ans;

    for(int x = 0; x < n; ++x) cin >> a[x + 1];

    for(int x = 1; x <= n; ++x){ 

        if(!vis[x]){ 
            vis[a[x]] = 1;
        }

    }

    for(int x = 1; x <= n; ++x){
        if(!vis[x]) ans.push_back(x);
    }

    cout << (int)ans.size() << "\n";
    for(auto &x : ans) cout << x << "\n";
}
