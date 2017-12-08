#pragma once
#include <ostream>
#include <iostream>
#include <string>

using namespace std;
class std_class
{
public:
	static void test_map();
	static void test_string();
};

inline void std_class::test_string()
{
	string line;
	while (getline(cin, line)) {
		if (!line.empty())
			cout << line << endl;
	}
	auto the_line_size = line.size();	// size() returns string::size_type

	// Error: can't add string literal directly (no string operand)
	// string s = "hello"+",";
}
