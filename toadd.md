https://zoom.us/j/96901529018?pwd=oCgi0F2BNgaM1Ylv07Jn5fX7ejncd9.1

# To add to cp notes:
- **REVISITE GOODE AND FIX SEGTREE** + **TAKE LOOK AT joi05fp5, SAME SEGTREE ISSUES**
- **DO grafftrip**
- binary search trick (oly20practice130 + lunch s3) where you test values on both side: see which is better
    - works if range only has one local min/max -> will reach global max
- for rte/exiting randomly: check how input is taken
- hashmap (#include <ext/pb_ds/assoc_container.hpp>, with using namespace __gnu_pbds; then use like normal unordered_map)
- lexicgraphical high (letter by letter)
- trie
    - implementation (build w/ for loop)
- find nums that avg equal to x = subtract x from arr, should sum up to 0 
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
- weird debugging (out of bounds but doesnt error??) e.g. for (int i = 0; i < n && filled + i < k; i++), must put i < n for some reason
    - brute forced it -> sometimes look at constraints and literally try every value
- use long long! use long long! use long long!
- smarter way of doing directions = have two parallel arrays for dr and dc (d = change in)
- odd 1 vs even 1 xor property (acadia 2 p6)
- topological sort!! (oly24practice26)
- x ^ y = x + y without carru
- trick: brute force to find pattern
- thinking: do constructive instead of cutting (e.g. usaco24decs2, ccc24s4)
- debugging: check i vs j in nested loops
- a ^ a = 0, a ^ a ^ a = a -> parity stuff (e.g. Jan 16 leetcode potd)
- sweep line = sweep across x, y is data structure -> add/remove/query data structure as the thing leaves or enters line ("event points")
- when using segtree for sweep, note that we are concerned with segments between points and not how many points (see joi05fp5)
- check dp transition carefully, rubber duck debug (vpex1p4)
- think the other way, instead of trying all subarrays and counting match try every ai and see how many subarraays make it match (usaco25jans1)
- in a table, infinite swapping rows & cols will always:
    - keep the same numbers in each row & col
    - keep the same number of distinct row & cols
- merge sort is O(n) if u alr have two sorted arrs
- with ad hoc, manually find patterns with paper & WRITE IT OUT -> also have clear variable naming when implementing, write what each variable does since a lot of the time it gets abstracted -> THERES ALWAYS SOME STUPID PATTERN (usaco21jans3)

# To add as an exemplar
- coci06c5p6
- ccc16s3
- cf 2024 D
- xorm
- ccc20s4
- oly19practice60 (why does it work? use paper?)
- oly21practice77
- oly24practice26 (top sort example)
- usaco24decs2 (figure out why bruce works and mine didnt)


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