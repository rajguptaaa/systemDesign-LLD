// # Single Responsibility Principle (SRP)

#include<iostream>
using namespace std;

class ReportGenerator {
public:
    void generateReport() {
        cout << "Generating report\n";
    }
};

class FileSaver {
public:
    void saveToFile() {
        cout<< "Saving to file\n";
    }
};

int main(){
    //code
}

//A class should have only single responsibility 