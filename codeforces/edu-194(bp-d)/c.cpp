#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    
    cin >> t;
    
    while(t--){  
        long long x, y;
        cin >> x >> y;

        long long ans = x ^ y;
        long long op = 0;

        for(int i = 40; i >= 0; i--) {

            long long pw = (1LL << i);
        
            int xb = (x >> i) & 1;
            int yb = (y >> i) & 1;
        
            // (0,1) or (1,0)
            if(xb != yb)
                continue;
        
            // (0,0)
            if(xb == 0 && yb == 0) {
        
                long long rem = y & (pw - 1);
                long long need = pw - rem;
        
                long long available = x & (pw - 1);
        
                if(available >= need) {
                    x -= need;
                    y += need;
                    op += need;
                    break;
                }
        
                continue;
            }
        
            // (1,1)
            x -= pw;
            y += pw;
            op += pw;
        }
        
        cout << (x^y) << " " << op << '\n';
        
    }
} 

// 100 
//  10  
// 110

//Simpler solution
//x^y = x + y - (x & y) 
//x^y = x + y 
//each bit only in x or 1 
//check the bits of x + y 
//if that bit is set in x, dont remove it else do
