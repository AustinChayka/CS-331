import search
import chickenWolf
import sys

def main(args):

    if len(args) < 4:
        print("ERROR: not enough arguments.")
        return

    f = open(args[0], "r")
    left = f.readline()[:-1].split(",")
    right = f.readline()[:-1].split(",")
    left = list(map(lambda s: int(s), left))
    right = list(map(lambda s: int(s), right))
    start = [left, right]
    f.close()
    f = open(args[1], "r")
    left = f.readline()[:-1].split(",")
    right = f.readline()[:-1].split(",")
    left = list(map(lambda s: int(s), left))
    right = list(map(lambda s: int(s), right))
    goal = [left, right]
    f.close()

    path = []
    if args[2] == "bfs":
        path = search.bfs(start, goal, chickenWolf.expand)
    elif args[2] == "dfs" :
        path = search.dfs(start, goal, chickenWolf.expand)
    elif args[2] == "iddfs":
        path = search.iddfs(start, goal, chickenWolf.expand)
    elif args[2] == "astar":
        path = search.aStar(start, goal, chickenWolf.expand, chickenWolf.h)

    if path == None:
        print("ERROR: no solution found.")
        return
    
    f = open(args[3], "w")
    f.write(str(len(path[1]) - 1) + " steps to goal.\n")
    f.write(str(path[0]) + " nodes explored.\n")
    f.writelines(map(lambda x : str(x) + "\n", path[1]))
    f.close()


if __name__ == "__main__":
    args = sys.argv[1:]
    main(args)