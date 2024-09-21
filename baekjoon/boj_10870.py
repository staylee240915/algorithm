global arr;

def fibo (num):
    if arr[num] != -1:
        return arr[num]
    arr[num] = fibo(num-1)+fibo(num-2)
    return arr[num]

n = int(input())
arr = [-1] * (n+2)
arr[0] = 0;
arr[1] = 1;
print(fibo(n))