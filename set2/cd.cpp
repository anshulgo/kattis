#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int temp,result;
	

	while(n != 0 && m!= 0)
	{
		int a[n], b[m];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> b[i];
		}
		
		result = 0;
		for (int i=0, j=0; i<n && j<m;)
		{
			if (a[i] < b[j] )
			{
				i++;
			}
			else if (b[j] < a[i])
			{
				j++;
			}
			else
			{
				result += 1;
				i++;
				j++;
			}
		}
		cout << result << endl;
		cin >> n >> m;
	}
	return 0;
}