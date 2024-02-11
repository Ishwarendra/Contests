class HashTable:
    def __init__(self):
        self.MAX = 5
        self.arr = [None for i in range(self.MAX)]

    def get_hash(self, key):
        h = 0
        for char in key:
            h += ord(char)
        return (h % self.MAX)

    def get_prob_range(self, index):
        return [*range(index, len(self.arr))] + [*range(0, index)]

    def __getitem__(self, key):
        h = self.get_hash(key)
        if self.arr[h] is None:
            return
        prob_range = self.get_prob_range(h)
        for prob_index in prob_range:
            element = self.arr[prob_index]
            if element is None:
                return None
            if element[0] == key:
                return element[1]

    def __setitem__(self, key, value):
        h = self. get_hash(key)
        prob_range = self.get_prob_range(h)
        for prob_index in prob_range:
            if self.arr[prob_index] is None:
                self.arr[prob_index] = (key, value)
                return

        if self.arr[prob_index][0] == key:
            self.arr[prob_index] = (key, value)
            return
        
        raise Exception("Hash Map Full")
    
    def __delitem__(self, key):
        h = self.get_hash(key)
        prob_range = self.get_prob_range(h)

        for prob_index in prob_range:
            if self.arr[prob_index][0] == key:
                self.arr[prob_index] = None
                return None

        return 

    
d = HashTable()
# d["march 9"] = 310
d["march 7"] = 320
d["march 8"] = 330
d["march 10"] = 340
d["march 13"] = 56
d["march 11"] = 260

print(d.arr)

    