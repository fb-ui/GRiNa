#include "GR_Element.h"

GR_Element::GR_Element()
{
    this->tex = new GR_Texture();
}

GR_Element::GR_Element(SDL_RWops *src, SDL_Renderer *ren, std::string name)
{
    this->tex = new GR_Texture();
    this->tex->Load(src, ren);
    this->name = name;
}

GR_Element::~GR_Element()
{
    delete this->tex;
}

void GR_Element::LoadTexture(SDL_RWops *src, SDL_Renderer *ren)
{
    this->tex->Load(src, ren);
}

void GR_Element::Free()
{
    this->tex->Free();
    delete this->tex;
}

void GR_Element::SetName(std::string s)
{
    this->name = s;
}

std::string GR_Element::GetName()
{
    return this->name;
}

void GR_Element::SetResourceName(const std::string &s)
{
    this->res_name = s;
}

std::string GR_Element::GetResourceName()
{
    return this->res_name;
}

void GR_Element::Render_clip(SDL_Rect dest, SDL_Rect clip, SDL_Renderer *ren)
{
    this->tex->Render_clip(dest, clip, ren);
}

void GR_Element::Render_clip(int dstX, int dstY, int dstW, int dstH, int srcX, int srcY, int srcW, int srcH, SDL_Renderer *ren)
{
    this->tex->Render_clip(dstX, dstY, dstW, dstH, srcX, srcY, srcW, srcH, ren);
}

int GR_Element::GetHeight()
{
    return this->tex->GetHeight();
}

int GR_Element::GetWidth()
{
    return this->tex->GetWidth();
}


//=========================
//  GR_ElementList
//=========================

GR_ElementList::GR_ElementList(std::string name)
{
    this->name = name;
    this->vec_elem = new std::vector<GR_Element*>();
}

GR_ElementList::~GR_ElementList()
{
    for(this->iter=this->vec_elem->begin();this->iter!=this->vec_elem->end();this->iter++)
    {
        delete (*this->iter);
    }
    delete this->vec_elem;
}

bool GR_ElementList::IsInList(std::string s)
{
    bool ret = false;
    for(this->iter=this->vec_elem->begin();this->iter!=this->vec_elem->end();this->iter++)
    {
        if((*this->iter)->GetName()==s)
        {
            ret = true;
        }
    }
    return ret;
}

GR_Element* GR_ElementList::GetElement(std::string s)
{
    for(this->iter=this->vec_elem->begin();this->iter!=this->vec_elem->end();this->iter++)
    {
        if((*this->iter)->GetName()==s)
        {
            return (*this->iter);
        }
    }
    return nullptr;
}

bool GR_ElementList::Push(GR_Element *elem)
{
    for(this->iter=this->vec_elem->begin();this->iter!=this->vec_elem->end();this->iter++)
    {
        if((*this->iter)->GetName()==elem->GetName())
        {
            //  Name duplicated
            return false;
        }
    }
    this->vec_elem->push_back(elem);
    return true;
}

bool GR_ElementList::Push(GR_Element *elem, const std::string name)
{
    for(this->iter=this->vec_elem->begin();this->iter!=this->vec_elem->end();this->iter++)
    {
        if((*this->iter)->GetName()==name)
        {
            //  Name duplicated
            return false;
        }
    }
    this->vec_elem->push_back(elem);
    return true;
}

bool GR_ElementList::Pop(std::string s)
{
    for(this->iter=this->vec_elem->begin();this->iter!=this->vec_elem->end();this->iter++)
    {
        if((*this->iter)->GetName()==s)
        {
            //  if there is name match
            this->vec_elem->erase(this->iter);
            return true;
        }
    }
    return false;
}

void GR_ElementList::CursorReset()
{
    this->iter = this->vec_elem->begin();
    this->begin = this->vec_elem->begin();
    this->end = this->vec_elem->end();
}

bool GR_ElementList::CursorEnd()
{
    return this->iter==this->end;
}

void GR_ElementList::CursorNext()
{
    this->iter++;
}

GR_Element* GR_ElementList::GetCursor()
{
    return (*this->iter);
}