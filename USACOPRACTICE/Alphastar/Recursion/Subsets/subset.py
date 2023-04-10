import sys
def powerset(seq):
  if len(seq) == 0:
    return [[]]
  else:
    p = powerset(seq[1:])
    return [[seq[0]]+c for c in p] + p
n=int(input())
s= input().strip()
s=''.join(s.split())
print(s)
a=powerset(s)

a=sorted(a, key = lambda ele : len(ele))
print(a)
for i in a:
  if ''.join(i)=="":
    continue
  print(''.join(i))

