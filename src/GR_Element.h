#ifndef GR_Element_H
#define GR_Element_H
#include <vector>
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
        //  void Render() need to be implemented by yourself
        void SetName(const std::string &s);
        void SetResourceName(const std::string &s);
        std::string GetResourceName();
        std::string GetName();
        void Free();
    protected:
        GR_Texture *tex;
        std::string name;
        std::string res_name;
        Uint32 type;
        SDL_Rect dst;
};

class GR_ElementList
{
    public:
        GR_ElementList(std::string &name);
        ~GR_ElementList();
        bool IsInList(std::string &s);
        GR_Element* GetElement(std::string &s);
        bool Push(GR_Element *elem);
        bool Pop(std::string &s);
    private:
        std::vector<GR_Element*> *vec_elem;
        std::vector<GR_Element*>::iterator iter;
        std::string name;
};

#endif