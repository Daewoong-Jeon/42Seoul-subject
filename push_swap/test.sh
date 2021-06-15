export ARG=$(../push_swap_tester/random_numbers 100 0)
echo $ARG
./push_swap $ARG
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
