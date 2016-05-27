#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

typedef struct node
{
	long int x;
	long int y;
}node;

// bool acompare(node lhs, node rhs) { return lhs.x < rhs.x; }
// bool bcompare(node lhs, node rhs) { return lhs.y < rhs.y; }

long int diff(node a, node b)
{
	long int d;
	if(a.x > b.x)
	{
		d = a.x - b.x;
	}
	else
	{
		d = b.x - a.x;
	}

	if(a.y > b.y)
	{
		d += a.y - b.y;
	}
	else
	{
		d += b.y - a.y;
	}
	return d;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		vector<node> a;
		// vector<node> b;
		
		node temp;
		for (int i = 0; i <= n+1; ++i)
		{
			cin >> temp.x >> temp.y;

			a.push_back(temp);
			// b.pushback(temp +32768);
		}

		// node start, end;
		// start.x = a[0].x;
		// start.y = a[0].y;
		// end.x = a[n+1].x;
		// end.y = a[n+1].y;

		// int adj[n+2][n+2];
		vector<int> adj[n+2];

		// int rem[n+2];
		// for (int i = 0; i <= n+1; ++i)
		// {
		// 	rem[i] = 0;
		// }
		int sub;

		for (int i = 0; i <= n+1; ++i)
		{
			for (int j = 0; j <= n+1 ; ++j)
			{
				sub = diff(a[i], a[j]);
				// if(i != j && sub <= 1000 - rem[i])
				if(i != j && sub <= 1000)
				{
					// cout << "entered " << i << " " << j << endl;
					adj[i].push_back(j);
					// rem[j] = (sub-rem[i])%50;
					// cout << "i j and rem " << i << " " << j << " " << rem[j] << endl;
					// if(adj[j][i] != 1)
					// {
					// 	adj[i][j] = 1;
					// }
					// else
					// {
					// 	adj[i][j] = 0;
					// }
					
				}
				// else
				// {
				// 	adj[i][j] = 0;
				// }
			}
		}

		// for (int i = 0; i <= n+1; ++i)
		// {
		// 	for (int j = 0; j < adj[i].size(); ++j)
		// 	{
		// 		cout << adj[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		// for (int i = 0; i <= n+1; ++i)
		// {
		// 	for (int j = 0; j <= n+1 ; ++j)
		// 	{
		// 		cout << adj[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		int enter[n+2];
		for (int i = 0; i <= n+1; ++i)
		{
			enter[i] = 0;
		}
		stack<int > s;
		s.push(0);
		enter[0] = 1;
		int temp1, result=0;
		while(!s.empty())
		{
			temp1 = s.top();
			if(temp1 == n+1)
			{
				result = 1;
				break;
			}
			s.pop();
			for (int i = 0; i < adj[temp1].size(); ++i)
			{
				if(enter[adj[temp1][i]] == 0)
				{
					enter[adj[temp1][i]] = 1;
					s.push(adj[temp1][i]);
				}
				
				// if(adj[temp1][i] == n+1)
				// {
				// 	result = 1;
				// 	break;
				// }
			}
		// 	// for (int i = 0; i <= n+1; ++i)
		// 	// {
		// 	// 	if(adj[temp1][i])
		// 	// 	{
		// 	// 		s.push(i);
		// 	// 		if(i == n+1)
		// 	// 		{
		// 	// 			result = 1;
		// 	// 			break;
		// 	// 		}
		// 	// 	}
		// 	// }
		}

		if(result == 1)
		{
			cout << "happy" << endl;
		}
		else
		{
			cout << "sad" << endl;
		}
		// sort(a, a+n+1, acompare);
		// sort(b, b+n+1, bcompare);
		// int posx, posy;

		// for (int i = 0; i <= n+1; ++i)
		// {
		// 	if(start.x == a[i].x && start.y == a[i].y)
		// 	{
		// 		posx = i;
		// 		a.erase(a.begin() + i);
		// 	}
		// 	if(start.x == b[i].x && start.y == b[i].y)
		// 	{
		// 		posy = i;
		// 		b.erase(b.begin() + i);
		// 	}
		// }

		// stack<node> s;
		// s.push(start);
		// int temp=1, result=1;
		// long int rem = 0;
		// while(temp)
		// {
		// 	if(diff(s.top, end) + rem < 1000 )
		// 	{
		// 		break;
		// 	}
		// 	else
		// 	{

		// 	}
		// }



	}

	return 0;
}