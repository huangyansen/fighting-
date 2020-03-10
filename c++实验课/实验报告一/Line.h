class Line//线框
{
private:
	int x,y;//参考点，对于矩形来说是左上角的点，对于圆来说是圆心
	int thick;//粗细
	char color[10];//颜色

public:
	Line(int x=0,int y=0,int thick=0.1,char* color=NULL);

	void show();
};