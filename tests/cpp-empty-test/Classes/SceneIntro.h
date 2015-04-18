#ifndef __SCENE_INTRO_H__
#define __SCENE_INTRO_H__

#include "cocos2d.h"

USING_NS_CC;
class SceneIntro : public cocos2d::Layer
{
public:
    virtual bool init();  
    static cocos2d::Scene* scene();
	void onEnter();
	void onExit();
    CREATE_FUNC(SceneIntro);
};

#endif // __SCENE_INTRO_H__
