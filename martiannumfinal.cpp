///////////////////////////////////////////////////////////////////////////////////////
// Joshua Stromberg
// Input: User inputs a "martian number" that follows similar rules to roman numeral
// Output: Either a translated martian number into an integer we can read OR
//         we tell the user that their entry wasn't valid
// Processes: Through a while loop the program runs over and over until told not to
//            Switch cases tell what martian numbers equate to
//            A separate function runs the parts of the string individually
//            A main program prints out the statements and collects the input
//////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include <string>
 
using namespace std;
 
// This function returns value of a martian symbol
int value(char r)
{
    if (r == 'S')
        return 1;
    if (r == 'W')
        return 5;
    if (r == 'B')
        return 10;
    if (r == '&')
        return 50;
    if (r == 'E')
        return 100;
    if (r == 'Z')
        return 500;
    if (r == '@')
        return 1000;
     
    return -1;
}
 
// returns decimal value of martian number
int martianToInteger(string &str)
{
    //  start at a result of zerio
    int result = 0;
     
    // go up in our string by one at a time
    for (int i=0; i<str.length(); i++)
    {
        // getting value of symbol s[i]
        int s1 = value(str[i]);
         
        if (i+1 < str.length())
        {
            // getting value of symbol s[i+1]
            int s2 = value(str[i+1]);
             
            // comparing both values
            if (s1 >= s2)
            {
                // value of current symbol is greater
                // or equal to the next symbol
                result = result + s1;
            }
            else
            {
                // value of current symbol is
                // less than the next symbol
                result = result + s2 - s1;
                i++;
            }
        }
        else
        {
            result = result + s1;
            i++;
        }
    }
    return result;
}
 
// main program that puts everything together
int main()
{
    // created a while loop to keep the program running unless told to stop
    string str;
    // key word to stop program is stop
    while(str != "stop")
    {
        cout << "Enter the martian number or enter stop: ";
        cin >> str;
        // after user enters a martian number program searches for these cases in string
        // to see if the user entered an invalid case of martian numbers
        bool exists1 = str.find("@@@@@") != string::npos;
        bool exists2 = str.find("ZZ") != string::npos;
        bool exists3 = str.find("EEEEE") != string::npos;
        bool exists4 = str.find("&&") != string::npos;
        bool exists5 = str.find("BBBBB") != string::npos;
        bool exists6 = str.find("WW") != string::npos;
        bool exists7 = str.find("SSSSS") != string::npos;
         
        // if the user enters an invalid entry they are not given a translation
        // and they are told to try again
        if (exists1 || exists2 || exists3 || exists4 || exists5 || exists6 || exists7 == true)
        {
            cout << "Invalid entry please try again: ";
            continue;
        }
         
        // if the user enters a valid entry they are given a translation and then
        // we run it through our martian to decimal "translator"
        if (exists1 || exists2 || exists3 || exists4 || exists5 || exists6 || exists7 == false)
        {
            // if user says stop, we stop
            if (str == "stop")
            {
                break;
            }
             
            // otherwise we continue and do as usual, translating the symbol
            else
            {
                cout << str << " is equal to " << martianToInteger(str) << " decimal digits " << endl;
                continue;
            }
        }
 
return 0;
 
    }
}
