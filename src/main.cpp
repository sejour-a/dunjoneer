//MAIN_CPP_

#include <string>
#include "../include/customIrrlicht.h"

int main(int ac, char **av)
{
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1600, 900), 16, false, false, false, 0);

    if (!device)
        return 1;

    device->setWindowCaption(L"DOG - The IrrLicht Demo");
    irr::video::IVideoDriver *driver = device->getVideoDriver();
    irr::scene::ISceneManager *smgr = device->getSceneManager();
    irr::gui::IGUIEnvironment *guienv = device->getGUIEnvironment();

    irr::scene::ICameraSceneNode *camera = smgr->addCameraSceneNodeFPS(0, 200.0f, .02f);
    camera->setPosition(irr::core::vector3df(-8, 1, -8));
    camera->setTarget(irr::core::vector3df(0, 1, 0));

    irr::scene::IAnimatedMesh *mesh = smgr->getMesh("../../media/dog.ms3d");
    if (!mesh)
    {
        device->drop();
        return 1;
    }

    irr::scene::IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(mesh);

    if (node)
    {
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, true);
        node->setMaterialFlag(irr::video::EMF_BILINEAR_FILTER, false);
        node->setMaterialFlag(irr::video::EMF_TRILINEAR_FILTER, true);
        node->setMaterialTexture(0, driver->getTexture("../../media/dog.png"));
    }

    irr::gui::IGUIStaticText *fpsBox = guienv->addStaticText(L"0", irr::core::rect<irr::s32>(10, 10, 100, 22), false);

    //COLLIDE
    irr::scene::ITriangleSelector* selector = 0;
    selector = smgr->createOctreeTriangleSelector(node->getMesh(), node, 128);
    node->setTriangleSelector(selector);

    irr::scene::ISceneNodeAnimator *anim = smgr->createCollisionResponseAnimator(selector, camera, irr::core::vector3df(1, 1, 1), irr::core::vector3df(0, 0, 0), irr::core::vector3df(0, 0, 0));

    selector->drop();
    camera->addAnimator(anim);
    anim->drop();

    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));

        smgr->drawAll();
        guienv->drawAll();

        driver->endScene();

        int fps = driver->getFPS();
        fpsBox->setText(std::to_wstring(fps).c_str());
    }

    device->drop();

    return 0;
}