#ifndef __MD_PARSER_H__
#define __MD_PARSER_H__

#include "pageparser.h"
#include <string>

using std::string;

class MDparser : public PageParser {
public:
	virtual ~MDparser() { }

  /** 
   * Parses a file and returns all unique words according
   *  to some parser rules and all hyperlinks based 
   *  on the format the parser is designed to implement
   */
  virtual void parse(string filename,
		     MySet<string>& allWords,
		     MySet<string>& allLinks);
private:


};


#endif