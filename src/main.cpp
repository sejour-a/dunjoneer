//MAIN_CPP_

#include <irrlicht.h>
#include <Player.hpp>

int main(void)
{
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1600, 900), 32, false, false, false, 0);

    if (!device)
        return 1;

    Player  test(device);

    test.setPos(t_vec3df(1, 1, 1));
    test.setAcc(t_vec3df(1, 1, 1));
    test.setSpeed(2.f);
    test.setName("un nom");
    test.setPos(t_vec3df(0, 0, 0));
    test.setAcc(t_vec3df(0, 0, 0));
    test.setSpeed(1.f);
    test.getSpeed();
    test.getPos();
    test.getAcc();
    test.getName();
    test.getType();

    device->drop();

    return 0;
}