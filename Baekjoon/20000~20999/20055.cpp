#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> belt;
vector<bool> hasRobot;

int beginIndex;
int endIndex;
int loopCount = 1;
int brokenCount = 0;

void MoveBelt()
{
	beginIndex--;
	if (beginIndex < 0)
		beginIndex += (2 * N);

	endIndex--;
	if (endIndex < 0)
		endIndex += (2 * N);

	if (hasRobot[endIndex])
		hasRobot[endIndex] = false;
}

void MoveRobot()
{
	int currIndex = endIndex;

	for (int i = 0; i < N - 1; i++) {
		int next = currIndex;

		currIndex--;
		if (currIndex < 0)
			currIndex += (2 * N);

		if (!hasRobot[next] && hasRobot[currIndex] && belt[next] > 0) {
			belt[next]--;
			if (belt[next] == 0) {
				brokenCount++;
				if (brokenCount >= K)
					break;
			}

			hasRobot[next] = true;
			hasRobot[currIndex] = false;
		}
	}

	hasRobot[endIndex] = false;
}

void SetRobot()
{
	if (belt[beginIndex] <= 0)
		return;

	belt[beginIndex]--;
	if (belt[beginIndex] == 0) {
		brokenCount++;
	}
	hasRobot[beginIndex] = true;
}

void Loop()
{
	while (true) {
		MoveBelt();
		MoveRobot();
		SetRobot();

		if (brokenCount >= K)
			break;

		loopCount++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	belt = vector<int>(2 * N);
	hasRobot = vector<bool>(2 * N, false);

	for (int i = 0; i < 2 * N; i++) {
		cin >> belt[i];
	}
	beginIndex = 0;
	endIndex = N - 1;

	Loop();

	cout << loopCount << "\n";

	return 0;
}