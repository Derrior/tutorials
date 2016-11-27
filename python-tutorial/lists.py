A = [] # empty array
A = [0] # array with one element
A = [0] * 10 # array with 10 zeros

#look at these functions
A.append(179) # adding value to the end of list
print(A, "A.append(179)")
a = A.pop() # removing value from the end
print(A, "a = A.pop() ")
print(a)
A.append("a")
print(A, "A.append('a')")
A.extend(["b", "c", "d"])
print(A, "A.extend(['b', 'c', 'd'])")
A.append(["b", "c", "d"])
print(A, 'A.append(["b", "c", "d"])')



##Creating multidimensional arrays
print("wrong way")
A = [[0] * 10] * 10 # you want to do it this way, but..
print('\n'.join(map(str, A))) # you can guess, which sense has the word 'join'
A[0][0] = 1 # Pay attention to indexing
print("changing one cell...")
print('\n'.join(map(str, A)))

print("right way")
A = []
for i in range(10): 
    A.append([0] * 10) # it works
print('\n'.join(map(str, A))) # you can guess, which sense has the word 'join'

A[0][0] = 1 # Pay attention to indexing
print("changing one cell...")
print('\n'.join(map(str, A)))
