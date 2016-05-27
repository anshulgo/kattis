#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		int n, length = 10, pos, result=1;
		cin >> n;
		string a[n];
		string temp;
		getline(cin,temp);

		for (int j = 0; j < n; ++j)
		{
			getline(cin, a[j]);
			// cout << a[j] << endl;
			if(length > a[j].length())
			{
				length = a[j].length();
				pos = j;
			}
		}
		// cout << "length is " << length << endl;
		// for (int i = 0; i < n; ++i)
		// {
		// 	cout << i << " " << a[i] << endl;
		// }

		map<string, string> m;
		map<string, string>:: iterator it;
		string subs1, subs2;

		temp = a[0].substr(0,length);
		m[temp] = a[0];


		for (int j = 1; j < n; ++j)
		{
			temp = a[j].substr(0,length);
			it = m.find(temp);

			if(it == m.end())
			{
				m[temp] = a[j];
			}
			else
			{
				temp = it->second;
				int l1 = temp.length();
				int l2 = a[j].length();
				if (l1 > l2)
				{
					subs1 = temp.substr(0, l2);
					if (subs1 == a[j])
					{
						result = 0;
						break;
					}
				}
				else
				{
					subs1 = a[j].substr(0,l1);
					if (subs1 == temp)
					{
						result = 0;
						break;
					}
				}


				subs1 = temp.substr(0, length+1);
				subs2 = a[j].substr(0,length+1);
				int k = 2;
				while(subs1 == subs2)
				{
					// cout << subs1 << " " << subs2 << endl;
					// cout << "k is " << k;
					subs1 = temp.substr(0, length+k);
					subs2 = a[j].substr(0,length+k);
					k++;
				}
				m[subs2] = a[j]; 
				// if ((subs1 == temp || subs2 == a[j]))
				// {
				// 	cout << subs1 << " " << subs2 << endl;
				// 	result = 0;
				// }
				
			}
		}
		if (result == 0)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}

	}

	return 0;
}