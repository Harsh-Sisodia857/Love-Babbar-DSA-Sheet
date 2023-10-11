#include <iostream>
#include <string>
using namespace std;

bool isValidPhoneNumber(string &phoneNumber)
{
    // Check if the phone number is empty
    if (phoneNumber.empty())
    {
        return false;
    }
    string plus91 = phoneNumber.substr(0, 3);
    if(plus91 == "+91"){
        // now check for spaces
        phoneNumber.erase(0, 3);

        if(phoneNumber[0] == ' ')
            phoneNumber.erase(0, 1);
        if(phoneNumber[5] == ' '){
            phoneNumber.erase(5, 1); //    Remove character from string at given index position
        }
    
        // now check for length
        if (phoneNumber.size() != 10)
            return false;
        // check for any other space
        for(int i = 0; i < 10; i++){
            if(phoneNumber[i] == ' ')
                return false;
        }
        return true;
    }
    else{
        // Check if the cleaned number starts with a valid prefix
        if (phoneNumber[0] != '0' && phoneNumber[0] != '7' &&
            phoneNumber[0] != '8' && phoneNumber[0] != '9' && phoneNumber.size() != 10){
            return false;
        }
        // checking spaces 
        for(int i = 0; i < phoneNumber.size(); i++){
            if(phoneNumber[i] == ' '){
                if(i == 5)
                    continue;
                return false;
            }
        }
        return true;
    }
    return false;
}

int main()
{
    // Sample phone numbers
    string phoneNumbers[] = {"+91 12345 67890", "+91 8524 78637", "+9183293223847", "0765432109", "09987 654 321", "1234 567 890"};

    for (string &phoneNumber : phoneNumbers)
    {
        if (isValidPhoneNumber(phoneNumber))
        {
            cout<< true <<" ";
        }
        else
        {
            cout << false<<" ";
        }
    }
    return 0;
}
