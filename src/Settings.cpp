//
// Created by sejour_a on 20/06/16.
//

#include <fstream>
#include <iostream>

#include <Settings.hpp>
#include <INIReader.hpp>

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

    _anisotropic        =   file.GetBoolean((const std::string &)"config", (const std::string &)"anisotrop", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Anisotropic filtering\t\t" << BLUE << _anisotropic << std::endl;

    _antiAliasing       =   file.GetBoolean((const std::string &)"config", (const std::string &)"antiAlias", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Anti aliasing\t\t\t" << BLUE << _antiAliasing << std::endl;

    _bilinearFilter     =   file.GetBoolean((const std::string &)"config", (const std::string &)"bilinearF", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Bilinear filtering\t\t" << BLUE << _bilinearFilter << std::endl;

    _trilinearFilter    =   file.GetBoolean((const std::string &)"config", (const std::string &)"trilinear", false);
    if (DBG >= DEBUG_1) std::cerr<< YELLOW << "\t>Trilinear filtering\t\t" << BLUE << _trilinearFilter << std::endl << std::endl;
}

Settings::~Settings()
{
}