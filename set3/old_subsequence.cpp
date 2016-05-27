#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		string temp;
		getline(cin, temp);

		int n;
		cin >> n;
		int a[n], sum[n];
		cin >> a[0];
		sum[0] = a[0];
		for (int j = 1; j < n; ++j)
		{
			cin >> a[j];
			sum[j] = sum[j-1] + a[j];
		}

		int value=0, j=1, result=0, k=-1, flag1=0, flag2=0;
		// value = sum[0];
		// cout << endl<< endl;
		for (int j = 0; j < n; ++j)
		{
			flag2 = 0;
			if(flag1 == 1)
			{
				value = sum[j] - sum[k];
			}
			else
			{
				value = sum[j];
			}
			// cout << "value is " << value << endl;

			int temp = k+1;
			while(value<47 && a[temp]<0 && temp<j)
			{
				if((value - a[temp]) == 47)
				{
					result += 1;
					k = j;
					flag2 = 1;
					for (int p = temp+1; p < j; ++p)
					{
						if(sum[p] - sum[temp] == 0)
						{
							result += 1;
						}
					}
					for (int p = j+1; p < n; ++p)
					{
						if(sum[p] - sum[j] == 0)
						{
							result += 1;
						}
					}
					break;
				}
				temp += 1;
			}
			if(flag2 == 1)
			{
				continue;
			}
			
			if(value > 47)
			{
				flag1 = 1;
				while(value > 47)
				{
					k += 1;
					value = sum[j] - sum[k];
					// cout << "entered value is " << value << endl;
				}
			}
			
			if(value == 47)
			{
				flag1 = 1;
				result += 1;
				for (int m = k+1; m < j; ++m)
				{
					if(sum[m] - sum[k] == 0)
					{
						result += 1;
					}
				}

				for(int m = j+1; m<n; m++)
				{
					if(sum[m] - sum[j] == 0)
					{
						result += 1;
					}
				}
				// cout << "result increased" << endl;
				k = j;
				// cout << "k is " << k << endl;
			}
		}

		cout << result << endl;
	}

	return 0;
}