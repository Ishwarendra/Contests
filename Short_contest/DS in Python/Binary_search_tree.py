# BST - 
# In our BST all element in left node will be smaller than Base/Root Node and those at right will be greater than root-node 

class BinarySearchTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    
    def add_child(self, data):
        if (data == self.data):
            return # since BST don't have any duplicate element 
        
        if (data < self.data):
            if self.left is not None:
                # we are not in leaf node so move forward
                self.left.add_child(data) # this will add data only when we reach root node
            else:
                self.left = BinarySearchTreeNode(data)
        
        else:
            if self.right is not None:
                 # we are not in leaf node so move forward
                 self.right.add_child(data)
            else:
                self.right = BinarySearchTreeNode(data)

    def in_order_traversal(self): 
        #return element [left subtree -> node -> right subtree] in this order (recursively)
        #in our case (see Line-2) it is same as ascending order

        elements = []

        #visiting left subtree first
        if self.left:
            elements += self.left.in_order_traversal()

        #visit the Base/Root node
        elements.append(self.data)

        #visit right subtree
        if self.right:
            elements += self.right.in_order_traversal()

        return elements

    def post_order_traversal(self):
        # return element [left -> right -> node] in this order (recursively)
        elements = []    

        # visit left subtree
        if self.left is not None:
            elements += self.left.post_order_traversal()
        
        #visit right subtree
        if self.right is not None:
            elements += self.right.post_order_traversal()
        
        #visit base/root node
        elements.append(self.data)

        return elements

    def pre_order_traversal(self):
        # return elements [node -> left subtree -> right subtree] in this order (recursively)
        elements = []

        #visit node
        elements.append(self.data)

        #visit left subtree
        if self.left:
            elements += self.left.pre_order_traversal()

        #visiting right subtree
        if self.right:
            elements += self.right.pre_order_traversal()

        return elements

    def search(self, val):
        if self.data == val:
            return True

        if (val < self.data): # it might be in left subtree
            if self.left is not None: 
                return self.left.search(val)
            else:
                return False
            
        if (val > self.data): # it might be in right subtree
            if self.left is not None:
                return self.right.search(val)
            else:
                return False

    def find_min(self):
        if self.left is None:
            return self.data
        return self.left.find_min()

    def find_max(self):
        if self.right is None:
            return self.data
        return self.right.find_max() 

    def calc_sum(self):
        left_sum = self.left.calc_sum() if self.left is not None else 0 
        right_sum = self.right.calc_sum() if self.right else 0
        return left_sum + right_sum + self.data

    def delete(self, val):
        # find max ele from right subtree method

        if val < self.data: # go in the left subtree
            if self.left:
                self.left = self.left.delete(val) # recusrively call delete method for left subtree

        elif val > self.data: # go to right subtree
            if self.right:
                self.right = self.right.delete(val)

        else: 
            if self.left is None and self.right is None: #reached a leaf node
                return None
            if self.left is None: #only right-child is present
                return self.right 
            if self.right is None: #only left-child is present
                return self.right

            min_val = self.right.find_min()            
            self.data = min_val
            self.right = self.right.delete(min_val) 

        return self        

    def delete_v1(self, val):
        if val < self.data:
            if self.left:
                self.left = self.left.delete_v1(val)
        
        elif val > self.data:
            if self.right:
                self.right = self.right.delete_v1(val)
        
        else:
            if self.left is None and self.right is None:
                return None
            if self.left is None:
                return self.left
            if self.right is None:
                return self.left

            max_val = self.left.find_max()
            self.data = max_val
            self.left = self.left.delete_v1(max_val)

        return self


# Helper method to help us build a tree
def build_tree(elements):
    root = BinarySearchTreeNode(elements[0])

    for i in range(1, len(elements)):
        root.add_child(elements[i])

    return root

if  __name__ == "__main__":
    numbers = [17, 4, 1, 9, 20, 18, 34, 23] # first element is considered node
    number_tree = build_tree(numbers)   
    print(number_tree.in_order_traversal()) 
    number_tree.delete_v1(34)
    print(number_tree.in_order_traversal())