//
// Created by sejour_a on 20/06/16.
//

#ifndef DUNJONEER_SETTINGS_HPP
#define DUNJONEER_SETTINGS_HPP

#include <irrlicht.h>
#include <EDriverTypes.h>
#include <string>
#include <map>

#include <customMacro.hh>

class Settings
{
private:
    Settings(); //Illegal call

    bool    _vSync;
    bool    _fullscreen;
    bool    _anisotropic;
    bool    _antiAliasing;
    bool    _stencilBuffer;
    bool    _bilinearFilter;
    bool    _trilinearFilter;

    std::string _mapFolder;
    std::string _modelFolder;
    std::string _textureFolder;
    std::string _modelconfigFolder;

    irr::video::E_DRIVER_TYPE           _driverType;
    irr::core::dimension2d<irr::u32>    _resolution;

    irr::u32    _colorDepth;

    std::map<std::string, t_mesh *> _models;
    std::map<std::string, irr::video::ITexture *> _textures;


    void    _load(const std::string &modelconfig);

    t_irrDevice                 *_device;
    irr::video::IVideoDriver    *_driver;
    t_sManager                  *_sceneManager;

public:
    Settings(const  std::string &configFile);
    ~Settings();

    const   bool    &getVSync()         const;
    const   bool    &getBilinear()      const;
    const   bool    &getTrilinear()     const;
    const   bool    &getFullscreen()    const;
    const   bool    &getAnisotropic()   const;
    const   bool    &getAntiAliasing()  const;
    const   bool    &getStencilBuffer() const;

    void    setDevice(irr::IrrlichtDevice *newDevice);

    void    loadModels();

    const   irr::video::E_DRIVER_TYPE           &getDriver()        const;
    const   irr::core::dimension2d<irr::u32>    &getResolution()    const;

    const   irr::u32    &getColorDepth()    const;
};

#endif //DUNJONEER_SETTINGS_HPP
