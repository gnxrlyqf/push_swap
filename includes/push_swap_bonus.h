#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <push_swap.h>

typedef struct __attribute__((packed)) s_line
{
	char			c;
	struct s_line	*next;
}				t_line;

int		contains_nl(char *str);
void	populate_list(t_line **head, char *str);
char	*get_next_line(int fd);
t_line	*gnl_add_node(t_line **head, char c);
void	free_list(t_line **head);
char	*make_str(t_line **head, int size);
int		listchr_len(t_line *head);
void	op_checker(t_stacks *s, t_op op);

#endif
