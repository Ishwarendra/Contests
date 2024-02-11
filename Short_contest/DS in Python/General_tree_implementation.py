class TreeNode: 
    # This class doesn't represent a tree but one node of tree 
    def __init__(self, data):
        self.data = data
        self.children = []
        self.parent = None

    def add_child(self, child):
        child.parent = self  # parent of this child is self
        self.children.append(child) # adding child to self object

    def get_level(self):
        level = 0
        p = self.parent
        while p is not None:
            level += 1
            p = p.parent

        return level

    def print_tree(self):
        prefix = "    "*self.get_level() + "|__" if self.parent is not None else ""
        print(prefix + self.data)
        if len(self.children) > 0:
            for child in self.children:
                child.print_tree()



def build_product_tree():
    root = TreeNode("Electronics")

    laptop = TreeNode("Laptop")
    laptop.add_child(TreeNode("Macbook"))
    laptop.add_child(TreeNode("HP"))
    laptop.add_child(TreeNode("Surface"))

    cellphone = TreeNode("Cell Phone")
    cellphone.add_child(TreeNode("iPhone"))
    cellphone.add_child(TreeNode("Google Pixel"))
    cellphone.add_child(TreeNode("Vivo"))

    tv = TreeNode("TV")
    tv.add_child(TreeNode("Samsung"))
    tv.add_child(TreeNode("LG"))

    root.add_child(laptop)
    root.add_child(cellphone)
    root.add_child(tv)

    return root

if __name__ == "__main__":
    root = build_product_tree()
    root.print_tree()
    