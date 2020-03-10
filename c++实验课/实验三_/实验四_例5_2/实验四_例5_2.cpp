#include<iostream>
using namespace std;

class Clock{
	private:
		int H,M,S;
	public:
		Clock(int h=0,int m=0,int s=0)
		{
			H=h,M=m,S=s;
			cout<<"constructor"<<H<<":"<<M<<":"<<S<<endl;
		}

		~Clock()
		{
			cout<<"destructor"<<H<<":"<<M<<":"<<S<<endl;
		}
		
};

Clock c1(8,0,0);
Clock c2(30,0,0);

int main()
{
	Clock c3(1,2);
	Clock c4(10);
	Clock c5(7,8,9);
	return 0;
}
