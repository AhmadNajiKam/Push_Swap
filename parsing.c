#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static int check_mode(char *argv1) {
  int mode;

  if (ft_strncmp(argv1, "--simple", 8))
    mode = 1;
  else if (ft_strncmp(argv1, "--medium", 8))
    mode = 2;
  else if (ft_strncmp(argv1, "--complex", 9))
    mode = 3;
  else if (ft_strncmp(argv1, "--adaptive", 10) || ft_isnum(argv1))
    mode = 4;
  else if (ft_strncmp(argv1, "--bench", 7))
    mode = 5;
  else if (!ft_isnum(argv1))
    mode = -1;
  return mode;
}

int parse_command_line(int argc, char **argv, t_list **stackA) {
  int mode;
  t_list *node;
  int i;

  mode = check_mode(argv[1]);
  i = 1;
  while (i < argc) {
    node->content = malloc(sizeof(int));
    if (!(node->content))
      return -1;
    if (ft_isnum(argv[i]))

      ft_lstadd_back(stackA, node);
    i++;
  }
}
