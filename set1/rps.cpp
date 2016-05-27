#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n,k;
	cin >> n;
	while(n!= 0)
	{
		cin >> k;
		int cases = k*n*(n-1)/2;
		int a[n], b[n];
		for (int i = 0; i < n; ++i)
		{
			a[i] = 0;
			b[i] = 0;
		}
		for (int i = 0; i < cases; ++i)
		{
			int temp1, temp2;
			string str1, str2;

			cin >> temp1;
			cin >> str1;
			cin >> temp2;
			cin >> str2;

			temp1 -= 1;
			temp2 -= 1;
			
			if(str1 != str2)
			{
				if (str1 == "rock")
				{
					if(str2 == "paper")
					{
						a[temp2] += 1;
						b[temp1] += 1;
					}
					else
					{
						a[temp1] += 1;
						b[temp2] += 1;
					}
				}
				else if(str1 == "paper")
				{
					if(str2 == "rock")
					{
						a[temp1] += 1;
						b[temp2] += 1;
					}
					else
					{
						a[temp2] += 1;
						b[temp1] += 1;
					}
				}
				else if(str1 == "scissors")
				{
					if(str2 == "paper")
					{
						a[temp1] += 1;
						b[temp2] += 1;
					}
					else
					{
						a[temp2] += 1;
						b[temp1] += 1;
					}
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if(a[i] + b[i] != 0)
			{
				float res = (float)a[i]/ ((float)a[i] + (float)b[i]);
				printf("%.3f\n", res);
			}
			else
			{
				cout << "-" << endl;
			}
			

		}
		cout << endl;


		cin >> n;
	}
	return 0;
}