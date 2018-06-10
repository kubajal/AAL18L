/*
Jakub Jalowiec
WEiTI PW
2018
Sortowanie pojemnikow z farba CMYK.
*/

#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>

#define FASTSORT 1
#define BRUTEFORCE 2
#define BRUTEPREPROCESS 3

using namespace std;


class Algorithm {
private:
	clock_t startTime;
	clock_t endTime;
	clock_t clockTicksTaken = 0;
	double timeInSeconds;

	int countLetters(string s, char l, int start);
	int findLastSortedLetter(int start, string &s, char l);
	string movePostfixToEnd(string &s, int n);
	string movePrefixToEnd(string &s, int n);
	void count(char l, string &s, vector<int> &tab);
	string sortNext(string &s, int i, char l);
	void bruteForceLetter(int index, string &s, char l);
	void bruteForce(string &s);
	string preprocessLetter(int index, string &s, char l);
	void goodMove(string &s, int i, int k, char l);
	void bruteForceLetterWithPreprocessing(int i, string &s, char l);
	void bruteForceWithPreprocessing(string &s);
	void fastSortLetter(int lettersLeft, string &s, char l, int start);
	void fastSort(string &s);

public:
	double run(string s, int type);
	string generateRandomSeq(int n);
	int moves = 0;
};