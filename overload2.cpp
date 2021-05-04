#include<bits/stdc++.h>
using namespace std;
class Point
{
	private:
	int x,y;
	public:
	Point(int i,int j)
	{
		x=i;
		y=j;
	}
	void print()
	{
		cout<<endl<<"x="<<x<<"y="<<y;
	}
};
int main()
{
Point t(20,20);
t.print();
}
