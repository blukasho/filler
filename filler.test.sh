while true;
	do
		./resources/filler_vm -p2 ./resources/players/iruban.filler -p1 ./blukasho.filler -f resources/maps/map02; 
		cat filler.trace | grep "won";
		sleep 3;
	done
#./resources/players/iruban.filler
