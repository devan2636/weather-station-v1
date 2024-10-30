//Menampilkan ICON
//referensi : https://arduinogetstarted.com/faq/how-to-use-special-character-on-lcd#:~:text=LCD%2016x2%20can%20display%2032,2%20rows%20and%2016%20columns).

//Icon Termometer
byte icon_termometer[8] = {
  0b00100,
  0b01010,
  0b01010,
  0b01110,
  0b01110,
  0b11111,
  0b11111,
  0b01110
};

//Icon Humidity
byte icon_humidity[8] = {
  0b00100,
  0b00100,
  0b01010,
  0b01010,
  0b11011,
  0b10001,
  0b10001,
  0b01110
};

//Icon Presure
byte icon_presure[8] = {
  0b00100,
  0b01010,
  0b10001,
  0b10001,
  0b10001,
  0b01010,
  0b00100,
  0b11111
};

//Icon Luminositas
byte icon_lux[8] = {
  0b00100,
  0b10101,
  0b01110,
  0b11011,
  0b11011,
  0b01110,
  0b10101,
  0b00100
};

//Icon Kecepatan Angin
byte icon_accelerometer[8] = {
  0b00110,
  0b10100,
  0b10100,
  0b11111,
  0b00101,
  0b00101,
  0b01100,
  0b11111
};

//Icon Curah Hujan
byte icon_rain[8] = {
  0b00100,
  0b01110,
  0b10001,
  0b10001,
  0b11111,
  0b00000,
  0b10101,
  0b01010
};

//Icon Tegangan
byte icon_tegangan[8] = {
  0b01110,
  0b01110,
  0b01110,
  0b01110,
  0b00000,
  0b01010,
  0b01010,
  0b00100
};


void icon(){
  lcd.createChar(0, icon_termometer);
  lcd.createChar(1, icon_humidity);
  lcd.createChar(2, icon_presure);
  lcd.createChar(3, icon_lux);
  lcd.createChar(4, icon_accelerometer);
  lcd.createChar(5, icon_rain);
  lcd.createChar(6, icon_tegangan);

  //Menampilkan Icon
  lcd.setCursor(0,0); //Mengatur letak icon
  lcd.write((byte)0); //menampilkan icon termometer
  lcd.setCursor(0,1); //Mengatur letak icon
  lcd.write((byte)1); //menampilkan icon humidity
  lcd.setCursor(6,0); //Mengatur letak icon
  lcd.write((byte)4); //menampilkan icon accelerometer
  lcd.setCursor(6,1); //Mengatur letak icon
  lcd.write((byte)5); //menampilkan icon rain
  lcd.setCursor(0,3); //Mengatur letak icon
  lcd.write((byte)3); //menampilkan icon luminositas
  lcd.setCursor(0,2); //Mengatur letak icon
  lcd.write((byte)6); //menampilkan icon tegangan
  lcd.setCursor(0,2); //Mengatur letak icon
  lcd.write((byte)2); //menampilkan icon presure
  lcd.setCursor(14,2);
  lcd.print("<=");
  lcd.setCursor(14,3);
  lcd.print("=>");
}

//Satuan pengukuran
void satuan(){
  
}
