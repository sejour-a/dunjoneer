//
// Created by sejour_a on 20/06/16.
//

#include <fstream>
#include <iostream>

#include <Settings.hpp>
#include "../inih/INIReader.hpp"

#include <colors.hh>
#include <debug.hh>

Settings::Settings(const std::string &configFile)
{
    if  (DBG >= DEBUG_1)
        std::cerr << YELLOW << ">Opening config file\t" << MAGENTA << configFile;

    INIReader   file(configFile);

    if  (DBG >= DEBUG_1)
    {
        if      (file.ParseError() < 0)     std::cerr << RED    << "\t==Failure==" << COLOR_RESET << std::endl;
        else                                std::cerr << GREEN  << "\t==Success==" << COLOR_RESET << std::endl;
    }

    std::string driver;
    driver  =   file.Get((const std::string &)"config", (const std::string &)"driver", (const std::string &)"opengl");

            if  (driver == "opengl")    _driver =   irr::video::EDT_OPENGL;
    else    if  (driver == "directx")   _driver =   irr::video::EDT_DIRECT3D9;
    else    if  (driver == "software")  _driver =   irr::video::EDT_SOFTWARE;

    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Display driver\t\t" << BLUE << driver << COLOR_RESET << std::endl;

    _resolution.Height  =   file.GetInteger((const std::string &)"config", (const std::string &)"height", 720);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Screen height\t\t" << BLUE << _resolution.Height << COLOR_RESET << std::endl;

    _resolution.Width   =   file.GetInteger((const std::string &)"config", (const std::string &)"width", 1280);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Screen width\t\t" << BLUE << _resolution.Width << COLOR_RESET << std::endl;

    _colorDepth         =   file.GetInteger((const std::string &)"config", (const std::string &)"colorDepth", 16);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Color depth\t\t" << BLUE << _colorDepth << COLOR_RESET << std::endl;

    _stencilBuffer      =   file.GetBoolean((const std::string &)"config", (const std::string &)"stencilBuffer", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Stencil buffer\t\t" << BLUE << _stencilBuffer << COLOR_RESET << std::endl;

    _fullscreen         =   file.GetBoolean((const std::string &)"config", (const std::string &)"fullscreen", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Fullscreen\t\t" << BLUE << _fullscreen << COLOR_RESET << std::endl;

    _vSync              =   file.GetBoolean((const std::string &)"config", (const std::string &)"vSync", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Vertical Synch\t\t" << BLUE << _vSync << COLOR_RESET << std::endl;

    _anisotropic        =   file.GetBoolean((const std::string &)"config", (const std::string &)"anisotropic", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Anisotropic filtering\t" << BLUE << _anisotropic << COLOR_RESET << std::endl;

    _antiAliasing       =   file.GetBoolean((const std::string &)"config", (const std::string &)"antiAliasing", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Anti aliasing\t\t" << BLUE << _antiAliasing << COLOR_RESET << std::endl;

    _bilinearFilter     =   file.GetBoolean((const std::string &)"config", (const std::string &)"bilinear", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Bilinear filtering\t" << BLUE << _bilinearFilter << COLOR_RESET << std::endl;

    _trilinearFilter    =   file.GetBoolean((const std::string &)"config", (const std::string &)"trilinear", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Trilinear filtering\t" << BLUE << _trilinearFilter << COLOR_RESET << std::endl << std::endl;
}

Settings::~Settings()
{
}

//GETTERS

const   bool    &Settings::getVSync()           const   {   return  _vSync;             }
const   bool    &Settings::getBilinear()        const   {   return  _bilinearFilter;    }
const   bool    &Settings::getTrilinear()       const   {   return  _trilinearFilter;   }
const   bool    &Settings::getFullscreen()      const   {   return  _fullscreen;        }
const   bool    &Settings::getAnisotropic()     const   {   return  _anisotropic;       }
const   bool    &Settings::getAntiAliasing()    const   {   return  _antiAliasing;      }
const   bool    &Settings::getStencilBuffer()   const   {   return  _stencilBuffer;     }

const   irr::video::E_DRIVER_TYPE           &Settings::getDriver()      const   {   return  _driver;        }
const   irr::core::dimension2d<irr::u32>    &Settings::getResolution()  const   {   return  _resolution;    }

const   irr::u32    &Settings::getColorDepth()  const   {   return  _colorDepth;    }