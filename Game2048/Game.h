#pragma once


#include <vector>
#include <functional>
#include <random>
#include <memory>
#include "ScoreBoard.h"


enum Dir
{
	/* do not change the order here */
	UP, DOWN, LEFT, RIGHT
};

class Game
{
public:
	Game();
	~Game();

	void init(int size);
	void quit();
	void restart();
	void move(Dir dir);

	void render();
	void update(int delta_ms);


	ScoreBoard *curScoreBoard() { return m_curScoreBoard; }
	ScoreBoard *bestScoreBoard() { return m_bestScoreBoard; }

	bool gameOver() { return m_gameOver; }

	friend void debugPrintGrids(Game *g);

private:
	std::default_random_engine m_random_engine;
	int m_size;
	bool m_gameOver;
	int m_score;
	int m_bestScore;
	ScoreBoard *m_curScoreBoard;
	ScoreBoard *m_bestScoreBoard;


	std::vector<int> getAvailableCells();
	void addRandomTile();
	bool movesAvailable();
	void fill(Dir dir, int a, int b, int *pRow, int *pCol);
	void reduce(const std::vector<int> &mapping, bool *pMoved, int *pDeltaScore);
};