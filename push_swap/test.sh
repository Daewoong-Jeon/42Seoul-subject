export ARG=$(../push_swap_tester/random_numbers 3 1)
./push_swap $ARG
./push_swap $ARG | ../push_swap/checker_Mac $ARG
./push_swap $ARG | wc -l
