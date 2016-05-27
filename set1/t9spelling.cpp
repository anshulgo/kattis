#include <iostream>
#include <algorithm>


using namespace std;
// #include <boost/algorithm/string.hpp>
// using namespace boost::algorithm;

// static inline void rtrim(std::string &s) {
//     s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
// }

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
}

int main()
{
	int t;
	cin >> t;
	string temp;
	getline(cin, temp);

	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		string text;
		getline(cin, text);
		// ltrim(text);
		rtrim(text);
		// trim_right(text);
		int prevnum = -1;
		for(int j = 0; j < text.length(); ++j)
		{
			int conv = text[j] - 'a';
			// cout << endl << endl << conv/3 + 2 << prevnum << endl << endl;
			if(text[j] == ' ')
			{
				conv = 25;
			}
			// cout << "conv is " << conv << ' ' << prevnum << endl;
			if(prevnum != -1)
			{
				if(conv <= 17 && conv >= 0)
				{
					if(prevnum == conv/3 + 2)
					{
						cout << ' ';
					}
				}
				else if(conv == 18 & prevnum == 7)
				{
					cout << ' ';
				}
				else if((conv == 19 || conv == 20 || conv == 21) && prevnum == 8)
				{
					cout << ' ';
				}
				else if(conv > 21 && prevnum == 9)
				{
					cout << ' ';
				}
				else if(conv == 25 && prevnum == 25)
				{
					cout << ' ';
				}
			}
			if (text[j] == ' ')
			{
				prevnum = 25;
				cout << 0;
			}
			else if(conv <= 17 && conv >= 0)
			{
				int num = conv/3;
				num += 2;
				prevnum = num;
				int rep = conv%3;
				if(rep == 1)
				{
					num = num*10 + num;
				}
				else if(rep == 2)
				{
					num = num*100 + num*10 + num;
				}
				cout << num;

			}
			else if(conv == 18)
			{
				prevnum = 7;
				cout << 7777;
			}
			else if(conv > 18 && conv < 22)
			{
				prevnum = 8;
				if(conv == 19)
				{
					cout << 8;
				}
				else if(conv == 20)
				{
					cout << 88;
				}
				else
				{
					cout << 888;
				}
			}
			else if(conv > 21)
			{
				prevnum = 9;
				if(conv == 22)
				{
					cout << 9;
				}
				else if(conv == 23)
				{
					cout << 99;
				}
				else if(conv == 24)
				{

					cout << 999;
				}
				else 
				{
					cout << 9999;
				}

			}
		}
		cout << endl;
	}
	
	return 0;
}