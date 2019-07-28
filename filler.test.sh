echo -n > filler.result;

while true;
	do
		./resources/filler_vm -p1 ./blukasho.filler -p2 ./resources/players/ybuhai.filler -f resources/maps/map02; 
		cat filler.trace | grep "won";
		cat filler.trace | grep "won" >> filler.result;
		sleep 10;
	done
#./resources/players/iruban.filler
