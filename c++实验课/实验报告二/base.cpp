#include "base.h"

CGraph::CGraph(int type, double thick, char *color)
{
	this->type=type;
	this->thick=thick;
	if(color!=NULL)
		strcpy(this->color,color);
};

CGraph::CGraph(CGraph& G)
{
	this->thick=G.thick;
	this->type=G.type;
	if(G.color!=NULL)
		strcpy(this->color,G.color);
};
