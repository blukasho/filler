while true;
	do
		echo -n "blukasho ";
		cat filler.result | grep blukasho | wc -l; 
		echo -n "iruban ";
		cat filler.result | grep iruban | wc -l; 
		echo -n "all games ";
		cat filler.result | wc -l ;
		sleep 1;
		clear;
	done
