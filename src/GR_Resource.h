#ifndef GR_ResourceManager_H
#define GR_ResourceManager_H

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "../include/SDL.h"

/*

Resource Manager
Copyright by mpsk @ 2018

This Module is to manage the resource that the platform need to load
and map its external name to an internal name.

Resource Map Script has the format of
<name>\t<type>\t<path>

every scene (with different resources) has their unique id (0-31)
and when 

TODO:
    *   external name will be replace with ResourcePack Offset in ther future
*/

#define NAME_BUFF   255


//  This structure will be moved to GR_Global.h
typedef struct Resource
{
    SDL_RWops *content;     //  SDL_RWops file object
    std::string name;       //  id [internal name]
    std::string type;       //  type of the resource
    //Uint32  mask;           // mask for scene load
}GR_RESUNIT;

class GR_ResourceManager
{
    private:
        std::vector<GR_RESUNIT> *res_list;
        std::vector<GR_RESUNIT>::iterator iter;
        std::ifstream res_script;

    public:
        GR_ResourceManager(const std::string &filename);
        ~GR_ResourceManager();

        void Load(const std::string &filename);
        void Clear();
        SDL_RWops* GetResource(const std::string &type, const std::string &name);

        Uint32 flag;        //  This flag is a bitwise mask flag.
        Uint8 id;           //  This id is the bitwise used to do the masking

};

#endif