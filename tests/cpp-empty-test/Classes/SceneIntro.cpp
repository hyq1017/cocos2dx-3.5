#include "SceneIntro.h"
#include "SceneLobby.h"


using namespace std;

Scene* SceneIntro::scene()
{
    auto scene = Scene::create();
    SceneIntro *layer = SceneIntro::create();
    scene->addChild(layer);

    return scene;
}

bool SceneIntro::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    return true;
}

void SceneIntro::onEnter()
{
	Layer::onEnter();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SceneLobby::scene(), Color3B::WHITE));
}

void SceneIntro::onExit()
{
	Layer::onExit();
}



