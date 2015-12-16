#include <stdlib.h>
//#include "Application.h"
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


int main(int argc, char ** argv)	
{
	int main_return = EXIT_FAILURE;
	main_return = EXIT_SUCCESS;
	main_states state = MAIN_CREATION;



	LOG("Close OK :)\n");
	return main_return;
}