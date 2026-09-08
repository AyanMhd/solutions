#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    //first month x employees & y projects
    //second month x + 1 emloyees & y + 1 projects 
    //in first month, he gets x % y projects
    //second month, he gets (x + 1) % (y + 1) projects
    //ans is y % x + (y + 1) % (x + 1) + (y + 2) % (x + 2) + ...(y + k - 1) % (x + k -1)
    
    //if y < x 
    //y + y + 1 + y + 2 + ...y + k - 1 
    //k*y + k*(k - 1)/2
    //assuming y >= x
    //5 % 3 = 2 
    //6 % 4 = 2 
    //7 % 5 = 2 
    //8 % 6 = 2 
    //9 % 7 = 2 
    //10 % 8 = 2 
    //11 % 9 = 2 
    //12 % 10 = 2 
    
    
    /*  
        7 % 3 = 1           8 % 3 = 2      10 % 3 = 1
        8 % 4 = 0           9 % 4 = 1      11 % 4 = 3
        9 % 5 = 4           10 % 5 = 0     12 % 5 = 2
        10 % 6 = 4          11 % 6 = 5     13 % 6 = 1
        11 % 7 = 4          12 % 7 = 5     14 % 7 = 0
        12 % 8 = 4 
        13 % 9 = 4 
        14 % 10 = 4..
        until (y + 1) / (x + 1) == 1 do that... 
        and then its the same value
    */
    /*  
        3 8 6 
        
        8 % 3 = 2 
        9 % 4 = 1 
        10 % 5 = 0 
        11 % 6 = 5 
        12 % 7 = 5
        13 % 8 = 5
    */
    int t;
    cin >> t;
    
    while(t--){  
        
         long long x, y, k;
         
         cin >> x >> y >> k;
         long long ans = 0;
         
         if(y < x){ 
             
            long long ans = k*y + (k*(k - 1))/2;
            cout << ans << "\n";
            continue;
            
         }
         while(y/x > 1 && k > 0){  
             
             ans += (y % x);
             y++, x++;
             k--;
             
         }  
         
         if(k == 0){ 
             cout << ans << "\n";
         }
         else{ 
             long long rem = y % x;
             ans += rem*k; 
             cout << ans << "\n";
         }  
    }
}   
