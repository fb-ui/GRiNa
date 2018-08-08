#include "GR_ResourceManager.h"

void SplitString(const std::string &s, std::vector<std::string> &v, const std::string &c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
    return;
}

void StringToMap(const std::string filename, std::vector<GR_NAMEMAP> *v)
{
    std::ifstream file;
    file.open(filename);
    while (file.eof())
    {
        std::vector<std::string> list;
        std::string s;
        getline(file, s);
        SplitString(s, list, "\t");
    }
    file.close();
    return;
}

GR_ResourceManager::GR_ResourceManager(const std::string filename)
{
    StringToMap(filename, this->map_list);
}

GR_ResourceManager::~GR_ResourceManager()
{
}

