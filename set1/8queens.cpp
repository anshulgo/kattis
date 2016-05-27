#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	char a[8][8];
	int total = 0;
	for(int i = 0; i < 8; i++)
	{
		int sum = 0;
		for (int j = 0; j < 8; j++)
		{
			// cout << i << j << endl;
			char temp;
			cin >> temp;
			if(temp == '.')
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = 1;
				sum += 1;
				total += 1;
			}
		}
		if(sum != 1)
		{
			// cout << "1";
			cout << "invalid";
			return 0;
		}
	}

	if(total != 8)
	{
		cout << "invalid";
		return 0;
	}

	for(int i = 0; i < 8; i++)
	{
		int sum = 0;
		for (int j = 0; j < 8; j++)
		{
			// cout << j << i << endl;
			if(a[j][i] == 1)
			{
				sum += 1;
			}
		}

		if(sum != 1)
		{
			// cout << "2";
			cout << "invalid";
			return 0;
		}

	}
	// cout << endl;
	int sum = 0, n_sum = 0;
	for(int i = 0; i < 8; i++)
	{
		// cout << 7-i << i << endl;
		if(a[i][i] == 1)
		{
			sum += 1;
		}
		if(a[7-i][i] == 1)
		{
			n_sum += 1;
		}
		
	}
	if(sum > 1 || n_sum > 1)
	{
		// cout << "3";
		cout << "invalid";
		return 0;
	}
	// cout << endl << endl << endl;
	for(int k = 1; k < 8; k++)
	{
		int sum1 = 0;
		int sum2 = 0;
		int sum3 = 0;
		int sum4 = 0;
		for (int i = 0, j = (i + k); j < 8 && i < 8; i++, j++)
		{
			// cout << 7-i << j << endl;
			if(a[i][j] == 1)
			{
				sum1 += 1;
				// cout << i << j << endl;
			}

			if(a[j][i] == 1)
			{
				sum2 += 1;
			}
			if(a[i][7-j] == 1)
			{
				sum3 += 1;
			}
			if(a[7-i][j] == 1)
			{
				sum4 += 1;
			}
		}
		// cout << endl;
		if(sum1 > 1 || sum2 > 1 || sum3 > 1 || sum4 > 1)
		{
			// cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << endl;
			// cout << k << " " << endl;
			// cout << "4";
			cout << "invalid";
			return 0;
		}
	}

	cout << "valid";

	return 0;
}