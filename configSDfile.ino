#include <SPI.h>
#include <SD.h>
byte interval = 1;
String apn = "internet";
String username = "";
String password = "";
String email = "";
String emailPassword = "";
float lintang = -6.6722106;
float bujur = 106.8053471;

#define produk "I-TIDE"
#define IDproduk "002"

File myFile;
char files[] = "/config.txt";
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  bool ada = SD.exists(files);
  if (ada) {
    Serial.println("config exist");
    SD.remove(files);
  }

  Serial.println("isi config");
  configs();
  Serial.println("done.");

  // re-open the file for reading:
  Serial.println("\r\n\r\n BUKA CONFIG.TXT");
  myFile = SD.open(files, FILE_READ);
  if (myFile) {
    Serial.println("config.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening config.txt");
  }
}

void loop() {
  // nothing happens after setup
}

void configs() {
  //cek apakah config.txt ada
  File myFile = SD.open("/CONFIG.TXT", FILE_WRITE);
  /*myFile.print("ID = ");
  myFile.print(produk);
  myFile.print(" ");
  myFile.println(IDproduk);
  myFile.print("INTERVAL DATA (MINUTE) = ");
  myFile.println(interval);
  myFile.println("OFFSET = 0");
  myFile.print("LINTANG = ");
  myFile.println(lintang,6);
  myFile.print("BUJUR = ");
  myFile.println(bujur,6);
  myFile.print("APN = ");
  myFile.println(apn);
  myFile.print("USERNAME = ");
  myFile.println(username);
  myFile.print("PASSWORD =  ");
  myFile.println(password);
  myFile.print("EMAIL =  ");
  myFile.println(email);
  myFile.print("EMAIL PASSWORD =  ");
  myFile.println(emailPassword);
  myFile.println("JARAK TOTAL (cm) = 100");
  */
  myFile.println("Interval Waktu Pengambilan Data (menit) =  15");
  
  myFile.close();
}
