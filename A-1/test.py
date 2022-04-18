import main

searchParams = ["bfs", "dfs", "iddfs", "astar"]
stateFiles = [("start1.txt", "goal1.txt"), ("start2.txt", "goal2.txt"), ("start3.txt", "goal3.txt")]
for search in searchParams:
    i = 0
    for file in stateFiles:
        main.main([file[0], file[1], search, "out.txt"])
        f = open("out.txt", "r")
        steps = f.readline().split(" ")[0]
        explored = f.readline().split(" ")[0]
        f.close()
        print(search, " test ", str(i), ":\n\tsteps: ", steps, "\texplored: ", explored)
        i += 1
