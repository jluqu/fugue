#include <stdio.h>
#include <stdlib.h>
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

bool LevelXmlParser::load(const char* filename, std::vector<LevelObject*>* objList)
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

    } else if (xmlStrcmp(root->name, (const xmlChar*)"level")) { 
        printf("Root node is called %s, expected 'root'\n", root->name);
        return false;
    }
    processLevel(root, objList);

    xmlFreeDoc(doc);
    return true;
}

void LevelXmlParser::processLevel(xmlNodePtr cur, std::vector<LevelObject*>* objList)
{
    xmlNodePtr child = cur->xmlChildrenNode;
    while (child != NULL)
    {
        if (!xmlStrcmp(child->name, (const xmlChar*)"map"))
        {
            processMap(child, objList);
        }
        // TODO: <playerstart x=... y=...>
        child = child->next;
    }
}

void LevelXmlParser::processMap(xmlNodePtr cur, std::vector<LevelObject*>* objList)
{
    xmlNodePtr child = cur->xmlChildrenNode;
    while (child != NULL)
    {
        if (!xmlStrcmp(child->name, (const xmlChar*)"block"))
        {
            processBlock(child, objList);
        }
        child = child->next;
    }
}

void LevelXmlParser::processBlock(xmlNodePtr cur, std::vector<LevelObject*>* objList)
{
    xmlChar* xStr = xmlGetProp(cur, (const xmlChar*)"x");
    xmlChar* yStr = xmlGetProp(cur, (const xmlChar*)"y");
    xmlChar* wStr = xmlGetProp(cur, (const xmlChar*)"w");
    xmlChar* hStr = xmlGetProp(cur, (const xmlChar*)"h");
    xmlChar* typeStr = xmlGetProp(cur, (const xmlChar*)"type");
    
    float x, y, w, h;
    const char* type;
    
    if (xStr != NULL)
    {
        x = float(atof((const char*)xStr));
    }
    else
    {
        printf("<block> tag does not specify x value!\n");
        x = 0;
    }
    
    if (yStr != NULL)
    {
        y = float(atof((const char*)yStr));
    }
    else
    {
        printf("<block> tag does not specify y value!\n");
        y = 0;
    }
    
    if (wStr != NULL)
    {
        w = float(atof((const char*)wStr));
    }
    else
    {
        w = 1;  // Default block width = 1
    }
    
    if (hStr != NULL)
    {
        h = float(atof((const char*)hStr));
    }
    else
    {
        h = 1;  // Default block height = 1
    }
    
    if (typeStr != NULL)
    {
        type = (const char*)typeStr;
    }
    else
    {
        printf("<block> tag does not specify a type!\n");
        type = "solidBlue";   // default to a solid blue block
    }
    
    Block* b = ObjectFactory::buildBlock(type, x, y, w, h);
    objList->push_back(b);
    
    xmlFree(xStr);
    xmlFree(yStr);
    xmlFree(wStr);
    xmlFree(hStr);
    xmlFree(typeStr);
}
