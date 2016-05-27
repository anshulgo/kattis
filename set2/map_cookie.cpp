#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	string temp;
	map<int, int> a;
	map<int, int>::iterator it;
	map<int, int>::iterator *del;
	// int t;
	// cin >> t;
	// a[t] = t;
	// int change = 1;

	while(getline(cin, temp))
	{
		if (temp == "#")
		{
			// int size = a.size();
			// int i = 0;

			// for(it = a.begin(); i<(size/2); it++, i++)
			// {

			// }

			cout << (*it).first << endl;
			int val = (*it).first;
			if (a.size()%2 == 0)
			{
				// cout << "entered" << endl;
				// cout << "in " << endl;
				it--;
				// (*del)--;
				// cout << "out " << endl;
			}
			else
			{
				it++;
			}

			
			a.erase(val);
			// cout << a.size() << endl;

			// del = &it;
			// cout << "after " << (*it).first << endl;
		}
		else
		{
			int val = atoi(temp.c_str());
			a[val] = val;
			if (a.size() == 1)
			{
				it = a.begin();
				// *del = a.begin();
			}
			else if (a.size()%2 == 0)
			{
				// it--;
				if((*it).first < val)
				{
					it++;
				}
				// cout << "here " << (*it).first << endl;
				// (*del)++;
			}
			else if(a.size()%2 == 1)
			{
				// cout << "entered";
				if((*it).first > val)
				{
					it--;
				}
			}
			// cout << "value is " << (*it).first << endl;
		}
	}

	return 0;
}