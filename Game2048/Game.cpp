#include "Game.h"
#include <ctime>
#include <utility> // move
#include <algorithm> // fill, for_each
#include "Render.h"

Game::Game()
{
	//m_cells = nullptr;
}

Game::~Game()
{

}

void Game::init(int size)
{


	m_score = 0;
	m_bestScore = 100;
	m_curScoreBoard = new ScoreBoard("SCORE", m_score);
	m_bestScoreBoard = new ScoreBoard("BEST", m_bestScore);
}

void Game::quit()
{
	delete m_curScoreBoard;
	delete m_bestScoreBoard;
}

void Game::restart()
{
	m_gameOver = false;
	m_score = 0;

}

//std::vector<int> Game::getAvailableCells()
//{
//	//TODO
//	//std::vector<int> availableCells;
//	//for (int i = 0; i < m_size * m_size; i++)
//	//	if (m_cells[i] == nullptr)
//	//		availableCells.push_back(i);
//
//	//return std::move(availableCells);
//}

void Game::addRandomTile()
{
	//TODO
	//auto availableCells = getAvailableCells();
	//if (availableCells.empty())
	//	return;

	//std::uniform_int_distribution<int> u1(0, availableCells.size() - 1);
	//auto cell = availableCells[u1(m_random_engine)];

	//std::bernoulli_distribution u2(0.9);
	//int value = u2(m_random_engine) ? 2 : 4;

	//Tile *tile = new Tile(cell / m_size, cell % m_size, value);
	//tile->attachAnimation(tileAppearAnimation);
	//m_cells[cell] = tile;
}

//void Game::forEachTile(std::function<void(Tile *)> callback)
//{
//	for (int i = 0; i < m_size * m_size; i++)
//		if (m_cells[i] != nullptr)
//			callback(m_cells[i]);
//}

void debugPrintGrids(Game *g)
{
	//for (int row = 0; row < g->m_size; row++) {
	//	for (int col = 0; col < g->m_size; col++) {
	//		Tile *t = g->m_cells[row * g->m_size + col];
	//		printf(" %d", t ? t->value() : 0);
	//	}
	//	putchar('\n');
	//}
}

void Game::fill(Dir dir, int a, int b, int *pRow, int *pCol)
{
	if (dir % 2 == 1)
		b = m_size - 1 - b;

	if (dir / 2 == 1)
		*pRow = a, *pCol = b;
	else
		*pRow = b, *pCol = a;
}

void Game::reduce(const std::vector<int> &mapping, bool *pMoved, int *pDeltaScore)
{

}

void Game::move(Dir dir)
{

}

bool Game::movesAvailable()
{
	return false;
}

void Game::render()
{
	m_bestScoreBoard->render();
	m_curScoreBoard->render();

}

void Game::update(int delta_ms)
{

}