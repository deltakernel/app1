#ifndef APP_H
#define APP_H

#include <iostream>
#include <Ogre.h>
#include <OgreTrays.h>
#include <OgreApplicationContext.h>
#include <OgreCameraMan.h>

#include "listener.h"

using namespace Ogre;
using namespace OgreBites;

class app1 :
public OgreBites::ApplicationContext,
public OgreBites::InputListener,
public OgreBites::TrayListener
{
public:
    app1();
    virtual ~app1();
    void go();

protected:
    bool keyPressed(const OgreBites::KeyboardEvent& evt);
    void setup();
    void setupView();
    void createScene();
    void setupFramelistner();
private:
    SceneManager* mScnManager;
    Viewport* mViewport;

    TrayManager* mTrayMgr;
    CameraMan* mCameraMan;
    Camera*    mCamera;
    SceneNode* camNode;
    RTShader::ShaderGenerator* shadergen;
    MyListener ouvinte;
};

#endif //APP_H
