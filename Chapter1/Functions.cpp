
#include "Functions.h"
#include "IDGenerator.h"
#include "Sales_item.h"
#include <iostream>
#include <map>
#include <cctype>
#include <vector>
#include <sstream>

using namespace std;

void my_functions::test_ostream()
{
	// Test cout, cerr and clog
	cout << "Hello world" << endl;
	cerr << "error message" << endl;
	clog << "program about to end" << endl;
}

void my_functions::test_id_generator()
{
	for(int count = 0;count<5;++count)
	{
		cout << "The next ID is: " << id_generator::get_next_id() << endl;
	}
}

void my_functions::test_istream()
{
	
	int v1, v2;
	cin >> v1 >> v2;	// Two contents can be separated by Enter or Space key
	cout << "v1:" << v1 << " ; v2:" << v2<<" ";
}

void my_functions::test_illegal_nested_comment()
{
	// delete "//" before each line to test

	// /*
	// * comment pairs /* */
	// */

	// /* ??????? */ ??????comment
	cout << "/*";
	cout << "*/";
	cout <</* "*/" */";
	cout <</*   "*/" /* "/*" */;
}

void my_functions::read_unknown_number_input()
{
	auto sum = 0;
	auto value = 0;
	while(cin>>value)	/* Input will continue forever no matter you enter "space" or "enter", 
						 *	unless you input 
						 *	1. "/0" or "Ctrl+z", 
						 *	2. wrong type
						 *	then press "Enter"
						 */
	{
		sum += value;
	}
	cout << "Sum is "<< sum << endl;
}


void my_functions::read_unknown_number_input_own_version()
{
	auto sum = 0;
	for (int value; cin >> value; sum += value);
	cout << "Sum is " << sum << endl;
}

void my_functions::number_occurrence_counter_of_me()
{
	int val;
	auto never_in_game = true;
	auto number_counter = 0;
	auto current_val = 0;
	while(cin>>val)
	{
		if(never_in_game)
		{
			current_val = val;
			number_counter = 1;
			never_in_game = false;
		}
		else if(current_val!=val)
		{
			if(val!=current_val)
				cout << current_val << " occurs " << number_counter << " times" << endl;
			number_counter = 1;
			current_val = val;
		}
		else
		{
			number_counter++;
		}
	}
	cout << current_val << " occurs " << number_counter << " times" << endl;
}

void my_functions::number_occurrence_counter_official()
{
	int currentValue, value = 0;
	if(cin>>currentValue)
	{
		int count = 1;
		while(cin>>value)
		{
			if(currentValue == value)
			{
				count++;
			}
			else
			{
				cout << currentValue << " occurs " << count << " times" << endl;
				count = 1; // reset the counter
				currentValue = value;
			}
		}
		cout << currentValue << " occurs " << count << " times" << endl;
	}
	
}

void my_functions::read_booksales_transaction()
{
	// read booksales transaction
	//for (Sales_item item; cin >> item; cout << item << endl);

	// Add Sales_items
	/*Sales_item item1, item2;
	cin >> item1 >> item2;
	cout << item1 + item2 << endl;*/

	// read several transactions for the same ISBN
	Sales_item total;
	if(cin>>total)
	{
		Sales_item current;
		while(cin>>current)
		{
			if(total.isbn() == current.isbn())
			{
				total += current;
			}
			else
			{
				cout << "Switching from " << total.isbn() << " to " << current.isbn() << endl;
				total = current;
			}
		}
		cout << total << endl;
	}
	else
	{
		cout << "No data input" << endl;
	}
}

/*
 * count transaction that can't group books from of the same ISBN
 */
void my_functions::count_boolsales_transaction()
{
	Sales_item current_item;
	Sales_item next_item;
	if(cin>>current_item)
	{
		int count = 1;
		while(cin>>next_item)
		{
			if(current_item.isbn() == next_item.isbn())
			{
				count++;
			}
			else
			{
				cout << current_item << " occurs " << count << " times " << endl;
				current_item = next_item;
				count++;
			}
		}
		cout << current_item << " occurs " << count << " times " << endl;
	}
}

/*
 *
 */
void my_functions::count_boolsales_transaction_advanced()
{
	Sales_item current_item;
	Sales_item next_item;
	map<string, Sales_item> book_id_marker;
	map<string, Sales_item>::iterator it = book_id_marker.begin();
	while (cin >> current_item)
	{
		map<string, Sales_item>::iterator content_checker = book_id_marker.find(current_item.isbn());
		if(content_checker!=book_id_marker.end())
		{
			book_id_marker[current_item.isbn()] += current_item;
		}
		else
		{
			book_id_marker[current_item.isbn()] = current_item;
		}
	}
	
	it = book_id_marker.begin();
	while(it!=book_id_marker.end())
	{
		cout << it->second << endl;
		++it;
	}

}

void my_functions::read_word_at_time()
{
	string current_str;
	while(cin>>current_str)
	{
		cout << current_str << endl;
	}
}

void my_functions::input_whitespace_handling()
{
	istream& is = cin;
	string s;
	is >> s;	// cut when encountering any whitespace
	cout << "string is :" << s << endl;	
	string getline_s;
	getline(is, getline_s);	// cut when encountering \n
	cout << "string is :" << getline_s << endl;	
	string getlinedelimit_s;
	getline(is, getlinedelimit_s, ',');	// cut when encountering delimiter
	cout << "string is :" << getlinedelimit_s << endl;
}

void my_functions::concatenate_and_separate_string()
{
	string str;
	string buffer;
	while(cin>>buffer)
	{
		// if user just put nothing and click enter, then no space should be generated
		str += (buffer.empty() ? "" : " ") + buffer;	
	}
	cout << "The concatenated string is " << str << endl;
}

void my_functions::general_string_test()
{
	char a = 'a';	// return 2
	char b = 1; // return 0
	cout << isalnum(a) << endl;
}
void my_functions::count_punctuation_character()
{
	string s("Hello world!!!");
	decltype(s.size()) punct_cnt = 0;
	for(auto c:s)
	{
		if(ispunct(c))
		{
			++punct_cnt;
		}
	}
	cout << punct_cnt << " punctuation characters in " << s << endl;
}

void my_functions::using_subscript_to_iterate()
{
	string s("some string");
	decltype(s.size()) i = 0;
	while(i!=s.size()&&!isspace(s[i]))
	{
		s[i] = toupper(s[i]);
		++i;
	}
	cout << s << endl;
}

void my_functions::input_hex_number()
{
	string hexdigits = "0123456789ABCDEF";

	cout << "Enter a series of numbers between 0 and 15"
		<< "separated by spaces. Hit ENTER when finished: "
		<< endl;

	string result = "";
	decltype(result.size()) decimal_number;
	while(cin>>decimal_number)
	{
		if (decimal_number >= 16)
			break;
		result += hexdigits[decimal_number];
	}
	cout << "Your hex number is " << result << endl;
}

void my_functions::convert_string_using_rangefor()
{
	string s = "hello world";
	for(auto& c : s)
	{
		c = 'X';
	}
	cout << s << endl;
}

void my_functions::convert_string_using_for()
{
	string s = "hello world";
	for (decltype(s.size()) index = 0; index != s.size(); ++index)
	{
		s[index] = 'X';
	}
	cout << s << endl;
}

void my_functions::convert_string_using_while()
{
	string s = "hello world";
	decltype(s.size()) index = 0;
	while(index != s.size())
	{
		s[index] = 'X';
		++index;
	}
	cout << s << endl;
}

void my_functions::delete_punct_in_string()
{
	string s = "hello,world";
	string result;
	for(char& c:s)
	{
		if(!ispunct(c))
		{
			result += c;
		}
	}
	cout << result << endl;
}

void my_functions::reference_and_const()
{
	const string s = "Keep out!";
	for(auto& c:s)
	{
		cout << c << endl;
	}
}

void my_functions::vertor_template_constructor()
{
	vector<int> v1;
	vector<int> v2 = v1;
	vector<int> v3(v2);
	vector<int> v4(3, 4);
	vector<int> v5(3);
	vector<int> v6{ 2,3,4,5,6 };
	vector<int> v7 = { 2,3,4,5,6 };
	vector<string> v8 = { 10,"hi" };
}

void my_functions::read_int_into_vector()
{
	vector<int> v1;
	int num;
	while(cin>>num)
	{
		v1.push_back(num);
	}
}

void my_functions::read_string_into_vector()
{
	vector<string> v1;
	for (string str; cin >> str; v1.push_back(str));
}

void my_functions::test_rangefor_vector()
{
	string s = "hello world";
	vector<char> v1;
	for(auto c:s)
	{
		v1.push_back(c);
	}
}

void my_functions::store_score_in_vector()
{
	string texts[14] = { "42","65","95","100","39","67","95","76","88","76","83","92","76","93" };
	vector<int> mark_map(11,0);
	for(string score:texts)
	{
		stringstream machine(score);
		int a;
		machine >> a;
		mark_map[a / 10]++;
	}
	for(auto x:mark_map)
	{
		cout << x << " ";
	}
}

void my_functions::signed_and_unsigned()
{
	int a = -1;
	unsigned b = 1;
	cout << a*b << endl;	// a large number
	cout << b*a << endl;	// a large number

	// conclusion: int will be converted to unsigned int anyway

	
}

void my_functions::override_default_literal()
{
	// move your mouse to right side to see the type
	auto val1 = L'a';
	auto val2 = u8"hi!";	// UTF8
	auto val3 = 42ULL;
	auto val4 = 1E-3F;
	auto val5 = 3.14159L;
	auto val6 = L"a";
	auto val7 = 10.;	// no "f" specified is always double
	int day = 07;
	//	int month = 09; // in vaild because 9 is out of the bound of octal
	// 1024f is invalid because f suffix can only be applied to floating point literals

}
