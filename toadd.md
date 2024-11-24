# To add to cp notes:
- lexicgraphical high (letter by letter)
- gnu hash table
- ENDL IS SLOW ASF USE \n
- trie
    - implementation (build w/ for loop)
- tree diameter
    - start at any node & find
- tree traversal
    - by definition there is only one way to go from a to b in a tree -> dist very easy just dfs
    - to traverse entire tree & return is 2 * node cnt
    - if wish to traverse entire tree from any node, dist = (2 * nodecnt) - diameter
    - if wish to traverse entire tree given root, dist = (2 * nodecnt) - depth
- factorial arithmitic
    - to count factors of n!, div n by k^1, k^2, ..., k^wtv till n/k^wtv is zero
- how to model graph questions 
    -> shortest path surprisingly common (e.g. cf 2024 D)
    -> how to combine distances in equation to abstractify -> dist(a, b) + dist(b, c) = dist(a, c) (e.g. dmopc21c9p3)
- minimum spanning tree w/ dsu -> trees are easy to traverse, + other things
- xor trie -> specifically to get min/max with query, go the SAME/OPPOSITE WAY
    - if min and mask & queryInt = 0, go 0
    - if min and mask & queryInt = 1, go 1
- add template for segtree & fenwick tree
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
- for hashing, DONT USE UNSIGNED, LET IT GO NEG AND THEN ADD MODS (credit kevin lu, see ccc20s3)
    
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