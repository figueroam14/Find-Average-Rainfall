//Michael
//Figueroa
//900389292
//CS1410, CRN 11297, Fall 2018
//Programming Assignment #6

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//Total_Rainfall Prototype
double Total_Rainfall(double arr[]);

//Average_Rainfall Prototype
double Average_Rainfall(double arr[]);

//Min_Rainfall Prototype
int Min_Rainfall(string[], int, double arr[]);

//Max_Rainfall Prototype
int Max_Rainfall(string[], int, double arr[]);

//function to get total rainfall
double Total_Rainfall(double arr[])
{

    int i;
    double total = 0;

    for (i = 0; i < 12; i++)
    {
        total += arr[i];
    }

    return total;
}

//function to get average of rainfall
double Average_Rainfall(double arr[])
{

    int i;
    double sum = 0;

    for (i = 0; i < 12; i++)
    {
        sum += arr[i];
    }

    double average = sum / 12.00;
    return average;
}

//function definition for MinRainfall Index
int Min_Rainfall(string months[], int arrSize, double vals[])
{
    double max = vals[0];
    int index = 10;

    for (int i = 0; i < arrSize; i++)
    {
        if (i < arrSize - 1)
        {
            if (vals[i + 1] < max)
            {
                max = vals[i + 1];
                index = i + 1;
            }
        }
    }

    return index;
}

//function definition for MaxRainfall Index
int Max_Rainfall(string months[], int arrSize, double vals[])
{
    double max = vals[0];
    int index = 10;

    for (int i = 0; i < arrSize; i++)
    {
        if (i < arrSize - 1)
        {
            if (vals[i + 1] > max)
            {
                max = vals[i + 1];
                index = i + 1;
            }
        }
    }

    return index;
}

int main()
{

    //output to file
    ofstream outputFile;
    outputFile.open("michael_figueroa.txt");

    //array containing month names
    const int monthCount = 12;
    string monthNames[monthCount] = {"January", "February", "March",
                                     "April", "May", "June", "July",
                                     "August", "September", "October",
                                     "November", "December"};

    //array containing default values
    const int valuesCount = 12;
    double defaultValues[valuesCount] = {2.10, 1.60, 0.50, 0.70, 0.90, 1.60, 3.60, 1.50, 0.30, 5.20, 3.10, 4.30};

    //output heading
    cout << "RAINFALL REPORT" << endl;
    cout << endl;

    //output heading to file
    outputFile << "RAINFALL REPORT" << endl;
    outputFile << endl;

    //initial output names and values together
    for (int i = 0; i < 12; i++)
    {

        cout << monthNames[i] << "           " << setprecision(2) << fixed << defaultValues[i] << endl;
        cout << endl;

        //output default info to file
        outputFile << monthNames[i] << "           " << setprecision(2) << fixed << defaultValues[i] << endl;
        outputFile << endl;
    }

    //call function to get total using default values
    double rainfallTotal = Total_Rainfall(defaultValues);
    //output total using default values
    cout << "The total rainfall was: " << rainfallTotal << " inches" << endl;

    //output to file
    outputFile << "The total rainfall was: " << rainfallTotal << " inches" << endl;

    //call function to get average
    double totalAverage = Average_Rainfall(defaultValues);

    //output average
    cout << "The average rainfall was: " << setprecision(2) << totalAverage << " inches" << endl;
    cout << endl;

    //output to file
    outputFile << "The average rainfall was: " << setprecision(2) << totalAverage << " inches" << endl;
    outputFile << endl;

    //call function and ouput largest rainfall
    int maxIndex = Max_Rainfall(monthNames, valuesCount, defaultValues);
    cout << "The month with the largest rainfall was: " << monthNames[maxIndex] << endl;

    //output to file
    outputFile << "The month with the largest rainfall was: " << monthNames[maxIndex] << endl;

    //call function and output the smallest rainfall
    int minIndex = Min_Rainfall(monthNames, valuesCount, defaultValues);
    cout << "The month with the smallest rainfall was: " << monthNames[minIndex] << endl;

    //output to file
    outputFile << "The month with the smallest rainfall was: " << monthNames[minIndex] << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Would you like to process more data? (Y/N)" << endl;
    char again;
    cin >> again;

    if (again == 'Y' || again == 'y')
    {
        do
        {

            double userValues[12];

            cout << endl;
            cout << "Please enter the new values: " << endl;
            int i;

            for (i = 0; i < 12; i++)
                cin >> userValues[i];

            if (userValues <= 0)
                cout << "Enter a positive value... " << endl;

            //output heading
            cout << "RAINFALL REPORT" << endl;
            cout << endl;

            for (i = 0; i < 12; i++)
            {
                cout << monthNames[i] << "           " << setprecision(2) << fixed << userValues[i] << endl;
                outputFile << monthNames[i] << "           " << setprecision(2) << fixed << userValues[i] << endl;
            }

            //call function to get total using user values
            double rainfallTotalUser = Total_Rainfall(userValues);
            //output total using default values
            cout << "The total rainfall was: " << rainfallTotalUser << " inches" << endl;

            outputFile << "The total rainfall was: " << rainfallTotalUser << " inches" << endl;

            //call function to get average
            double totalAverageUser = Average_Rainfall(defaultValues);
            //output average
            cout << "The average rainfall was: " << setprecision(2) << totalAverageUser << " inches" << endl;
            cout << endl;

            //output to file
            outputFile << "The average rainfall was: " << setprecision(2) << totalAverageUser << " inches" << endl;
            outputFile << endl;

            //call function and ouput largest rainfall
            int maxIndexUser = Max_Rainfall(monthNames, valuesCount, userValues);
            cout << "The month with the largest rainfall was: " << monthNames[maxIndexUser] << endl;

            //output to file
            outputFile << "The month with the largest rainfall was: " << monthNames[maxIndexUser] << endl;

            //call function and output the smallest rainfall
            int minIndexUser = Min_Rainfall(monthNames, valuesCount, userValues);
            cout << "The month with the smallest rainfall was: " << monthNames[minIndexUser] << endl;
            ;
            cout << endl;

            //output to file
            outputFile << "The month with the smallest rainfall was: " << monthNames[minIndexUser] << endl;
            ;

            //blank spaces betweeen sets
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;

            //prompt user if want to process more data
            cout << "Would you like to process more data? (Y | N) " << endl;
            cin >> again;

        } while (again == 'Y' || again == 'y');
    }

    //output to console
    cout << endl;
    cout << "Michael Figueroa" << endl;
    cout << "This is my own work – I did not copy or allow anyone else to copy my work" << endl;

    //output to file
    outputFile << "Michael Figueroa" << endl;
    outputFile << "This is my own work - I did not copy or allow anyone else to copy my work" << endl;

    return 0;
}
