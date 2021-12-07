#include <iostream>

int main() {
	char string[255];
	std::cout << "Enter your string: ";
	std::cin.getline(string, 255);
	char floatNumber[255];

	bool dotExist = false;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == '.') {
			dotExist = true;
			int k = 0;

			//before dot
			if (i == 0) {
				floatNumber[k] = '0';
				k++;
			} else if (string[i - 1] < '0' && string[i - 1] > '9') {
				floatNumber[k - 1] = '0';
				k++;
			}
			else {
				for (int j = 0; j < i; j++) {
					if (string[j] >= '0' && string[j] <= '9') {
						floatNumber[k] = string[j];
						k++;
					}
					else {
						k = 0;
					}
				}
			}
			
			//dot
			floatNumber[k] = string[i];
			k++;

			//after dot
			if (string[i + 1] < '0' || string[i + 1] > '9') {
				floatNumber[k] = '0';
				k++;
			} else {
				for (int l = i + 1; l < strlen(string); l++) {
					if (string[l] >= '0' && string[l] <= '9') {
						floatNumber[k] = string[l];
						k++;
					} else {
						break;
					}
				}
			}
			floatNumber[k] = NULL;
			

			//nulls before number?
			while (floatNumber[0] == '0' && floatNumber[1] != '.') {
				for (int i = 0; i < strlen(floatNumber); i++) {
					floatNumber[i] = floatNumber[i + 1];
				}
			}

			//output number
			for (int i = 0; i < strlen(floatNumber); i++) {
				std::cout << floatNumber[i];
			}
			break;
		}
	}
	
	if (!dotExist) {
		std::cout << "There is no dots in this string!";
	}
	

	return 0;
}