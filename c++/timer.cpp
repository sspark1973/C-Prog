/*
http://www.cplusplus.com/forum/beginner/317/
*/


#include <iostream>
#include <time.h>
using namespace std;

class timer {
private:
	unsigned long beg;
	unsigned long end;
	bool resetted;
	bool running;

public:
	void start();
	void stop();
	void reset();
	bool isRunning();
	unsigned long getTime();
	bool isOver(unsigned long seconds);
};

timer::timer()
{
	resetted = true;
	running = false;
	beg = 0;
	end = 0;
}

void timer::start()
{
	if(!running) {
		if(resetted)
			beg = (unsigned long)clock();
		else
			beg -= end - (unsigned long)clock();

		running = true;
		resetted = false;
	}
}

void timer::stop()
{
	if(running) {
		end = (unsigned long)clock();
		running = false;
	}
}

void timer::reset() 
{
	

int main()
{
	unsigned long seconds = 10;
	timer t;
	t.start();
	cout << "timer started..." << endl;

	while(true) {
		if(t.elapsedTime() >= seconds) {
			break;
		} else {
			//do other things
		}
	}

	cout << seconds << " seconds elapsed" << endl;

	cin >> seconds; //it's just to stop the execution and look at the output

	return 0;
}
