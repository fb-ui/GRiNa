#ifndef RESOURCEPACKAGE_H
#define RESOURCEPACKAGE_H

#include "../include/SDL.h"
#include <string>
#include <fstream>
#include <cstdlib>

#define NAME_LEN    256
#define TYPE_LEN    16

using namespace std;

/*  
    This part is to define how the file storage in an
    rpk file. All resource file have a head, which describe
    its name, type and size. Then following is the real
    content of the resource file.
*/
typedef struct BinContent
{
    //  Head of the Binary file
    char name[NAME_LEN];
    char type[TYPE_LEN];
    //  size of real content
    Sint64 size;
    //  ptr to the content
    SDL_RWops *content;
}BIN;

class ResourcePackage
{
public:
    ResourcePackage();
    int Load();
    int ReadRPK(const string file);
private:
    int size;
    
};


#endif