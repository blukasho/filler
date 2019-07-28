while true;
	do
		echo -n "blukasho ";
		cat filler.result | grep blukasho | wc -l; 
		echo -n "ybuhai ";
		cat filler.result | grep ybuhai | wc -l; 
		echo -n "all games ";
		cat filler.result | wc -l ;
		sleep 1;
		clear;
	done
