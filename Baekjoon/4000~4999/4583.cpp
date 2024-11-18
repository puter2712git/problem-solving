#include <iostream>
#include <map>

const std::map<char, char> mirrorMap = {
    {'b', 'd'},
    {'d', 'b'},
    {'p', 'q'},
    {'q', 'p'},
    {'i', 'i'},
    {'o', 'o'},
    {'v', 'v'},
    {'w', 'w'},
    {'x', 'x'}};

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Solve()
{
    std::string word;

    while (true)
    {
        std::cin >> word;
        if (word == "#")
        {
            break;
        }

        std::string mirroredWord;
        bool isMirror = true;
        for (int i = word.length() - 1; i >= 0; i--)
        {
            if (mirrorMap.find(word[i]) == mirrorMap.end())
            {
                std::cout << "INVALID\n";
                isMirror = false;
                break;
            }

            mirroredWord += mirrorMap.at(word[i]);
        }

        if (isMirror)
        {
            std::cout << mirroredWord << "\n";
        }
    }
}

int main()
{
    Setup();
    Solve();

    return 0;
}