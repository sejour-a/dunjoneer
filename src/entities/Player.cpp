//
// Created by Alexandre Sejournant on 09/06/2016.
//

#include <Player.hpp>

#include <iostream>

#include <debug.hh>
#include <colors.hh>

Player::Player(t_irrDevice *newDevice, Settings *config): Object(newDevice, config)
{
    _type   =   (const std::string &) "PLAYER";
    _name   =   (const std::string &) "Player";
    if (DBG >= DEBUG_1)
        std::cerr << YELLOW << ">Object is type " << CYAN << "[" << _type << "]" << COLOR_RESET << std::endl << std::endl;
}
