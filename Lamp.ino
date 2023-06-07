#define BLYNK_TEMPLATE_ID "TMPL6wvNTLPzm"
#define BLYNK_TEMPLATE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "KOEYSnU8E4S3sLGMu9AxpLovohX9dG95"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Isikan informasi WiFi kamu di sini

char ssid[] = "Redmi Note 10 5G";
char pass[] = "punyarian";

// Isikan pin relay di board ESP8266 yang terhubung ke relay
int relayPin = 2;

void setup()
{
  // Menginisialisasi koneksi WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  // Menginisialisasi koneksi Blynk
  Blynk.begin (BLYNK_AUTH_TOKEN , ssid, pass);

  // Menginisialisasi pin sebagai OUTPUT
  pinMode(relayPin, OUTPUT);

  // Menyalakan lampu saat pertama kali memulai
  digitalWrite(relayPin, HIGH);
}

void loop()
{
  // Menjalankan koneksi Blynk
  Blynk.run();
}

// Fungsi yang dijalankan saat tombol virtual di aplikasi Blynk ditekan
BLYNK_WRITE(V0)
{
  int relayStatus = param.asInt();

  // Mengontrol status relay berdasarkan nilai tombol virtual di Blynk
  digitalWrite(relayPin, relayStatus);
}
