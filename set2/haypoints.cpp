#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	int m,n;
	cin >> m >> n;
	map <string, int> a;

	for (int i = 0; i < m; ++i)
	{
		string temp1;
		int temp2;
		cin >> temp1 >> temp2;

		a[temp1] = temp2;
	}

	// for (map<string, int> :: iterator it= a.begin(); it!= a.end(); ++it)
	// {
	// 	cout << it->first << " " << it->second << endl;
	// }
	// char c;
	// cin >> c;
	// cout << c;
	string str = "";
	// getline(cin, str);
	// cout << str[str.length()-1];
	// cout << "print str " << str << endl;
	for (int i = 0; i < n; ++i)
	{
		int result = 0;
		// cin >> str;
		while(cin >> str && str != ".")
		{
			result += a[str];
			// if(a.count(str) != 0)
			// {
			// 	result += a[str];
			// }
			// cin >> str;
			// cout << str << endl;
		}
		cout << result << endl;
		// cout << a["temp"];
	}

	return 0;
}