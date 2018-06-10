/*
Jakub Jalowiec
WEiTI PW
2018
Sortowanie pojemnikow z farba CMYK.
*/

#pragma once
#include "Algorithm.h"

using namespace std;

class Benchmark {
private:
	Algorithm algorithm;
	int N;
	int K;
	int R;
	int step;
	double **results;
	double complexityFast;
	double complexityBrut;
	double complexityBruP;
	void showTable(double cFast, double cBrut, double cBruP);
public:
	void run();
	void setComplexity();
	Benchmark(int _N, int _K, int _R, int _step);
	void showTable();
};