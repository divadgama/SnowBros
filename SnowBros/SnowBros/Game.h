#ifndef __GAME_CPP_
#define __GAME_CPP_

#include<list>
#include "Globals.h"
//#include "Module.h" 

class Game
{
public:
	Game();
	~Game();

	bool Init();
	update_status Update();
	bool CleanUp();
};
#endif //__GAME_CPP_
