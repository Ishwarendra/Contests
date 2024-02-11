from collections import deque #pronounced as deck not d-q-q
import threading, time

class Queue:
    def __init__(self):
        self.buffer = deque() #buffer stores our data
    
    def enqueue(self, val): #adding data at beginning 
        self.buffer.appendleft(val)

    def dequeue(self):
        """return last element (see enqueue carefully and convince yourself that dequeue follows FI"FO" principle)"""
        if len(self.buffer) == 0:
            print("Queue is Empty")
            return 
        return self.buffer.pop()
    
    def size(self):
        return len(self.buffer)

    def is_empty(self):
        return (len(self.buffer) == 0)

food_orders = Queue()

def place_order(orders):
    for order in orders:
        print(f"Placing order: {order}")
        food_orders.enqueue(order)
        time.sleep(0.5)

def serve_orders():
    time.sleep(1)
    while food_orders.size() != 0: 
        order = food_orders.dequeue()
        print(f"Order served: {order}")
        time.sleep(2)



orders = ['pizza','samosa','pasta','biryani','burger']
t1 = threading.Thread(target=place_order, args=(orders,))
t2 = threading.Thread(target=serve_orders, args=())

t1.start(); t2.start()
t1.join(); t2.join()
