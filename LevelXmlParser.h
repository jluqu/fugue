#ifndef _LEVEL_XML_PARSER_H_
#define _LEVEL_XML_PARSER_H_

class LevelXmlParser
{
    public:
		// I'm a singleton!
        static LevelXmlParser* getInstance();
        
        bool load(const char* filename);
        
    private:
        LevelXmlParser();
        ~LevelXmlParser();
    	static LevelXmlParser* m_pInstance;
};

#endif
