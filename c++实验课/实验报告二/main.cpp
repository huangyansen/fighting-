#include "base.h"
#include "derive.h"

int main()
{
	vector<CGraph*>v0;
	CPPage Cpp(v0);
	while(1){
		cout<<"-----------------Please input the operation in a CPPage-----------------\n";
		cout<<"1:Add a Rectangle       2:Add a Ellipse          3:ADD a CRoundRect\n";
		cout<<"4:Delete a Rectangle    5:Delete a Ellipse       6:Delete a CRoundRect\n";
		cout<<"0:Quit the program\n";
		cout<<"------------------------------------------------------------------------\n";
		
		int t;
		cin>>t;
		switch (t)
		{
		case 0: return 0;break;
		case 1:{
				cout<<"Please input the message of the Rectangle\n";
				cout<<"length,width:"; int length,width; cin>>length>>width;
				cout<<"thick:"; int thick; cin>>thick;
				cout<<"color:"; char c[10]; cin>>c;
				Rectangle rec(length,width,0,thick,c);
				Cpp.ADDR(rec);
				Cpp.show();
				break;
			   }
		case 2: {
				cout<<"Please input the message of the Ellipse\n";
				cout<<"long axis:"; int a; cin>>a;
				cout<<"minor axis:"; int b; cin>>b;
				cout<<"focal length:"; int c; cin>>c;
				cout<<"thick:"; int thick; cin>>thick;
				cout<<"color:"; char color[10]; cin>>color;
				ellipse ell(a,b,c,1,thick,color);
				Cpp.ADDE(ell);
				Cpp.show();
				break;
				}
		case 3: {
				cout<<"Please input the message of the CRoundRect\n";
				cout<<"length,width:"; int length,width; cin>>length>>width;
				cout<<"long axis:"; int a; cin>>a;
				cout<<"minor axis:"; int b; cin>>b;
				cout<<"focal length:"; int c; cin>>c;
				cout<<"thick:"; int thick; cin>>thick;
				cout<<"color:"; char color[10]; cin>>color;
				CRoundRect CR(length,width,a,b,c,2,thick,color);
				Cpp.ADDCR(CR);
				Cpp.show();
				break;
				}
		case 4:
			   int num1;
			   cout<<"Please input the number of the Rectangle\n";
			   cin>>num1;
			   Cpp.Del(0,num1);
			   Cpp.show();
			   break;
		case 5:
			   int num2;
			   cout<<"Please input the number of the Rectangle\n";
			   cin>>num2;
			   Cpp.Del(1,num2);
			   Cpp.show();
			   break;
		case 6:
			   int num3;
			   cout<<"Please input the number of the CRoundRect\n";
			   cin>>num3;
			   Cpp.Del(2,num3);
			   Cpp.show();
			   break;
		}

	}

	return 0;

}