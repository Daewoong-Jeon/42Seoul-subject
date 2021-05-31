export ARG=$(../push_swap_tester/random_numbers 100 1)
echo $ARG
./push_swap $ARG
./push_swap $ARG | ./checker_Mac $ARG
./push_swap $ARG | wc -l
