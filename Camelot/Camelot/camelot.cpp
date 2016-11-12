/*
NAME: lukezhu1
LANG: C++
TASK: camelot
*/
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define CODE_WORKS true
#define mi vector<vector<int> >
#define vi vector<int>
using namespace std;

struct pos {
	int x, y, mC; //mC == moveCount
	pos(int x = 0, int y = 0, int mC = 0) : x(x), y(y), mC(mC) {}
};

pos moves[8] = { pos(2, 1), pos(2, -1), pos(1, 2), pos(-1, 2), pos(-2, 1), pos(-2, -1), pos(-1, -2), pos(1, -2) };
int R, C, kC = 0; //kC == knightCount
pos king;

bool valid(pos box) {
	return ((box.x > 0 && box.x <= R) && (box.y > 0 && box.y <= C));
}
bool maybKing(pos loc, int gx, int gy) {
	if (loc.x < min(gx, king.x) || loc.x > max(gx, king.x) || loc.y < min(gy, king.y) || loc.y > max(gy, king.y)) return false; //checks if king is even inside the rectangle goal and init pos' make
	if (abs(gy - king.y) >= abs(gx - king.x)) {
		return (abs(loc.x - gx) <= abs(loc.y - gy) && abs(loc.x - king.x) <= abs(loc.y - king.y));
	}
	else {
		return (abs(loc.x - gx) >= abs(loc.y - gy) && abs(loc.x - king.x) >= abs(loc.y - king.y));
	}
}


int main() {
	ifstream in("camelot.in");
	ofstream out("camelot.out");
	in >> C >> R;
	char temp; in >> temp; int temp2;
	king.x = temp - 'A' + 1; in >> king.y;

	vector<pos> knights;
	while (!in.eof()) {
		in >> temp >> temp2;
		knights.push_back(pos((temp - 'A' + 1), temp2));
		kC++;
	}
	knights[knights.size() - 1] = king;
	vector<vector<vector<int> > > knightDist = vector<mi >(kC, mi((R + 1), vi((C + 1), 1000000)));
	mi v(R + 1, vi(C + 1, 0));
	for (int i = 0; i < kC; i++) { //Figures out shortest amount of moves to each square for each knight
		for (int j = 0; j < (R + 1); j++) for (int k = 0; k < (C + 1); k++) v[j][k] = 0;
		int filledIn = 0; //Keeps track of how many end points we have reached
		queue<pos> Q;
		Q.push(knights[i]);
		while (!Q.empty()) {
			pos curr = Q.front(); Q.pop();
			if (filledIn == R * C) break;
			if (curr.mC < knightDist[i][curr.x][curr.y]) {
				if (knightDist[i][curr.x][curr.y] != 1000000) filledIn++;
				knightDist[i][curr.x][curr.y] = curr.mC;
			}
			if (v[curr.x][curr.y]++) continue;
			for (int j = 0; j < 8; j++) { //cycles through moves
				pos moved = pos(curr.x + moves[j].x, curr.y + moves[j].y, curr.mC + 1);
				if (!valid(moved)) continue;
				Q.push(moved);
			}
		}
	}

	mi kingDist(R + 1, vi(C + 1, 0)); //Stores shortest amount of moves from king to each square
	for (int i = 1; i < R + 1; i++) for (int j = 1; j < C + 1; j++) kingDist[i][j] = max(abs(i - king.x), abs(j - king.y));
	int minMoves = 1000000;
	for (int gx = 1; gx <= R; gx++) {
		for (int gy = 1; gy <= C; gy++) { //Tests each point as meeting point
			int sKm = 0; //Sum of moves of all knights going to certain position
			for (int i = 0; i < kC - 1; i++) sKm += knightDist[i][gx][gy];

			int allGo = kingDist[gx][gy] + sKm; //Everyone goes by themselves

			int rideK = allGo; //Knight picks up king
			for (int i = 0; i < kC - 1; i++) {
				int pickup = knightDist[kC - 1][gx][gy] + knightDist[i][king.x][king.y];
				rideK = min(rideK, allGo - knightDist[i][gx][gy] - kingDist[gx][gy] + pickup);
			}

			int goTo = allGo; //King walks to knight
			for (int i = 0; i < kC - 1; i++) {
				goTo = min(goTo, allGo - kingDist[gx][gy] + kingDist[knights[i].x][knights[i].y]);
			}
			int ans = min(min(allGo, rideK), goTo);
			minMoves = min(minMoves, ans);
		}

	}
	out << minMoves << endl;
}
