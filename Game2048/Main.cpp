#include <stdio.h>
#include <vector>
#include "Render.h"
#include "Game.h"

#include <algorithm>
#include <math.h>
#include "Button.h"
#include <SDL_image.h>

Game g;
Button *newGameBtn;
extern const int SCREEN_WIDTH = 700;
extern const int SCREEN_HEIGHT = 640;

static SDL_Window *g_window = NULL;
static SDL_Renderer *g_renderer = NULL;

bool InitSDL()
{
	SDL_Log("dc roi");
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_Log(SDL_GetError());
		success = false;
	}
	else {
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			SDL_Log("Warning: Linear texture filtering not enabled!\n");
		}

		g_window = SDL_CreateWindow(
			"2048",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
		if (g_window == NULL) {
			

			success = false;
		}
		else {
			g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (g_renderer == NULL) {
				SDL_Log(SDL_GetError());
			}
			g_render.init(g_renderer);

			int imgFlags = IMG_INIT_PNG;
			int debug1 = IMG_Init(imgFlags);
			if (!(debug1& imgFlags)) {
				SDL_Log(SDL_GetError());
				success = false;
			}

			if (TTF_Init() == -1) {
				SDL_Log(TTF_GetError());
				success = false;
			}
		}
	}

	return success;
}

void CloseSDL()
{
	SDL_DestroyRenderer(g_renderer);
	g_renderer = NULL;
	SDL_DestroyWindow(g_window);
	g_window = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Frame(int delta_ms)
{
	SDL_Color WHITE = { 255, 255, 255, 255 };
	g_render.setDrawColor(WHITE);
	g_render.clear();

	g.render();
	newGameBtn->render();

	g_render.present();

	g.update(delta_ms);
	newGameBtn->update(delta_ms);
}

int main(int argc, char *argv[])
{
	if (!InitSDL())
		return 1;

	Button_loadMetaData();

	g.init(4);
	newGameBtn = new Button("New Game", [] { g.restart(); });
	newGameBtn->setXY(100, 35);

	g.curScoreBoard()->setXY(
		400,
		20);
	g.bestScoreBoard()->setXY(
		500,
		20);



	SDL_Event e;
	Uint32 ticks = SDL_GetTicks();
	for (;;) {
		while (SDL_PollEvent(&e)) {
			newGameBtn->handleEvent(e);

			if (e.type == SDL_QUIT)
				goto quit;
			else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					g.move(UP);
					break;
				case SDLK_RIGHT:
					g.move(RIGHT);
					break;
				case SDLK_DOWN:
					g.move(DOWN);
					break;
				case SDLK_LEFT:
					g.move(LEFT);
					break;
				}
			}
		}

		Uint32 new_ticks = SDL_GetTicks();
		int delta = new_ticks - ticks;
		ticks = new_ticks;
		Frame(delta);
	}

quit:

	g.quit();
	free(newGameBtn);

	Button_unloadMetaData();

	CloseSDL();

	return 0;
}

