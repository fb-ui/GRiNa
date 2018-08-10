#include "GR_Element.h"

void GR_Element::LoadTexture(SDL_RWops *src, SDL_Renderer *ren)
{
    this->tex = new GR_Texture();
    this->tex->Load(src, ren);
}

void GR_Element::Free()
{
    this->tex->Free();
    delete this->tex;
}

void GR_Element::SetName(const std::string &s)
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

//=========================
//  GR_ElementList
//=========================

GR_ElementList::GR_ElementList(std::string &name)
{
    this->name = name;
    this->vec_elem = new std::vector<GR_Element*>();
}

GR_ElementList::~GR_ElementList()
{
    delete this->vec_elem;
}

bool GR_ElementList::IsInList(std::string &s)
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

GR_Element* GR_ElementList::GetElement(std::string &s)
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

bool GR_ElementList::Pop(std::string &s)
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