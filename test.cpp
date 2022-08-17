#include "Iris.hpp"
#include "FilesFunc.hpp"
using namespace std;

int main() {
    /*string str;
    string irisesToReturn = "";
    ifstream input("classified.csv");
    getline(input, str);
    irisesToReturn.append(str.c_str());
    while (!input.eof()) {
        getline(input, str);
        if (!str.empty()) {
            irisesToReturn.append(" ");
            irisesToReturn.append(str.c_str());
            cout << irisesToReturn << endl;
        }    
    }
    input.close();
    string str1;
    str1 = "";
    cout << str1 << endl;
    str1 += "hello";
    cout << str1 << endl;
    str1 += " ";
    string str2 = "banana";
    cout << str1 << endl;
    str1 += str2;
    str1 += str2;
    str1 += str2;
    str1 += str2;
    str1 += str2;
    str1 += str2;
    cout << str1 << endl;*/
    cout << fileToString("Unclassified.csv") << endl;
}