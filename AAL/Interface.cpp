/*
Jakub Jalowiec
WEiTI PW
2018
Sortowanie pojemnikow z farba CMYK.
*/

#include "Interface.h"
#include "Benchmark.h"

using namespace std;

void Interface::prompt(int argc, char ** argv){
	bool benchmark = false;
	bool user = false;
	bool fromFile = false;
	bool fromStdin = false;
	int N = -1;
	int K = -1;
	int R = -1;
	int step = -1;

	Algorithm algorithm;

	if (argc == 1) {
		cout << "No input given. Closing.";
		return;
	}

	if (strcmp(argv[1], "-benchmark") == 0)
	{
		benchmark = true;
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-n") == 0 && i + 1 <= argc) {
				N = atoi(argv[i + 1]);
			}
			else if (strcmp(argv[i], "-k") == 0 && i + 1 <= argc) {
				K = atoi(argv[i + 1]);
			}
			else if (strcmp(argv[i], "-step") == 0 && i + 1 <= argc) {
				step = atoi(argv[i + 1]);
			}
			else if (strcmp(argv[i], "-r") == 0 && i + 1 <= argc) {
				R = atoi(argv[i + 1]);
			}
		}
	}
	else if (strcmp(argv[1], "-stdin") == 0)
		fromStdin = true;

	if (fromStdin == true) {
		string s;
		cout << "Reading from stdin." << endl;
		while (1) {
			cout << "Type in new sequence: ";
			std::cin >> s;
			cout << "Checking if input is correct (should be only letters: {C, M, Y, K}." << endl;
			bool validInputFlag = true;
			for (int i = 0; i < s.size(); i++)
				if (s[i] != 'C' && s[i] != 'M' && s[i] != 'Y' && s[i] != 'K') {
					cout << "Input has wrong format. Skipping." << endl;
					validInputFlag = false;
					break;
				}
			if (validInputFlag == false)
				continue;
			else
				cout << "Input is correct. Processing." << endl << "-------" << endl << endl;
			string s1 = s;
			string s2 = s;
			string s3 = s;
			cout << "Your input: " << "s: " << s << endl;
			algorithm.run(s1, FASTSORT, true);
			algorithm.run(s2, BRUTEFORCE, true);
			algorithm.run(s3, BRUTEPREPROCESS, true);
		}
	}
	else if (benchmark == true && N != -1 && K != -1 && R != -1 && step != -1) {
		cout << "Wait for the table. Calculating..." << endl;
		Benchmark benchmark = Benchmark(N, K, R, step);
		cout << endl;
		benchmark.run();
		benchmark.showTable();
		cout << "Done." << endl;
		cout << "\'FAST SORT\' - results of FAST SORT algorithm, the one that uses combinatorical analysis of the problem." << endl;
		cout << "\'qFast\' - quotion q for the FAST SORT algorithm." << endl;
		cout << "\'BRUTE FORCE without preprocessing\' - results of pure BRUTE FORCE algorithm" << endl;
		cout << "\'qBrut\' - quotion q for the BRUTE FORCE algorithm without preprocessing." << endl;
		cout << "\'BRUTE FORCE with preprocessing\' - results of BRUTE FORCE algorithm with preprocessing of groups of 4 letters" << endl;
		cout << "\'qBrut with Preproc\' - quotion q for the BRUTE FORCE algorithm with preprocessing." << endl;
		cout << endl;
	}
	else {
		cout << "Something went wrong. Did you supply enough arguemnts if using -benchmark? Make sure you use -n, -r, -k -step" << endl;
	}
	string s;
	cout << endl << "Enter anything to exit" << endl;
	cin >> s;
}

