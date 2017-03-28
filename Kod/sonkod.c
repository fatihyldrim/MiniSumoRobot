#include <16F877.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //High speed Osc (> 4mhz)
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NOBROWNOUT                 //Reset when brownout detected
#FUSES NOLVP                      //Low Voltage Programming on B3(PIC16) or B5(PIC18)
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOCPD


#use delay(clock=20000000)

 void dur(){
   output_low(pin_c0);
   output_low(pin_c3);
   output_low(pin_c5);
   output_low(pin_d2);
   output_low(pin_c2);
   output_low(pin_d1);
   output_low(pin_c7);
   output_low(pin_c4);
 }
 void ileri(){
    dur();
    output_high(pin_c0);
    output_high(pin_c3);
    output_high(pin_c5);
    output_high(pin_d2);
 }
  void geri(){
   dur();
   output_high(pin_c4);
   output_high(pin_c2);
   output_high(pin_c7);
   output_high(pin_d1);
  }
    void sag(){
    dur();
   output_high(pin_c4);
   output_high(pin_c7);
   output_high(pin_c0);
   output_high(pin_c3);
    }
    void sol(){
    dur();
   output_high(pin_c2);
   output_high(pin_d1);
   output_high(pin_c5);
   output_high(pin_d2);
    }
int8 on,sa,so,x;

void main()
{

output_high(pin_d3);
output_high(pin_c6);
output_high(pin_d0);
output_high(pin_c1);

output_high(pin_e0);


setup_adc_ports(AN0_AN1_AN2_AN3_AN4);
setup_adc(ADC_CLOCK_DIV_32);

set_tris_b(0x01);

delay_ms(2000);

/*
if(input(pin_d6)==1) {}        // 1 numaralý anahtar açýk ise
else if(input(pin_d5)==1) {}   // 2 numaralý anahtar açýk ise
else if(input(pin_d4)==1) {}   // 3 numaralý anahtar açýk ise
*/

//anahtar 1 saga dönerek baþla

if(input(pin_d6)==1){
x=1;
while(TRUE){

if(input(pin_b0)==0){ ileri(); delay_ms(700); x=3;}
else if(input(pin_b1)==0){ geri(); delay_ms(700); x=0; }
else {

set_adc_channel(0);
delay_us(10);
on=read_adc();

set_adc_channel(1);
delay_us(10);
sa=read_adc();

set_adc_channel(2);
delay_us(10);
so=read_adc();

if(on>45){x=0; ileri();}
else if(sa>45){x=1; sag();}
else if(so>45){x=2; sol();}
else {
   if(x==0)ileri();
   else if(x==1)sag();
   else if(x==2) sol();
   else geri();
    }
}
}
}

//anahtar 2 sola dönerek baþla
else if(input(pin_d5)==1){
x=2;
while(TRUE){

if(input(pin_b0)==0){ ileri(); delay_ms(700); x=3;}
else if(input(pin_b1)==0){ geri(); delay_ms(700); x=0; }
else {

set_adc_channel(0);
delay_us(10);
on=read_adc();

set_adc_channel(1);
delay_us(10);
sa=read_adc();

set_adc_channel(2);
delay_us(10);
so=read_adc();

if(on>45){x=0; ileri();}
else if(sa>45){x=1; sag();}
else if(so>45){x=2; sol();}
else {
   if(x==0)ileri();
   else if(x==1)sag();
   else if(x==2) sol();
   else geri();
    }
}
}
}

//anahtar 3 geri giderek baþla
else if(input(pin_d4)==1){
x=3;
while(TRUE){

if(input(pin_b0)==0){ ileri(); delay_ms(700); x=3;}
else if(input(pin_b1)==0){ geri(); delay_ms(700); x=0;}
else {

set_adc_channel(0);
delay_us(10);
on=read_adc();

set_adc_channel(1);
delay_us(10);
sa=read_adc();

set_adc_channel(2);
delay_us(10);
so=read_adc();

if(on>45){x=0; ileri();}
else if(sa>45){x=1; sag();}
else if(so>45){x=2; sol();}
else {
   if(x==0)ileri();
   else if(x==1)sag();
   else if(x==2) sol();
   else geri();
    }
}
}
}



}

