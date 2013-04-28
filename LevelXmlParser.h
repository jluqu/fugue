#ifndef _LEVEL_XML_PARSER_H_
#define _LEVEL_XML_PARSER_H_

//TODO: which of these do we need?
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <vector>

#include "LevelObject.h"

class LevelXmlParser
{
    public:
        static LevelXmlParser* getInstance();
        
        bool load(const char* filename, std::vector<LevelObject*>* objList);
        
    private:
        LevelXmlParser();
        ~LevelXmlParser();
    	static LevelXmlParser* m_pInstance;
    	
    	void processLevel(xmlNodePtr cur, std::vector<LevelObject*>* objList);
    	void processMap(xmlNodePtr cur, std::vector<LevelObject*>* objList);
    	void processBlock(xmlNodePtr cur, std::vector<LevelObject*>* objList);
};

#endif
