// This file is automatically generated by the Open Roberta Lab.

#include <Arduino.h>
#include <MFRC522/src/MFRC522.h>
#include <NEPODefs.h>


String ___item;
bool ___item2;
#define SS_PIN_R 10
#define RST_PIN_R 9
MFRC522 _mfrc522_R(SS_PIN_R, RST_PIN_R);
String _readRFIDData(MFRC522 &mfrc522) {
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return "N/A";
    }
    if (!mfrc522.PICC_ReadCardSerial()) {
        return "N/D";
    }
    return String(((long)(mfrc522.uid.uidByte[0])<<24)
        | ((long)(mfrc522.uid.uidByte[1])<<16)
        | ((long)(mfrc522.uid.uidByte[2])<<8)
        | ((long)(mfrc522.uid.uidByte[3]), HEX));
}

void setup()
{
    SPI.begin();
    _mfrc522_R.PCD_Init();
    ___item = _readRFIDData(_mfrc522_R);
    ___item2 = _mfrc522_R.PICC_IsNewCardPresent();
}

void loop()
{
}