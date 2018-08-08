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