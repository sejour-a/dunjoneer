//MAIN_CPP_

#include <irrlicht.h>

int main(void)
{
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1600, 900), 16, false, false, false, 0);

    return 0;
}