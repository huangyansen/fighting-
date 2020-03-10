#include<iostream>
using namespace std;

class Clock{
	private:
		int H,M,S;
	public:
		Clock(int h=0,int m=0,int s=0)
		{
			H=h,M=m,S=s;
			//cout<<"constructor"<<H<<":"<<M<<":"<<S<<endl;
		}
		
		Clock(Clock &p)
		{
			H=p.H;
			M=p.M;
			S=p.S;
		}

		void Show()
		{
			cout<<H<<":"<<M<<":"<<S<<endl;
		}

		~Clock()
		{
			//cout<<"destructor"<<H<<":"<<M<<":"<<S<<endl;
		}
		
};

int main()
{
	Clock c1(1,2,3);
	//Clock c2(c1);
	c1.Show;
	//c2.Show;
	return 0;
}
