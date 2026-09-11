#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
 //can't add std library?
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
// Empty list
//
 {
		ULListStr list;
		std::cout << "Testing for an empty list...:" << std::endl;
		std::cout << "is empty?";
		if (list.empty() == 1){
			std:: cout << "yes" << std::endl;
		}
		else {
			cout << "no" << endl;
		}
		std::cout << "size SHOULD be 0. size is: " << list.size() << std::endl;
 }

 // attempt push_back while there's room in the array
 //
 list.push_back("x");
 list.push_back("y");
 list.push_back("z");
 std::cout << "Testing push_back while there's room in the array" << std::endl;
 std::cout << "is size equal to 3?" << list.size() << std::endl;
 std::cout << "is front equal to x?" << list.front() << std::endl;
 std::cout << "is back equal to z?" << list.back() << std::endl;
}
