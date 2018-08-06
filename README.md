#   GRiNa

GeneRal interface for Non-3D animation

GRiNa is still under development. This document is for developers.

For most games uses Qt5 as a container of games or interface, we found that SDL is also a good Render platform who has been maintained by Software Develop Companies like Valve. And Also it is quite light compared to Qt5, which means it would be easier to SDL2 based project when transferring its code to another multi-media platform.

## Documentation
[English Version is avaliable](https://blog.csdn.net/mpsk07/article/details/81453830)

*   Dev reminder
    *   Use ttf file to paint custom fonts
    *   Design a dialog box to test the scripts
    *   Use the SDL_RWops to storage resources and preload it to memory when start up
    *   Use encrypted binary files to storage images, scripts and sounds.
    *   preloaded objects can be fast and flexible
    *   Scripts should be excutable in global

##  What is GRiNa?
GRiNa is a game framework for multi-platform purpose. This framework is mainly designed for Chinese action script. For now stage we have completed the the low level implement.

##  ABOUT
    Nickname:   mpsk
    Liu Fangrui
    Email:  mpskex@163.com
    Beijing University of Technology

##  Required Libs
*   libsdl2-dev
    *   libsdl-image1.2-dev 
    *   libsdl-mixer1.2-dev 
    *   libsdl-ttf2.0-dev 
    *   libsdl-gfx1.2-dev