#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <math.h>

using namespace std;

float calculateMean(float input[4]) {
    float sum = 0;
    sum = accumulate(input, input + (sizeof(input)), sum);
    float mean = sum / sizeof(input);
    return mean;
}

float calculateStandardDeviation(float mean, float input[4]) {
    float deviation[sizeof(input)];
    
    for (int i = 0; i < 4; i++) {
        
        deviation[i] = input[i] - mean;
        deviation[i] *= deviation[i];
        
    }

    float sum = 0; 
    sum = accumulate(deviation, deviation + (sizeof(input)), sum);
    sum /= sizeof(input) - 1;
    float result = sqrt(sum);

    return result;
}

int main()
{
    fstream inFile;
    inFile.open("inMeanStd.dat");
    fstream outFile;
    outFile.open("outMeanStd.dat");

    string rawInput[4];
    float input[4];

    cout << "Do you want to input your own numbers? Y/N\n";
    string userInput;
    cin >> userInput;

    if (userInput == "Y" || userInput == "y") {
        cout << "Enter the first number: ";
        cin >> input[0];
        cout << "\nEnter the second number: ";
        cin >> input[1];
        cout << "\nEnter the third number: ";
        cin >> input[2];
        cout << "\nEnter the last number: ";
        cin >> input[3];
        cout << endl;
    }
    else if (userInput == "N", userInput == "n") {
        int counter = 0;
        for (int i = 0; i < 4; i++) {
            getline(inFile, rawInput[i]);
            input[i] = stof(rawInput[i]);
        }
    }
    else {
        cout << "Imma just assume thats a no\n";
        int counter = 0;
        for (int i = 0; i < 4; i++) {
            getline(inFile, rawInput[i]);
            input[i] = stof(rawInput[i]);
        }
    }

    float mean = calculateMean(input);
    float standerdDiviation = calculateStandardDeviation(mean, input);

    cout << "The mean is: " << mean << endl << "The standered deviation is: " << standerdDiviation << endl;
    outFile << "The mean is: " << mean << endl << "The standered deviation is: " << standerdDiviation << endl;

    inFile.close();
    outFile.close();
}

