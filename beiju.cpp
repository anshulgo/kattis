#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string str = "";
	getline(cin, str);
	int pos = 0;
	string output = "";

	for (int i = 0; i < str.length(); ++i)
	{
		if(str[i] == '[')
		{
			pos = 0;
			continue;
		}
		else if (str[i] == ']')
		{
			pos = output.length();
		}
		else
		{
			output.insert(pos, 1, str[i]);
			pos += 1;
		}

	}
	cout << endl;
	cout << output << endl;
}