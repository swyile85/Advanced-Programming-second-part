#include "FilesFunc.hpp"
using namespace std;

int lengthOfFile(string fileName) {
    int counter = 0;
    string s;
    ifstream inputFile(fileName);
    while (!inputFile.eof()) {
        getline(inputFile, s);
        if (!s.empty()) {
            counter++;
        }
    }
    inputFile.close();
    return counter;
}

Iris* readFile(string fileName)
{
    const char comma = ',';
    int amountOfIrises = lengthOfFile(fileName);
    Iris* irises = new Iris[amountOfIrises];
    string str;
    double cupLength, cupWidth, petalLength, petalWidth;
    int counter = 0;
    ifstream inputFile(fileName);
    while (!inputFile.eof()) {
        getline(inputFile, str);
        if (!str.empty()) {
            irises[counter++].setWithString(str, comma);
        }
    }
    inputFile.close();
    return irises;
}

void toFile(string fileName, double(Iris::* distanceFunc)(Iris),
    Iris* classifiedIrises, int numOfClassified, Iris* unClassifiedIrises,
    int numOfUnClassified, int k)
{
    ofstream output;
    output.open(fileName);
    for (int i = 0; i < numOfUnClassified; i++) {
        output << (unClassifiedIrises[i].classify(classifiedIrises, k,
            numOfClassified, distanceFunc)) << endl;
    }
    output.close();
}

string fileToString(string fileName) {
    string str;
    string irisesString = "";
    ifstream inputFile(fileName);
    if (inputFile.eof()) {
        return irisesString;
    }
    getline(inputFile, str);
    irisesString = irisesString.append(str);
    while (!inputFile.eof()) {
        getline(inputFile, str);
        if (!str.empty()) {
            irisesString = irisesString.append(" ");
            irisesString = irisesString.append(str);
        }
    }
    inputFile.close();
    return irisesString;
}

void typesToFile(string types, string fileName) {
    ofstream output;
    output.open(fileName);
    int i, j = 0, counter = 0;
	const char comma = ' ';
	while ((i = data.find(comma, j)) != -1) {
        output << data.substr(j, i - j) << endl;
        counter++;
	}
    output.close();
}