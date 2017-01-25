#ifndef OUTGOINGLINKCOMP_H_
#define OUTGOINGLINKCOMP_H_
#include <string>
#include "webpage.h"

class OutgoingLinkComp
{
	public:
		bool operator()(WebPage* x, WebPage* y);
};


#endif /* OUTGOINGLINKCOMP_H_ */