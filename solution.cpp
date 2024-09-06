#include <bits/stdc++.h>
using namespace std;

const int MAX_ENEMY = 11;

bool can_cross_chakravyuh(int current_enemy, int current_power, int skip_count, int heal_count, int initial_power, vector<int>& enemy_power) {
  if(current_enemy == MAX_ENEMY) return true;
  if(current_power <= enemy_power[current_enemy]) return false;

  bool skip = can_cross_chakravyuh(current_enemy + 2, current_power, skip_count - 1, heal_count, initial_power, enemy_power);
  bool heal = current_power == initial_power ? false : can_cross_chakravyuh(current_enemy, initial_power, skip_count, heal_count - 1, initial_power, enemy_power);
  if(current_enemy == 2 || current_enemy == 6) {
    enemy_power[current_enemy + 1] += enemy_power[current_enemy] / 2;
  }
  bool fight = can_cross_chakravyuh(current_enemy + 1, current_power - enemy_power[current_enemy], skip_count, heal_count, initial_power, enemy_power);
  if(current_enemy == 2 || current_enemy == 6) {
    enemy_power[current_enemy + 1] -= enemy_power[current_enemy] / 2;
  }
  return skip || heal || fight;

}

int main() {
  int test_cases;
  cin >> test_cases;

  while (test_cases--) {
    int initial_power;
    cin >> initial_power;
    int skip_count;
    cin >> skip_count;
    int heal_count;
    cin >> heal_count;

    vector<int> enemy_power(MAX_ENEMY);
    for (int i = 0; i < MAX_ENEMY; i++) 
      cin >> enemy_power[i];

  }

  return 0;
}