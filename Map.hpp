/**
Copyright (C) 2011 babin philippe

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.*/
//#include "includes.hpp"
#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED
struct Type{
	bool		visible;	//is the tile visible
	bool		solid;	//is the tile solid
	bool		kill;	//is the tile killer
	sf::Color   colorPix;
	sf::IntRect zoneRect;
	sf::Sprite tile;};
class MapTile{
	public:
        MapTile();
        MapTile(sf::RenderWindow *App,const char* tileset,const char* image_schema,const char* image_corr,const char* tileprop,vector<sf::Image*> *imgManag,Player *playerOne, Player *playerTwo);
		void loadMap(const char* tileset,const char* image_schema,const char* image_corr,const char* tileprop);		//loads the map from a file
		void draw();
        vector<Type> & operator [] (int X);
        unsigned char findType(sf::Color Pix);
        bool collisionTile(float x,float y);
        Type Tile(float x, float y);
        vector<GameObject*> * getMapObject();

        bool collisionGeneral(const sf::FloatRect playerRect,bool &kill);
        bool collisionHorizontal(const sf::FloatRect playerRect, bool &gauche, bool &droite,int &solidLimit);
        bool collisionVertical(const sf::FloatRect playerRect, bool &haut, bool &bas,int &solidLimit);
		int m_width, m_height;
		sf::Vector2f m_spawnLocationOne;
		sf::Vector2f m_spawnLocationTwo;
	private:
        sf::RenderWindow *m_app;
		sf::Image m_ImgTypeTile;
		sf::Sprite m_drawSprite;
		vector <vector<Type> > m_tileSet;
		vector <Type> m_typeList;
		vector <GameObject*> m_mapObject;
		vector <GameItems*> m_mapItems;
        vector<sf::Image*> *m_imgManag;
		Player *m_playerOne;
		Player *m_playerTwo;
		sf::RenderImage m_map;

};


#endif // MAP_HPP_INCLUDED
