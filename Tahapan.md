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

<br>

## 3. 🚀 PILIHAN WA GATEWAY
### Step 1: Daftar Fonnte <br>

> - Buka https://fonnte.com
> - Klik "Daftar" → Isi data dir
> - Verifikasi email
> - Login ke dashboard

<br>

### Step 2: Setup WhatsApp <br>

> - Di dashboard Fonnte → Klik "Device"
> - Klik "Add Device" → Pilih "WhatsApp"
> - Scan QR Code dengan HP (WA yang mau dijadiin bot)
> - Tunggu status jadi "Connected"

<br>

### Step 3: Dapatkan API Key <br>

> - Masuk menu "API"
> - Copy API Key 
> - Catat Token Device

### Step 4: Test API <br>

```bash

<?php
// test_fonnte.php
$curl = curl_init();

curl_setopt_array($curl, array(
  CURLOPT_URL => 'https://api.fonnte.com/send',
  CURLOPT_RETURNTRANSFER => true,
  CURLOPT_ENCODING => '',
  CURLOPT_MAXREDIRS => 10,
  CURLOPT_TIMEOUT => 0,
  CURLOPT_FOLLOWLOCATION => true,
  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
  CURLOPT_CUSTOMREQUEST => 'POST',
  CURLOPT_POSTFIELDS => array(
    'target' => '628123456789', // Nomor tujuan
    'message' => 'Test pesan dari sistem absensi!',
  ),
  CURLOPT_HTTPHEADER => array(
    'Authorization: YOUR_API_KEY_DISINI'
  ),
));

$response = curl_exec($curl);
curl_close($curl);
echo $response;
?>



> xampp 7.4.33: link download https://sourceforge.net/projects/xampp/files/XAMPP%20Windows/7.4.33/xampp-windows-x64-7.4.33-0-VC15-installer.exe/download

```
