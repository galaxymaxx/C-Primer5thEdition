#include "std.h"

#include <iostream>
#include <map>

using namespace std;
void std_class::test_map()
{
	map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['b'] = 4;
	first['x'] = 5;
	first.insert(pair<char,int>('e',5));
	/*for(map<char,int>::iterator it = first.begin();it!=first.end();++it)
	{
		cout << it->first << " " << it->second << endl;
	}*/
	map<char, int>::iterator it = first.find('a');
	cout << it->first << " " << it->second << endl;

	cout << first['b'] << endl;
}
