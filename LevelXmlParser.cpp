#include <stdio.h>
#include <vector>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include "LevelXmlParser.h"
#include "ObjectFactory.h"
#include "LevelObject.h"

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

bool LevelXmlParser::load(const char* filename, std::vector<LevelObject*> objList)
{
    xmlDocPtr doc = xmlReadFile(filename, NULL, 0);
    if (doc == NULL) {
        printf("Failed to parse %s\n", filename);
        return false;
    }
    xmlNodePtr root = xmlDocGetRootElement(doc);
    if (root == NULL) {
        printf("Can't find root node in the level file\n");
        return false;

    } else if (xmlStrcmp(root->name, (const xmlChar *)"level")) { 
        printf("Root node is called %s, expected 'root'\n", root->name);
        return false;
    }
    processLevel(root, objList);

    xmlFreeDoc(doc);
    return true;
}

void LevelXmlParser::processLevel(xmlNodePtr cur, std::vector<LevelObject*> objList)
{
    xmlNodePtr child = cur->xmlChildrenNode;
    while (child != NULL)
    {
        if (!xmlStrcmp(cur->name, (const xmlChar *)"block"))
        {
            processBlock(child, objList);
        }
        child = child->next;
    }
}

void LevelXmlParser::processBlock(xmlNodePtr cur, std::vector<LevelObject*> objList)
{
    printf("Found a block\n");
}
