#include <bits/stdc++.h>
using namespace std;
//5 4
int main() {
    
    int n, q; string s;
    
    cin >> n >> q;
    cin >> s;

    vector<int> pref00(n + 1), pref11(n + 1);
    vector<int> pref10(n + 1), pref01(n + 1);
    
    for (int i = 0; i < n; ++i) {
        pref00[i + 1] = pref00[i];
        pref11[i + 1] = pref11[i];
        pref10[i + 1] = pref10[i];
        pref01[i + 1] = pref01[i];
    
        int j = (i + 1) % n;
    
        if (s[i] == '0' && s[j] == '0') pref00[i + 1]++;
        if (s[i] == '1' && s[j] == '1') pref11[i + 1]++;
        if (s[i] == '1' && s[j] == '0') pref10[i + 1]++;
        if (s[i] == '0' && s[j] == '1') pref01[i + 1]++;
    }
    
    while(q--){  
        
        int l, r;
        cin >> l >> r;
        l--, r--;
        
        int cnt00 = pref00[r] - pref00[l] + (s[r] == '0' && s[l] == '0');
        int cnt11 = pref11[r] - pref11[l] + (s[r] == '1' && s[l] == '1');
        int cnt10 = pref10[r] - pref10[l] + (s[r] == '1' && s[l] == '0');
        int cnt01 = pref01[r] - pref01[l] +(s[r] == '0' && s[l] == '1');
        
        
        if(cnt01 >= max(cnt00, cnt11)){  
            cout << 2*cnt01 - cnt00 - cnt11 << "\n";
        }
        else{  
            
            if(cnt00 < cnt11) swap(cnt00, cnt11);
    
            int ans = 0;
            int a = min((cnt00 - cnt01 + 1)/2, cnt00 - cnt11);
            ans += a;
            cnt00 -= a;
            cnt01 += a;
            if(cnt00 > cnt11){  
                ans += (2*cnt01 - cnt11 - cnt00);
            }
            else{  
                if(cnt01 >= cnt00){  
                    ans += (2*cnt01 - cnt11 - cnt00);
                }
               else{  
                    int lo = 0, hi = cnt00 + cnt11;
                    int extra = hi;
                    while(hi >= lo){  
                        int mid = lo + (hi - lo + 1)/2;
                
                        int ap = cnt01 + 2*mid;
                        int bp = cnt00 - mid;
                        int cp = cnt11 - mid;
                
                        if(ap >= bp && ap >= cp){  
                            hi = mid - 1;
                            extra = min(extra, mid);
                        }
                        else{ 
                            lo = mid + 1;
                        }
                    }
                    
                    cnt01 += 2*extra;
                    ans += 2*extra;
                    cnt00 -= extra;
                    cnt11 -= extra; 
                    
                    if(cnt01 >= cnt00 + 1 && cnt01 >= cnt11 + 2){  
                        cnt01--;
                        cnt11++; //extra op 
                        ans--;
                    }
                    ans += (2*cnt01 - cnt00 - cnt11);
                }
            }
            
            cout << ans << "\n";
        }
    }
} 



// your code goes here
//string s
//00 = 01 = 10 = 11 
//
//insert 0,1 anywhere 
//(01) : 001 - 1 (00)
//(01) : 011 - 1 (11)
//(10) : 100 - 1 (00)
//(10) : 110 - 1 (11)
//(00) : 000 - 1 (00)
//(00) : 010 - 1 (01) & 1 (10) - 1 (00) 
//(11) : 101 - 1 (10) & 1 (01) - 1 (11)
//(11) : 111 - 1 (11) 
//so initially count(10) = count(01) must be satisfied 
//this condition is satisfied for every cyclic string  
//so its true  
//lets say they are x and other 2 are y and z
//if x >= max(y, z) 
//ans = 2*x - y - z 
//if x < max(y, z) 
//if x = 0, its only impossible when 0000... or 1111.. 
//x = 0, 00 = 4, 11 = 4 
//01000 -> 010100 : x = 2, y = 2, z = 0 
//00000-> 010000 -> 0101000 -> 01010100->
//use 2 more operations : 0110100 -> 01110100 x = y = z = 2
//if x > 0 atmost we can increase x by y + z
/*  Binary search approach :
//cnt01 + x, cnt00 - x 
//x >= (cnt00 - cnt01)/2
//x = ceil(cnt00 - cnt01)/2 
//also i have to make sure cnt00 - x >= cnt11 
//x <= (cnt00 - cnt11) 
//therefore make cnt01 = cnt01 + min(cnt00 - cnt11, ceil(..)) 
//after that  
//a' b' c' 
//if b' > c' 
//it means we could had extra operations which we didnt perform
//therefore a' > b' > c' for sure 
//extra op = 2*a' - b' - c' 
//if b' = c' 
//a' can be < b' 
//so now
//a' b' b' 
//if a' >= b' 
//extra op = 2*a' - b' - c'
//else(a' < b') - we need to increase a'
//max op we can perform is 2*b' 
//we try to reduce first from 00 and then 11 and then 00 and so on 
//if we perform x operations on 00 and y on 11  
//a' -> a' + x + y 
//b' -> b' - x 
//c' -> c' - y (b' - y)
//now since we are performing operations alternatively 
//x - y =  1 or 0 (extra operation on 00 since we start from 00)
//if x - y = 0 
//lets calculate final value and check if final a' >= final b' 
//a' = a' + 2x 
//b' = b' - x 
//a' + 2x >= b' - x 
//x >= ceil((b' - a')/3)
//check if condition is satisfied, if it is satisfied, 
//extra op = 2*a' - 2b' 
//else perform next operation on 00 and now a' > c' > b' 
//extra op = 2*a' - 2b'

//a b c
//a' b' c
//0 6 0 
//3 3 0
//if a' >= b' > c..
//op extra = ...
//a' c c  
//apply binary search instead of math
*/
