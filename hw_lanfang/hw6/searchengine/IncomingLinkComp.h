#ifndef INCOMINGLINKCOMP_H_
#define INCOMINGLINKCOMP_H_
#include <string>
#include "webpage.h"

class IncomingLinkComp
{
	public:
		bool operator()(WebPage* x, WebPage* y);
};


#endif /* INCOMINGLINKCOMP_H_ */
