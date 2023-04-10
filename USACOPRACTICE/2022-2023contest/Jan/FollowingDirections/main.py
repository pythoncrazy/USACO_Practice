# This is a sample Python script.
import copy
from functools import lru_cache
# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

from functools import lru_cache
'''

def hash_list(l: list) -> int:
    __hash = 0
    for i, e in enumerate(l):
        __hash = hash((__hash, i, hash_item(e)))
    return __hash


def hash_item(e) -> int:
    if hasattr(e, '__hash__') and callable(e.__hash__):
        try:
            return hash(e)
        except TypeError:
            pass
    if isinstance(e, (list, set, tuple)):
        return hash_list(list(e))
    else:
        raise TypeError(f'unhashable type: {e.__class__}')


def my_lru_cache(*opts, **kwopts):
    def decorator(func):
        def wrapper(*args, **kwargs):
            __hash = hash_item([id(func)] + list(args) + list(kwargs.items()))

            @lru_cache(*opts, **kwopts)
            def cached_func(args_hash):
                return func(*args, **kwargs)

            return cached_func(__hash)

        return wrapper

    return decorator
'''

#@my_lru_cache(maxsize=2**23)
def calc_cost(grid,y_pos,x_pos):
     #print(grid[x_pos][y_pos])
     if grid[y_pos][x_pos][1] == 7:
         return int(grid[y_pos][x_pos][0])
     else:
         if grid[y_pos][x_pos][1] == "R":
             return calc_cost(grid, y_pos,x_pos+1)
         elif grid[y_pos][x_pos][1] == "D":
             return calc_cost(grid, y_pos+1,x_pos)

#@my_lru_cache(maxsize=2**23)
def calc_total_cost():
    ans =0
    for y in range(n):
        for x in range(n):
            z= int((calc_cost(grid,y,x)))
            #print(z)
            ans += z
    return ans

grid=[]
# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    n=int(input())
    cost = [[0 for i in range(n)] for i in range(n)]
    temp = [] #first element is the money that the cell represents, second element is the direction to go in next.
    tempp=[0,0]
    for i in range(n):
        tempp = [0, 0]
        temp = []
        s,a= input().split(" ")
        a = int(a)
        tempstr = list(s)
        for i in range(n):
            tempp[0]=0;
            tempp[1]=tempstr[i]
            temp.append(copy.deepcopy(tempp))
        temp.append([a,7])
        grid.append((temp))
    temp = []
    tempp = [0,0]

    s = input().split(" ")
    for i in s:
        tempp[0]=int(i)
        tempp[1]=7
        temp.append(copy.deepcopy(tempp))
    grid.append(temp)

    ans = calc_total_cost()
    print(ans)
    q = int(input())
    for i in range(q):
        y,x = input().split(" ")
        x= int(x)
        y=int(y)
        x-=1
        y-=1
        #print(grid[y][x])
        if(grid[y][x][1]=="R"):
            grid[y][x][1] = "D"
        elif(grid[y][x][1]=="D"):
            grid[y][x][1] = "R"
        ans=calc_total_cost()
        print(ans)

    #print()
'''print()
print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in grid]))
print()
print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in cost]))
print()
print(ans)'''