#include "Font.h"
#include <stdio.h>

void Font::init(const char *filePath, int size)
{
	free();

	m_font = TTF_OpenFont(filePath, size);
	if (!m_font) {
		SDL_Log(TTF_GetError());
	}
}

void Font::free()
{
	if (m_font) {
		TTF_CloseFont(m_font);
		m_font = NULL;
	}
}

SDL_Surface *Font::renderLatin(const char *str, SDL_Color fgColor)
{
	return TTF_RenderText_Blended(m_font, str, fgColor);
}
