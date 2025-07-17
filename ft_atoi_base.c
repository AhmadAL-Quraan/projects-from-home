#include <stdio.h>
#include <unistd.h>
int check_valid_base(char *base, int size) {
  /*
   * Check repeat
   * Check if size == 1
   * Check +, -, spaces
   */
  if (size == 1) {
    return 0;
  }
  int i, j;
  i = 0, j = 0;
  while (base[i]) {
    j = i + 1;
    if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13) ||
        base[i] == ' ') {
      return 0;
    }
    while (base[j]) {
      if (base[i] == base[j]) {
        return 0;
      }
      j += 1;
    }
    i += 1;
  }
  return 1;
}
int find_idx(char *base, char c) {
  int i = 0;
  while (base[i]) {
    if (base[i] == c) {
      return i;
    }
    i += 1;
  }
  return -1;
}
int convert_it(char *str, int neg, char *base, int base_size, int idx) {
  int i = 0;
  while (str[i]) {
    i += 1;
  }
  i -= 1;
  int decimal = 0;
  int power = 0;
  int power_result;
  int follow_power = 0;
  while (i != idx - 1) {
    follow_power = 0;
    power_result = 1;
    while (follow_power != power) {
      power_result *= base_size;
      follow_power += 1;
    }
    if (find_idx(base, str[i]) == -1) {
      break;
    }
    decimal += power_result * find_idx(base, str[i]);
    power += 1;
    i -= 1;
    printf("%d\n", decimal);
  }
  return (neg * decimal);
}
int ft_atoi_base(char *str, char *base) {
  int base_size = 0;
  int i = 0;
  while (base[i]) {
    base_size += 1;
    i += 1;
  }
  i = 0;
  int neg = 1;
  if (check_valid_base(base, base_size)) {
    while (str[i]) {
      if (str[i] == '-') {
        neg *= -1;
        i += 1;
      } else if (str[i] == '+' || str[i] == ' ' ||
                 (str[i] >= 9 && str[i] <= 13)) {
        i += 1;
      } else {
        break;
      }
    }
  }
  printf("%d", i);
  return convert_it(str, neg, base, base_size, i);
}
// main for testing
int main() { printf("%d", ft_atoi_base("+----1A ", "0123456789ABCDEF")); }
