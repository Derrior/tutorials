#function definition
def fibbonachi(n): #the keyword 'def', then function name, then (arguments list):
    if (n <= 2):
        return 1 #if you want to get some result from function, write 'return' and value. If this line is evaluated, 
                 #you leave the function.
    else:
        return fibbonachi(n - 1) + fibbonachi(n - 2)

print("type a number")
n = int(input()) #input value, it's a number
print(fibbonachi(n))

#array = list(map(int, input().split())) how to input an array by one line
print("type a list of numbers, separated by spaces, for example, this line\n1 2 3 4 5")
string = input() #what we have actually got
print(string, "look at it")
first_list = string.split()
print(first_list, "\twe have parsed our line, first space means the end of the first element, and so on")
second_list = list(map(int, first_list))
print(second_list, "\t\tfunction 'map' calls function at first parameter, for each element from second parameter")
print("\t\t\tobject, which we have got, we need to cast to list - name of array class in python3")
#this code is doing the same
second_list = [0] * len(first_list) #creation of an array, which has n elements, 
                                    #where n - amount of elements in the
                                    #first_list, and all elements are equal to 0
for i in range(len(first_list)):
    second_list[i] = int(first_list[i])
#as you can notice, line 13 is much more short, than 23-27
print(second_list)
print("if you want to end it, press q, then Enter")
quit_string = input()
if (quit_string == 'q'):
    print("ok, bye")
    exit(0)


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

print(A[0]) # first element, indexing from 0

print(A[0:2])
print(A[:2])

print(A[-1]) # last element. ~ A[len(A) - 1]

print(A[-2]) # ~ A[len(A) - 2]

print(A[1:3])

print(A[1:-1])
print(A[1:])

A = list(range(10)) # easy way to fill list with the numbers from 0 till 10 (excluding 10)
print(A)
print(A[1::2])
print(A[::2])
print(A[::3])
print(A[::-1]) #third parameter - step


