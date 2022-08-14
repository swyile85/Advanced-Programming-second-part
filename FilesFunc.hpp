#ifndef FILES_FUNC
#define FILES_FUNC

#include <fstream>
#include <list>
#include "Iris.hpp"

/**
 * @brief This file is responsible for the functions on the files;
 * 
 */

/**
 * @brief This func receives a name of file and returns the amount
 * of lines at the file.
 * 
 * @param fileName (the name of the file).
 * @return int (the length).
 */
int lengthOfFile(string fileName);

/**
 * @brief This func receives a name of file with data about irises and
 * returns a pointer to (an array of) irises with this datas.
 * 
 * @param fileName (the name of the file).
 * @return Iris* (the pointer).
 */
Iris* readFile(string fileName);

/**
 * @brief This func classifyes irises (by KNN) and write into a file
 * the classifyies.
 * 
 * @param fileName (the name of the output file).
 * @param distanceFunc (the distance func for the KNN).
 * @param classifiedIrises (an array of classified irises).
 * @param numOfClassified (as it is).
 * @param unClassifiedIrises (an array of un-classified irises that we
 * want to classify).
 * @param numOfUnClassified (as it is).
 * @param k (the k for the KNN).
 */
void toFile(string fileName, double(Iris::* distanceFunc)(Iris),
    Iris* classifiedIrises, int numOfClassified, Iris* unClassifiedIrises,
    int numOfUnClassified, int k);

#endif // FilesFunc