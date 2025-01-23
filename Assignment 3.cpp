#include <iostream> 
#include <fstream> 
#include <string> 
#include <iomanip>
using namespace std;

const int MAXUNI = 100;


bool getInput(string universities[], int intake[], int enrolment[], int output[], int& count) {
ifstream inputFile("input.txt"); 
if (!inputFile.is_open()) { 
cout << "Error opening input file." << endl;
return false; 
}

count = 0; 
while (inputFile >> universities[count] >> intake[count] >> enrolment[count] >> output[count]) { 
count++; 
if (count >= MAXUNI) { 
cout << "Exceeded maximum number of universities." << endl; 
return false; 
}
}

inputFile.close(); 
return true; 
}

int calTotal(const int arr[], int size) {
int total = 0;
for (int i = 0; i < size; ++i) { 
total += arr[i]; 
}
return total; 
}


int getLowest(const int arr[], int size) {
int lowestIndex = 0; 
for (int i = 1; i < size; ++i) { 
if (arr[i] < arr[lowestIndex]) { 
lowestIndex = i; 
}
}
return lowestIndex;
}


int getHighest(const int arr[], int size) {
int highestIndex = 0; 
for (int i = 1; i < size; ++i) { 
if (arr[i] > arr[highestIndex]){ 
highestIndex = i; 
}
}
return highestIndex; 
}




int main() {
string universities[MAXUNI];
int intake[MAXUNI]; 
int enrolment[MAXUNI]; 
int output[MAXUNI]; 
int uniCount; 
if (!getInput(universities, intake, enrolment, output, uniCount)) { 
return 1; 
}



int totalIntake = calTotal(intake, uniCount); 
int totalEnrolment = calTotal(enrolment, uniCount); 
int totalOutput = calTotal(output, uniCount); 
double averageIntake = static_cast<double>(totalIntake) / uniCount; 
double averageEnrolment = static_cast<double>(totalEnrolment) / uniCount; 
double averageOutput = static_cast<double>(totalOutput) / uniCount; 


ofstream outputFile("output.txt"); 
outputFile << "\t\t\t\tNUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT" << endl;
outputFile << "\t\t\t\t\tIN PUBLIC UNIVERSITIES (2023)" << endl << endl;
outputFile << "------------------------------------------------------------------------------------------------------" << endl;
outputFile << "UNIVERSITY\t\t\t" << "INTAKE\t\t\t" << "ENROLMENT\t\t\t" << "OUTPUT\t\t\t" << endl;
outputFile << "------------------------------------------------------------------------------------------------------" << endl;
for (int i = 0; i < uniCount; ++i) { 
outputFile << setw(7) << universities[i] << setw(30) << intake[i] << setw(26) << enrolment[i] << setw(30) << output[i] << endl; 
}
outputFile << "------------------------------------------------------------------------------------------------------" << endl;


outputFile << "  TOTAL" << setw(30) << totalIntake << setw(26) << totalEnrolment << setw(30) << totalOutput << endl; 
outputFile << showpoint;
outputFile << "  AVERAGE" << setw(28) << averageIntake << setw(26) << setprecision(7) << averageEnrolment << setw(30) << setprecision(6) << averageOutput << endl; 
outputFile << "------------------------------------------------------------------------------------------------------" << endl << endl;
  

int lowestIntakeIndex = getLowest(intake, uniCount); 
int highestIntakeIndex = getHighest(intake, uniCount); 
int lowestEnrolmentIndex = getLowest(enrolment, uniCount); 
int highestEnrolmentIndex = getHighest(enrolment, uniCount); 
int lowestOutputIndex = getLowest(output, uniCount); 
int highestOutputIndex = getHighest(output, uniCount); 

outputFile << "THE LOWEST NUMBER OF STUDENT'S INTAKE    = " << intake[lowestIntakeIndex] << " " << "(" << universities[lowestIntakeIndex] << ")" << endl; 
outputFile << "THE LOWEST NUMBER OF STUDENT'S ENROLMENT = " << enrolment[lowestEnrolmentIndex] << " " << "(" << universities[lowestEnrolmentIndex] << ")" << endl;
outputFile << "THE LOWEST NUMBER OF STUDENT'S OUTPUT    = " << output[lowestOutputIndex] << " " << "(" << universities[lowestOutputIndex] << ")" << endl << endl;  
outputFile << "THE HIGHEST NUMBER OF STUDENT'S INTAKE    = " << intake[highestIntakeIndex] << " " << "(" << universities[highestIntakeIndex] << ")" << endl;
outputFile << "THE HIGHEST NUMBER OF STUDENT'S ENROLMENT = " << enrolment[highestEnrolmentIndex] << " " << "(" << universities[highestEnrolmentIndex] << ")" <<endl;
outputFile << "THE HIGHEST NUMBER OF STUDENT'S OUTPUT    = " << output[highestOutputIndex] << " " << "(" << universities[highestOutputIndex] << ")" << endl << endl;

int rangeIntake = intake[highestIntakeIndex] - intake[lowestIntakeIndex];
int rangeEnrolment = enrolment[highestEnrolmentIndex] - enrolment[lowestEnrolmentIndex]; 
int rangeOutput = output[highestOutputIndex] - output[lowestOutputIndex]; 
outputFile << "THE RANGE OF NUMBER OF STUDENT'S INTAKE    = " << rangeIntake << endl; 
outputFile << "THE RANGE OF NUMBER OF STUDENT'S ENROLMENT = " << rangeEnrolment << endl; 
outputFile << "THE RANGE OF NUMBER OF STUDENT'S OUTPUT    = " << rangeOutput << endl; 
outputFile << "------------------------------------------------------------------------------------------------------" << endl;
outputFile.close(); 
return 0;
}