#include<iostream>
using namespace std;

class Clock{
	private:
		int H,M,S;
	public:
		void SetTime(int h,int m,int s)
		{
			H=(h>=0&&h<24)?h:0;
			M=(m>=0&&m<60)?m:0;
			S=(s>=0&&s<60)?s:0;
		}

		void ShowTime()
		{
			cout<<H<<":"<<M<<":"<<S<<endl;
		}
};

int main()
{
	Clock myclock;
	myclock.ShowTime();
	myclock.SetTime(8,30,30);
	myclock.ShowTime();
	return 0;
}
