#ifndef __GAME_CPP_
#define __GAME_CPP_

#include<list>
#include "Globals.h"
#include "Module.h" 


/*class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleAudio;
class ModuleFadeToBlack;
class ModulePlayer;
class ModuleParticles;
class ModuleCollision;
class ModuleSceneIntro;
class ModuleSceneSpace;*/


class Game
{
public:
	Game();
	~Game();

	bool Init();
	update_status Update();
	bool CleanUp();


public:
	//ModuleRender* renderer;
	//ModuleWindow* window;
	//ModuleTextures* textures;
	//ModuleInput* input;
	//ModuleAudio* audio;
	//ModuleFadeToBlack* fade;
	//ModuleParticles* particles;
	//ModuleCollision* collision;

	// Game logic --
	//ModulePlayer* player;
	//ModuleSceneIntro* scene_intro;
	//ModuleSceneSpace* scene_space;


private:

	std::list<Module*> modules;
	//Module* first_scene = nullptr;
};

extern Game* App;
#endif //__GAME_CPP_
