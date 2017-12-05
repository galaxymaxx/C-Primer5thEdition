
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
