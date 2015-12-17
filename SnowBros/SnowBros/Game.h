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
	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
};
#endif //__GAME_CPP_
