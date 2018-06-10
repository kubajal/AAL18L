#include "Interface.h"
#include "Benchmark.h"

using namespace std;

void Interface::prompt(int argc, char ** argv){
	bool benchmark = false;
	bool user = false;
	bool fromFile = false;
	bool fromStdin = false;
	int N = 0;
	int K = 0;
	int R = 0;
	int step = 0;

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
			algorithm.run(s1, FASTSORT);
			algorithm.run(s2, BRUTEFORCE);
			algorithm.run(s3, BRUTEPREPROCESS);
		}
	}
	if (benchmark == true) {
		Benchmark benchmark = Benchmark(N, K, R, step);
		benchmark.run();
		benchmark.setComplexity();
		benchmark.showTable();
		benchmark.setComplexity();
		benchmark.showTable();
		benchmark.setComplexity();
		benchmark.showTable();
		cout << "Done." << endl;
	}
}

