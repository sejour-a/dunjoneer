# dunjoneer
Meant to be a simple game.

Dunjoneer was supposed to be a game in and of itself, but it finished as a base for Irrlicht games.
It was a test to see how Irrlicht worked, and how to build with it.

I highly recommend Irrlicht as a game engine for new coders, as it's easy to use and cross-platforms.

My code may help you understand the engine, but the Irrlicht website's tutorial and documentation
are really well done, and I can only recommend it. Also, I am not certain it did everything correctly,
so don't take my code as reference.



The whole thing will only require Irrlicht, and shall be compatible with Linux and Mac OSX.

`./compile.sh` should be all you need, but you might want to tweak a few things (your compiler, for example).

Build status on OSX/Linux:

[![Build Status](https://travis-ci.org/sejour-a/dunjoneer.svg?branch=master)](https://travis-ci.org/sejour-a/dunjoneer)

My code is under MIT license, but:

[`./cmake/FindIrrlicht.cmake`](./cmake/FindIrrlicht.cmake) is by [Andreas Schneider](https://de.linkedin.com/in/cryptomilk), and under BSD license.

[Inih](https://github.com/benhoyt/inih) is by [Ben Hoyt](http://benhoyt.com/), and under BSD license.

[Irrlicht](http://irrlicht.sourceforge.net) is on zlib/libpng license, and uses [Independent JPEG Group](http://www.ijg.org) code, so does this project.
