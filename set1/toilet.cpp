#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string pos;
	getline(cin,pos);
	int res1, res2, res3;
	int length = pos.length();
	res3 = 0;
	res1 = 0;
	res2 = 0;
	// if(pos[0] == 'U')
	// {
	// 	res2 = 1;
	// }
	// else
	// {
	// 	res1 = 1;
	// }

	for (int i = 1; i < length; ++i)
	{
		if(pos[i-1] != pos[i])
		{
			res3 += 1;
		}

		if(pos[i] == 'U')
		{
			if(i != 1)
			{
				res2 += 2;
			}
			else
			{
				if(pos[i-1] == 'D')
				{
					res2 += 2;
					res1 += 1;
				}
				else
				{
					res2 += 1;
				}
			}
		}
		else
		{
			if(i != 1)
			{
				res1 += 2;
			}
			else
			{
				if(pos[i-1] == 'U')
				{
					res1 += 2;
					res2 += 1;
				}
				else
				{
					res1 += 1;
				}
			}
		}

		// if(pos[i-1] == 'U' && pos[i] == 'U')
		// {

		// }
		// else if(pos[i-1] == 'U' && pos[i] == 'D')
		// {
		// 	res1 += 2;
		// }
		// else if(pos[i-1] == 'D' && pos[i] == 'U')
		// {
			
		// }
		// else
		// {

		// }
	}

	cout << res1 << endl << res2 << endl << res3;
	
	return 0;
}