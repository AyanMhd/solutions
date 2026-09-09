#include <bits/stdc++.h>
using namespace std;

bool possible(const string& s, long long x) {
    long long L = 0, R = 0;

    for (char c : s) {
        if (c == '+') {
            // We can add [-x,-1] or [1,x].
            // Need resulting prefix > 0.

            long long nL = L - x;
            long long nR = R + x;

            L = max(1LL, nL);
            R = nR;

            if (L > R) // not feasible
                return false;
        }

        else if (c == '-') {
            // Need resulting prefix < 0.

            long long nL = L - x;
            long long nR = R + x;

            L = nL;
            R = min(-1LL, nR);

            if (L > R) // not feasible
                return false;
        }

        else {
            // Need prefix exactly 0.
            // Therefore previous prefix must be nonzero
            // and have absolute value <= x.

            bool ok = false;

            if (L <= -1 && R >= -x)
                ok = true;

            if (L <= x && R >= 1)
                ok = true;

            if (!ok)
                return false;

            L = R = 0;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;
        strin cp = '0' + s;
        
        for(int x = 0; x < n - 1; ++x){   
            
            if(cp[x] == '0' && cp[x + 1] == '0'){ 
                cout << "-1\n";
                continue; 
            } 
            
        }
        
        long long lo = 1, hi = n;

        while (lo < hi) {
            long long mid = (lo + hi) / 2;

            if (possible(s, mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        cout << lo << '\n';
    }
}
// your code goes here
//a1 a2 a3 a4 .... (no element is 0)
//a1 (a1 + a2) (a1 + a2 + a3) (a1 + a2 + a3 + a4) ..... 
//p1 p2 p3 p4 .... 
//if pi > 0 => + 
//if pi < 0 => - 
//if pi = 0 => 0 
//find min value of max(ai) 
//``````````````````````````````````````````````` 
//-4 - 5, -3 - 4, -2 - 3, -1 - 2, 0 - 1, 1 - 1, 2 - 1... (previous sum and current positive)
//ai depends only on pi-1
//if pi-1 < 0 and ai > 0, ai >= abs(pi - 1) + 1 (pi is monotonic increasing as ai increaes)
//if pi - 1 > 0 and ai > 0, ai >= 1(monotonic increasing) 

//if pi - 1 > 0 and ai < 0, if pi - 1 = -1, ai <= -1(sum monotonic increasing) 
//else ai >= [1,abs(pi - 1) - 1] 
//In this case, its optimal to choose min value 1 even though sum remains bigger 
//because if this is last index, its optimal
//in case its not last index, it balances out  
//if pi - 1 > 0 and ai < 0 => ai < -(pi-1 + 1)(sum again monotonic)
//-4 - 1, -3 - 1, -2 - 1, -1 - -1, 0 - -1, 1 - -2, 2 - -3, 3 - -4, ... 
// + - + - + + + - - 0 +  -  +  -  +   -  0  +  -  +   -  -  -  + + + + ... 
//                     1 -2  2 -2  2  -2     1 -2  2  -2 -1 -1  4 1 1 1
//                     2 -3  2 -2  2  -2 
//                     2 -5  4 -4  4  -2 
//               