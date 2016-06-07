//
// Created by Alexandre Sejournant on 07/06/2016.
//

#ifndef DUNJONEER_CUSTOMIRRLICHT_H_H
#define DUNJONEER_CUSTOMIRRLICHT_H_H

#ifdef _WIN32 //pragma for VisualStudio, if you use something else, you will need a different implementation
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

#elif __APPLE__ //for classical brew installed irrlicht version
#include <irrlicht/irrlicht.h>

#elif __linux__ //works most of the time, might want to change that if your irrlicht install is exotic
#include <irrlicht.h>

#else
#   error "Unknown compiler"
#endif

#endif //DUNJONEER_CUSTOMIRRLICHT_H_H
