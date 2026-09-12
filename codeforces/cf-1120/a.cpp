#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    // 100000100000
    // 1100000100000 
    // i only care about 10 and 01 pairs
    // 1010... 
    // 110..
    // 101
    int t;
    cin >> t;
    
    while(t--){
        
        int n; 
        cin >> n;
        string s;
        
        cin >> s;
        
        int one = 0, zero = 0;
        
        for(int x = 0; x < n; ++x){ 
            if(s[x] == '0') ++zero;
            else ++one;
        }
        
        if(one >= zero) cout << "Bessie\n";
        else cout << "Elsie\n"; 
    }
}
