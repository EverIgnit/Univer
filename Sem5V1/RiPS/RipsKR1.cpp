// 2
// stdin
// stdout
#include <iostream>
using namespace std;

int main()
{
	int N, K;
	cout << "Enter number of threads:\n> ";
	cin >> K;
	cout << "Enter N:\n> ";
	cin >> N;

	auto arr = new double* [N + 1];
	for (auto i = 1; i <= N; i++)
		arr[i] = new double[N + 1];

	cout << "Enter matrix elements:\n";
	for (auto i = 1; i <= N; i++)
		for (auto j = 1; j <= N; j++)
			cin >> arr[i][j];

#pragma omp parallel num_threads(K)
	{
		auto mins = new double[N+1];
		double temp;
		for (auto i = 1; i <= N; i++) {
			temp = arr[i][1];
			for (auto j = 1; j <= N / 2 + 1; j++)
				if (arr[i][2 * j - 1] < temp)
					temp = arr[i][2 * j - 1];
			mins[i] = temp;
		}

		cout << "Min els:\n";

		for (auto i = 1; i <= N; i++)
			cout << mins[i] << " ";
		cout << endl;

		auto sum = 0.0;
		for (int i = 1; i <= N; i++)
			sum += mins[i];
		cout << "Sum: " << sum << endl;
	}

	system("pause");
	return 0;
}