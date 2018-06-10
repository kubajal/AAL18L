/*
Jakub Jalowiec
WEiTI PW
2018
Sortowanie pojemnikow z farba CMYK.
*/

#include "Benchmark.h"

void Benchmark::run()
{
	int length = N;
	for (int k = 0; k < K; k++) {
		double **q;
		q = new double*[R];
		for (int i = 0; i < R; i++) {
			q[i] = new double[3];
		}
//		cout << "----------------------------------------------------------" << endl;
//		cout << "|    N    |     T(N)    |     moves     |       q        |" << endl;
//		cout << "----------------------------------------------------------" << endl;

		for (int r = 0; r < R; r++) {

			string s = algorithm.generateRandomSeq(length);
			string s1 = s;
			string s2 = s;
			string s3 = s;
//			cout << "Generated sequence : " << s << endl;
			double d = algorithm.run(s1, FASTSORT, false);
			q[r][0] = (double)algorithm.moves / (length * length);
//			printf("|%9s|%13s|%15s|%16s|\n", std::to_string(length).c_str(), std::to_string(length * length).c_str(), std::to_string(algorithm.moves).c_str(), std::to_string(q[r][0]).c_str());
			results[k][0] += d;
			d = algorithm.run(s2, BRUTEFORCE, false);
			q[r][1] = (double)algorithm.moves / (length * length * length);
			results[k][1] += d;
			d = algorithm.run(s3, BRUTEPREPROCESS, false);
			q[r][2] = (double)algorithm.moves / (length * length * length);
			results[k][2] += d;
		}
		results[k][0] /= (double)R;
		results[k][1] /= (double)R;
		results[k][2] /= (double)R;


//		cout << "----------------------------------------------------------" << endl;


		length += step;


	}
}

Benchmark::Benchmark(int _N, int _K, int _R, int _step)
{
	N = _N;
	K = _K;
	R = _R;
	complexityBruP = 3.0;
	complexityBrut = 3.0;
	complexityFast = 2.0;
	step = _step;
	results = new double*[K];
	for (int i = 0; i < K; i++)
		results[i] = new double[3];
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 3; j++) {
			results[i][j] = 0;
		}
	}
}

void Benchmark::showTable()
{
	showTable(complexityFast, complexityBrut, complexityBruP);
}

void Benchmark::showTable(double cFast, double cBrut, double  cBruP)
{
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| no  |    length   |   FAST SORT   |  qFast  |     BRUTE FORCE      |  qBrut  |    BRUTE FORCE   |    qBrut    |" << endl;
	cout << "|     | of sequence |               |         |  without preprocess  |         | with preprocess  |with Preproc |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	double tMedianFast = results[K / 2][0];
	double tMedianBrut = results[K / 2][1];
	double tMedianBrutPreprocess = results[K / 2][2];

	for (int i = 0; i < K; i++) {
		double qFast = (results[i][0] * (pow(N + K / 2 * step, cFast))) / (pow(N + i * step, cFast) * results[K / 2][0]);
		double qBrut = (results[i][1] * (pow(N + K / 2 * step, cBrut))) / (pow(N + i * step, cBrut) * results[K / 2][1]);
		double qBruP = (results[i][2] * (pow(N + K / 2 * step, cBruP))) / (pow(N + i * step, cBruP) * results[K / 2][2]);
		
		printf("|%5s|%13s|%15s|%9s|%22s|%9s|%18s|%13s|\n", std::to_string(i + 1).c_str(), std::to_string(N + i * step).c_str(), std::to_string(results[i][0]).c_str(), std::to_string(qFast).c_str(), std::to_string(results[i][1]).c_str(), std::to_string(qBrut).c_str(), std::to_string(results[i][2]).c_str(), std::to_string(qBruP).c_str());
	}
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

}

void Benchmark::setComplexity() {
	cout << "cFast = ";
	cin >> complexityFast;
	cout << endl;
	cout << "cBrut = ";
	cin >> complexityBrut;
	cout << endl;
	cout << "cBruP = ";
	cin >> complexityBruP;
	cout << endl;
}