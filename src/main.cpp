//MAIN_CPP_

#include <Player.hpp>
#include <EntityList.hpp>

#include <iostream>

int     main(void)
{
    Settings    *config =   new Settings((const std::string &) "./config/dunjoneer.ini");

    irr::IrrlichtDevice *device = irr::createDevice(config->getDriver(),
                                                    config->getResolution(),
                                                    config->getColorDepth(),
                                                    config->getFullscreen(),
                                                    config->getStencilBuffer(),
                                                    config->getVSync(),
                                                    0);

    if  (!device)
        return 1;

    device->setWindowCaption(L"dunjoneer");

    Player *test        =   new Player(device, config);

    EntityList list;
    list.addEntity(test);

    irr::scene::ICameraSceneNode *cam = device->getSceneManager()->addCameraSceneNodeFPS();
    cam->setPosition(t_vec3df(20, 10, 20));
    cam->setTarget(t_vec3df(0,0,0));

    test->loadStandingMesh((const std::string &) "crystal");
    test->setAcc(t_vec3df(1,1,1));
    test->setSpeed(0.0f);
    test->setCurrentNode((const std::string &) "standing");

    while   (device->run())
    {
        list.updatePosition();

        device->getVideoDriver()->beginScene(true, true, irr::video::SColor(255,100,101,140));
        device->getSceneManager()->drawAll();
        device->getVideoDriver()->endScene();
    }

    device->drop();

    return 0;
}