#include <mbed.h>

#include <stdbool.h>

int main() {
    bool flashing = false;
    DigitalOut red(PTB22);
    DigitalIn  btn(PTC6);

    while(1) {
      //if there is a button input then the LED stops flashing
        if( btn.read() ) flashing = true;
            else         flashing = false;
        //if button 0 is pressed (PTC6), that information is output to the
        //terminal
        printf("button %d\n", btn.read() );
        if(flashing){
          //when flashing is true the LED goes on and off
            red.write(0);
            wait(0.5);
            red.write(1);
            wait(0.5);
        }else{
          //if flashing is false the LED stays off while the button is pressed
            red.write(1);
            wait(1);
        }
    }
}
