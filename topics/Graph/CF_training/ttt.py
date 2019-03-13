from heapq import *
from functools import reduce
ee = [set() for _ in range(2)]
ee[0].add(1)
ee[0].add(1)
ee[0].add(2)
ee[1].add(1)
a = [0]
heappush(a,2)
heappush(a,1)
print(heappop(a))
print(heappop(a))
print(heappop(a))
b = set()
b.add(1)
b.add(3)
b.add(2)
ids = [1,2,4,3,2,1,3]
func = lambda x,y : x if y in x else x+[y]
tmp = reduce(func,[[],]+ids)
print(tmp)
