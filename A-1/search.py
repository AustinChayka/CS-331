def bfs(start, goal, expand):
    frontier = [(start, 0)]
    explored = []
    path = []
    count = 0
    while True:
        if len(frontier) == 0:
            break
        leaf = frontier.pop(len(frontier) - 1)
        if(len(path) <= leaf[1]):
            path.append(leaf[0])
        else:
            path[leaf[1]] = leaf[0]
        if leaf[0] == goal:
            print(count, " nodes explored.")
            return path
        explored.append(leaf[0])
        count += 1
        nextNodes = expand(leaf[0])
        for node in nextNodes:
            if not node in explored and not node in map(lambda a : a[0], frontier):
                frontier.insert(0, (node, leaf[1] + 1))
    print(count, " nodes explored.")
    return path

def dfs(start, goal, expand):
    frontier = [(start, 0)]
    explored = []
    path = []
    count = 0
    while True:
        if len(frontier) == 0:
            break
        leaf = frontier.pop(len(frontier) - 1)
        if(len(path) <= leaf[1]):
            path.append(leaf[0])
        else:
            path[leaf[1]] = leaf[0]
        if leaf[0] == goal:
            print(count, " nodes explored.")
            return path
        explored.append(leaf[0])
        count += 1
        nextNodes = expand(leaf[0])
        for node in nextNodes:
            if not node in explored and not node in map(lambda a : a[0], frontier):
                frontier.append((node, leaf[1] + 1))
    print(count, " nodes explored.")
    return path

def iddfs(start, goal, expand):
    count = 0
    depth = 1
    while True:
        frontier = [(start, 0)]
        explored = []
        path = []
        while True:
            if len(frontier) == 0:
                break
            leaf = frontier.pop(len(frontier) - 1)
            if leaf[1] >= depth:
                break
            if(len(path) <= leaf[1]):
                path.append(leaf[0])
            else:
                path[leaf[1]] = leaf[0]
            if leaf[0] == goal:
                print(count, " nodes explored.")
                return path
            explored.append(leaf[0])
            count += 1
            nextNodes = expand(leaf[0])
            for node in nextNodes:
                if not node in explored and not node in map(lambda a : a[0], frontier):
                    frontier.append((node, leaf[1] + 1))
        depth += 1
