#include "base.h"
#include "derived.h"
# include "CPPage.h"

int	 main()
{
	CPPage Cpp;
	while(1){
		cout<<"-----Please input the operation in a CPPage-----\n";
		cout<<"1:Add a Rectangle       2:Add a Ellipse\n";
		cout<<"3:Delete a Rectangle    4:Delete a Ellipse\n";
		cout<<"0:Quit the program\n";
		cout<<"------------------------------------\n";

		int t;
		cin>>t;

		switch (t)
		{
		case 0: return 0;
				break;
		case 1:{
				cout<<"Please input the message of the Rectangle\n";
				cout<<"length,width:"; int length,width; cin>>length>>width;
				cout<<"(x,y):"; int x, y; cin>>x>>y;
				cout<<"thick of Line:"; int thick; cin>>thick;
				cout<<"color of Line:"; char c1[10]; cin>>c1;
				cout<<"size of Text:"; int size; cin>>size;
				cout<<"content of Text:"; char content[100]; cin>>content;
				cout<<"color of Text:"; char c2[10]; cin>>c2;
				Rectangle rec(length,width,x,y,thick,c1,size,content,c2);
				Cpp.AddR(rec);
				Cpp.show();
				break;
			   }
		case 2: {
				cout<<"Please input the message of the Ellipse\n";
				cout<<"radius:"; int radius; cin>>radius;
				cout<<"(x,y):"; int x, y; cin>>x>>y;
				cout<<"thick of Line:"; int thick; cin>>thick;
				cout<<"color of Line:"; char c1[10]; cin>>c1;
				cout<<"size of Text:"; int size; cin>>size;
				cout<<"content of Text:"; char content[100]; cin>>content;
				cout<<"color of Text:"; char c2[10]; cin>>c2;
				ellipse ell(radius,x,y,thick,c1,size,content,c2);
				Cpp.AddE(ell);
				Cpp.show();
				break;
				}
		case 3:Cpp.DelR();
			   Cpp.show();
			   break;
		case 4:Cpp.DelE();
			   Cpp.show();
			   break;
	}

		}
/*	char s[]="World!"; 

	Text t1(1,s,"red");//Text类
	Rectangle Rec1(10,20,2,5,3,"black",t1);//构造
	Rec1.show();
	Rectangle Rec2(Rec1);
	Rec2.show();

	CPPage Cpp1;
	Cpp1.AddR(Rec1);
	Cpp1.AddR(Rec2);//增加两个矩形
	Cpp1.show();
	cout<<endl;
	Cpp1.DelR();//删去一个矩形
	Cpp1.show();
*/
	return 0;
}