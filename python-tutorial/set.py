a = [1, 2, 3, 4, 3, 2]
print(a, len(a))
print("creating set from list")
print(set(a), len(set(a)))

print("\n\n\n")
#how to add, remove and check if element is in
Set = set()
for i in range(1, 10):
    Set.add(i)
print("add from 1 to 10")
print(Set, len(Set))

for i in range(5, 15):
    Set.add(i)
print("add from 5 to 15")
print(Set, len(Set))

for i in range(7, 12):
    Set.remove(i)
print("remove from 7 to 12")
print(Set, len(Set))

print("\n\none way")
for i in range(1, 20):
    if i in Set:
        print("Our set contains", i)

print("\n\nthe other way")
for i in Set:
    print("Our set contains", i)

print("\n\n")
first = set(range(1, 5))
second = set(range(3, 8))
print(first, "first")
print(second, "second")
print(first.union(second), "Union")
print(first.intersection(second), "Intersection")
