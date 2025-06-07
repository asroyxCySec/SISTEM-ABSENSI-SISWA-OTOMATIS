#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN D8   // Sesuai wiring kamu
#define RST_PIN D4  // Sesuai wiring kamu

MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {
  Serial.begin(9600);   // Lihat hasil di Serial Monitor
  SPI.begin();          // Mulai komunikasi SPI
  mfrc522.PCD_Init();   // Inisialisasi RC522
  Serial.println("Scan kartu RFID...");
}

void loop() {
  // Cek apakah ada kartu
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Cek apakah kartu bisa dibaca
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Tampilkan UID kartu ke Serial Monitor
  Serial.print("UID kartu: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  delay(2000); // Delay biar tidak baca terus-menerus
}
