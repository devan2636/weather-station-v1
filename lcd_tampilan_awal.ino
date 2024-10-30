void lcd_tampilan_awal(){
  lcd.clear();
  lcd.backlight();

  //Menuliskan teks
  lcd.setCursor(0,0); // kolom x baris
  lcd.print("GATE WEATHER STATION");
  lcd.setCursor(4,1); // kolom x baris
  lcd.print("S-TRON 2022");
  lcd.setCursor(0,2);
  lcd.print("====================");
  lcd.setCursor(0,3);
  lcd.print("  BEN DES DEM IDR   ");
}
