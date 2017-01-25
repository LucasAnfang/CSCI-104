#include "FilenameComp.h"

bool FilenameComp::operator()(WebPage* x, WebPage* y)
{
	return x->filename() < y->filename();
}
