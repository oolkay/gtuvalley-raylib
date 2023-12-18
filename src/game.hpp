#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "player.hpp"
#include "enemy.hpp"

class Enemy;
class player;
class mesh;
using std::vector;

class Game {
	public:
		Game();
		void	run();
		void	initMap();
		void	renderMap() const ;
		void	drawHuds() const ;
		void	fillEnemy();
		void	initTextures();
	private:
		vector<vector<mesh *> >	map;
		vector<Enemy *>			enemies;

		const int				width;
		const int				height;
		player					pl;
		//vector<enemy>			enemy;
};

#endif
