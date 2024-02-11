class Node:
	def __init__(self, data = None, next= None):
		self.data = data;
		self.next = next;

class linkedlist:
	def __init__(self):
		self.head = None
	
	def insert_at_beginning(self, data):
		node = Node(data, self.head) # data + address of head 
		self.head = node

	def print(self):
		if self.head is None:
			print("Linked list is empty")
			return
		itr = self.head #iterator
		llstr = "" #linkedlist string
		while itr:
			llstr += str(itr.data) + "--->"
			itr = itr.next
		print(llstr)

	def insert_at_end(self, data):
		if self.head is None:
			node = Node(data, None) # data + address as None since no element will be after this
			self.head = node
			return
		#if elements are present then go to end then do the next job
		itr = self.head
		while itr.next:
			itr = itr.next
		
		itr.next = Node(data, None)  

	def insert_values(self, data_list):
		self.head = None
		for data in data_list:
			self.insert_at_end(data)

	def len(self):
		count = 0;
		itr = self.head 
		while itr is not None:
			count += 1
			itr = itr.next
		return count

	def remove_at(self, index):
		if (index < 0 or index >= self.len()):
			raise Exception("Inavlid index")

		if index == 0:
			self.head = self.head.next
			return 
		
		count = 0
		itr = self.head 
		while itr:
			if count == index - 1:
				itr.next  = itr.next.next
				break
			itr = itr.next
			count += 1

	def insert_at(self, index, data):
		if (index < 0 or index >= self.len()):
			raise Exception("Invalid index")
		
		if index == 0:
			self.insert_at_beginning(data)
			return
		
		count = 0
		itr = self.head
		while itr is not None:
			if count == index - 1:
				node = Node(data, itr.next)
				itr.next = node
				break
			itr = itr.next
			count += 1

	def insert_after_value(self, data_after, data_to_insert):
		if self.head == None:
			return
		itr = self.head 
		while itr:
			if itr.data == data_after:
				itr.next = Node(data_to_insert, itr.next)
				break
			itr = itr.next

	def remove_by_value(self, data_to_remove):
		if self.head is None:
			return
		if self.head.data == data_to_remove:
			self.head = self.head.next 
			return
		itr = self.head
		while itr.next:
			if itr.next.data == data_to_remove:
				itr.next = itr.next.next
				return
			itr = itr.next
		


if __name__ == '__main__':
	ll = linkedlist()
	ll.insert_values(["banana","mango","grapes","orange","figs"])
	ll.print()
	ll.insert_after_value("orange","apple") # insert apple after mango
	ll.print()
	ll.remove_by_value("orange") # remove orange from linked list
	ll.print()
	ll.remove_by_value("figs")
	ll.print()
	ll.remove_by_value("banana")
	ll.remove_by_value("mango")
	ll.remove_by_value("apple")
	ll.remove_by_value("grapes")
	ll.print()