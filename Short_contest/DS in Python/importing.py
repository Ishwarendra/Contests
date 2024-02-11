import sys
sys.path.append('C:/Users/ISHWARENDRA/Desktop/RandomQuestion/DS in Python')

from LinkedList import *

node1 = Node("d1")
node2 = Node("d2")
node3 = Node("d3")
node1.setNext(node2)
node2.setNext(node3)

LinkedList.addFirst("wow","a")
print_list(node1)
