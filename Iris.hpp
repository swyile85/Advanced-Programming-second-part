#ifndef IRIS
#define IRIS

#include <string>
#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief 
 * This class is responsible for the Iris flower.
 */
class Iris {
	string m_type;
	double m_cupLength;
	double m_cupWidth;
	double m_petalLength;
	double m_petalWidth;
public:
	/**
 	* @brief Construct a new Iris object.
 	* 
 	* @param cupLength (as it is).
 	* @param cupWidth (as it is).
 	* @param petalLength (as it is).
 	* @param petalWidth (as it is).
 	* @param type (the type of the iris).
 	*/
	Iris(double cupLength, double cupWidth
		, double petalLength, double petalWidth, string type);
	
	/**
	 * @brief Construct a new Iris object.
	 * 
	 */
	Iris();

	/**
	 * @brief Construct a new Iris object.
	 * 
	 * @param cupLength (as it is).
	 * @param cupWidth (as it is).
	 * @param petalLength (as it is).
	 * @param petalWidth (as it is).
	 */
	Iris(double cupLength, double cupWidth,
		double petalLength, double petalWidth);
	
	/**
	 * @brief set the params of the iris object.
	 * 
	 * @param cupLength (as it is).
	 * @param cupWidth (as it is).
	 * @param petalLength (as it is).
	 * @param petalWidth (as it is).
	 * @param type (as it is).
	 */
	void set(double cupLength, double cupWidth
		, double petalLength, double petalWidth, string type);
	
	/**
	 * @brief Set the params with string of data.
	 * 
	 * @param data (the string).
	 * @param comma (the comma between the params).
	 */
	void setWithString(string data, char comma);

	/**
	 * @brief Set the type of the object.
	 * 
	 * @param type (the type).
	 */
	void setType(string type);
	
	/**
	 * @brief this func outputs the type of the iris.
	 * 
	 * @return string (the type of the iris).
	 */
	string type();

	/**
	 * @brief this func returns the length of the cup
	 * of the iris.
	 * 
	 * @return double (the length).
	 */
	double cupLength();
	
	/**
	 * @brief this func returns the width of the cup
	 * of the iris.
	 * 
	 * @return double (the width).
	 */
	double cupWidth();

	/**
	 * @brief this func returns the length of the petal
	 * of the iris.
	 * 
	 * @return double (the length).
	 */
	double petalLength();

	/**
	 * @brief this func returns the width of the petal
	 * of the iris.
	 * 
	 * @return double (the width).
	 */
	double petalWidth();

	/**
	 * @brief this func prints the data of the iris.
	 * 
	 */
	void printIris();

	/**
	 * @brief this func classify the iris (by KNN).
	 * 
	 * @param irises (the classified irises).
	 * @param k (the k of the KNN).
	 * @param length (the amount of the classified irises).
	 * @param distanceFunc (the distance func).
	 * @return string (the type).
	 */
	string classify(Iris* irises, int k, int length, double (Iris::*distanceFunc)(Iris));
	
	/**
	 * @brief this func returns the euclidean distance between
	 * this iris and other.
	 * 
	 * @param checking (the other iris).
	 * @return double (the euclidean distance).
	 */
	double euclideanDistance(Iris checking);
    
	/**
	 * @brief this func returns the manhattan distance between
	 * this iris and other.
	 * 
	 * @param checking (the other iris).
	 * @return double (the euclidean distance).
	 */
	double manhattanDistance(Iris checking);
    
	/**
	 * @brief this func returns the chebyshev distance between
	 * this iris and other.
	 * 
	 * @param checking (the other iris).
	 * @return double (the chebyshev distance).
	 */
	double chebyshevDistance(Iris checking);  
};

#endif // IRIS