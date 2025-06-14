#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// --- Konfigurasi PIN ---
#define SS_PIN D8          // SDA RFID
#define RST_PIN D4         // RST RFID
#define BUZZER_PIN D3      // Buzzer pin

LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 mfrc522(SS_PIN, RST_PIN);

// --- WiFi ---
const char* ssid = "MADANIPRIA_C2";
const char* password = "MADANIC72";
const char* serverUrl = "http://192.168.0.123/rfid_absensi_system/absen.php";

void setup() {
  Serial.begin(9600);
  Wire.begin(D2, D1);
  lcd.begin(16, 2);
  lcd.backlight();

  // PERBAIKAN 1: Inisialisasi buzzer dengan benar
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);  // Pastikan buzzer OFF di awal
  delay(100); // Beri waktu untuk stabilisasi

  SPI.begin();
  mfrc522.PCD_Init();

  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");
  WiFi.begin(ssid, password);
  int retry = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    lcd.print(".");
    Serial.print(".");
    retry++;
    if (retry > 20) {
      lcd.clear(); 
      lcd.print("WiFi Failed");
      return;
    }
  }

  lcd.clear();
  lcd.print("WiFi Connected!");
  Serial.println("WiFi Connected!");
  delay(1000);
  lcd.clear();
  lcd.print("Tap Kartu RFID");
  lcd.setCursor(0, 1);
  lcd.print("untuk Absen");
}

void loop() {
  // PERBAIKAN 2: Pastikan buzzer selalu OFF di loop utama
  digitalWrite(BUZZER_PIN, LOW);

  // PERBAIKAN 3: Cek kartu dengan lebih stabil
  if (!mfrc522.PICC_IsNewCardPresent()) {
    delay(50); // Tambah delay kecil untuk stabilitas
    return;
  }
  
  if (!mfrc522.PICC_ReadCardSerial()) {
    delay(50);
    return;
  }

  // Kartu terdeteksi - aktifkan buzzer
  Serial.println("Kartu terdeteksi!");
  
  // PERBAIKAN 4: Buzzer bunyi saat kartu terdeteksi
  digitalWrite(BUZZER_PIN, HIGH);  // Buzzer ON
  delay(200);                      // Durasi bunyi
  digitalWrite(BUZZER_PIN, LOW);   // Buzzer OFF

  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uid += String(mfrc522.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();
  Serial.println("UID: " + uid);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("UID:");
  lcd.setCursor(0, 1);
  lcd.print(uid);

  // Kirim ke server
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    http.begin(client, serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String postData = "uid=" + uid;

    int code = http.POST(postData);
    String response = http.getString();
    http.end();

    Serial.println("Server Response: " + response);

    lcd.clear();
    lcd.setCursor(0, 0);
    if (code == 200) {
      lcd.print("Absen Sukses!");
      // PERBAIKAN 5: Bunyi sukses berbeda
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
      delay(100);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
    } else {
      lcd.print("Absen Gagal");
      // PERBAIKAN 6: Bunyi error panjang
      digitalWrite(BUZZER_PIN, HIGH);
      delay(500);
      digitalWrite(BUZZER_PIN, LOW);
    }
    lcd.setCursor(0, 1);
    lcd.print(response);
  } else {
    lcd.clear();
    lcd.print("WiFi Disconnected");
  }

  // PERBAIKAN 7: Pastikan buzzer OFF sebelum delay
  digitalWrite(BUZZER_PIN, LOW);
  
  delay(3000); // Anti double tap
  
  // Reset tampilan
  lcd.clear();
  lcd.print("Tap Kartu RFID");
  lcd.setCursor(0, 1);
  lcd.print("untuk Absen");
  
  // Halt kartu untuk mencegah pembacaan berulang
  mfrc522.PICC_HaltA();
}
