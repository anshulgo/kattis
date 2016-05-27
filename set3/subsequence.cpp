#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct node
{
	int value;
	int index;
}node;

bool acompare(node lhs, node rhs) { return lhs.value < rhs.value; }

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		// cout << endl;
		string temp;
		getline(cin, temp);

		int n;
		cin >> n;

		int a[n], sum[n];
		node b[n];

		cin >> a[0];
		sum[0] = a[0];
		b[0].value = a[0];
		b[0].index = 0;
		for (int j = 1; j < n; ++j)
		{
			cin >> a[j];
			sum[j] = sum[j-1] + a[j];
			b[j].value = sum[j];
			b[j].index = j;
		}

		int result = 0;
		// for (int j = 0; j < n; ++j)
		// {
		// 	cout << "sum " << sum[j] << endl;
		// 	if(sum[j] == 47)
		// 	{
		// 		result += 1;
		// 	}
		// }
		// for (int j = 0; j < n; ++j)
		// {
		// 	for(int k = 0; k < j; k++)
		// 	{
		// 		if(sum[j] - sum[k] == 47)
		// 		{
		// 			result += 1;
		// 			cout << k+2 << " " << j+1 << endl;
		// 		}
		// 	}
		// }
		// cout << "result is " << result << endl;

		// sort(sum, sum+n);
		sort(b, b+n, acompare);
		// for (int j = 0; j < n; ++j)
		// {
		// 	cout << "sum " << sum[j] << " " << b[j].value << " " << b[j].index << endl;
		// }
		int j=0, k=0;
		result=0;
		for (int j = 0; j < n; ++j)
		{
			if(b[j].value == 47)
			{
				result += 1;
			}
		}

		j = 0;
		while(j<n)
		{
			// cout << "condition " << sum[j] << " " << sum[k] << endl;
			// if(sum[j] == 47)
			// {
			// 	result += 1;
			// }
			// if(b[j].value == 47)
			// {
			// 	result += 1;
			// }
			
			// if(sum[j]-sum[k] < 47)
			// {
			// 	j++;
			// }
			if(b[j].value-b[k].value < 47)
			{
				j++;
			}
			// else if(sum[j]-sum[k] > 47)
			// {
			// 	k++;
			// }
			else if(b[j].value-b[k].value > 47)
			{
				k++;
			}
			else if(b[j].value-b[k].value == 47)
			{
				// cout << sum[j] << " " << sum[k] << endl;
				int temp1 = 0, temp2 = 0, temp3 = b[j].value, temp4 = b[k].value;
				// if(b[j].index > b[k].index)
				// {
				// 	result += 1;
				// }
				while(k+temp1<j && b[k+temp1].value == temp4)
				{
					temp2 = 0;
					while(j+temp2<n && b[j+temp2].value == temp3)
					{
						if(b[j+temp2].index > b[k+temp1].index)
						{
							result += 1;
						}
						temp2 += 1;
					}
					
					temp1 += 1;
				}
				j = j+temp2-1;
				k = k+temp1;
				// k++;
			}
			// else if(sum[j]-sum[k] == 47)
			// {
			// 	cout << sum[j] << " " << sum[k] << endl;
			// 	int count1 = 1;
			// 	int count2 = 1;
			// 	while(k+1<j && sum[k+1] == sum[k])
			// 	{
			// 		cout << sum[j] << " " << sum[k] << endl;
			// 		// result += 1;
			// 		cout << "a" << endl;
			// 		count1 += 1;
			// 		k += 1;
			// 	}

			// 	int sub = 0;
			// 	while(j+1<n && sum[j+1] == sum[j])
			// 	{
			// 		if(sum[j] == 47)
			// 		{
			// 			result += 1;
			// 			sub = -1;
			// 		}
			// 		cout << sum[j] << " " << sum[k] << endl;
			// 		// result += 1;
			// 		cout << "b" << endl;
			// 		count2 += 1;
			// 		j += 1;
			// 	}
			// 	result += sub;
			// 	result += count1*count2;
			// 	k++;				
			// }
		}

		cout << result << endl;


	}

	return 0;
}