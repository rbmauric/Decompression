//Ryan Mauricio
//Google Practice Questions
//01/29/20

#include <iostream>
#include <string>
#include <vector>

//Function Prototypes
void decompress(std::string str);

//Helper Methods
std::pair<std::string, int> split(std::string str);
std::string vectostr(std::vector<char> vec);

int main() {
	std::string test = "10[abc]2[a]3[ab]";
	decompress(test);

	return 0;
}

//CHECKLIST:
//Take a string up to ]
//Get the string within the brackets
//Get the amount of times the string must be repeated 
//Repeat the string that number of times

void decompress(std::string str) {
	//Find the first ]
	//At every increment, add a character to the string
	//Decompress set of strings and print it out
	//Move to next set of strings.
	std::vector<char> newstr_;
	std::pair<std::string, int> decompressed;
	std::string newstr;

	for (int i = 0; i < str.length(); i++) {
		newstr_.push_back(str[i]);
		if (str[i] == ']') {
			newstr = vectostr(newstr_);
			decompressed = split(newstr);
			for (int j = 0; j < decompressed.second; j++)
				std::cout << decompressed.first;
			newstr_.clear();
		}
	}
}

std::pair<std::string, int> split(std::string str) {
	//read from the given string
	//note the number and the actual characters in the string
	//return a pair with the string and the number
	std::vector<char> num_;
	std::vector<char> newstr_;
	std::string num;
	std::string newstr;
	
	int val = 0;

	for (int i = 0; i < str.length(); i++) {
		//1st if else is for the number
		if (str[i] == '[') {
			for (int j = i; j < str.length(); j++) {
				//2nd if else is for the characters
				if (str[j] == ']')
					break;
				else if (str[j] != '[')
					newstr_.push_back(str[j]);
			}
			break;
		}
		else
			num_.push_back((int)str[i]);
	}

	num = vectostr(num_);
	newstr = vectostr(newstr_);

	return std::make_pair(newstr, std::stoi(num));
}

//Converts a vector of characters into a string
std::string vectostr(std::vector<char> vec) {
	std::string str(vec.begin(), vec.end());
	return str;
}