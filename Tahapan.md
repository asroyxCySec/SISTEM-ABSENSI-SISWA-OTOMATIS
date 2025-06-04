# Tahapan Pembuatan Project

## 1. Membeli Komponen Hardware
> Berikut daftar belanja minimal untuk 1 unit alat absensi RFID:

<br>

| Komponen            | Jumlah | Catatan                                                 |
| ------------------- | ------ | ------------------------------------------------------- |
| ✅ NodeMCU ESP8266   | 1      | merk Amica atau LoLin                         |
| ✅ RFID RC522 Reader | 1      | Sudah include 1 kartu & 1 gantungan            |
| ✅ LCD 16x2 + I2C    | 1      | Agar hemat pin dan mudah coding                         |
| ✅ Breadboard / PCB  | 1      | Untuk prototipe (breadboard) atau permanen (PCB lubang) |
| ✅ Kabel jumper      | 1 set  | Male-to-male                                            |
| ✅ Power supply USB  | 1      | Bisa pakai charger HP biasa                             |
| ✅ Buzzer Atif  | 1      | Jika ingin bunyi saat tap kartu                         |

<br>

## 2. Merakit Komponen Hardware
> Berikut adalah gambar perakitan komponen
<br>

![Perakitan Komponen](https://github.com/asroyxCySec/SISTEM-ABSENSI-SISWA-OTOMATIS/raw/main/rakit%20komponen.png)

<br>

### LCDx2 <br>
| LCD            | NodeMCU 8266                                                 |
| ------------------- | ------------------------------------------------------------- |
| GND   | GND                         |
| VCC | 3V            |
| SDA    | D2                         |
| SCL  | D1 |

<br>

### RFID-RC522 <br>
| RFID-RC522          | NodeMCU 8266                                                |
| ------------------- | --------------------------------------------------------- |
| SDA   | D8                         |
| SCK | D5            |
| MOSI    | D7                         |
| MISO  | D6  |
| GND      | GND                                            |
| RST  | D4                             |
| 3.3V  | 3V                         |

<br>

### Buzzer Aktif <br>
| Buzzer          | NodeMCU 8266                                                |
| ------------------- | --------------------------------------------------------- |
| GND   | GND                         |
| VCC | D3            |
