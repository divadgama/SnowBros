#include <stdlib.h>
#include "Game.h"
#include "Globals.h"

#include "../SDL/include/SDL.h"
#pragma comment( lib, "../SDL/libx86/SDL2.lib" )
#pragma comment( lib, "../SDL/libx86/SDL2main.lib" )

enum main_states
{
	MAIN_CREATION,
	MAIN_INIT,
	MAIN_START,
	MAIN_PREUPDATE,
	MAIN_UPDATE,
	MAIN_POSTUPDATE,
	MAIN_FINISH, 
	MAIN_EXIT
};

Game* App = NULL;

int main(int argc, char ** argv)	
{
	int main_return = EXIT_FAILURE;
	main_states state = MAIN_CREATION;
	while (state != MAIN_EXIT)
	{
		switch (state)
		{
		case MAIN_CREATION:

			LOG("Application Creation --------------");
			App = new Game();
			state = MAIN_INIT;
			break;

		case MAIN_INIT:

			LOG("Application Init --------------");
			if (App->Init() == false)
			{
				LOG("Application Init exits with error -----");
				state = MAIN_EXIT;
			}
			else
			{
				state = MAIN_START;
				LOG("Application Update --------------");
			}

			break;

		case MAIN_START:

			LOG("Application Start --------------");
			if (App->Start() == false)
			{
				LOG("Application Start exits with error -----");
				state = MAIN_EXIT;
			}
			else
			{
				state = MAIN_PREUPDATE;
				LOG("Application Update --------------");
			}

			break;

		case MAIN_PREUPDATE:
		{
			int update_return = App->PreUpdate();

			if (update_return == UPDATE_CONTINUE){
				state = MAIN_UPDATE;
			}

			if (update_return == UPDATE_ERROR)
			{
				LOG("Application PreUpdate exits with error -----");
				state = MAIN_EXIT;
			}
			if (update_return == UPDATE_STOP)
				state = MAIN_FINISH;
		}
		break;

		case MAIN_UPDATE:
		{
			int update_return = App->Update();

			if (update_return == UPDATE_CONTINUE){
				state = MAIN_POSTUPDATE;
			}
			if (update_return == UPDATE_ERROR)
			{
				LOG("Application Update exits with error -----");
				state = MAIN_EXIT;
			}

			if (update_return == UPDATE_STOP)
				state = MAIN_FINISH;
		}
		break;

		case MAIN_POSTUPDATE:
		{
			int update_return = App->PostUpdate();

			if (update_return == UPDATE_CONTINUE){
				state = MAIN_PREUPDATE;
			}

			if (update_return == UPDATE_ERROR)
			{
				LOG("Application PostUpdate exits with error -----");
				state = MAIN_EXIT;
			}
			if (update_return == UPDATE_STOP)
				state = MAIN_FINISH;
		}
		break;

		case MAIN_FINISH:

			LOG("Application CleanUp --------------");
			if (App->CleanUp() == false)
			{
				LOG("Application CleanUp exits with error -----");
			}
			else
				main_return = EXIT_SUCCESS;

			state = MAIN_EXIT;

			break;

		}
	}

	delete App;
	LOG("Close OK :)\n");
	return main_return;
}