#include <iostream>
using namespace std;
bool isValidCharacter(char c, const string& validChars) 
{
    return validChars.find(c) != string::npos;
}

bool isValidEmail(const string& email) 
{
    string validCharsBeforeAt = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-/=?^_{|}~`";
    string validCharsAfterAt = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-";
    
    int atIndex = email.find('@');
    if (atIndex == string::npos || atIndex == 0 || atIndex == email.length()-1) 
    {
        return false;
    }
    
    string localPart = email.substr(0, atIndex);
    if (localPart.length() > 64) 
    {
        return false;
    }

    for (char c : localPart) 
    {
        if (!isValidCharacter(c, validCharsBeforeAt)) 
        {
            return false;
        }
        if (c == '.' && (localPart[0] == '.' || localPart[localPart.length()-1] == '.'))
         {
            return false;
        }
    }
    
    string domainPart = email.substr(atIndex + 1);
    if (domainPart.length() > 63) 
    {
        return false;
    }
    for (char c : domainPart) 
    {
        if (!isValidCharacter(c, validCharsAfterAt)) 
        {
            return false;
        }
        if (c == '.' && domainPart.find("..") != string::npos) 
        {
            return false;
        }
    }
    return true;
}

int main() {
    string email;
    cout << "Введите email для проверки его корректности: ";
    cin >> email;
    if (isValidEmail(email)) 
    {
        cout << "Yes" << endl;
    } 
    else 
    {
        cout << "No" << endl;
    }
    
    return 0;
}