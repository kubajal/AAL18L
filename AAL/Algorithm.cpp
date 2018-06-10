/*
Jakub Jalowiec
WEiTI PW
2018
Sortowanie pojemnikow z farba CMYK.
*/

#include "Algorithm.h"

using namespace std;

int Algorithm::countLetters(string s, char l, int start) {
	int count = 0;
	for (int i = start; i < s.size(); i++) {
		if (s[i] == l)
			count++;
	}
	return count;
}

int Algorithm::findLastSortedLetter(int start, string &s, char l) {
	int i = start;
	while (s[i] == l)
		i++;
	return i;
}

string Algorithm::movePostfixToEnd(string &s, int n) {
	int first = n;
	int last = first + 4;
	if (last > s.size())
		throw "Out of boud";
	string p = s;
	s.append(p, first, 4);
	s.erase(first, 4);
	moves++;
	return s;
}


string Algorithm::movePrefixToEnd(string &s, int n) {
	int last = min((int)s.length(), n);
	int first = max(0, last - 4);
	string p = s;
	s.append(p, first, 4);
	s.erase(first, 4);
	moves++;
	return s;
}

void Algorithm::count(char l, string &s, vector<int> &tab) {

	if (tab.size() == 0)
		for (int i = 0; i < s.length(); i++)
			tab.push_back(0);
	int n = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == l)
			n = 0;
		tab[i] = n++;
	}
}

string Algorithm::sortNext(string &s, int i, char l) {

	if (s.size() - i <= 4)
		return s;

	int max = -1;

	switch ((s.size() - i) % 4)
	{
	case 0:
		max = (s.size() - i) / 4;
		break;
	case 1:
		max = (s.size() - i);
	case 2:
		max = (s.size() - i) / 2;
	case 3:
		max = (s.size() - i);
	}

	int p = 0;
	int q = 0;
	while (s[i] != l) {
		if (max == 0)
		{
			switch ((s.size() - i) % 4)
			{
			case 0:
				max = (s.size() - i) / 4;
				break;
			case 1:
				max = (s.size() - i);
			case 2:
				max = (s.size() - i) / 2;
			case 3:
				max = (s.size() - i);
			}
			s = movePostfixToEnd(s, i + 1);
		}
		else
		{
			s = movePostfixToEnd(s, i);
			max--;
		}
	}

	return s;
}

void Algorithm::bruteForceLetter(int index, string &s, char l)
{
	if (s[index] != l)
		s = sortNext(s, index, l);
	return;
}

void Algorithm::bruteForce(string &s) {

	int CLettersToSort = countLetters(s, 'C', 0);
	int MLettersToSort = countLetters(s, 'M', 0);
	int YLettersToSort = countLetters(s, 'Y', 0);
	int KLettersToSort = countLetters(s, 'K', 0);

	int index = 0;
	while (CLettersToSort > 0) {
		bruteForceLetter(index, s, 'C');
		index++;
		CLettersToSort--;
	}
	while (MLettersToSort > 0) {
		bruteForceLetter(index, s, 'M');
		index++;
		MLettersToSort--;
	}
	while (YLettersToSort > 0) {
		bruteForceLetter(index, s, 'Y');
		index++;
		YLettersToSort--;
	}
	while (KLettersToSort > 0) {
		bruteForceLetter(index, s, 'K');
		index++;
		KLettersToSort--;
	}
}

string Algorithm::preprocessLetter(int index, string &s, char l) {
	int size = s.size();
	int n = 0;
	for (int i = index; i < size; i++) {
		if (s[i] != l)
			continue;
		int rowLength = 0;
		int rowBegin = i;
		while (s[i] == l && i < size) {
			i++;
			rowLength++;
		}
		while (rowLength >= 4) {
			movePostfixToEnd(s, rowBegin);
			rowLength -= 4;
			size -= 4;
			n++;
		}
		i = rowBegin;
	}
	int k = 0;
	while (k < (s.size() - index) / 4 - n) {
		s = movePostfixToEnd(s, index);
		k++;
	}
	return s;
}

void Algorithm::goodMove(string &s, int i, int k, char l) {
	if (i >= s.size() || i + k >= s.size())
		return;
	int n = countLetters(s, l, i);
	if (n == 0)
		return;
	switch (k % 4) {
	case 0:
		return;
	case 1:
		switch ((s.size() - i - k - 1) % 4) {
		case 0:
			movePrefixToEnd(s, i + 1);
			while (s[i - 3] != l || s[i - 2] != l || s[i - 1] != l || s[i] != l)
				movePostfixToEnd(s, i - 2);
			break;
		case 1:
			movePostfixToEnd(s, i);
			while (s[i] != l)
				movePostfixToEnd(s, i);
			break;
		case 2:
			movePostfixToEnd(s, i + 1);
			while (s[i] != l)
				movePostfixToEnd(s, i);
			break;
		case 3:
			movePostfixToEnd(s, i + 1);
			movePrefixToEnd(s, s.size() - 3);
			while (s[i] != l)
				movePostfixToEnd(s, i);
			break;
		}
		break;
	case 2:
		switch ((s.size() - i - k - 1) % 4) {
		case 0:
			movePrefixToEnd(s, i + 2);
			while (s[i - 2] != l || s[i - 1] != l || s[i] != l)
				movePostfixToEnd(s, i - 1);
			break;
		case 1:
			movePostfixToEnd(s, i + k);
			while (s[i] != l)
				movePostfixToEnd(s, i);
			break;
		case 2:
			movePostfixToEnd(s, i);
			movePrefixToEnd(s, s.size() - 1);
			while (s[i] != l)
				movePostfixToEnd(s, i);
			break;
		case 3:
			movePostfixToEnd(s, i);
			while (s[i] != l)
				movePostfixToEnd(s, i);
			break;
		}
		break;
	case 3:
		switch ((s.size() - i - k - 1) % 4) {
		case 0:
			movePostfixToEnd(s, i + 3);
			while (s[i] != l)
				movePostfixToEnd(s, i);
			break;
		case 1:
			movePostfixToEnd(s, i);
			while (s[i] != l)
				movePostfixToEnd(s, i);
			break;

		case 2:
			movePostfixToEnd(s, i + 1);
			while (s[i] != l)
				movePostfixToEnd(s, i);
			break;
		case 3:
			movePostfixToEnd(s, i + 2);
			while (s[i] != l)
				movePostfixToEnd(s, i);
			break;
		}
		break;
	}
}

void Algorithm::bruteForceLetterWithPreprocessing(int i, string &s, char l) {
	preprocessLetter(i, s, l);
	int firstWrong = findLastSortedLetter(i, s, l);
	int lettersLeft = countLetters(s, l, firstWrong);
	int index = firstWrong;
	while (lettersLeft > 0) {
		bruteForceLetter(index, s, l);
		index++;
		lettersLeft--;
	}
}

void Algorithm::bruteForceWithPreprocessing(string &s) {

	int CLettersToSort = countLetters(s, 'C', 0);
	int MLettersToSort = countLetters(s, 'M', 0);
	int YLettersToSort = countLetters(s, 'Y', 0);
	int KLettersToSort = countLetters(s, 'K', 0);

	int index = 0;
	if (CLettersToSort != 0) {
		bruteForceLetterWithPreprocessing(index, s, 'C');
		index = findLastSortedLetter(index, s, 'C');
	}
	if (MLettersToSort != 0) {
		bruteForceLetterWithPreprocessing(index, s, 'M');
		index = findLastSortedLetter(index, s, 'M');
	}
	if (YLettersToSort != 0) {
		bruteForceLetterWithPreprocessing(index, s, 'Y');
		index = findLastSortedLetter(index, s, 'Y');
	}
	if (KLettersToSort != 0)
		bruteForceLetterWithPreprocessing(index, s, 'K');
	return;
}

void Algorithm::fastSortLetter(int lettersLeft, string &s, char l, int start) {

	if (lettersLeft <= 4) {
		for (int i = start; i < start + lettersLeft; i++)
			bruteForceLetter(i, s, l);
		return;
	}

	for (int i = start; i < start + 4; i++) {
		bruteForceLetter(i, s, l);
	}

	for (int i = 4 + start; i < start + lettersLeft && i < s.size() - 4; i++) {
		if (s[i] == l)
			continue;
		int k = 1;
		if (i + k >= s.size())
			return;
		while (s[i + k] != l && i + k < s.size())
			k++;
		while (k >= 4) {
			movePostfixToEnd(s, i);
			k -= 4;
		}
		goodMove(s, i, k, l);
	}
}

void Algorithm::fastSort(string &s) {
	int CLettersToSort = countLetters(s, 'C', 0);
	int MLettersToSort = countLetters(s, 'M', 0);
	int YLettersToSort = countLetters(s, 'Y', 0);
	int KLettersToSort = countLetters(s, 'K', 0);

	int index = 0;

	fastSortLetter(CLettersToSort, s, 'C', index);
	index += CLettersToSort;
	fastSortLetter(MLettersToSort, s, 'M', index);
	index += MLettersToSort;
	fastSortLetter(YLettersToSort, s, 'Y', index);
	index += YLettersToSort;
	fastSortLetter(KLettersToSort, s, 'K', index);
}

#define FASTSORT 1
#define BRUTEFORCE 2
#define BRUTEPREPROCESS 3

double Algorithm::run(string s, int type) {

	moves = 0;
	switch (type) {
	case FASTSORT:
//		cout << endl << "fast sort:                          ";
		startTime = clock();
		fastSort(s);
		endTime = clock();
		break;
	case BRUTEFORCE:
//		cout << endl << "brute force without  preprocessing: ";
		startTime = clock();
		bruteForce(s);
		endTime = clock();
		break;
	case BRUTEPREPROCESS:
//		cout << endl << "brute force with preprocessing:     ";
		startTime = clock();
		bruteForceWithPreprocessing(s);
		endTime = clock();
		break;
	}
//	cout << "s: " << s << endl;
	clockTicksTaken = endTime - startTime;
	timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
//	cout << "time [s]: " << timeInSeconds << " moves done: " << moves << endl;
	
	return timeInSeconds;
}

string Algorithm::generateRandomSeq(int n)
{
	char T[] = { 'C', 'M', 'Y', 'K' };
	string s = "";
	srand(time(0));
	
	for (int i = 0; i < n; i++) {
		int r = rand() % 4;
		s += T[r];
	}
	return s;
}
