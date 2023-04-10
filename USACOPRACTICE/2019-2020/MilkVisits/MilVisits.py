from collections import defaultdict

n,m=map(int,input().split())
s=input()
milktype=list(s)
print(n,m,milktype)

for i in range(n-1):
    pass

G = {}
# modified BFS
def find_all_parents(G, s):
    Q = [s]
    parents = defaultdict(set)
    while len(Q) != 0:
        v = Q[0]
        Q.pop(0)
        for w in G.get(v, []):
            parents[w].add(v)
            Q.append(w)
    return parents

# recursive path-finding function (assumes that there exists a path in G from a to b)   
def find_all_paths(parents, a, b):
    return [a] if a == b else [y + b for x in list(parents[b]) for y in find_all_paths(parents, a, x)]