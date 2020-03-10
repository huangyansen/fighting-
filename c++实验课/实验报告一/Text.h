class Text//文本
{
private:
	int size;//大小
	char* content;//内容，需要动态分配
	char color[10];//颜色

public:
	Text(int size, char* content=NULL, char* color=NULL);
	
	Text(){cout<<"空\n";}//空的构造函数

	Text(Text& T);//拷贝

	void show();

	~Text();
};