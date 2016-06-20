//
// Created by Alexandre Sejournant on 18/06/2016.
//

#ifndef DUNJONEER_MOVEMENTUPDATER_HPP
#define DUNJONEER_MOVEMENTUPDATER_HPP

#include <Object.hpp>
#include <vector>

class MovementUpdater
{
private:
    std::vector<Object *> _objectList;

public:
    MovementUpdater();
    ~MovementUpdater();

    void addEntity(Object *newObject);
    void updatePosition();
};

#endif //DUNJONEER_MOVEMENTUPDATER_HPP
