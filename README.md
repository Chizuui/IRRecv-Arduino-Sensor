# IRRecv-Arduino-LED Sensor

## Tools We Need / Alat Yang Dibutuhkan 
    - Board Arduino Uno = 1 Piece
    - Led (Whatever Color / Terserah Warna Apa) =  4 Piece
    - Infrared Receiver TSOP38238 = 1 Piece
    - BreadBoard = 1 Piece
    - Remote control Infrared = 1 Pcs 
Example Remote Control :

<img decoding="async" loading="lazy" class="wp-image-11214 aligncenter" src="https://indobot.co.id/premium/wp-content/uploads/2020/08/remote.png" alt="" width="203" height="203" data-pin-no-hover="true">
<p style="text-align: center;"><span style="font-weight: 400;">Gambar Remote yang digunakan</span></p>

## Program Untuk Inisialisasi Kode
``` #include <IRremote.h>   //Memasukan library IR Remote

int RECV_PIN = 6;      //Lokasi pin data dari Receiver IR
IRrecv irrecv(RECV_PIN);  //Membuat objek receiver dengan nama irrecv
decode_results results;   //membuat objek hasil penerimaan data penekanan tombol remot dengan nama results
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();  //Memulai proses penerimaan data.
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
} ```
