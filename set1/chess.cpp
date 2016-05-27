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
		char c;
		cin >> c;
		int a = c - 'A';
		int b;
		cin >> b;
		b -= 1;

		cin >> c;
		int p = c - 'A';
		int q;
		cin >> q;
		q -= 1;

		// cout << a << b << ' ' << p << q << endl;

		if((a+b) % 2 != (p+q) % 2)
		{
			cout << "Impossible" << endl;
		}
		else
		{
			vector<int> ab;
			vector<int> pq;

			ab.push_back(a*10 + b);
			pq.push_back(p*10 + q);

			for (int j = a+1, k = b+1; j<8 && k<8 ; ++j, ++k)
			{
				ab.push_back(j*10 + k);
			}
			for(int  l = p+1, m = q+1; l<8 && m<8; ++l, ++m)
			{
				pq.push_back(l*10 + m);
			}

			for (int j = a+1, k = b-1; j<8 && k>=0 ; ++j, --k)
			{
				ab.push_back(j*10 + k);
			}
			for(int  l = p+1, m = q-1; l<8 && m>=0; ++l, --m)
			{
				pq.push_back(l*10 + m);
			}

			for (int j = a-1, k = b+1; j>=0 && k<8 ; --j, ++k)
			{
				ab.push_back(j*10 + k);
			}
			for(int  l = p-1, m = q+1; l>=0 && m<8; --l, ++m)
			{
				pq.push_back(l*10 + m);
			}

			for (int j = a-1, k = b-1; j>=0 && k>=0 ; --j, --k)
			{
				ab.push_back(j*10 + k);
			}
			for(int  l = p-1, m = q-1; l>=0 && m>=0; --l, --m)
			{
				pq.push_back(l*10 + m);
			}

			// for (vector<int>::iterator it = ab.begin(); it != ab.end(); ++it)
			// {
   //  			cout << ' ' << *it;
			// }

   //  		cout << endl;
   //  		for (vector<int>::iterator it = pq.begin(); it != pq.end(); ++it)
   // 			{
   // 				std::cout << ' ' << *it;
   // 			}

			if(a*10 + b == p*10 + q)
			{
				char first = 'A'+a;
				cout << 0 << " " << first << " " << b+1 << endl;
				// return 0;
				continue;
			}
			vector<int>::iterator one;
			one = find(ab.begin(), ab.end(), (p*10 + q));
			if(one != ab.end())
			{
				char first = 'A'+a, second = 'A'+p;
				cout << 1 << " " << first << " " << b+1 << " " << second << " " << q+1 << endl;
			}
			else
			{
				sort(ab.begin(), ab.end());
				sort(pq.begin(), pq.end());
				vector<int> common;

				set_intersection(ab.begin(), ab.end(), pq.begin(), pq.end(), std::back_inserter(common));
				int c = common.front();
				char first = 'A'+a, second = 'A'+(c/10), third = 'A'+p;
				cout << 2 << " " << first << " " << b+1 << " " << second << " " << (c%10) + 1 << " " << third << " " << q+1 << endl;
				// cout << endl;
				// for (vector<int>::iterator it = common.begin(); it != common.end(); ++it)
				// {
	   //  			cout << ' ' << *it;
				// }
				// cout << endl;				
			}

		}

	}
	return 0;
}