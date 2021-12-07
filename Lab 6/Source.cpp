#include <iostream>

int main() {
	char* string = new char[255];
	std::cout << "Enter your string: ";
	std::cin.getline(string, 255); 
	int strSize = strlen(string);

	for (int i = 0; i < strSize; i++) {
		if (!((string[i] <= 'z' && string[i] >= 'a') || (string[i] <= 'Z' && string[i] >= 'A') || string[i] == ' ')) {
			for (int j = i; j < strSize - 1; j++) {
				string[j] = string[j + 1];
			}
			strSize--;
			i--;
		}
	}

	std::cout << "New string: ";
	for (int i = 0; i < strSize; i++) {
		std::cout << string[i];
	}

	delete[] string;
	return 0;
}