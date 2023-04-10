c,n = map(int,input().split())
print(c,n)
zero_count = [0]*n
best = [0]*n
for i in range(n):
	cowsss = input()
	zero_count[i]+= cowsss.count("G")
print(zero_count)