
#include "Functions.h"
#include "IDGenerator.h"
#include <iostream>

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

void my_functions::number_occurrence_counter()
{
	int val;
	auto never_in_game = true;
	auto number_counter = 0;
	auto current_val = 0;
	while(cin>>val)
	{
		if(current_val!=val||never_in_game)
		{
			if(never_in_game)
				current_val = val;

			if(val!=current_val)
				cout << current_val << " occurs " << number_counter << " times" << endl;
			number_counter = 1;
			current_val = val;
			never_in_game = false;
		}
		else
		{
			number_counter++;
		}
	}
	cout << current_val << " occurs " << number_counter << " times" << endl;
}
