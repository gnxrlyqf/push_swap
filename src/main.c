#include <push_swap.h>

int main(int ac, char **av)
{
	t_stacks stacks;

	if (ac < 3)
		return (1);
	stacks = init_stack(ac, av);
	// print_stack(stacks.a);
	// printf("cost: %d\n", find_best(&stacks, &pos_a, &pos_b));
	// printf("positions: %d - %d\n", pos_a, pos_b);
	sort(&stacks);
}
