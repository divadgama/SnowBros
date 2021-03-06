#include "Globals.h"
#include "Game.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleSceneSpace.h"

ModuleSceneSpace::ModuleSceneSpace(bool start_enabled) : Module(start_enabled)
{
	background = NULL;
	stars = NULL;
}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("background.png");

	App->collision->Enable(); // enable before player
	App->player->Enable();
	App->audio->PlayMusic("stage1.ogg", 1.0f);

	App->renderer->camera.x = App->renderer->camera.y = 0;

	App->collision->AddCollider({0, 224, 3000, 16}, COLLIDER_WALL);

	App->collision->AddCollider({1376, 0, 112, 95}, COLLIDER_WALL);
	App->collision->AddCollider({1376, 144, 112, 95}, COLLIDER_WALL);

	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();
	App->collision->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 1;

	App->player->position.x += 1;
	App->renderer->camera.x -= 3;
	
	// Draw everything --------------------------------------
	App->renderer->Blit(background, 0, 0, NULL);
	
	return UPDATE_CONTINUE;
}