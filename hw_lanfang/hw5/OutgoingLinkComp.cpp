#include "OutgoingLinkComp.h"


bool OutgoingLinkComp::operator()(WebPage* x, WebPage* y)
{
	return x->outgoing_links().size() < y->outgoing_links().size();
}