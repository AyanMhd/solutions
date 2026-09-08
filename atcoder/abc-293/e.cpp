#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, x, m;
    cin >> a >> x >> m;

    // We want:
    // 1 + A + A^2 + ... + A^(X-1)

    long long sum = 0;       // sum of powers processed so far
    long long power = 1;     // A^(number of terms already in sum)

    // Current block:
    // blockSum   = 1 + A + ... + A^(k-1)
    // blockPower = A^k
    long long blockSum = 1;
    long long blockPower = a % m;

    for (int bit = 0; bit < 60; ++bit) {

        if ((1LL << bit) & x) {
            // Append this block after the terms already in sum.
            sum = (sum + power * blockSum) % m;
            // Shift power by the size of this block.
            power = (power * blockPower) % m;
        }
        // Double the size of the block.
        //
        // S(2k) = S(k) + A^k * S(k)
        //       = S(k) * (1 + A^k)
        //
        blockSum = blockSum * (1 + blockPower) % m;

        // A^(2k)
        blockPower = blockPower * blockPower % m;
    }

    cout << sum << '\n';
}

// your code goes here
//(1 + A + A^2 + ... A^1e12) % mod

//((A^(1e12 + 1) - 1)/(A - 1)) % mod
//(A^c - 1) % mod * ((A - 1)^-1) mod

//(A - 1)^-1 inverse wrt mod is (A - 1, mod - 2) % mod
//a^(2 + 4 + 8) = a^2*a^4*a^8 

//handle the case of when (a - 1) % m == 0  
//=> a % m = 1 
//In this case mod of (a - 1)^-1 wrt m will not exist
//but a^n mod m will be 1 for every n 
//Therefore a^0 + a^1 + ..a^(x - 1) = x 
//This apporach works only works if M is prime and M aint prime this time 


//Method 2 : Square root decomposition 

//1 + A + A^2 + .A^sqrt(x) - 1 + A^sqrt(x)(1 + A^2 + A^3 + ...A^sqrt(x) - 1) + ....