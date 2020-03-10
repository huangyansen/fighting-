#include <stdio.h>
#include <iostream>
using namespace std;

class Auto
{
private:
	int power;

public:
	Auto(int power)
	{
		this->power=power;
		cout<<"construct Auto\n";
	}

	void show()
	{
		cout<<"power is:"<<power<<endl;
	}

	~Auto()
	{
		cout<<"destory Auto\n";
	}
};

class Car: virtual public Auto 
{
private:
	int seat;

public:
	Car(int seat,int power):Auto(power)
	{
		this->seat=seat;
		cout<<"construct Car\n";
	}

	void show()
	{
		cout<<"seat is:"<<seat<<endl;
	}

	~Car()
	{
		cout<<"destory Car\n";
	}
};

class Wag: virtual public Auto 
{
private:
	int load;

public:
	Wag(int load,int power):Auto(power)
	{
		this->load=load;
		cout<<"construct Wag\n";
	}

	void show()
	{
		cout<<"load is:"<<load<<endl;
	}

	~Wag()
	{
		cout<<"destory Wag\n";
	}
};

class SW: public Car,public Wag
{
public:
	SW(int power,int seat,int load):Auto(power),Car(seat,power),Wag(load,power)
	{
		cout<<"construct SW\n";
	}
	
	void show()
	{
		cout<<"the message of SW:\n";
		Car::show();
		Wag::show();
	}

	~SW()
	{
		cout<<"destory SW\n";
	}
};

int main()
{
	SW sw(10,20,30);
	sw.show();
	return 0;
}