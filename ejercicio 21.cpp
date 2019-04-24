#include<iostream>
using namespace std;


class Point{
private:
	int x,y;
public:
	Point(int u, int v):x(u),y(v){};
	int getX(){return x;};
	int getY(){return y;};
	void doubleVal()
	{
		x=x*2;
		y=y*2;
	}
};

int main()
{
	Point myPoint(5,3);
	myPoint.doubleVal();
	cout<<myPoint.getX()<<" "<<myPoint.getY()<<endl;
	return 0;
}
