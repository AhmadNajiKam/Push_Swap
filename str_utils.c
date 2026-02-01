#include "libft.h"
int ft_isnum(char *str) {
  int i;

  i = 0;
  while (str[i]) {
    if (!ft_isdigit(str[i]))
      return -1;
    i++;
  }
  return i;
}
