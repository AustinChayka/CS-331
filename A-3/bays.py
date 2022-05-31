import math
import preProc

def probClassVar(cv, featureSet):
    n = 0
    for feature in featureSet:
        if feature[-1] == cv:
            n = n + 1
    return n / len(featureSet)

def probVarGiveCV(var, cv, featureSet, vocab):
    cCV = 0
    for feature in featureSet:
        if feature[-1] == cv:
            cCV = cCV + 1
    loc = -1
    for i in range(len(vocab)):
        if vocab[i] == var:
            loc = i
            break
    if loc == -1:
        return 1 / len(vocab)
    n = 0
    for feature in featureSet:
        if feature[loc] == 1 and feature[-1] == cv:
            n = n + 1
    return (n + 1) / (cCV + len(vocab))

def logProbArgsGiveCV(args, cv, featureSet, vocab):
    prob = math.log(probClassVar(cv, featureSet))
    for var in args:
        prob = prob + math.log(probVarGiveCV(var, cv, featureSet, vocab))
    return prob

def predictCV(args, featureSet, vocab):
    pCV_T = logProbArgsGiveCV(args, 1, featureSet, vocab)
    pCV_F = logProbArgsGiveCV(args, 0, featureSet, vocab)
    if pCV_T > pCV_F:
        return 1
    else:
        return 0

def predictCorrect(lines, featureSet, vocab):
    correct = 0
    for line in lines:
        line = line.split('\t')
        cv = int(line[1][1])
        args = preProc.simplify(line[0]).split()
        prediction = predictCV(args, featureSet, vocab)
        if prediction == cv:
            correct = correct + 1

    return correct / len(lines)