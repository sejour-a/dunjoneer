//MAIN_CPP_

#include <Player.hpp>
#include <MovementUpdater.hpp>

#include <iostream>

int     main(void)
{
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1600, 900), 32, false, false, false, 0);

    if  (!device)
        return 1;

    MovementUpdater list;
    Player *test = new Player(device);
    list.addEntity(test);

    device->setWindowCaption(L"dunjoneer");
    irr::scene::ICameraSceneNode *cam = device->getSceneManager()->addCameraSceneNodeFPS();
    cam->setPosition(t_vec3df(20, 10, 20));
    cam->setTarget(t_vec3df(0,0,0));

    test->loadStandingMesh("crystal");
    test->setAcc(t_vec3df(1,1,1));
    test->setCurrentNode("standing");

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