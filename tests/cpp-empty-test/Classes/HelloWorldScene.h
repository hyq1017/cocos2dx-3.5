#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;
class SceneIntro : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // a selector callback
    void menuCloseCallback(Ref* sender);

	bool SceneIntro::onTouchBegan(Touch* touch, Event* event);
	void SceneIntro::onTouchMoved(Touch* touch, Event* event);
	void SceneIntro::onTouchEnded(Touch* touch, Event* event);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneIntro);
	cocos2d::experimental::TMXTiledMap *m_map;
	Sprite* m_player;
};

#endif // __HELLOWORLD_SCENE_H__
