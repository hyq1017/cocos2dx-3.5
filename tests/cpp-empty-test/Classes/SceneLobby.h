#ifndef __SCENE_LOBBY_H__
#define __SCENE_LOBBY_H__

#include "cocos2d.h"

USING_NS_CC;

class SceneLobby : public Layer
{
public:
    virtual bool init();  
    static Scene* scene();
	void onEnter();
	void onExit();
    CREATE_FUNC(SceneLobby);
	
	void CallbackStart(Ref* sender);
	void CallbackRank(Ref* sender);
	void CallbackHelp(Ref* sender);
	void CallbackSetting(Ref* sender);
};

#endif // __SCENE_LOBBY_H__
