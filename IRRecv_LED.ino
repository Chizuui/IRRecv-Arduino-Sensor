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
  Serial.begin(9600); //menentukan kecepatan dan penerimaan data melalui port serial
  irrecv.enableIRIn();  //Memulai proses penerimaan data.
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
}

unsigned long data;

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results))   //Jika ada data yang masuk
    {
      Serial.println(results.value);  //cetak data yang diterima ke serial monitor
      data = results.value;   //simpan nilai di variabel data
      irrecv.resume();  //reset receiver dan mempersiapkan untuk menerima kode lain

      //Kondisi saat tombol Remot
      switch(data){
        case 16738455:    //Jika angka 1 remot ditekan 
          digitalWrite (12, HIGH);   //hidupkan LED 1
          digitalWrite (13, LOW);    //matikan LED 2
          digitalWrite (4, LOW);    //matikan LED 3
          digitalWrite (5, LOW);    //matikan LED 4
        break;

        case 16750695:    //Jika angka 2 remot ditekan 
          digitalWrite (12, LOW);   //matikan LED 1
          digitalWrite (13, HIGH);  //hidupkan LED 2
          digitalWrite (4, LOW);    //matikan LED 3
          digitalWrite (5, LOW);    //matikan LED 4
        break;

        case 16756815:    //Jika angka 3 remot ditekan 
          digitalWrite (2, LOW);   //matikan LED 1
          digitalWrite (3, LOW);   //matikan LED 2
          digitalWrite (4, HIGH);  //hidupkan LED 3
          digitalWrite (5, LOW);   //matikan LED 4
        break;
        case 16724175:    //Jika angka 4 remot ditekan 
          digitalWrite (2, LOW);   //matikan LED 1
          digitalWrite (3, LOW);    //matikan LED 2
          digitalWrite (4, LOW);    //matikan LED 3
          digitalWrite (5, HIGH);    //hidupkan LED 4
        break;
      }
    }
}