//
// Created by sejour_a on 20/06/16.
//

#ifndef DUNJONEER_SETTINGS_HPP
#define DUNJONEER_SETTINGS_HPP

#include <string>

class Settings
{
private:
    Settings(); //Illegal call

    bool    _anisotropic;
    bool    _antiAliasing;
    bool    _bilinearFilter;
    bool    _trilinearFilter;

public:
    Settings(const  std::string &configFile);
    ~Settings();
};

#endif //DUNJONEER_SETTINGS_HPP
