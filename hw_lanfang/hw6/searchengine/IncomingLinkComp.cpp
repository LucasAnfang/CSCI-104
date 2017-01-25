#include "IncomingLinkComp.h"


bool IncomingLinkComp::operator()(WebPage* x, WebPage* y)
{
	return x->incoming_links().size() < y->incoming_links().size();
}