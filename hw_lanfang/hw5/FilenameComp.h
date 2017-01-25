

#ifndef FILENAMECOMP_H_
#define FILENAMECOMP_H_
#include <string>
#include "webpage.h"

class FilenameComp
{
	public:
		bool operator()(WebPage* x, WebPage* y);
};


#endif /* FILENAMECOMP_H_ */
