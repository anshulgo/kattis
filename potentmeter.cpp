#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class seg_tree
{
	public:
		seg_tree *left, *right;
		int from, to, value;
		seg_tree(int from, int to) : from(from), to(to), left(NULL), right(NULL), value(0){}
};

seg_tree* build(const vector<int> &a, int l, int r)
{
	if(l>r) 
	{
		return NULL;
	}

	seg_tree *res = new seg_tree(l,r);
	if(l==r)
	{
		res->value = a[l];
	}
	else
	{
		int m = (l+r)/2;
		res->left = build(a,l,m);
		res->right = build(a,m+1,r);
		if(res->left != NULL)
		{
			res->value += res->left->value;
		}

		if(res->right != NULL)
		{
			res->value += res->right->value;
		}
	}

	return res;
}

int query(seg_tree *t, int l, int r)
{
	// cout << "from " << t->from << " to " << t->to << endl; 
	if(t == NULL)
	{
		return 0;
	}
	if((l <= t->from) && (t->to <= r))
	{
		return t->value;
	}
	if(l>t->to)
	{
		return 0;
	}
	if(r<t->from)
	{
		return 0;
	}
	return query(t->left,l,r) + query(t->right,l,r);
}

int update(seg_tree *t, int i, int value)
{
	if(t == NULL)
	{
		return 0;
	}
	if(t->to  < i)
	{
		return t->value;
	}
	if(t->from > i)
	{
		return t->value;
	}
	if((t->from == t->to) && (t->from == i))
	{
		t->value = value;
	}
	else
	{
		t->value = update(t->left,i,value) + update(t->right,i,value);
	}
	return t->value;
}

int main()
{
	string temp;
	int count = 1;
	while(getline(cin,temp))
	{
		// cout << "inside " << temp << endl;
		int n = atoi(temp.c_str());
		if(n == 0)
		{
			break;
		}
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		string str;
		cin >> str;
		seg_tree *t = build(a,0,n-1);
		cout << "CASE " << count << ":" << endl;
		// cout << endl << endl;
		while(str != "END")
		{
			int p,q,result;
			cin >> p >> q;

			if(str == "M")
			{
				// cout << "M " << p << " " << q << endl;
				result = query(t,p-1,q-1);
				cout << result << endl;
			}
			else
			{
				update(t,p-1,q);				
				// cout << "S " << p << " " << q << endl;
			}

			cin >> str;
		}
		cout << endl;


		getline(cin,temp);
	}

	return 0;
}