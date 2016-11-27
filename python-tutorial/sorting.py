## standard functions

A = [3, 4, 1, 2, 5]
B = sorted(A)
print(A)
print(B)
A.sort()
print(A)
A = [3, 4, 1, 2, 5]


def my_function(x):
    return -x

print(sorted(A, key=my_function))

print(sorted(A, reverse=True))

def is_odd(x):
    return x % 2 == 1

A = list(range(10)) # easy way to fill list with the numbers from 0 till 10 (excluding 10)
print(sorted(A, key=is_odd))
