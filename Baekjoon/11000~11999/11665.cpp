#include <iostream>

using namespace std;

int N;
int x1, y1, z1;
int x2, y2, z2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	int maxX1 = 0, maxY1 = 0, maxZ1 = 0;
	int minX2 = 12345, minY2 = 12345, minZ2 = 12345;

	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		maxX1 = max(maxX1, x1);
		maxY1 = max(maxY1, y1);
		maxZ1 = max(maxZ1, z1);
		minX2 = min(minX2, x2);
		minY2 = min(minY2, y2);
		minZ2 = min(minZ2, z2);
	}

	int x = minX2 - maxX1;
	int y = minY2 - maxY1;
	int z = minZ2 - maxZ1;
	x = x < 0 ? 0 : x;
	y = y < 0 ? 0 : y;
	z = z < 0 ? 0 : z;

	cout << x * y * z;

	return 0;
}