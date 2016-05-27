#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
	string temp;
	priority_queue<int, vector<int>, std::greater<int> > max;
	priority_queue<int> min;

	while(getline(cin, temp))
	{
		if (temp == "#")
		{
			int result = min.top();
			min.pop();

			int temp;
			if(!max.empty() && (min.size() == max.size()))
			{
				temp = max.top();
				max.pop();
				min.push(temp);
			}
			cout << result << endl;
		}
		else
		{
			int val = atoi(temp.c_str());
			int temp;

			if(min.empty() || min.size() == 1)
			{
				min.push(val);
				// cout << min.top() << endl;
			}
			else if(min.size() == max.size() + 1)
			{
				if(max.top() >= val)
				{
					min.push(val);
				}
				else
				{
					temp = max.top();
					max.pop();
					max.push(val);
					min.push(temp);
				}
				
			}
			else if(min.size() > max.size() + 1)
			{
				if(min.top() <= val)
				{
					max.push(val);
				}
				else
				{
					temp = min.top();
					min.pop();
					min.push(val);
					max.push(temp);
				}
			}
		}
	}


	return 0;
}