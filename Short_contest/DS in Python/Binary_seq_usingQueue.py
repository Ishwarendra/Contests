# print Binary number for decimal number (1 to n)

from collections import deque #pronounced as deck not d-q-q

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

    def front(self):
        return self.buffer[~0]


def generate_binary(n):
    queue = Queue()
    queue.enqueue("1")

    for i in range(n):
        front_num = queue.front()
        print(front_num)
        queue.enqueue(front_num + "0")
        queue.enqueue(front_num + "1")
        # print(queue)
        queue.dequeue()

# generate_binary(10)

        