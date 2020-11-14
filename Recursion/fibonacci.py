f = [0] * 1000


def fibonacci(n):
    if(n <= 1):
        f[n] = n
        return f[n]
    if(f[n] == 0):
        f[n] = fibonacci(n-1) + fibonacci(n-2)
    return fibonacci(n-1) + fibonacci(n-2)


print(fibonacci(10))

# 0 to 10
for i in range(11):
    print(fibonacci(i), end=' ')
