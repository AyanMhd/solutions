#include <bits/stdc++.h>
using namespace std;

long long result(int base, int exponent) {  
        
    long long res = 1;
    for(int x = 1; x <= exponent; ++x)
        res *= base;
    
    return res;
}

bool notbigger(long long base, int exponent, long long bound) {   
    // check if base^exponent <= bound
    long long res = 1;

    for(int x = 1; x <= exponent; x++) {  
        
        if(res > bound / base)
            return false;

        res *= base;
    }
    
    return true;
}

int main() {

    // when n is written in base b, every digit is 0 or 1
    // basically for all integers up till 100, we can check manually
    // for > 100:
    // we fix a mask, say 1011
    // and check z^3 + z^1 + z^0 = n
    // there is only a single value of z because this is strictly monotonic
    int t;
    cin >> t;
    
    while(t--){
        long long n;
        cin >> n;
        
        int count = 0;
        
        // Check bases from 2 to 100
        for(int x = 2; x <= 100; ++x) {  
            
            long long ans = 0;
            long long res = 1;
            
            for(int bit = 0; bit <= 60; ++bit) { 
                
                if(res > n / x)
                    break;

                ++ans;
                res *= x;
            }
            
            long long cn = n;
            
            for(int bit = ans; bit >= 0; --bit) {  
                
                long long val = result(x, bit);

                if(cn - val >= 0)
                    cn -= val;
            }
            
            if(cn == 0)
                ++count;
        }
        
        // Check bases > 100
        for(int mask = 1; mask < (1 << 10); ++mask) {  

            long long lo = 101, hi = 1e18;
            
            while(hi >= lo) {  

                long long mid = lo + (hi - lo) / 2;

                // Find largest set bit
                int ls = 0;

                for(int bit = 10; bit >= 0; --bit) {

                    if((1 << bit) & mask) { 
                        ls = bit;
                        break;
                    }
                }

                if(notbigger(mid, ls, n)) {  
                    
                    long long sum = 0;
                    long long res = 1;

                    // No need to calculate powers beyond ls
                    for(int bit = 0; bit <= ls; ++bit) {  
                        
                        if((1 << bit) & mask) {  
                            sum += res;
                        }

                        // Don't calculate the next power after ls
                        if(bit < ls)
                            res *= mid;
                    }
                    
                    if(sum == n) { 
                        ++count;
                        break;
                    }
                    else if(sum > n) {  
                        hi = mid - 1;
                    }
                    else {  
                        lo = mid + 1;
                    }
                }
                else {  
                    hi = mid - 1;
                }
            }
        }
        
        cout << count << "\n";  
    }
} 
/*
    A more simpler solution is as follows : 
    Each base representation with number of bits d(d <= 60) will have only one solution 
    Proof : For d, minimum value = 100000...(d - 1 times 0) = b^d-1, max value = b^d-1 + b^d-2 + ...1 

    Now, lets consider b + 1
    min value in d for this base will be : (b + 1)^d-1 

    (1 + b)^d-1 = 1 + nC(n-1)*b + nc(n - 2)*b^2 + .... + 1*b^d-1 

    Except for d = 2 for which this will be 1 + b < 1 + b + b^2 
        For this case, b = N(10) and b = N - 1(11) are the 2 solutions.
    For d = 1, 1 = 1
    For d >= 3 : 
        1 + 2*b^2 + b > 1 + b + b^2 
    So, they are non overlappping intervals

    So, for a particular d >= 3, only one value of b will be there

    b^d-1 <= N
        Find max b which satisfies it using binary seach for each d
    Then it becomes 0/1 problem for each d

*/