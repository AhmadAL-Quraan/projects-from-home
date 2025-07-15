#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char *ft_strjoin(int size, char **strs, char *sep) {
  if (size == 0) {
  }
  int sizeSep = 0;
  int i = 0, j;
  while (sep[i]) {
    sizeSep += 1;
    i += 1;
  }
  i = 0;
  j = 0;
  int total_size = 0;
  while (i != size) {
    while (strs[i][j]) {

      total_size += 1;
      j += 1;
    }
    total_size += sizeSep;
    j = 0;
    i += 1;
  }
  total_size -= sizeSep;

  char *ret;
  if (size == 0) {
    ret = (char *)malloc(1);
    *ret = '\0';
    return ret;
  }
  ret = (char *)malloc(sizeof(char) * total_size);

  if (ret == NULL) {
    return NULL;
  }
  i = 0, j = 0;
  int idx = 0;
  while (i != size) {
    while (strs[i][j]) {
      ret[idx] = strs[i][j];
      idx += 1;
      j += 1;
    }
    j = 0;
    if (i != size - 1) {
      while (j != sizeSep) {
        ret[idx] = sep[j];
        idx += 1;
        j += 1;
      }
    }
    j = 0;
    i += 1;
  }

  return ret;
}
// // main for testing
// int main() {
//   char *arr1 = "hello";
//   char *arr2 = "hi";
//   char *arr3 = "welcome";
//
//   char **str = malloc(3 * sizeof(char *));
//   str[0] = arr1;
//   str[1] = arr2;
//   str[2] = arr3;
//   char *sep = ", ";
//   printf("%s", ft_strjoin(0, str, sep));
// }
