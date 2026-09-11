#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    //n problems
    //e . . . . . . e(wants)
    //there should be atleast 2 easy problems 
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        int easy = 0;
        vector<int>a(n);
        int ans = 0;
        
        for(int x = 0; x < n; ++x){  
            
            cin >> a[x];
            if(a[x] == 0) ++easy;
        }
        
        if(easy < 2){  
            cout << "-1\n";
            continue;
        }
        if(a[0] != 0) ++ans;
        if(a[n - 1] != 0) ++ans;
        
        cout << ans << "\n"; 
        
    }
}
