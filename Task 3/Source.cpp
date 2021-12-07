#include <iostream>

int getStringSize(char* string) {
	int size = 0;
	while (string[size] != '\0') {
		size++;
	}
	return size;
}

void stringCopy(char* s1, char* s2) {
	while (*s1 || *s2) {
		*s1 = *s2;
		s1++;
		s2++;
	}
}

int stringComparison(char* s1, char* s2) {
	if (getStringSize(s1) != getStringSize(s2)) {
		return 1;
	} 
	while (*s1) {
		if (*s1 - *s2) {
			return -1;
		}
		else {
			s1++;
			s2++;
		}
	}
	return 0;
}

void stringConcat(char* s1, char* s2) {
	int size = getStringSize(s1);
	while (*s1 + *s2) {
		*(s1 + size) = *s2;
		s1++;
		s2++;
	}
	*(++s1) = '\0';
}

int main() {
	char* string1 = new char[255];
	std::cout << "Enter your string 1: ";
	std::cin.getline(string1, 255);

	char* string2 = new char[255];
	std::cout << "Enter your string 2: ";
	std::cin.getline(string2, 255);

	std::cout << "String Comparison: " << stringComparison(string1, string2) << std::endl;

	stringConcat(string1, string2);
	std::cout << "String1 after concat: " << string1 << std::endl;
	std::cout << "String2 after concat: " << string2 << std::endl;

	stringCopy(string1, string2);
	std::cout << "String1 after copy: " << string1 << std::endl;
	std::cout << "String2 after copy: " << string2 <<std::endl;

	delete[] string1;
	delete[] string2;
	return 0;
}