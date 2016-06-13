//MAIN_CPP_

#include <irrlicht/irrlicht.h>

int main(void)
{
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1600, 900), 32, false, false, false, 0);

    if (!device)
        return 1;

    device->drop();

    return 0;
}