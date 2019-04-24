#include<iostream>
using namespace std;

class Point{
private:
	int x,y;
public:
	Point(int _x=0, int _y=0)
	{
		x=_x;
		y=_y;
	}

	int getX();
	int getY();
	void setX(int);
	void setY(int);
} ;


int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

void Point::setX(int newX)
{
	x=newX;
}

void Point::setY(int newY)
{
	y=newY;
}

int main()
{
	Point p1;
	cout<<"el valor de x es: "<<p1.getX()<<endl;
	cout<<"El valor de y es: "<<p1.getY();
	Point p2(3,5);
	p2.setX(12345);
    cout<<"el valor de x es: "<<p2.getX()<<endl;
	cout<<"El valor de y es: "<<p2.getY();

	return 0;
}
