#ifndef MYLISTENER
#define MYLISTENER

//#include <Ogre.h>
//#include <OgreInput.h>
#include <OgreFrameListener.h>
#include <OgreLogManager.h>

using namespace Ogre;
using namespace OgreBites;

class MyListener : public OgreBites::InputListener
{
    void frameRendered(const Ogre::FrameEvent& evt)
    {
        Ogre::LogManager::getSingleton().logMessage("Funciona!!!");
    }
    bool keyPressed(const KeyboardEvent& evt)
    {
        return true;
    }
    bool keyReleased(const KeyboardEvent& evt)
    {
        return true;
    }

    bool mouseMoved(const MouseMotionEvent& evt)
    {
        return true;
    }
    bool mouseWheelRolled(const MouseWheelEvent& evt)
    {
        return true;
    }
    bool mousePressed(const MouseButtonEvent& evt)
    {
        return true;
    }
    bool mouseReleased(const MouseButtonEvent& evt)
    {
        return true;
    }

};

#endif // LISTENER
