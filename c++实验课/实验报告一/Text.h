class Text//�ı�
{
private:
	int size;//��С
	char* content;//���ݣ���Ҫ��̬����
	char color[10];//��ɫ

public:
	Text(int size, char* content=NULL, char* color=NULL);
	
	Text(){cout<<"��\n";}//�յĹ��캯��

	Text(Text& T);//����

	void show();

	~Text();
};