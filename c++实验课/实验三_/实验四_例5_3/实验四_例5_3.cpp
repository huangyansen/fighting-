#include <iostream>
using namespace std;
char* a="123";

class String{
	private:
		int len;
		char* Str;

	public:
		/*String()
		{
			len=3;
			Str=a;
		}*/

		String(char* s=a)//�������캯��
		{
			Str=s;
			if(Str==a)
				len=3;
			else{
				len=strlen(s);
				Str=new char[len+1];
				strcpy(Str,s);
			}
		}

		void ShowStr()
		{
			if(Str==NULL){
				cout<<"���ַ���\n";
				return;
			}
			cout<<"string:"<<Str<<"\nlen:"<<len<<endl;
		}

		~String()
		{
			if(Str!=a){//ע������û����Ϊ����ֵ�����ͷ�
				delete[] Str;
				Str=a;
			}
			cout<<"����!\n";
		}

};

int main()
{
	char s[]="ABCDEF";
	String s1;
	String s2(s);
	String s3("HELLO");
	s1.ShowStr();
	s2.ShowStr();
	s3.ShowStr();
	return 0;
}
