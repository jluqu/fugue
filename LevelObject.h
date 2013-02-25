#ifndef _LEVELOBJECT_H_
#define _LEVELOBJECT_H_

class LevelObject
{
    public:
        LevelObject();
        LevelObject(float x, float y, float w, float h);
		virtual ~LevelObject();
		
        virtual void draw();
        void setPosition(float x, float y);
        void setSize(float w, float h);
    
    protected:
        float m_x, m_y;
        float m_w, m_h;
};

#endif
