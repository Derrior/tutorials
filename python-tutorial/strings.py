string = "abacaba"
print(string.find('b'), "| first position of letter b")
print(string.rfind('b'), "| last position of letter b")

print(string[1:-1], "| substring")
print(string * 2, "| double string")
print(string.replace('b', 'd'), "| can replace anything in your string")
print(string.replace('b', "dddd"))
