def isValidState(state):
    if state == None:
        return False
    left = state[0]
    right = state[1]
    if left[0] < 0 or left[1] < 0 or right[0] < 0 or right[1] < 0:
        return False
    elif left[2] < 0 or left[2] > 1 or right[2] < 0 or right[2] > 1:
        return False
    else:
        return (left[0] > 0 or left[0] >= left[1]) and (right[0] > 0 or right[0] >= right[1])

def alterState(state, action):
    left = [state[0][0], state[0][1], -1 if state[0][2] == 1 else 1]
    right = [state[1][0], state[1][1], -1 if state[1][2] == 1 else 1]
    if action == 0:
        left[0] += 1 * left[2]
        right[0] += 1 * right[2]
    elif action == 1:
        left[0] += 2 * left[2]
        right[0] += 2 * right[2]
    elif action == 2:
        left[1] += 1 * left[2]
        right[1] += 1 * right[2]
    elif action == 3:
        left[1] += 2 * left[2]
        right[1] += 2 * right[2]
    elif action == 4:
        left[0] += 1 * left[2]
        right[0] += 1 * right[2]
        left[1] += 1 * left[2]
        right[1] += 1 * right[2]
    newState = [[left[0], left[1], 1 if left[2] == 1 else 0], [right[0], right[1], 1 if right[2] == 1 else 0]]
    return newState

def expand(state):
    nextNodes = []
    for i in range(0, 5):
        newState = alterState(state, i)
        if isValidState(newState):
            nextNodes.append(newState)
    return nextNodes

def h(state):
    return (abs(state[0][0] - state[1][0]) + abs(state[0][1] - state[1][1])) / 2