echo -n > filler.result;

while true;
	do
		./resources/filler_vm -p1 ./resources/players/iruban.filler -p2 ./blukasho.filler -f resources/maps/map02 > filler.out; 
		cat filler.trace | grep "won";
		cat filler.trace | grep "won" >> filler.result;
#		sleep 3;
	done
#./resources/players/iruban.filler
