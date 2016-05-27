#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n, count = 0, set1;
		cin >> n;
		map<string, int> m;
		map<string, int> :: iterator it;
		vector<set<string> > a;
		// cout << endl;
		for (int j = 0; j < n; ++j)
		{
			string s1, s2;
			cin >> s1 >> s2;
			it = m.find(s1);
			// cout << s1 << " " << s2 << endl;
			if(it != m.end())
			{
				set1 = m[s1];
			}
			else
			{

				m[s1] = count;
				// cout << s1 << endl;
				set<string> tempo;
				tempo.insert(s1);
				a.push_back(tempo);
				// a[count].insert(s1);
				set1 = count;
				// cout << "flag1" << endl;
				count++;
			}
			// cout << "flag1" << endl;
			it = m.find(s2);
			if(it != m.end())
			{
				int set2 = m[s2];
				if(set2 != set1)
				{
					set<string>::iterator ita;
					string s;
					if(a[set2].size() < a[set1].size())
					{
						// cout << set1 << " " << m[s2] << endl;
						for(ita = a[set2].begin(); ita!= a[set2].end(); ita++)
						{
							// cout << *ita << endl;
							a[set1].insert(*ita);
							m[*ita] = set1;
							// cout << "m is " << *ita << " " << m[*ita] << endl;
							// cout << "flag1 " << endl;
						}
						// cout << "flag1 " << endl;
					}
					else
					{
						for(ita = a[set1].begin(); ita!= a[set1].end(); ita++)
						{
							a[set2].insert(*ita);
							m[*ita] = set2;
						}
						set1 = set2;
					}
					
				}
			}
			else
			{
				// cout << "entered " << endl;
				m[s2] = set1;
				a[set1].insert(s2);
			}

			cout << a[set1].size() << endl;
			// cout << "length of a is" << a.size() << endl;

			// set<string>::iterator ita;
			// if(a[set1].size() == 8)
			// {
			// 	cout << "1st " << endl;
			// 	for(ita = a[0].begin(); ita!= a[0].end(); ita++)
			// 	{
			// 		cout << (*ita) << endl;
			// 	}

			// 	cout << "2nd " << endl;
			// 	for(ita = a[1].begin(); ita!= a[1].end(); ita++)
			// 	{
			// 		cout << (*ita) << endl;
			// 	}

			// 	cout << "3rd " << endl;
			// 	for(ita = a[2].begin(); ita!= a[2].end(); ita++)
			// 	{
			// 		cout << (*ita) << endl;
			// 	}
			// }

		}
	}

	return 0;
}