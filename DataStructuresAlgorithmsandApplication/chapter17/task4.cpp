#include <iostream>

void change(int dollars, int cents)
{
  int num_dollars_100, num_dollars_20, num_dollars_10, num_dollars_5, num_dollars_1;
  int num_cents_25, num_cents_10, num_cents_5, num_cents_1;
  num_dollars_100 = dollars / 100;
  dollars = dollars % 100;
  num_dollars_20 = dollars / 20;
  dollars = dollars % 20;
  num_dollars_10 = dollars / 10;
  dollars = dollars % 10;
  num_dollars_5 = dollars / 5;
  dollars = dollars % 5;
  num_dollars_1 = dollars;

  num_cents_25 = cents / 25;
  cents = cents % 25;
  num_cents_10 = cents / 10;
  cents = cents % 10;
  num_cents_5 = cents / 5;
  cents = cents % 5;
  num_cents_1 = cents;
  std::cout << "the dollars is "
            << num_dollars_100 << " "
            << num_dollars_20 << " "
            << num_dollars_10 << " "
            << num_dollars_5 << " "
            << num_dollars_1 << '\n';
  std::cout << "the cents is "
            << num_cents_25 << " "
            << num_cents_10 << " "
            << num_cents_5 << " "
            << num_cents_1 << '\n';
}

int main()
{
  int dollars = 67;
  int cents = 67;
  change(dollars, cents);
  return 0;
}