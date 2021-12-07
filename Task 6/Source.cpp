//Formula:
//result = l!/i!
//where i - number of dublicate elements

#include <iostream>
#include <map>
#include <string>

using namespace std;

long long fact(int n) {
    int f;
    if (n == 0) {
        f = 1;
    }
    else {
        f = n * fact(n - 1);
    }
    return f;
}

int main() {
    string s;
    map <char, int> m; //Creating conteiner map

    cout << "Enter your string: ";
    std::getline(std::cin, s);

    int l = s.size(); //getting string size
    int count = 1;  //denominator

    //Filling map
    for (int i = 0; i < l; i++) {
        ++m[s[i]];
    }
    
    //getting denominator
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > 1) {
            count *= fact(it->second);
        }
    }  

    //result
    cout << "Number of anagrams: " << fact(l) / count;
    
    return 0;
}