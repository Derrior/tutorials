print("type a number")
a = input() # string
print(type(a), a)

b = int(a) # integer
print(type(b), b)

c = list(a) # list ~ array
print(type(c), c) # array of letters

print("type a row of numbers, for example:\n1 2 3")
#array = list(map(int, input().split())) how to input an array by one line
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
#as you can notice, line 13 is much more short, than 21-25
print(second_list)


