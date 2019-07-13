#include "app.h"

using namespace Ogre;
using namespace OgreBites;

app1::app1() : OgreBites::ApplicationContext("App1")
{

}

app1::~app1()
{
    if(mTrayMgr) OGRE_DELETE  mTrayMgr;
    if(mCameraMan) OGRE_DELETE mCameraMan;
}

void app1::go()
{
    initApp();
    getRoot()->startRendering();
    closeApp();
}

void app1::setup()
{
    ApplicationContext::setup();
    mScnManager = getRoot()->createSceneManager();
    addInputListener(this);
    getRoot()->addFrameListener(this);
    shadergen = RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(mScnManager);

    mScnManager->addRenderQueueListener(getOverlaySystem());
    setupView();
    setupFramelistner();
    createScene();
}

void app1::setupView()
{
    camNode = mScnManager->getRootSceneNode()->createChildSceneNode("camNode", Ogre::Vector3(0, -5, 5));
    camNode->lookAt(Ogre::Vector3(0,0,-300), Ogre::Node::TS_WORLD);
    // Create the camera
    mCamera = mScnManager->createCamera("PlayerCam");
    mCamera->setNearClipDistance(5);
    camNode->attachObject(mCamera);
    mCameraMan = new OgreBites::CameraMan(camNode);   // create a default camera controller
    mCameraMan->setStyle(OgreBites::CS_ORBIT);
    addInputListener(mCameraMan);
    // Create one viewport, entire window
    mViewport = getRenderWindow()->addViewport(mCamera);
    mViewport->setBackgroundColour(Ogre::ColourValue(0,0,0));

    // Alter the camera aspect ratio to match the viewport
    mCamera->setAspectRatio(
        Ogre::Real(mViewport->getActualWidth()) / Ogre::Real(mViewport->getActualHeight()));

}

void app1::createScene()
{
    Ogre::Light* light = mScnManager->createLight("MainLight");
    mScnManager->getRootSceneNode()->createChildSceneNode("lux1", Vector3(0, 10, 15))->attachObject(light);

    Entity* ogre = mScnManager->createEntity("Sinbad", "Sinbad.mesh");
    mScnManager->getRootSceneNode()->createChildSceneNode("SinbadNode")->attachObject(ogre);
}

void app1::setupFramelistner()
{
    mTrayMgr = OGRE_NEW TrayManager("myTray", getRenderWindow(), this);
    mTrayMgr->showFrameStats(TL_BOTTOMLEFT, 250.0f);
    addInputListener(mTrayMgr);
}

