#include <iostream>

using namespace std;

class Cdummy{
public:
	static int n;
	Cdummy(){
		++n;
	}

	~Cdummy()
	{
		--n;
	}

};

int Cdummy::n=0;
int main()
{
	Cdummy a;
	Cdummy b[5];
	Cdummy* c=new Cdummy;
	cout<<a.n<<endl;
	delete c;
	cout<<Cdummy::n<<endl;
	return 0;
}