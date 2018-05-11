#include "MoveTile.h"

void move(Direction d) {
	bool didMove = 0;
	if (d == Up) {
		for (int j = 0; j<M; j++) {
			for (int i = 0; i<N - 1; i++) {
				if (MAP[i][j] == 0) {
					bool change = 0;
					for (int k = i; k<N - 1; k++) {
						MAP[k][j] = MAP[k + 1][j];
						if (MAP[k][j] != 0)
						{
							didMove = 1;
							change = 1;
						}
					}
					MAP[N - 1][j] = 0;
					if (change) i--;
				}
			}
			for (int i = 0; i<N - 1; i++) {
				if (MAP[i][j] == MAP[i + 1][j] && MAP[i][j] != 0) {
					didMove = 1;
					for (int k = i; k<N - 1; k++)
						MAP[k][j] = MAP[k + 1][j];
					MAP[N - 1][j] = 0;
					MAP[i][j] = MAP[i][j]* MAP[i][j];
				}
			}
		}
	}
	else if (d == Left) {
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<M - 1; j++) {
				if (MAP[i][j] == 0) {
					bool change = 0;
					for (int k = j; k<M - 1; k++) {
						MAP[i][k] = MAP[i][k + 1];
						if (MAP[i][k] != 0)
						{
							didMove = 1;
							change = 1;
						}
					}
					MAP[i][M - 1] = 0;
					if (change) j--;
				}
			}
			for (int j = 0; j<N - 1; j++) {
				if (MAP[i][j] == MAP[i][j + 1] && MAP[i][j] != 0) {
					didMove = 1;
					for (int k = j; k<M - 1; k++)
						MAP[i][k] = MAP[i][k + 1];
					MAP[i][M - 1] = 0;
					MAP[i][j] = MAP[i][j] * MAP[i][j];
				}
			}
		}
	}
	else if (d == Down) {
		for (int j = 0; j<M; j++) {
			for (int i = N - 1; i >= 0; i--) {
				if (MAP[i][j] == 0) {
					bool change = 0;
					for (int k = i; k>0; k--) {
						MAP[k][j] = MAP[k - 1][j];
						if (MAP[k][j] != 0)
						{
							didMove = 1;
							change = 1;
						}
					}
					MAP[0][j] = 0;
					if (change) i++;
				}
			}
			for (int i = N - 1; i>0; i--) {
				if (MAP[i][j] == MAP[i - 1][j] && MAP[i][j] != 0) {
					didMove = 1;
					for (int k = i; k >= 0; k--)
						MAP[k][j] = MAP[k - 1][j];
					MAP[0][j] = 0;
					MAP[i][j] = MAP[i][j] * MAP[i][j];
				}
			}
		}
	}
	else if (d == Right) {
		for (int i = 0; i<N; i++) {
			for (int j = M - 1; j >= 0; j--) {
				if (MAP[i][j] == 0) {
					bool change = 0;
					for (int k = j; k>0; k--) {
						MAP[i][k] = MAP[i][k - 1];
						if (MAP[i][k] != 0) {
							didMove = 1;
							change = 1;
						}
					}
					MAP[i][0] = 0;
					if (change) j++;
				}
			}

			for (int j = M - 1; j>0; j--) {
				if (MAP[i][j] == MAP[i][j - 1] && MAP[i][j] != 0) {
					didMove = 1;
					for (int k = j; k>0; k--)
						MAP[i][k] = MAP[i][k - 1];
					MAP[i][0] = 0;
					MAP[i][j] = MAP[i][j] * MAP[i][j];
				}
			}
		}
	}
	if (didMove)
		addNewTile();
}