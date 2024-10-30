// SimpleRx - the slave or the receiver
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

//Konfigurasi NRF
//#define CE_PIN  22
//#define CSN_PIN 21
#define CE_PIN  13
#define CSN_PIN 12
const byte thisSlaveAddress[5] = {'R', 'x', 'A', 'A', 'A'};
RF24 radio(CE_PIN, CSN_PIN);
char data_Received[32]; // this must match dataToSend in the TX
bool newData = false;
int recv = 0; //Counter data terima

//Konfigurasi LCD 20x4
#include <Wire.h> //library I2C
#include <LiquidCrystal_I2C.h>    //library LCD
LiquidCrystal_I2C lcd(0x27,20,4); // set address I2C dan besar karakter untuk lcd 20x4

void setup()
{
   Serial.begin(115200);
   //LCD
   lcd.init(); //Inisialisasi LCD
//   lcd.begin(); //LCD yang digunakan

   //Radio
   radio.begin();
   //radio.setDataRate( RF24_250KBPS );
   radio.openReadingPipe(0, thisSlaveAddress);
   radio.startListening();

   //Tampilan Awal 
   lcd_tampilan_awal();
   delay(5000);
}

//=============

void loop()
{
   getData();
   showData();
}

//==============

void getData()
{
   if ( radio.available() )
   {
      radio.read( &data_Received, sizeof(data_Received) );
      newData = true;
      recv +=1;
      if (recv > 9999){
        recv = 0;
      }
   }
}

void showData() //Menampilkan data yang diterima kemudian ditampilkan pada LCD
{
   if (newData == true)
   {
      //Memparsing data
      Serial.print("Data received :");
      Serial.println(data_Received);
      Serial.print("data string: ");Serial.println(data_Received);
      String subdata_Received0 = getValue(data_Received, ' ', 0);
      Serial.print("Temperature: ");Serial.println(subdata_Received0);
      String subdata_Received1 = getValue(data_Received, ' ', 1);
      Serial.print("Humidity: ");Serial.println(subdata_Received1);
      String subdata_Received2 = getValue(data_Received, ' ', 2);
      Serial.print("Tekanan Udara: ");Serial.println(subdata_Received2.toInt());
      String subdata_Received3 = getValue(data_Received, ' ', 3);
      Serial.print("Lux: ");Serial.println(subdata_Received3);
      String subdata_Received4 = getValue(data_Received, ' ', 4);
      Serial.print("Kecepatan Angin: ");Serial.println(subdata_Received4);
      String subdata_Received5 = getValue(data_Received, ' ', 5);
      Serial.print("Curah Hujan: ");Serial.println(subdata_Received5);
      String subdata_Received6 = getValue(data_Received, ' ', 6);
      Serial.print("Tegangan: ");Serial.println(subdata_Received6);

      //Menampilkan icon
      //lcd.backlight();
      lcd.clear();
      icon();
      //menampilkan data
      lcd.setCursor(2,0);
      lcd.print(subdata_Received0); //menampilkan data temperature
      lcd.setCursor(2,1);
      lcd.print(subdata_Received1); //menampilkan data humidity
      lcd.setCursor(7,0);
      lcd.print(subdata_Received4); //menampilkan data kecepatan angin
      lcd.setCursor(7,1);
      lcd.print(subdata_Received5); //menampilkan data curah hujan
      lcd.setCursor(1,2);
      lcd.print(subdata_Received2.toInt()); //menampilkan data tekanan udara 
      lcd.setCursor(1,3);
      lcd.print(subdata_Received3); //menampilkan data luminositas
      lcd.setCursor(14,0);
      lcd.print("Teg. "); 
      lcd.setCursor(14,1);
      lcd.print(subdata_Received6); //menampilkan data tegangan

      //Menampilkan counter
      lcd.setCursor(16,2);
      lcd.print(recv); //menampilkan jumlah data yang diterima
      lcd.setCursor(16,3);
      lcd.print("1"); //menampilkan jumlah data yang ditekirim
      newData = false;
   }
}

//Source : https://lms.onnocenter.or.id/wiki/index.php/Arduino:_Parsing_Text
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;
 
  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  } 
 
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
