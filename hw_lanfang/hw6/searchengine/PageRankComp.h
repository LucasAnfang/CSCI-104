#ifndef PAGERANKCOMP_H_
#define PAGERANKCOMP_H_
#include <string>
#include "webpage.h"

class PageRankComp
{
	public:
		bool operator()(WebPage* x, WebPage* y);
};


#endif /* PAGERANKCOMP_H_ */