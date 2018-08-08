#ifndef GR_Element_H
#define GR_Element_H
#include <string>
#include "GR_Texture.h"

/*
GR_Element
Copyright by mpsk @ 2018

This is a base class for GRiNa Visual Elements
Currently have child:
    GR_Background
    GR_Button
    GR_ParticleSys

*/

class GR_Element
{
    public:
        void LoadTexture(SDL_RWops *src, SDL_Renderer *ren);
        void Render(int Screen_w, int Screen_h, SDL_Renderer *ren);
        void SetName(const std::string &s);
        std::string GetName();
        void Free();
    protected:
        GR_Texture *tex;
        std::string name;
    private:
        Uint32 type;
        SDL_Rect dst;
};

#endif