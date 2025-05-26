# PERANCANGAN SISTEM ABSENSI SISWA OTOMATIS MENGGUNAKAN RFID DENGAN FITUR NOTIFIKASI WHATSAPP UNTUK ORANG TUA
<br>

## 💡 RINGKASAN SISTEM <br>
> Alat yang digunakan: <br>
> - NodeMCU ESP8266  C <br>
> - RFID Reader RC522 <br>
> - Kartu RFID (tag) <br>
> - buzzer <br>
> - LCD 16x2 <br>
> - Server & Database (PHP + MySQL) <br>
> - Web App (untuk guru, admin, wali kelas, siswa) <br>
> - WhatsApp API (untuk notifikasi ke orang tua)

<br>

## 🛠️ PERSIAPAN HARDWARE
> Komponen: <br>
> - NodeMCU ESP8266 <br>
> - RFID Reader RC522 <br>
> - Kabel jumper <br>
> - Breadboard <br>
> - LCD 16x2 + I2C

<br>

| Komponen            | Jumlah | Catatan                                                 |
| ------------------- | ------ | ------------------------------------------------------- |
| ✅ NodeMCU ESP8266   | 1      | Bisa beli merk Amica atau LoLin                         |
| ✅ RFID RC522 Reader | 1      | Biasanya sudah include 1 kartu & 1 gantungan            |
| ✅ LCD 16x2 + I2C    | 1      | Agar hemat pin dan mudah coding                         |
| ✅ Breadboard / PCB  | 1      | Untuk prototipe (breadboard) atau permanen (PCB lubang) |
| ✅ Kabel jumper      | 1 set  | Male-to-male                                            |
| ✅ Power supply USB  | 1      | Bisa pakai charger HP biasa                             |
| (Opsional) Buzzer   | 1      | Jika ingin bunyi saat tap kartu                         |

<br>

## Web Interface (PHP + Bootstrap)
> Fitur
> - Login Admin/Guru <br>
> - Lihat Riwayat Absen <br>
> - Tambah/Edit Data Siswa <br>
> - Kirim ulang notifikasi

<br>

##  WHATSAPP GATEWAY
> - whacenter.com <br>
> - Watzap.id <br>
> - UltraMsg
