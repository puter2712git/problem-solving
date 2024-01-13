#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/// @brief Solve the problem of pokemon.
/// @param _pokemons pokemon map
/// @param _names vector of pokemons' name
void solve_question(map<string, int> &_pokemons, vector<string> &_names)
{
  int key;
  string question;
  cin >> question;

  if (key = atoi(question.c_str())) {
    cout << _names[key - 1] << '\n';
  } else {
    cout << _pokemons[question] << '\n';
  }
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<string, int> pokemons;
  vector<string> names;

  int nr_pokemon, nr_question;

  cin >> nr_pokemon >> nr_question;
  for (int i = 1; i <= nr_pokemon; i++) {
    string pokemon;
    cin >> pokemon;

    pokemons.insert(make_pair(pokemon, i));
    names.push_back(pokemon);
  }

  for (int i = 0; i < nr_question; i++) {
    solve_question(pokemons, names);
  }

  return 0;
}