#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int i = 3;
	int x = (1<<5) | (1<<i) | (1<<4) | (1<<5);
	int y = (1<<4);
	int z = ~x & ((1<<n)-1);
	cout << z << endl;

	return 0;
}