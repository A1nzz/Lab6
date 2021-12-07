#include <iostream>
#include <string>
using namespace std;

bool isEqualSymb(string s) {    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[0]) return false;
    }
    return true;
}

bool isPal(string s) {      
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1])  return false;
    }
    return true;
}

int numberOfNonPalSymbols(string str) {
    if (isEqualSymb(str)) {
        return -1;
    }
    else {
        if (!isPal(str)) {
            return str.length();
        }
        else {
            return str.length() - 1;
        }
    }
}

int main() {
    string str;
    cout << "Enter your string: ";
    getline(cin, str);
    cout << numberOfNonPalSymbols(str);
    return 0;
}