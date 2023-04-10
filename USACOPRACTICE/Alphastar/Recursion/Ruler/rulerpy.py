def ruler(n):
    if(n==1):return "*"
    return ruler(n-1)+"\n"+n*"*"+"\n"+ruler(n-1)
    #return n*"*"+"\n"+ruler(n-1)+"\n"+n*"*"
p=int(input())
print(p*"*")
print(ruler(p-1))
print(p*"*")
