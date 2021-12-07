#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cout << "Enter your string: ";
    getline(cin, str);

    int sum = 0;

    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            sum += (str[i] - '0');
        }
    }
    cout << "sum: " << sum << endl;
}