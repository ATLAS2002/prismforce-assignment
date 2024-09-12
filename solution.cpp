#include <bits/stdc++.h>
using namespace std;

const int MAX_ENEMY = 11;

class Solution {
private:
  int max_power = 0;
  int skip_count = 0;
  int heal_count = 0;
  int enemy_power[MAX_ENEMY];
  vector<vector<vector<vector<bool>>>> dp;
  int solve(int current_enemy, int current_power, int current_skips, int current_heals) {
    if (current_enemy >= MAX_ENEMY) {
      return true;
    }

    if(dp[current_enemy][current_power][current_skips][current_heals])
      return false;

    // Abhimanyu can skip the current enemy
    if (current_skips > 0) {
      bool res = solve(current_enemy + 1, current_power, current_skips - 1, current_heals);
      if(res)
        return true;
    }

    // Abhimanyu can heal himself
    if (current_heals > 0 && current_power < this->max_power) {
      bool res = solve(current_enemy, this->max_power, current_skips, current_heals - 1);
      if(res)
        return true;
    }

    // Abhimanyu can fight the current enemy
    if (current_power >= enemy_power[current_enemy]) {
      bool res = solve(current_enemy + 1, current_power - enemy_power[current_enemy], current_skips, current_heals);
      if(res)
        return true;
    }

    dp[current_enemy][current_power][current_skips][current_heals] = true;
    return false;
  }
public:
  Solution() {
    cin >> this->max_power;
    cin >> this->skip_count;
    cin >> this->heal_count;
    // Abhimanyu does not need to heal more times than the number of enemies
    this->heal_count = min(this->heal_count, MAX_ENEMY);

    for (int i = 0; i < MAX_ENEMY; i++) {
      cin >> this->enemy_power[i];
    }

    dp.resize(
      MAX_ENEMY, 
      vector<vector<vector<bool>>>(
        this->max_power + 1,
        vector<vector<bool>>(
          this->skip_count + 1,
          vector<bool>(
            this->heal_count + 1,
            false
          )
        )
      )
    );
  }
  bool canCross() {
    // abhimanyu can skip all the enemies
    if(skip_count >= MAX_ENEMY)
      return true;

    return solve(0, this->max_power, this->skip_count, this->heal_count);
  }
};

auto initialise = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  cout.tie(NULL);
  return 0;
}();

int main() {
  int test_cases;
  cin >> test_cases;

  while (test_cases--) {
    Solution test;

    if (test.canCross()) {
      cout << "Abhimanyu can cross the Chakravyuha" << endl;
    } else {
      cout << "Abhimanyu can not cross the Chakravyuha" << endl;
    }
  }

  return 0;
}