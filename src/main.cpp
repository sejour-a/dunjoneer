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

    config->setDevice(device);
    config->loadModels();

    Player *steven  =   new Player(config);

    EntityList list;
    list.addEntity(steven);

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