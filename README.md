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
``` 
#include <IRremote.h>   //Memasukan library IR Remote

int LED_RED = 12
int LED_GREEN = 13
int LED_BLUE = 4
int LED_WHITE = 5

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
}
```
## Tabel Tombol Remote dan Kode Hexadesimal
<table>
<tbody>
<tr>
<td>
<p style="text-align: center;"><strong>Tombol</strong></p>
</td>
<td>
<p style="text-align: center;"><strong>Kode Hex</strong></p>
</td>
</tr>
<tr>
<td><span style="font-weight: 400;">CH-</span></td>
<td><span style="font-weight: 400;"> 0xFFA25D</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> CH</span></td>
<td><span style="font-weight: 400;"> 0xFF629D</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> CH+</span></td>
<td><span style="font-weight: 400;"> 0xFFE21D</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> &lt;&lt;</span></td>
<td><span style="font-weight: 400;"> 0xFF22DD</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> &gt;&gt;</span></td>
<td><span style="font-weight: 400;"> 0xFF02FD</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> &gt;||</span></td>
<td><span style="font-weight: 400;"> 0xFFC23D</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> –</span></td>
<td><span style="font-weight: 400;"> 0xFFE01F</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> +</span></td>
<td><span style="font-weight: 400;"> 0xFFA857</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> EQ</span></td>
<td><span style="font-weight: 400;"> 0xFF906F</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 100+</span></td>
<td><span style="font-weight: 400;"> 0xFF9867</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 200+</span></td>
<td><span style="font-weight: 400;"> 0xFFB04F</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 0</span></td>
<td><span style="font-weight: 400;"> 0XFF6897</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 1</span></td>
<td><span style="font-weight: 400;"> 0xFF30CF</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 2</span></td>
<td><span style="font-weight: 400;"> 0xFF18E7</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 3</span></td>
<td><span style="font-weight: 400;"> 0xFF7A85</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 4</span></td>
<td><span style="font-weight: 400;"> 0xFF10EF</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 5</span></td>
<td><span style="font-weight: 400;"> 0xFF38C7</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 6</span></td>
<td><span style="font-weight: 400;"> 0xFF5AA5</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 7</span></td>
<td><span style="font-weight: 400;"> 0xFF42BD</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 8</span></td>
<td><span style="font-weight: 400;"> 0xFF4AB5</span></td>
</tr>
<tr>
<td><span style="font-weight: 400;"> 9</span></td>
<td><span style="font-weight: 400;"> 0xFF52AD</span></td>
</tr>
</tbody>
</table>

## Program Untuk Menyalahkan LED
```
void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results))   //Jika ada data yang masuk
    {
      Serial.println(results.value);  //cetak data yang diterima ke serial monitor
      data = results.value;   //simpan nilai di variabel data
      irrecv.resume();  //reset receiver dan mempersiapkan untuk menerima kode lain

      //Kondisi saat tombol Remot
      switch(data){
        case 0xFF30CF:    //Jika angka 1 remot ditekan 
          digitalWrite (12, HIGH);   //hidupkan LED 1
          digitalWrite (13, LOW);    //matikan LED 2
          digitalWrite (4, LOW);    //matikan LED 3
          digitalWrite (5, LOW);    //matikan LED 4
        break;

        case 0xFF18E7:    //Jika angka 2 remot ditekan 
          digitalWrite (12, LOW);   //matikan LED 1
          digitalWrite (13, HIGH);  //hidupkan LED 2
          digitalWrite (4, LOW);    //matikan LED 3
          digitalWrite (5, LOW);    //matikan LED 4
        break;

        case 0xFF7A85:    //Jika angka 3 remot ditekan 
          digitalWrite (2, LOW);   //matikan LED 1
          digitalWrite (3, LOW);   //matikan LED 2
          digitalWrite (4, HIGH);  //hidupkan LED 3
          digitalWrite (5, LOW);   //matikan LED 4
        break;
        case 0xFF10EF:    //Jika angka 4 remot ditekan 
          digitalWrite (2, LOW);   //matikan LED 1
          digitalWrite (3, LOW);    //matikan LED 2
          digitalWrite (4, LOW);    //matikan LED 3
          digitalWrite (5, HIGH);    //hidupkan LED 4
        break;
      }
    }
}
```