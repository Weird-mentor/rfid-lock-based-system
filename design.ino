#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include<LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
String UID = "41 22 79 1B";
String UID_1= "D1 F5 4C 1C";
String UID_2="01 FD E0 1D";
String UID_3="43 8C 9D 2F";

byte lock = 0;
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);
byte a[8] = {
  B00001,
  B00011,
  B00111,
  B01110,
  B11110,
  B11111,
  B11111,
  B11111
};

byte b[8] = {
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B11111,
  B11111,
  B11111
};

byte c[8] = {
  B10000,
  B11000,
  B11100,
  B01110,
  B01111,
  B11111,
  B11111,
  B11111
};

byte d[8] = {
  B11011,
  B11000,
  B11100,
  B11110,
  B01111,
  B00111,
  B00011,
  B00001
};

byte e[8] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};

byte f[8] = {
  B11011,
  B00011,
  B00111,
  B01111,
  B11110,
  B11100,
  B11000,
  B10000
};
byte g[8]={
  B00011,
  B00111,
  B00111,
  B01110,
  B11110,
  B11111,
  B11111,
  B11111
};

byte h[8]={
  B11111,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B11111,
  B11111
};

byte i[8]={
  B10000,
  B11000,
  B11100,
  B01110,
  B01111,
  B11111,
  B11111,
  B11111
};

byte j[8]={
  B11111,
  B11111,
  B11111,
  B11110,
  B01111,
  B00111,
  B00011,
  B00000
};

byte k[8]={
  B11111,
  B11111,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000
};

byte l[8]={
  B11111,
  B11111,
  B11111,
  B01111,
  B11110,
  B11100,
  B11000,
  B00000
};
void setup() {
lcd.init();

lcd.backlight();
lcd.begin(16, 2);
  lcd.createChar(11, a);
  lcd.createChar(12, b);
  lcd.createChar(13, c);
  lcd.createChar(14, d);
  lcd.createChar(15, e);
  lcd.createChar(16, f);
lcd.begin(16,2);
  lcd.createChar(0,g);
  lcd.createChar(1,h);
  lcd.createChar(2,i);
  lcd.createChar(3,j);
  lcd.createChar(4,k);
  lcd.createChar(5,l);
  lcd.clear();
Serial.begin(9600); 

lcd.setCursor(2,0);
lcd.print("## DE$IGN ##");
lcd.setCursor(3,1);
lcd.print(" THINKING");
delay(4000);
lcd.clear();
lcd.setCursor(5,0);
lcd.print(" ECE ");
lcd.setCursor(4,1);
lcd.print("STUDENTS");
delay(4000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" VISHVA");
lcd.setCursor(0,1);
lcd.print("RANJITH");
lcd.setCursor(10,0);
lcd.print("RAMJI");
lcd.setCursor(10,1);
lcd.print("VISHAL");
delay(4000);
Serial.println("Ready");
lcd.begin(20,4);  
lcd.clear(); 
  Serial.begin(9600);
  servo.write(180);
  servo.attach(3);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  lcd.setCursor(1, 1);
  lcd.print("Put your card");

  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanning");
  Serial.print("NUID");
  String ID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    lcd.print("*");
    ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    ID.concat(String(rfid.uid.uidByte[i], HEX));
    delay(300);
  }
  
  ID.toUpperCase();

    if (ID.substring(1) == UID && lock == 0 ) 
    {
    servo.write(180);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is locked");
    delay(1500);
    lcd.clear();
    lock = 1;
    } 
    else if (ID.substring(1) == UID && lock == 1 ) 
    {
    lcd.clear();
    servo.write(70);
    lcd.setCursor(6, 0);
    lcd.write(byte(11));
    lcd.setCursor(7, 0);
    lcd.write(byte(12));
    lcd.setCursor(8, 0);
    lcd.write(byte(13));
    lcd.setCursor(6, 1);
    lcd.write(byte(14));
    lcd.setCursor(7, 1);
    lcd.write(byte(15));
    lcd.setCursor(8, 1);
    lcd.write(byte(16));
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome Teacher1");
    lcd.setCursor(0,1);
    lcd.print("Door is open");
    delay(1500);
    lcd.clear();
    lock = 0;
    }
    else if (ID.substring(1) == UID_1 && lock == 0 ) 
    {
    servo.write(180);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is locked");
    delay(1500);
    lcd.clear();
    lock = 1;
    } 
    else if (ID.substring(1) == UID_1 && lock == 1 ) 
    {
    servo.write(70);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome Teacher2");
    lcd.setCursor(0,1);
    lcd.print("Door is open");
    delay(1500);
    lcd.clear();
    lock = 0;
    }
    else if (ID.substring(1) == UID_2 && lock == 0 ) 
    {
    servo.write(180);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is locked");
    delay(1500);
    lcd.clear();
    lock = 1;
    } 
    else if (ID.substring(1) == UID_2 && lock == 1 ) 
    {
    servo.write(70);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome Teacher3");
    lcd.setCursor(0,1);
    lcd.print("Door is open");
    delay(1500);
    lcd.clear();
    lock = 0;
    }
    
    else {
  lcd.clear();  
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.setCursor(7,0);
  lcd.write(byte(1));
  lcd.setCursor(8,0);
  lcd.write(byte(2));
  lcd.setCursor(6,1);
  lcd.write(byte(3));
  lcd.setCursor(7,1);
  lcd.write(byte(4));
  lcd.setCursor(8,1);
  lcd.write(byte(5));
  delay(2000);
  lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Invalid Card");
    lcd.setCursor(0,1);
    lcd.print("Get! out");
    delay(1500);
    lcd.clear();
  }
}
