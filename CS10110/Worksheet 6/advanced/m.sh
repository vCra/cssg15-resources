grep ".*:B.*:.*:.*:.*" carslist.txt > alpha-carslist.txt
grep ".*:C.*:.*:.*:.*" carslist.txt >> alpha-carslist.txt
wc -l alpha-carslist.txt
