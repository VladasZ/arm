
#include <iostream>
#include <map>

#include "mbed.h"

using namespace std;

Serial pc(USBTX, USBRX); 

class Pin : public DigitalIn {
public:

  using DigitalIn::DigitalIn;

  void wait_for_low() { while (read()); }
  void wait_for_high() { while (!read()); }

  void wait_for_change() {
	auto current = read();
	while (read() == current);
  }
};

Pin pin3(D3);
Pin pin4(D4);
Pin pin5(D5);
Pin pin6(D6);
Pin pin7(D7);

int main() {
  pc.baud(57600);
	
  while (true) {
	  
	//	cout << "sopokok" << endl;
	cout << pin3.read() << " D3" << endl;
	cout << pin4.read() << " D4" << endl;
	cout << pin5.read() << " D5" << endl;
	cout << pin6.read() << " D6" << endl;
	cout << pin7.read() << " D7" << endl;

	wait(0.1);
  }
}
