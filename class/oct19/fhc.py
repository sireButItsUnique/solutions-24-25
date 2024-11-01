from collections import defaultdict

class Node:
    def __init__(self):
        self.children = defaultdict(Node)

def solve():
    t = int(input())
    for idx in range(1, t + 1):
        n = int(input())
        root = Node()
        res = 0
        for _ in range(n):
            s = input().strip()
            cur = root
            tmp = 0
            for i, c in enumerate(s):
                if c not in cur.children:
                    if not tmp:
                        tmp = i + 1
                cur = cur.children[c]
            if not tmp:
                tmp = len(s)
            res += tmp
        print(f"Case #{idx}: {res}")

if __name__ == "__main__":
    solve()