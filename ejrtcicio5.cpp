#include<iostream>
using namespace std;

class Polygon{

protected:
	static int numPolygons;
	PointArray points;
public:
	Polygon(const PointArray &pa);
	Polygon(const Point points[], const int numPoints);
	virtual double area() const =0;
	static int getNumPolygons(){return numPolygons;}
	int getNumSides()const{return points.getSize();}
	const PointArray *getPoints() const{return &points;}
	~Polygon(){--numPolygons;}

};

int Polygon::n=0;

Polygon::Polygon(const PointArray &pa):points(pa){
	++numPolygons;
}

Polygon::Polygon(const Point pointArr[], const int numPoints):points(pointArr,numPoints){
	++numPolygons;
}


class Rectangle:public Polygon{
public:
	Rectangle(const Point &a, const Point &b);
	Rectangle(const int a, const int b, const int c, const int d);
	virtual doble area() const;
};

Point constructorPoints[4];

Point *updateConstructosPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4=Point(0,0) ){
	constructorPoints[0]=p1;
	constructorPoints[1]=p2;
	constructorPoints[2]=p3;
	constructorPoints[3]=p4;
	return constructorPoints;
}

Rectangle::Rectangle(const Point &ll, const Point &ur):Polygon(updateConstructosPoints(ll,Point(ll.getX(),ur.getY()),ur,Point(ur.getX(),ii.getY())),4){}
Rectangle::Rectangle(const int llx, const int lly, const int urx, cont int ury):Polygon(updateConstructosPoints(Point(llx,lly),Point(llx,ury),Point(urx,ury),Point(urx,lly)),4){}

double Rectangle::area() const{
	int length=points.get(1)->getY()-points.get(0)->getY();
	int width=points.get(2)->getX()-points.get(1)->getX;
	return std::abs((double)length*width);
}


class Triangle:public Polygon{
public:
	Triangle(const Point &a, const Point &b, const Point &c);
	virtual double area() const;
};


Triangle::Triangle(const Point &a, const Point &b, const Point &c):Polygon(updateConstructosPoints(a,b,c),3){}

double Triangle::area() const{
	int dx01=points.get(0)->getX()-points.get(1)->getX(),
		dx12=points.get(1)->getX()-points.get(2)->getX(),
		dx20=points.get(2)->getX()-points.get(0)->getX();
	int	dy01=points.get(0)->getY()-points.get(1)->getY(),
		dy12=points.get(1)->getY()-points.get(2)->getY(),
		dy20=points.get(2)->getY()-points.get(0)->getY();

	double a=std::sqrt(dx01*dx01+dy01*dy01),
			b=std::sqrt(dx12*dx12+dy12*dy12),
			c=std::sqrt(dx20*dx20+dy20*dy20);

	double s=(a+b+c)/2;

	return std::sqrt(s*(s-a)*(s-b)*(s-c));

}


void printAttributes(Polygon *p){
	cout<<"p's area es: "<<p->getPoints();
	cout<<"p's puntos son: ";
	const PointArray *pa=p->getPoints();
	for(int i=0;i<pa->getSize();++i){
		cout<<"("<<pa->get(i)->getX()<<","<<pa->get(i)->getY()<<")\n";
	}
}

int main(int argc, char *argv[])
{
	cout<<"ingresa 4 coordenadas del rectangulo desde el mas bajo al mas mayor:";
	int llx, lly, urx, ury;
	cin>>llx>>lly>>urx>>ury;
	Point ll(llx,lly), ur(urx,ury);
	Rectangle r(ll,ur);
	printAttributes(&r);

	cout<<"Ingres tres coordenadas de triangulo como seis enteros separados por un espacio: ";
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	Point a(x1,y1), b(x2,y2), c(x3,y3);
	Triangle t(a,b,c);
	printAttributes(&t);

	return 0;
}