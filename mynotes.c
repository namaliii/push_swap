1. Find the target node 
the closest (smallest) bigger node, if doesn't exist - the smallest

2. Find the median
Rounding up, i.e. if stack_len = 3, 3/2 = 1.5, median = 2

3. Count the push_price (how many moves we have to do to bring the node & it's target node to the top of the stack)
above median:
b_node->current_position + target_node->current_position
below median:
stack_len - current_position
push cost is excluded

after each push refresh the target node 

