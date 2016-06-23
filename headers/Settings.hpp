//
// Created by sejour_a on 20/06/16.
//

#ifndef DUNJONEER_SETTINGS_HPP
#define DUNJONEER_SETTINGS_HPP

#include <irrlicht.h>
#include <EDriverTypes.h>
#include <string>

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

    irr::video::E_DRIVER_TYPE           _driver;
    irr::core::dimension2d<irr::u32>    _resolution;

    irr::u32    _colorDepth;

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

    const   irr::video::E_DRIVER_TYPE           &getDriver()        const;
    const   irr::core::dimension2d<irr::u32>    &getResolution()    const;

    const   irr::u32    &getColorDepth()    const;
};

#endif //DUNJONEER_SETTINGS_HPP
