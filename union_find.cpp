#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;


class union_find 
{
	public:
		
		union_find(int n) 
		{
			parent = vector<int>(n+1);
			for (int i = 1; i < n+1; i++) 
			{
				parent[i] = i;
			}
		}

		int find(int x);
		void unite(int x, int y);
		int max();
		~union_find();
		// void insert(int x);

	private:
		vector<int> parent;
// find and union
};

union_find :: ~union_find(void)
{

}
int union_find:: find(int x) 
{
	if (parent[x] == x) 
	{
		return x;
	}
	else
	{
		parent[x] = find(parent[x]);
		return parent[x];
	}
}

void union_find:: unite(int x, int y)
{
	parent[find(x)] = find(y);
}

int union_find:: max()
{
	int m = 0, n = parent.size();
	int a[n],i = 0;
	vector<int>:: iterator it;
	for (int i = 0; i < n; ++i)
	{
		a[i] = 0;
	}
	for (it = parent.begin()+1; it!= parent.end(); it++)
	{
		a[find(*it)] += 1;
		i++;
		if(a[find(*it)] > m)
		{
			m = a[find(*it)];
		}

	}
	return m;
}

// void union_find:: insert(int x)
// {
// 	parent.push_back(x);
// }
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n,m;
		cin >> n >> m;
		union_find a(n);

		int temp1, temp2;
		for (int j = 0; j < m; ++j)
		{
			cin >> temp1 >> temp2;
			a.unite(temp1, temp2);
		}
		cout << a.max() << endl;
	}	
	return 0;
}