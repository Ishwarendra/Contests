from collections import deque #pronounced as deck not d-q-q

# We can implement this using list and linked list. 

class Queue:
    def __init__(self):
        self.buffer = deque() #buffer stores our data
    
    def enqueue(self, val): #adding data at beginning 
        self.buffer.appendleft(val)

    def dequeue(self):
        """return last element (see enqueue carefully and convince yourself that dequeue follows FI"FO" principle)"""
        return self.buffer.pop()
    
    def size(self):
        return len(self.buffer)

    def is_empty(self):
        return (len(self.buffer) == 0)

my_queue = Queue()
my_queue.enqueue(3)
my_queue.enqueue(9)
my_queue.enqueue(4)
my_queue.enqueue(8)
print(my_queue.dequeue()) # 3 was inserted first so output should be 3
print(my_queue.dequeue()) # 9 was inserted second to output should be 9