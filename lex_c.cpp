#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#define filePath "test.txt"

bool isDigit(string str)
{
    if (str.length() == 0)
        return false;

    for (auto strIter = str.begin(); strIter != str.end(); strIter++) {
        if (!(isdigit(*strIter)))
            return false;
    }

    return true;
}

bool isFloat(string str)
{
    bool dotFlag = false;

    if (str.length() == 0)
        return false;

    for (auto strIter = str.begin(); strIter != str.end(); strIter++) {
        if (*strIter == '.'
            && !dotFlag
            && strIter != str.begin()
            && strIter != str.end() - 1)
            dotFlag = true;
        else if (!(isdigit(*strIter)))
            return false;
    }

    return true && dotFlag;
}

bool isID(string str)
{

    if (!isalpha(str.at(0)))
        return false;

    for (auto strIter = str.begin(); strIter != str.end(); strIter++)
        if (!isalpha(*strIter) && *strIter != '_')
            return false;
    return true;
}

/*
    return 0: Error
    return 1: Int Number
    return 2: Float Number
    return 3: ID
*/
int check(string str)
{
    if (str.at(str.length() - 1) != ';')
        return 0;
    else {

        str.pop_back();
        if (isDigit(str))
            return 1;
        if (isFloat(str))
            return 2;
        if (isID(str))
            return 3;
    }
    return 0;
}

int main()
{
    int countError = 0, countInt = 0, countFloat = 0, countID = 0;
    string lineInp = "";
    fstream fin;
    fin.open(filePath, ios::in);
    while (getline(fin, lineInp)) {
        switch (check(lineInp)) {

        case 0:
            cout << "Find a Error: ";
            countError++;
            break;
        case 1:
            cout << "Find a Int Number: ";
            countInt++;
            break;
        case 2:
            cout << "Find a Float Number: ";
            countFloat++;
            break;
        case 3:
            cout << "Find a ID: ";
            countID++;
            break;
        }
        cout << lineInp << endl;
    }
    fin.close();

    cout << "Total Num = " << countInt << endl;
    cout << "Total Float = " << countFloat << endl;
    cout << "Total ID = " << countID << endl;
    cout << "Total Error = " << countError;
}
