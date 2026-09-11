/* 
   Can we solve it by applying BS on maxvalue of a?                  
   a -> [-x, -1] U [1, x] (fixed)
   How to check if its valid?

  p0 = [0,0] 
  What is the range of p1? 

  [-x, -1] U [1,x] 

  If p1 > 0 
  [1, x]
  if p1 < 0 
  [-x, -1]
  Else 0(impossible here though)

  Let us conside p1 > 0 -> [1, x]
  
  What about p2?
  [1, x]  - p1
  [-x, -1] U [1, x] - a(fixed)
  [-x + 1, 0] U [2, 2*x] - p2(not yet considered sign)
  
  If p2 > 0
      [2, 2*x] 
      [-x, -1] U [1, x]

      [2 - x, 2*x - 1] U [3, 3*x]

      .....continuing this
      If x >= 2 
      If p3 > 0 
        [3, 3*x]
        [-x, -1] U [3, 3*x]
        [3 - x, 3*x - 1] U [3 + 3*x, 6*x]
 
        [x', y'] U [x'', y'']
This approach doesnt work - the number of disjoint segments can become huge

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(7, INF));

        // p0 = 0
        dp[0][3] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = -3; j <= 3; j++) {
                //current prefix sum
                // j must have the required sign
                if (s[i - 1] == '+' && j <= 0) continue;
                if (s[i - 1] == '-' && j >= 0) continue;
                if (s[i - 1] == '0' && j != 0) continue;

                for (int k = -3; k <= 3; k++) {
                    //previous prefix sum value
                    if (k == j) continue; // a_i != 0
                    if (dp[i - 1][k + 3] == INF) continue; // this state was invalid previously 
                    //else the state was valid
                    dp[i][j + 3] = min(
                        dp[i][j + 3],
                        max(dp[i - 1][k + 3], abs(j - k))
                    );
                }
            }
        }

        cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
    }
} 

//+ -  
//x - 1 + x = 2*x + 1 
//current prefix_sum is = j and index = i 
//for next prefix_sum, there are atmost 7 values 
//and we need to update the answer accordingly
//so if dp[i][j] 
//  -x + 2,... -x ......x(r)

//   difference = 2 and abs(r + x) 
//   difference <= 2 
//   when problem goes like minimise some difference |a - b|, its useful to 
//   to think of bound.
