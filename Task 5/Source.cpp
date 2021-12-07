#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int get_t() {
	int t;
	while (true) {
		std::cout << "Enter number of tests: ";
		std::cin >> t;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}

		if (t <= 0 || t > 100) {
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}
		else {
			break;
		}
	}
	return t;
}

int get_L() {
	int L;
	while (true) {
		std::cout << "Enter number of letters in your string: ";
		std::cin >> L;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}

		if (L <= 0 || L > pow(10, 9)) {
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}
		else {
			break;
		}
	}
	return L;
}

int get_m() {
	int m;
	while (true) {
		std::cout << "Enter module: ";
		std::cin >> m;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}

		if (m <= 0 || 4 > pow(10, 4)) {
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}
		else {
			break;
		}
	}
	return m;
}

int main() {
	string s; // whole string
	string s1; //prefix
	string s2; //sufix

	int t = get_t();

	for (int i = 0; i < t; i++) {
		int L = get_L();
		int m = get_m();
		cout << "Enter prefix: ";
		cin >> s1;
		cout << "Enter sufix: ";
		cin >> s2;

		//  Start 
		// processing duplicate characters and getting the number of free characters
		int l1 = s1.length(); 
		int l2 = s2.length(); 
		for (int i = 1; i < s1.length(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (s1[i] == s1[j]) {
					l1++;
				}			
			}
		}

		for (int i = 1; i < s2.length(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (s2[i] == s2[j]) {
					l2++;
				}
			}
		}
		int dl = L - (l1 + l2);

		for (int i = 0; i < s1.length(); i++) {
			for (int j = 0; j < s2.length(); j++) {
				if (s1[i] == s2[j]) {
					dl++;
				}
			}
		}
		//// processing duplicate characters and getting the number of free characters
		// end
		

		//getting result based on free charecters
		if (dl < 0){
			cout << "Result: " << 0;
		}
		else if (dl == 0) {
			cout << "Result: " << 1;
		}
		else {
			cout << "Result: " << ((int)pow(26, dl) * 2) % m;
		}
		cout << endl << "-------------" << endl;
	}
	
	return 0;
}