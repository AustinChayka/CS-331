punct = [',', '.', '!', '?', '-', '/', '(', ')']

def processFileByLine(lines, f):
    for line in lines:
        f(line)
    return

def processLineByWord(line, f):
    l = line.split()
    for w in l:
        f(w)
    return

def simplify(line):
    for c in punct:
        line = line.replace(c, ' ')
    return line

def buildVocab(lines):
    vocab = set([])
    for line in lines:
        line = line.split('\t')[0]
        line = simplify(line)
        processLineByWord(line, vocab.add)
    return sorted(vocab)

def buildFeature(line, vocab):
    feature = []
    line = line.split('\t')
    classLabel = int(line[1][1])
    line = simplify(line[0]).split()
    for word in vocab:
        if word in line:
            feature.append(1)
        else:
            feature.append(0)
    feature.append(classLabel)
    return feature

def buildFeatureSet(lines, vocab):
    featureSet = []
    for line in lines:
        featureSet.append(buildFeature(line, vocab))
    return featureSet

def output(file, featureSet, vocab):
    f = open(file, "w")
    for word in vocab:
        f.write(word + ",")
    f.write("classlabel\n")
    for feature in featureSet:
        for i in feature[:-1]:
            f.write(str(i) + ",")
        f.write(str(feature[-1]) + "\n")
    f.close()