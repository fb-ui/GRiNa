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
        GR_Element();
        GR_Element(SDL_RWops *src, SDL_Renderer *ren, std::string name);
        ~GR_Element();
        void LoadTexture(SDL_RWops *src, SDL_Renderer *ren);
        //  void Render() need to be implemented by yourself
        void SetName(std::string s);
        void SetResourceName(const std::string &s);
        void Render_clip(SDL_Rect dest, SDL_Rect clip, SDL_Renderer *ren);
		void Render_clip(int dstX, int dstY, int dstW, int dstH, int srcX, int srcY, int srcW, int srcH, SDL_Renderer *ren);
        int GetHeight();
        int GetWidth();
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
        GR_ElementList(std::string name);
        ~GR_ElementList();
        bool IsInList(std::string s);
        GR_Element* GetElement(std::string s);
        bool Push(GR_Element *elem);
        bool Push(GR_Element *elem, std::string name);
        bool Pop(std::string s);

        void CursorReset();
        bool CursorEnd();
        void CursorNext();
        GR_Element* GetCursor();
    private:
        std::vector<GR_Element*> *vec_elem;
        std::vector<GR_Element*>::iterator iter, begin, end;
        std::string name;
};

#endif