#include<bits/stdc++.h>
using namespace std;
int main()
{
	string sign;
	
	cin>>sign;
	int i;
	int l=sign.length();
	stack <char> st;
	for(i=0;i<l;i++)
	{
		if(st.empty())
			st.push(sign[i]);
		else
		{
			if(st.top()==sign[i])
				st.pop();
			else
				st.push(sign[i]);
		}
	}
	if(st.empty())
		cout<<"Yes";
	else
		cout<<"No";


}