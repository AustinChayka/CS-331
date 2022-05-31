import sys
import preProc
import bays

preprocTrainFileOut = "preprocessed_train.txt" 
preprocTestFileOut = "preprocessed_test.txt"

def main(trainingSet, testSet):

    f = open(trainingSet, "r")
    training = f.readlines()
    f.close()
    f = open(testSet, "r")
    test = f.readlines()
    f.close()
    
    print("Pre-processing data...")
    vocab = preProc.buildVocab(training)
    trainingFeatureSet = preProc.buildFeatureSet(training, vocab)
    testFeatureSet = preProc.buildFeatureSet(test, vocab)
    preProc.output(preprocTrainFileOut, trainingFeatureSet, vocab)
    preProc.output(preprocTestFileOut, testFeatureSet, vocab)
    print("\t--> Pre-processing data outputed to: " + preprocTrainFileOut + " and " + preprocTestFileOut)

    print("Calculating naive bays predictions on training data...")
    trainPredAcc = bays.predictCorrect(training, trainingFeatureSet, vocab)
    print("\t--> Accuracy of naive bays on training data: " + str(trainPredAcc))
    print("Calculating naive bays predictions on test data...")
    testPredAcc = bays.predictCorrect(test, trainingFeatureSet, vocab)
    print("\t--> Accuracy of naive bays on test data: " + str(testPredAcc))

    return

if __name__ == "__main__":
    if len(sys.argv) < 3 :
        print("Usage: py main.py <trainingSet.txt> <testSet.txt>")
    else:
        main(sys.argv[1], sys.argv[2])