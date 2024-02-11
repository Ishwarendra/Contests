# def get_hash(key):
#     h = 0
#     for char in key:
#         h += ord(char)
#     return (h % 10)

# print(get_hash('march 2'))
# # two key got same has map this means our array size was not sufficient so we have to make a bigger array (worst case)
# print(get_hash('march 10'))
# print(get_hash('march 9'))

class HashTable:
    def __init__(self):
        self.MAX = 10
        self.arr = [[] for i in range(self.MAX)]

    def get_hash(self, key):
        h = 0
        for char in key:
            h += ord(char)
        return (h % self.MAX)

    # def __setitem__(self, key, pair): # t['match 6'] = 130
    # def __getitem__(self, key): #t['match 6'] returns 130 

    def __setitem__(self, key, value):
        h = self.get_hash(key)
        found = False
        for idx, element in enumerate(self.arr):
            if len(element) == 2 and element[0] == key:
                    self.arr[h][idx] = (key, value)
                    found = True
                    break
        if not found:
            self.arr[h].append((key, value))

    def __getitem__(self, key):
        h = self.get_hash(key)
        for element in self.arr[h]:
            if element[0] == key:
                return element[1]

        return None

    def __delitem__(self, key):
        h = self.get_hash(key)
        for index, element in enumerate(self.arr[h]):
            if element[0] == key:
                del self.arr[h][index]
                return
t = HashTable()
# t["hi"] = 34 will override march-6 as (ascii sum % 100) matches for both of them
t["march 17"] = 23
t["march 6"] = 345
print(t["march 17"])
del t["march 17"]
print(t["march 17"])
print(t.arr)
del t["march 6"]