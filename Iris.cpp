#include "Iris.hpp"

Iris::Iris(double cupLength, double cupWidth
	, double petalLength, double petalWidth, string type)
{
	Iris(cupLength, cupWidth, petalLength, petalWidth);
	m_type = type;
}

Iris::Iris(double cupLength, double cupWidth,
	double petalLength, double petalWidth)
{
	m_cupLength = cupLength;
	m_cupWidth = cupWidth;
	m_petalLength = petalLength;
	m_petalWidth = petalWidth;
}

Iris::Iris()
{
	m_type = "none";
	m_cupLength = 0.0;
	m_cupWidth = 0.0;
	m_petalLength = 0.0;
	m_petalWidth = 0.0;
}

void Iris::set(double cupLength, double cupWidth
	, double petalLength, double petalWidth, string type)
{
	m_type = type;
	m_cupLength = cupLength;
	m_cupWidth = cupWidth;
	m_petalLength = petalLength;
	m_petalWidth = petalWidth;
}

void Iris::setWithString(string data, char comma)
{
	int i, j = 0;
	i = data.find(comma);
	m_cupLength = stod(data.substr(j, i - j));
	j = i + 1;
	i = data.find(comma, j);
	m_cupWidth = stod(data.substr(j, i - j));
	j = i + 1;
	i = data.find(comma, j);
	m_petalLength = stod(data.substr(j, i - j));
	j = i + 1;
	i = data.find(comma, j);
	m_petalWidth = stod(data.substr(j, i - j));
	j = i + 1;
	if (j == 0)
		return;
	i = data.find('\0', j);
	m_type = data.substr(j, i - j);
}

string Iris::type() {
	return m_type;
}

double Iris::cupLength() {
	return m_cupLength;
}

double Iris::cupWidth() {
	return m_cupWidth;
}

double Iris::petalLength() {
	return m_petalLength;
}

double Iris::petalWidth() {
	return m_petalWidth;
}

void Iris::printIris() {
	cout << "cup length: " << m_cupLength << ", cup width: " << m_cupWidth << ", petal length: " << m_petalLength << ", petal width: " << m_petalWidth << ", type: " + m_type << endl;
}

string Iris::classify(Iris* irises, int k, int length, double (Iris::*distanceFunc)(Iris)) {
	double* distances = new double[length];
	int* amountOfType = new int[3];
	for (int m = 0; m < 3; m++) {
		amountOfType[m] = 0;
	}
	int* indexOutOfUse = new int[k];
	int maxIndex = 0;
	bool flag = true;
	for (int i = 0; i < length; i++) {
		distances[i] = (this->*distanceFunc)(irises[i]);
		if (distances[i] > distances[maxIndex]) {
			maxIndex = i;
		}
	}
	/*
	* This loop is in charge of counting the number of each type of the closest k Irises.
	* It has an array that is responsible for the indexes already chosen and it checks for 
	  all of the distances who is the shortest out of the indexes that was not chosen.
	*/
	for (int m = 0; m < k; m++) {
		int minIndex = maxIndex;
		for (int j = 0; j < length; j++) {
			for (int l = 0; l < m; l++) {
				if (indexOutOfUse[l] == j) {
					flag = false;
					break;
				}
			}
			if ((distances[j] < distances[minIndex]) && flag) {
				minIndex = j;
			}
			flag = true;
		}
		if (irises[minIndex].type().compare("Iris-setosa") == 0) {
			amountOfType[0]++;
		}
		if (irises[minIndex].type().compare("Iris-virginica") == 0) {
			amountOfType[1]++;
		}
		if (irises[minIndex].type().compare("Iris-versicolor") == 0) {
			amountOfType[2]++;
		}
		indexOutOfUse[m] = minIndex;
	}
	delete[] distances;
	delete[] indexOutOfUse;
	/*
	* The conditions are for the function to decide which type is suitable
	  to the Iris that we are checking.
	*/
	if ((amountOfType[0] > amountOfType[1]) && (amountOfType[0] > amountOfType[2])) {
		delete[] amountOfType;
		return "Iris-setosa";
	} else if ((amountOfType[1] > amountOfType[0]) && (amountOfType[1] > amountOfType[2])) {
		delete[] amountOfType;
		return "Iris-virginica";
	} else if ((amountOfType[2] > amountOfType[1]) && (amountOfType[2] > amountOfType[0])) {
		delete[] amountOfType;
		return "Iris-versicolor";
	}
	delete[] amountOfType;
	return "unIdentified";
}

void Iris::setType(string type) {
	m_type = type;
}

double Iris::euclideanDistance(Iris checking) {
    double dx = pow((this->cupLength() - checking.cupLength()), 2);
    double dy = pow((this->cupWidth() - checking.cupWidth()), 2);
    double dz = pow((this->petalWidth() - checking.petalWidth()), 2);
    double dw = pow((this->petalLength() - checking.petalLength()), 2);
    return sqrt(dx + dy  + dz + dw);
}

double Iris::manhattanDistance(Iris checking) {
    double dx = abs(this->cupLength() - checking.cupLength());
    double dy = abs(this->cupWidth() - checking.cupWidth());
    double dz = abs(this->petalWidth() - checking.petalWidth());
    double dw = abs(this->petalLength() - checking.petalLength());
    return dx + dy  + dz + dw; 
}

double Iris::chebyshevDistance(Iris checking) {
    double dx = abs(this->cupLength() - checking.cupLength());
    double dy = abs(this->cupWidth() - checking.cupWidth());
    double dz = abs(this->petalWidth() - checking.petalWidth());
    double dw = abs(this->petalLength() - checking.petalLength());
    double maxXY = max(dx, dy);   
    double maxZW = max(dz, dw);
    return max(maxXY, maxZW);
}
