/*
Nick Bennett
Lab 6 - 11-10-21
Using a file that has a binary expression in it. The program will gave the data that inside of the file and turn the data for binary number system to decimal number system.
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void FC(ifstream& inFile); // FC = filechecking
//Precondition: The function is passed a input stream
//Postcodition: The function will verify the input file when it is first opened
void RemoveLZeros(ifstream& inFile, char& input, int& position);
//Precondition: The input identified a 0 in the first position of the input file. Looks for zeros that are leading in the binary number 
//Postcondition: The function move the input forward to the first significant digit in the input file ever sinse in binary leading zeros don't matter toward the actually number in decimal
void PT(int total, string binaryNum); //PT = printing table/graph
//Postcodition: The function will output a table with the binary number that has been read in with its decimal number in base 10 if everything was read correctly
void ATotal(int& total, char input, int& position, string& binaryNum);
//Precondition: The input stream has read a character from the input file that is either a 1 or 0
//Postcodition: The function updates the location of the decimal total for the conversion from binary to decimal
int DecPlace(int total); // decimal number placement on the table
//Precondition: The main function has successfully calculated a decimal number called total which is passed to the function by value
//Postcondition: Function returns the number of places in the decimal number and where it will be placed on the table
void ResetC(int& total, int& position, string& binaryNum); //resetting the counter
//Precondition: The while loop has either encountered the end of a line or an error in the input stream
//Postcondition: Function resets the values of counters that are used during program execution

int main()
{
    ifstream inFile;
    cout << setw(22) << "Binary Number:" << setw(24) << "Decimal Equivalent:" << endl;
    // heading for the out put to the screen
    FC(inFile);
    char input; // reads the character from the file that is inputted
    int total = 0; // stores the decimal number from the binary number
    int position = 0; // counter that keeps track of input position
    string binaryNum = ""; // string is used to store the input values that are pulled for the file
    while (inFile.get(input) || (total != 0))
    {
        if (input == '0' && position == 0)
        { // if a 0 is read on the first on the line
            RemoveLZeros(inFile, input, position);
        }
        if ((input == '\n' && position > 0) || (!inFile))
        { // if the input file is leading with a 1 or the end of the file was reached
            PT(total, binaryNum); // prints to the screen
            // resets counter for the next line
            ResetC(total, position, binaryNum);
        }
        else if (input == '1' || input == '0')
        {// if the input char is a 1 or 0
            ATotal(total, input, position, binaryNum);
        }
        else if (input == '\n' && position == 0)
        { // if the cursor reads a newline character on the first spot for a character
            continue;
        }
        else if (((int(input) < '0' || int(input) > '1') && (input != ' ')) || (input == ' ' && position > 0))
        { // if the file has something that isn't a 1 or 0 than this will be put out to the screen
            cout << setw(24) << "Bad data on input" << endl;
            // resets counters
            ResetC(total, position, binaryNum);
            // ignores all characters with bad data
            inFile.ignore(1000, '\n');
        }
    }
    inFile.close(); // close the input file
    return 0;
}

void FC(ifstream& inFile)
{
    inFile.open("BinaryIn.dat.txt");
    if (!inFile)
    {
        cout << "The input file failed to open." << endl;
    }
}

void RemoveLZeros(ifstream& inFile, char& input, int& position)
{
    bool isOne = false; // value is not a 1
    bool isBadData = false; // value is not a invalid data value
    while (!isOne && !isBadData)
    {
        position++; // detects spaces in binary numbers
        inFile.get(input);
        if (input == '1')
            isOne = true; // first 1 of binary number found
        if (((int(input) < '0' || int(input) > '1') && (input != ' ')) || (input == ' ' && position > 0))
        { // if anything that is not a 0 or 1 then will be sent back to main as a bad value and say that the input was invalid
            isBadData = true; // if the data is a bad input then it will return as true. If true then will put on an error message
        }
    }
}

void ResetC(int& total, int& position, string& binaryNum)
{
    // resets counter for next line
    position = 0;
    total = 0;
    binaryNum = "";
}

void PT(int total, string binaryNum)
{
    // outputs the place values of the binary numbers
    switch (binaryNum.length())
    {
    case 1:
        cout << setw(long(binaryNum.length() + 14)) << binaryNum;
        break;
    case 2:
        cout << setw(long(binaryNum.length() + 13)) << binaryNum;
        break;
    case 3:
        cout << setw(long(binaryNum.length() + 13)) << binaryNum;
        break;
    case 4:
        cout << setw(long(binaryNum.length() + 12)) << binaryNum;
        break;
    case 5:
        cout << setw(long(binaryNum.length() + 12)) << binaryNum;
        break;
    case 6:
        cout << setw(long(binaryNum.length() + 11)) << binaryNum;
        break;
    case 7:
        cout << setw(long(binaryNum.length() + 11)) << binaryNum;
        break;
    case 8:
        cout << setw(long(binaryNum.length() + 10)) << binaryNum;
        break;
    case 9:
        cout << setw(long(binaryNum.length() + 10)) << binaryNum;
        break;
    case 10:
        cout << setw(long(binaryNum.length() + 9)) << binaryNum;
        break;
    case 11:
        cout << setw(long(binaryNum.length() + 9)) << binaryNum;
        break;
    case 12:
        cout << setw(long(binaryNum.length() + 8)) << binaryNum;
        break;
    case 13:
        cout << setw(long(binaryNum.length() + 8)) << binaryNum;
        break;
    case 14:
        cout << setw(long(binaryNum.length() + 7)) << binaryNum;
        break;
    case 15:
        cout << setw(long(binaryNum.length() + 7)) << binaryNum;
        break;
    case 16:
        cout << setw(long(binaryNum.length() + 6)) << binaryNum;
        break;
    default:
        cout << setw(22) << "16-bit limit\n";
        break;
    }
    // prints decimal values
    switch (DecPlace(total))
    { // switch statement is for placement on the screen for the different values when convered
    case 1:
        if (total < 4)
        {
            cout << setw(20) << total << endl;
        }
        else
            cout << setw(19) << total << endl;
        break;
    case 2:
        if (total <= 15)
        {
            cout << setw(19) << total << endl;
        }
        else if (total <= 32)
        {
            cout << setw(18) << total << endl;
        }
        else if (total > 32 && total <= 63)
        {
            cout << setw(18) << total << endl;
        }
        else
            cout << setw(17) << total << endl;
        break;
    case 3:
        if (total < 256)
        {
            cout << setw(18) << total << endl;
        }
        else
            cout << setw(17) << total << endl;
        break;
    case 4:
        if (total >= 1000 && total < 1024)
        {
            cout << setw(17) << total << endl;
        }
        else if (total >= 1024 && total < 2048)
        {
            cout << setw(16) << total << endl;
        }
        else if (total >= 2048 && total <= 4095)
        {
            cout << setw(16) << total << endl;
        }
        else if (total >= 4096 && total < 10000)
        {
            cout << setw(15) << total << endl;
        }
        break;
    case 5:
        if (total >= 10000 && total < 16384)
        {
            cout << setw(16) << total << endl;
        }
        else if (total >= 16384 && total <= 32768)
        {
            cout << setw(15) << total << endl;
        }
        else if (total > 32768 && total <= 65535)
        {
            cout << setw(15) << total << endl;
        }
        break;
    }
}

void ATotal(int& total, char input, int& position, string& binaryNum)
{
    // adds either one or zero
    int n;
    if (input == '1')
        n = 1;
    else
        n = 0;
    binaryNum += input; // uses the string to add the input 1 or 0 to a string
    total = (total * 2) + n; // multiply the total by 2 to account for the next highest place value and add 1
    position++;
}

int DecPlace(int total)
{
    int placeValue = 0;
    while (total != 0)
    {
        total /= 10;
        placeValue++;
    }
    return placeValue;
}
