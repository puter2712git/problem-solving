#include <iostream>

using namespace std;

string seminar;
int applicantCount;

string maxSeminar;
int maxApplicantCount = -1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 7; i++) {
		cin >> seminar >> applicantCount;
		if (maxApplicantCount < applicantCount) {
			maxApplicantCount = applicantCount;
			maxSeminar = seminar;
		}
	}

	cout << maxSeminar << "\n";

	return 0;
}