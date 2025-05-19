#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int total = 100;
void Play(int bet) {
  char cards[3] = {'J', 'K', 'Q'};
  cout << "Suffling Cards" << endl;
  srand(time(NULL));

  for (int i = 0; i < 5; i++) {
    int X = rand() % 3;
    int Y = rand() % 3;

    char temp = cards[X];
    cards[X] = cards[Y];
    cards[Y] = temp;
  }

  int guess;
  cout << "Guess Which one is Queen ?\n";
  cin >> guess;

  if (cards[guess - 1] == 'Q') {
    cout << "Congratulations You Won" << endl;
    cout << "Result:" << "{" << cards[0] << "," << cards[1] << "," << cards[2]
         << "}" << endl;

    total += 3 * bet;
    cout << "Your Total After Winning is $" << total << endl;
  } else {
    cout << "You Lose ! Better luck next time\n";
    cout << "Result:" << "{" << cards[0] << "," << cards[1] << "," << cards[2]
         << "}" << endl;
    total -= bet;
    cout << "Your Total After Winning is $" << total << endl;
  }
}

int main() {
  int bet;
  while (total > 0) {
    cout << "Welcome To Virtual Casino" << endl;
    cout << "What's Your bet ?" << endl;
    cin >> bet;
    if (bet == 0 || bet > total) {
      break;
    }
    Play(bet);
  }
  return 0;
}
