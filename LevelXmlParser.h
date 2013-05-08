#ifndef _LEVEL_XML_PARSER_H_
#define _LEVEL_XML_PARSER_H_

//TODO: which of these do we need?
#include <libxml/parser.h>
#include <libxml/tree.h>

#include "LevelObject.h"
#include "Level.h"

class LevelXmlParser
{
    public:
        static LevelXmlParser* getInstance();
        
        bool load(const char* filename, Level* level);
        
    private:
        LevelXmlParser();
        ~LevelXmlParser();
    	static LevelXmlParser* m_pInstance;
    	
    	void processLevel(xmlNodePtr cur, Level* level);
    	void processMap(xmlNodePtr cur, Level* level);
    	void processBlock(xmlNodePtr cur, Level* level);
    	void processPlayerStart(xmlNodePtr cur, Level* level);
};

#endif
