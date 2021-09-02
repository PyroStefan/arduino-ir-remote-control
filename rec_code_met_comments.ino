#include <IRLibRecvPCI.h> 

IRrecvPCI myReceiver(2);//pin number for the receiver

void setup() {
  Serial.begin(9600);
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
  myReceiver.setFrameTimeout(100000); //Sets the maximum 
  //milliseconds of 100000 to wait for a frame(series of bytes) of Receiver data 
}

void loop() {
  //Continue looping until you get a complete signal received
  if (myReceiver.getResults()) { 
    Serial.print(F("\n#define RAW_DATA_LEN ")); // #define gives a name to a constant value
    Serial.println(recvGlobal.recvLength,DEC); // gives the length of de data
    Serial.print(F("uint16_t rawData[RAW_DATA_LEN]={\n\t")); 
    for(bufIndex_t i=1;i<recvGlobal.recvLength;i++) {// outputs the raw data code
      Serial.print(recvGlobal.recvBuffer[i],DEC);
      Serial.print(F(", "));
      if( (i % 8)==0) Serial.print(F("\n\t")); //begin  on another line after completing 8 integers
    }
    Serial.println(F("1000};"));//Add arbitrary trailing space
    myReceiver.enableIRIn();      //Restart receiver
  }
}
