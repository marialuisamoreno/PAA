from collections import defaultdict 
import networkx as nx

G = nx.Graph()

class Node(object):

    def __init__(self, name):
        self.name = name
        self.neighbors = []

    def __repr__(self):
        return self.name

def find_cliques(potential_clique=[], remaining_nodes=[], skip_nodes=[], depth=0):

    # To understand the flow better, uncomment this:
    # print (' ' * depth), 'potential_clique:', potential_clique, 'remaining_nodes:', remaining_nodes, 'skip_nodes:', skip_nodes

    if len(remaining_nodes) == 0 and len(skip_nodes) == 0:
        print ('This is a clique:', potential_clique)
        return

    for node in remaining_nodes:

        # Try adding the node to the current potential_clique to see if we can make it work.
        new_potential_clique = potential_clique + [node]
        new_remaining_nodes = [n for n in remaining_nodes if n in node.neighbors]
        new_skip_list = [n for n in skip_nodes if n in node.neighbors]
        find_cliques(new_potential_clique, new_remaining_nodes, new_skip_list, depth + 1)

        # We're done considering this node.  If there was a way to form a clique with it, we
        # already discovered its maximal clique in the recursive call above.  So, go ahead
        # and remove it from the list of remaining nodes and add it to the skip list.
        remaining_nodes.remove(node)
        skip_nodes.append(node)


# Inserção no formato do site
# Uncommmet later
# linha = input()
# while (linha[0] == 'c'): linha = input()

# if (linha[0] == 'p'): p, col, vertices, arestas = linha.split()

# for i in range(int(arestas)):
#     linha = input()
#     e, vert1, vert2 = linha.split()
#     G.add_edge(vert1, vert2)

#all_nodes = list(G)

# teste:
A = Node('A')
B = Node('B')
C = Node('C')
D = Node('D')
E = Node('E')

A.neighbors = [B, C]
B.neighbors = [A, C]
C.neighbors = [A, B, D]
D.neighbors = [C, E]
E.neighbors = [D]

all_nodes = [A, B, C, D, E]

find_cliques(remaining_nodes=all_nodes)

            
