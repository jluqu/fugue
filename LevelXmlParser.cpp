#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include "LevelXmlParser.h"

LevelXmlParser* LevelXmlParser::m_pInstance = NULL;

LevelXmlParser* LevelXmlParser::getInstance()
{
    if (!m_pInstance)
    {
        m_pInstance = new LevelXmlParser();
    }
    return m_pInstance;
}

LevelXmlParser::LevelXmlParser()
{
}

LevelXmlParser::~LevelXmlParser()
{
	delete m_pInstance;
}

bool LevelXmlParser::load(const char* filename)
{
	
    xmlDocPtr doc = xmlReadFile(filename, NULL, 0);
    if (doc == NULL) {
		printf("Failed to parse %s\n", filename);
		return false;
	}
	xmlFreeDoc(doc);
	return true;
}
