#include "PageRankComp.h"


bool PageRankComp::operator()(WebPage* x, WebPage* y)
{
	return x->page_rank() < y->page_rank();
}