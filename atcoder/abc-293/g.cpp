#include <bits/stdc++.h>
using namespace std;

struct Query{ 
    int l;
    int r;
    int id;
};

int main() {
	// your code goes here 
    int n, q;
    cin >> n >> q;

    vector<int>a(n);
    int block = sqrt(n);
    vector<Query>queries(q);
    long long ans = 0;
    vector<long long> res(q);

    for(int x = 0; x < n; ++x){ 
        cin >> a[x];
    }

    int bound = *max_element(a.begin(), a.end());
    vector<long long>triplets(bound + 1), freq(bound + 1);

    for(int x = 0; x < q; ++x){ 

        int l, r;
        cin >> l >> r; 
        --l, --r;
        queries[x].l = l;
        queries[x].r = r;
        queries[x].id = x;

    }

    sort(queries.begin(), queries.end(), [&](Query &x, Query &y) {
        if (x.l / block != y.l / block)
            return x.l / block < y.l / block;

        return x.r < y.r;
    }); 

    auto add = [&](int idx) {
        int ncount = ++freq[a[idx]];
    
        ans -= triplets[a[idx]];
        triplets[a[idx]] = (1LL * ncount * (ncount - 1) * (ncount - 2)) / 6;
        ans += triplets[a[idx]];
    };
    
    auto remove = [&](int idx) {
        int ncount = --freq[a[idx]];
    
        ans -= triplets[a[idx]];
        triplets[a[idx]] = (1LL * ncount * (ncount - 1) * (ncount - 2)) / 6;
        ans += triplets[a[idx]];
    };

    int curL = 0, curR = -1;
    for(auto query : queries){ 
        int L = query.l;
        int R = query.r;
    
        while(curL < L){ 
            remove(curL);
            curL++; 
        }
    
        while(curL > L){
            --curL;
            add(curL);
        }
    
        while(curR < R){ 
            ++curR;
            add(curR);
        }
    
        while(curR > R){ 
            remove(curR);
            curR--;
        }
    
        res[query.id] = ans;
    }

    for(auto &x : res) cout << x << "\n";

}
 
//1, 2, 3, 4, 5, 6, 7, 8
//0 1 2 3 4 5 6 7 (L values)
//7, 7 - sqrt, 7 -2*sqrt, 7 - 3qrt 
//(0,0,6) (0,sqrt - 1,7) (1,sqrt,sqrt) (1,2*sqrt - 1,7) (2,2*sqrt,2*sqrt) (2,3*sqrt - 1,7) (3,3*sqrt,3*sqrt) (3,4*sqrt - 1,7) 
//total pointer move for block of size sqrt is L + R = sqrt + N 
//for all blocks, this will be O(sqrt*(sqrt + N))
//that is not correct 
//Actually, R is increasing 
//So R movement is fixed by N per block
//For the L movement : 
//Lets say R1 <= R2 < R3 <= R4 < R5 ...(for one block) 
//When we move from R2 to R3, we have L3 but L4 can be 1 which is less than L3 so L needs to move backwards
//so total movement per query is difference between adjacent L
//abs(L1 - L2) + abs(L2 - L3) + .... 
//worst case = number_of_queries*sqrt 
//total sum = Q*sqrt 
//TC : (Q*sqrt + N*sqrt)