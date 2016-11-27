A = list(range(10)) # easy way to fill list with the numbers from 0 till 10 (excluding 10)

# \t - tab character, to make it pretty
print(A[0], "\t\t\t\tA[0]") # first element, indexing from 0

print(A[0:2], "\t\t\t\tA[0:2]")
print(A[:2], "\t\t\t\tA[:2]")

print(A[-1], "\t\t\t\tA[-1]") # last element. ~ A[len(A) - 1]

print(A[-2], "\t\t\t\tA[-2]") # ~ A[len(A) - 2]

print(A[1:3], "\t\t\t\tA[1:3]") 

print(A[1:-1], "\tA[1:-1]")
print(A[1:], "\tA[1:]")

print(A, "\tA")
print(A[1::2], "\t\tA[1::2]")
print(A[::2], "\t\tA[::2]")
print(A[::3], "\t\t\tA[::3]")
print(A[::-1], "\tA[::-1]") #third parameter - step


