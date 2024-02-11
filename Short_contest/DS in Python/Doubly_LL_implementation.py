class Node:
    def __init__(self, data = None, next = None, prev = None):
        self.data = data
        self.next = next
        self.prev = prev
    
class doublyLinkedList:
    def __init__(self):
        self.head = None
    
    def insert_at_beginning(self, data):
        if self.head == None:
            node = Node(data, None, None)
            self.head = node
        else:
            node = Node(data, self.head, None)
            self.head.prev = node
            self.head = node
    
    def print_forward(self):
        if self.head is None:
            print("Linked List is empty")
            return
        llstr = ""
        itr = self.head
        while itr:
            llstr += str(itr.data) + "--->"
            itr = itr.next
        print(llstr)

    def get_last(self):
        itr = self.head
        while itr.next is not None:
            itr = itr.next
        return itr

    def print_backward(self):
        last_node = self.get_last()
        if self.head is None:
            print("Linked list is empty")
            return
            
        itr = last_node
        llstr = ""

        while itr is not None:
            llstr += str(itr.data) + "--->"
            itr = itr.prev
        print(llstr)

    def insert_at_end(self, data):
        if self.head is None:
            node = Node(data, None, None)
            self.head = node
            return
        
        last_node = self.get_last()
        node = Node(data, None, last_node)
        last_node.next = node

    def insert_values(self, data_list):
        self.head = None
        for data in data_list:
            self.insert_at_end(data)

    def length(self):
        count = 0
        itr = self.head
        while itr:
            itr = itr.next
            count += 1

        return count

    def remove_at(self, index):
        if (index < 0 or index > self.length()):
            raise Exception("Inavlid Index")

        if index == 0:
            self.head = self.head.next
            return 

        itr = self.head; count = 0
        while itr:
            if count == index - 1:
                itr.next = itr.next.next
                break
            itr = itr.next
            count += 1

    def insert_at(self, index, data):
        if (index < 0 or index >= self.length()):
            raise Exception("Inavlid Index")

        if index == 0:
            self.insert_at_beg
            inning(data)
            return
        
        itr = self.head; count = 0
        while itr:
            if count == index - 1:
                node = Node(data, itr.next, itr)
                itr.next.prev = node 
                itr.next = node
                break
            itr = itr.next
            count += 1

    def insert_after_value(self, data_after, data_to_insert):
        if self.head is None:
            node = Node(data_to_insert, None, None)
            self.head = node
            return

        itr = self.head
        while itr is not None:
            if itr.data == data_after:
                node = Node(data_to_insert, itr.next, itr)
                itr.next.prev = node
                itr.next = node
                break            
            itr = itr.next

    def remove_by_value(self, data_to_remove):
        if self.head is None:
            return
        
        if self.head.data == data_to_remove:
            self.head = self.head.next
            return
        
        itr = self.head.next 
        while itr is not None:
            if itr.data == data_to_remove:
                itr.prev.next = itr.next
                break
            itr = itr.next


dll = doublyLinkedList()
nums = [1,2,3,4,5]
dll.insert_values(nums)
dll.print_forward()
dll.remove_by_value(3)
dll.print_forward()
