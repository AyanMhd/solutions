## 1. Result of inserting `0/1` in a binary string

```text
01 + 0 -> 00 (+1)
01 + 1 -> 11 (+1)

10 + 0 -> 00 (+1)
10 + 1 -> 11 (+1)

00 + 0 -> 00 (+1)
00 + 1 -> 01 (+1), 10 (+1), 00 (-1)

11 + 0 -> 10 (+1), 01 (+1), 11 (-1)
11 + 1 -> 11 (+1) 

count(01) = count(10) in a cylic binary string 

##2. Bound on number of disjoint segments when merging different segments
 
 ```text
Start with p = [0, 0] and perform n operations
In each operation, we can merge p with [-x, 1] U [1, x]

What is the maximum number of disjoints segments in p possible?

n + 1 somewhat.