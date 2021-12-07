#include <iostream> 
#include <string>

int main() {
	std::string str;
	std::cout << "Enter your text: ";
	std::getline(std::cin, str);
	int size = str.length();

	std::string vowels{ "aeiou" };// гласные

	for (int i = 0; i <= size; i++) {


		if (str[i] == 'c' || str[i] == 'C') {
			if (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y') {
				if (str[i] =='c') {
					str[i] = 's';
				}
				else {
					str[i] = 'S';
				}
			}
			else {
				if (str[i] == 'c') {
					str[i] = 'k';
				}
				else {
					str[i] = 'K';
				}
			}
		}

		if ((str[i] == 'q' || str[i] == 'Q') && str[i + 1] == 'u') {
			if (str[i] == 'q') {
				str[i] = 'k';
			}
			else {
				str[i] = 'K';
			}
			str[i + 1] = 'v';
		}

		if (str[i] == 'q') {
			str[i] = 'k';
		}

		if (str[i] == 'Q') {
			str[i] = 'K';
		}
		

		if (str[i] == 'x' || str[i] == 'X') {
			size++;
			for (int j = size; j > i + 1; j--) {
				str[j] = str[j - 1];
			}
			if (str[i] == 'x') {
				str[i] = 'k';
			}
			else {
				str[i] = 'K';
			}
			str[i + 1] = 's';
			i++;
		}

		if (str[i] == 'w') {
			str[i] = 'v';
		}

		if (str[i] == 'W') {
			str[i] = 'V';
		}

		if ((str[i] == 'p' || str[i] == 'P') && str[i + 1] == 'h') {
			for (int j = i + 1; j < size; j++) {
				str[j] = str[j + 1];
			}
			size--;
			if (str[i] == 'p') {
				str[i] = 'f';
			}
			else {
				str[i] = 'F';
			}
		}

		if ((str[i] == 'y' || str[i] == 'Y') && str[i + 1] == 'o' && str[i + 2] == 'u') {
			for (int k = 0; k < 2; k++) {
				for (int j = i + 1; j < size; j++) {
					str[j] = str[j + 1];
				}
			}
		
			size -= 2;
			if (str[i] == 'y') {
				str[i] = 'u';
			}
			else {
				str[i] = 'U';
			}
			
		}

		if ((str[i] == 'o' || str[i] == 'O') && str[i + 1] == 'o') {
			for (int j = i + 1; j < size; j++) {
				str[j] = str[j + 1];
			}
			size--;
			if (str[i] == 'o') {
				str[i] = 'u';
			}
			else {
				str[i] = 'U';
			}
		}

		if ((str[i] == 'e' || str[i] == 'E') && str[i + 1] == 'e') {
			for (int j = i + 1; j < size; j++) {
				str[j] = str[j + 1];
			}
			size--;
			if (str[i] == 'e') {
				str[i] = 'i';
			}
			else {
				str[i] = 'I';
			}
		}

		if ((str[i] == 't' || str[i] == 'T') && str[i + 1] == 'h') {
			for (int j = i + 1; j < size; j++) {
				str[j] = str[j + 1];
			}
			size--;
			if (str[i] == 't') {
				str[i] = 'z';
			}
			else {
				str[i] = 'Z';
			}
		}

		if (str[i] == str[i + 1] && vowels.find(str[i]) == std::string::npos) {
			for (int j = i + 1; j < size; j++) {
				str[j] = str[j + 1];
			}
			size--;
		}

	}
	std::cout << "Result: " << str;
	return 0;
}