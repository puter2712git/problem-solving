#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct File
{
	string fileName;
	string extension;
	bool isOS;

	bool operator<(const File &f)
	{
		if (fileName != f.fileName) {
			return fileName < f.fileName;
		}

		if (isOS && f.isOS) {
			return extension < f.extension;
		}

		if (!isOS && !f.isOS) {
			return extension < f.extension;
		}

		return isOS;
	}
};

int N, M;
vector<File> files;
set<string> extensionSet;

File Parse(string file)
{
	File ret;

	size_t pos = file.find(".");
	ret.fileName = file.substr(0, pos);
	ret.extension = file.substr(pos + 1, file.length());

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	while (N--) {
		string file;
		cin >> file;
		files.push_back(Parse(file));
	}
	while (M--) {
		string extension;
		cin >> extension;
		extensionSet.insert(extension);
	}

	for (auto &file : files) {
		file.isOS = (extensionSet.find(file.extension) != extensionSet.end());
	}

	sort(files.begin(), files.end());

	for (const auto &file : files) {
		cout << file.fileName << "." << file.extension << "\n";
	}

	return 0;
}