#ifndef GR_ResourceManager_H
#define GR_ResourceManager_H

#include <vector>
#include <iostream>
#include <fstream>

#include "GR_ResourcePackage.h"

/*

Resource Manager
Copyright by mpsk @ 2018

This Module is to manage the resource that the platform need to load
and map its external name to an internal name.

Resource Map Script has the format of
<name>\t<id>\t<mask>

every scene (with different resources) has their unique id (0-31)
and when 

TODO:
    *   external name will be replace with ResourcePack Offset in ther future
*/

#define NAME_BUFF   255


//  This structure will be moved to GR_Global.h
typedef struct GlobalNameMap
{
    char    name[NAME_BUFF];    // path [external name]
    Uint32  id;                 // id [internal name]
    Uint32  mask;               // mask for scene load
}GR_NAMEMAP;

//  This funtion will be moved to GR_Script in ther future
void StringToMap(std::ifstream file, std::vector<GR_NAMEMAP> *v);

class GR_ResourceManager
{
    private:
        std::vector<GR_NAMEMAP> *map_list;
        std::ifstream res_script;

    public:
        GR_ResourceManager(const std::string filename);
        ~GR_ResourceManager();

        void SetNameMap(const std::vector<GR_NAMEMAP> map);

        Uint32 flag;        //  This flag is a bitwise mask flag.
        Uint8 id;           //  This id is the bitwise used to do the masking

};

#endif