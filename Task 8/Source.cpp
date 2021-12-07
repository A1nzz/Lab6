#include <iostream>
#include <string>
using namespace std;

int get_q() {
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

		if (t <= 0 || t > 500) {
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}
		else {
			break;
		}
	}
	return t;
}

string getString(string name, int frame) {
	string s;
	while (true) {	
		cout << "Enter string " << name << ": ";
		cin >> s;
		if (s.length() > frame) {
			cout << "Incorrect input! Try again: " << endl;
			continue;
		}
		else {
			break;
		}
	}
	return s;
}

int main() {
	int q = get_q();

	for (int index = 0; index < q; index++) {
		string s = getString("s", 500);
		string t = getString("t", 2 * s.length() - 1);
		int j = 0; // number of movements(index of t string)
		for (int i = 0; i < s.length(); i++) { //searching first symbol of t string
			if (s[i] == t[j]) {
				j++;
				for (int k = i + 1; k <= s.length(); k++) {// movement to the right
					if (s[k] != t[j] || k == s.length()) {
						for (int l = k - 2; l >= 0; l--) { // movement to the left
							if (s[l] != t[j]) {
								break;
							}
							else {
								j++;
							}
						}
						break;
					}
					else {
						j++;
					}
				}
				break;
			}
		}
		if (j == t.length()) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}