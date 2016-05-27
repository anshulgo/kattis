#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main()
{
	string temp;
	while(getline(cin,temp))
	{
		int cases = atoi(temp.c_str());
		int comm, val, s_val, q_val, p_val;
		stack<int> s;
		queue<int> q;
		priority_queue<int> p;
		int a[3] = {1, 1, 1};

		for (int i = 0; i < cases; ++i)
		{
			cin >> comm >> val;
			if(comm == 1)
			{
				s.push(val);
				q.push(val);
				p.push(val);
			}
			else
			{
				if (s.empty())
				{
					a[0] = 0;
					a[1] = 0;
					a[2] = 0;
					continue;
				}
				s_val = s.top();
				q_val = q.front();
				p_val = p.top();
				
				// cout << i << " " << s_val << " " << q_val << " " << p_val << " " << val << endl;
				if (a[0] == 1 && s_val != val)
				{
					a[0] = 0;
					// cout << "entered s" << endl;
				}

				if(a[1] == 1 && q_val != val)
				{
					a[1] = 0;
					// cout << "entered q" << endl;
				}

				if(a[2] == 1 && p_val != val)
				{
					a[2] = 0;
					// cout << "entered p" << endl;
				}
				s.pop();
				q.pop();
				p.pop();
			}

		}

		if(a[0] == 0 && a[1] == 0 && a[2] == 0)
		{
			cout << "impossible" << endl;
		}
		else if(a[0] == 1 && a[1] == 0 && a[2] == 0)
		{
			cout << "stack" << endl;
		}
		else if(a[0] == 0 && a[1] == 1 && a[2] == 0)
		{
			cout << "queue" << endl;
		}
		else if(a[0] == 0 && a[1] == 0 && a[2] == 1)
		{
			cout << "priority queue" << endl;
		}
		else
		{
			cout << "not sure" << endl;
		}


		getline(cin,temp);
	}


	return 0;
}