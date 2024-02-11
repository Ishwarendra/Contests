from abc import abstractproperty


class TreeNode: 
    # This class doesn't represent a tree but one node of tree 
    def __init__(self, name, designation): 
        data = (name, designation)
        self.data = data
        self.children = []
        self.parent = None

    def add_child(self, child): #child is TreeNode
        child.parent = self  # parent of this child is self        
        self.children.append(child) # adding child(a tuple) to self object

    def get_level(self):
        level = 0
        p = self.parent
        while p is not None:
            level += 1
            p = p.parent

        return level

    def print_tree(self, get = "both"):
        prefix = "    "*self.get_level() + "|__" if self.parent is not None else ""
        if get == "name":
            val = self.data[0]
        elif get == "designation":
            val = self.data[1]
        else:
            val = f"{self.data[0]} ({self.data[1]})"

        print(prefix + val)

        if len(self.children) > 0:
            for child in self.children:
                child.print_tree(get)


def build_product_tree():
    #CTO hierarchy
    infra_head = TreeNode("Vishwa", "Infrastructure Head")     
    infra_head.add_child(TreeNode("Dhaval", "Cloud Manager"))
    infra_head.add_child(TreeNode("Abhijit", "App Manager"))

    app_head = TreeNode("Aamir", "Application Head")

    cto = TreeNode("Chinmay", "CTO")
    cto.add_child(infra_head)
    cto.add_child(app_head)
    
    # HR Head Hierarchy
    hr_head = TreeNode("Gels", "HR Head")
    hr_head.add_child(TreeNode("Peter", "Recruitment Manager"))
    hr_head.add_child(TreeNode("Waqas", "Policy Manager"))

    root = TreeNode("Niupul", "CEO")
    root.add_child(cto)
    root.add_child(hr_head)

    return root

if __name__ == "__main__":
    root = build_product_tree()
    root.print_tree("bth")
    