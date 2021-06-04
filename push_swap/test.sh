export ARG=$(../push_swap_tester/random_numbers 5 1)
echo $ARG
./push_swap $ARG
./push_swap $ARG | ./checker_Mac $ARG
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
