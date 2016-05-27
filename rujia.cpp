#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int n,m;

	cin >> n >> m;
	map<int , vector<int> > a;

	for (int i = 0; i < n; ++i)
	{	
		int temp;
		cin >> temp;
		a[temp].push_back(i+1);
	}

	for (int i = 0; i < m; ++i)
	{
		int k,v;
		cin >> k >> v;
		if(a.count(v) == 0 && a[v].size() < k)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << a[v][k-1] << endl;
		}
	}
	return 0;
}