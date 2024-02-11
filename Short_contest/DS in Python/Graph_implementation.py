# Trees are special type of Graph as in tree, we can have only one path between two node but in case of graph multiple paths are possible between two nodes.

class Graph:
    def __init__(self, edges):
        self.edges = edges
        self.graph_dict = {}
        for start, end in self.edges:
            if start in self.graph_dict:
                self.graph_dict[start].append(end)
            else:
                self.graph_dict[start] = [end]

    def get_paths(self, start, end, path = []):
        path = path + [start]
        if start == end:
            return [path]

        if start not in self.graph_dict:
            return []

        paths = [] 

        for node in self.graph_dict[start]:
            if node not in path:
                new_path = self.get_paths(node, end, path)
                for p in new_path:
                    paths.append(p)            

        return paths 

    def get_shortest_path(self, start, end, path = []):
        path = path + [start]

        if start == end:
            return path
        if start not in self.graph_dict:
            return None

        shortest_path = None

        for node in self.graph_dict:
            if node not in self.path:
                sp = self.get_shortest_path(node, end, path)
                if sp is not None: 
                    if shortest_path is None or len(sp) < len(shortest_path):
                        shortest_path = sp

if __name__ == "__main__":
    routes = [
        ("Mumbai", "Paris"),
        ("Mumbai", "Dubai"),
        ("Paris", "Dubai"),
        ("Paris", "New York"),
        ("Dubai", "New York"),
        ("New York", "Toronto")
    ]

    route_Graph = Graph(routes)

    start = "Mumbai"
    end = "New York"

    print(route_Graph.get_paths(start, end))