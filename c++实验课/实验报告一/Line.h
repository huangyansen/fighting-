class Line//�߿�
{
private:
	int x,y;//�ο��㣬���ھ�����˵�����Ͻǵĵ㣬����Բ��˵��Բ��
	int thick;//��ϸ
	char color[10];//��ɫ

public:
	Line(int x=0,int y=0,int thick=0.1,char* color=NULL);

	void show();
};