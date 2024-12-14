# To add to cp notes:
- lexicgraphical high (letter by letter)
- trie
    - implementation (build w/ for loop)
- how to model graph questions 
    -> shortest path surprisingly common (e.g. cf 2024 D)
    -> how to combine distances in equation to abstractify -> dist(a, b) + dist(b, c) = dist(a, c) (e.g. dmopc21c9p3)
- xor trie -> specifically to get min/max with query, go the SAME/OPPOSITE WAY
    - if min and mask & queryInt = 0, go 0
    - if min and mask & queryInt = 1, go 1
- get last bit by -x & x -> -x = !x + 1 
    - therefore for all neg & pos pairs, every bit after first 1 is same and every bit before is flipped therefore will never be 1 after &
- bit is just prefix sum, prefix sum has a lot of uses
    - num inversions
    - freq sum (how many elements bigger/smaller)
- how to model subarray/BIT questions
    - given a, find num of subarrays where median >= x (2 median tricks: convert to psa, binary search)
        -> e.g. cf 1486 D -> bin search on median = x, then see if any subarray exsists which has the median
    - given a, find num subarrays where mean >= x
    - can shift BIT if triangle
online query: answer last question before take a new one 
offline query: take all questions in and process all of them and give back all ans
- fracturing search -> each time a decision is made, more decisions/paths open up (usually greedy pq)
    - e.g. ahscc1p5, cheerio1s2
- gcd properties
    - union of two sets = gcd <= gcd of both sets
    - gcd <= min of set
- "set.upper_bound is logn upper_bound(...) is n" -william ma in reference to ccc15s3
    - how to get highest element smaller than wtv/smallest element bigger than wtv
    - how to get how many elements are bigger/smaller than wtv (https://chatgpt.com/c/675bba71-4c38-8006-b125-67088eb9ebe7)
- limited dijkstra (e.g. ccc15s4, leetcode plane ticket thing, ccc23s4)
# To add as an exemplar
- coci06c5p6
- ccc16s3
- cf 2024 D
- xorm
- ccc20s4


There are N flowers arranged in a row. For each i (1 <= i <= N), the height and the beauty of the 
i-th flower from the left is hi and ai, respectively. Here, h1, h2, ..., hN are all distinct.
Taro is pulling out some flowers so that the following condition is met:
The heights of the remaining flowers are monotonically increasing from left to right.
Find the maximum possible sum of the beauties of the remaining flowers.

Restraints:
All values in input are integers.
1 <= N <= 2e5
1 <= hi <= N
h1, h2, ..., hN are all distinct
1 <= ai <= N

Given input:
The first line will contain the integer N.
The next line will contain N integers, hi.
The next line will contain N integers, ai.

Write a c++ program to print the maximum possible sum of the beauties of the remaining flowers.