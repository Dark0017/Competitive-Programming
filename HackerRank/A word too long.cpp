#include <iostream>
#include <string>

int main() {
	int nWords, length;
	std::string word;

	std::cin >> nWords;

	for (; nWords > 0; nWords--) {
		std::cin >> word;
		length = word.size();
		
		if (length > 10)
			std::cout << word.substr(0, 1) << length - 2 << word.substr(length - 1, length - 1) << "\n";
		else
			std::cout << word << "\n" ;
	}

}