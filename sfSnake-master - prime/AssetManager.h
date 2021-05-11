#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include<SFML/Graphics.hpp>
#include<map>
class AssetManager
{
public:
    AssetManager();
    static sf::Texture &GetTexture(std::string const &filename);
private:
    std::map<std::string, sf::Texture> m_Textures;
    //AssetManager是一个singleton，因此一次只能存在一个实例
   //sInstacne  指向一个每个 manage instance 对象的静态指针
    static AssetManager *sInstance;
};
#endif