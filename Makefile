
relay: relay.cpp
	g++ -o relay relay.cpp RpiBase.cpp -lwiringPi

run: relay
	./relay

clean:
	echo Deleting ./relay 
	rm -f ./relay
