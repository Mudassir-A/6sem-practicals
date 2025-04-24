class Node:
    def __init__(self, name, children=None, value=None):
        self.name = name
        self.children = children if children is not None else []
        self.value = value


def evaluate(node):
    return node.value


def is_terminal(node):
    return node.value is not None


def get_children(node):
    return node.children


def minimax(node, depth, maximizing_player):
    if depth == 0 or is_terminal(node):
        return evaluate(node)

    if maximizing_player:
        max_eval = float("-inf")
        for child in get_children(node):
            eval = minimax(child, depth - 1, False)
            max_eval = max(max_eval, eval)
        return max_eval
    else:
        min_eval = float("inf")
        for child in get_children(node):
            eval = minimax(child, depth - 1, True)
            min_eval = min(min_eval, eval)
        return min_eval


D = Node("D", value=3)
E = Node("E", value=5)
F = Node("F", value=6)
G = Node("G", value=9)
H = Node("H", value=1)
I = Node("I", value=2)

B = Node("B", children=[D, E, F])
C = Node("C", children=[G, H, I])

A = Node("A", children=[B, C])

# Run Minimax
depth = 3
maximizing_player = True

optimal_value = minimax(A, depth, maximizing_player)
print(f"The optimal value is: {optimal_value}")
