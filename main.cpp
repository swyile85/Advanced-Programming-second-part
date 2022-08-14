#include "FilesFunc.hpp"
#include "Iris.hpp"

int main(int argc, char** argv) {
	const string classifiedFileName = "classified.csv",
	//here the path of the classified file
		unClassifiedFilename = "Unclassified.csv";
	//here the class of the un-classified file
	int k = stoi(argv[1]), numOfClassified = lengthOfFile(classifiedFileName),
		numOfUnClassified = lengthOfFile(unClassifiedFilename);
	string outputs[] = { "euclidean_output.csv", 
	//the path that you want for the euclidean-output.
		"chebyshev_output.csv",
	//the path that you want for the chbyshev-output.
		"manhattan_output.csv" };
	//the path that you want for the manhattan-output.
	Iris* classifiedIrises = readFile(classifiedFileName);
	Iris* unClassifiedIrises = readFile(unClassifiedFilename);
	toFile(outputs[0], &Iris::euclideanDistance, classifiedIrises,
		numOfClassified, unClassifiedIrises, numOfUnClassified, k);
	toFile(outputs[1], &Iris::chebyshevDistance, classifiedIrises,
		numOfClassified, unClassifiedIrises, numOfUnClassified, k);
	toFile(outputs[2], &Iris::manhattanDistance, classifiedIrises,
		numOfClassified, unClassifiedIrises, numOfUnClassified, k);
	delete[] classifiedIrises;
	delete[] unClassifiedIrises;
	return 0;	
}