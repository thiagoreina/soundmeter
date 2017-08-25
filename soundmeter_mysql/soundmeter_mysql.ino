/* ============================================
Thiago Reina
============================================ */

#include <UIPEthernet.h>
#include "utility/logging.h"
#include <sound_meter.h>

#define SOUND_PIN A4
#define SOUND_PIN_DIG 7 

#define MACADDRESS 0x00,0x01,0x02,0x03,0x04,0x05
#define MYIPADDR 000,000,000,000                //IP DO SEU ARDUINO
#define MYIPMASK 255,255,255,0
#define MYDNS 8,8,8,8
#define MYGW 000,000,000,1                        //GATEWAY DA SUA REDE
#define LISTENPORT 1000
#define UARTBAUD 115200

uint8_t mac[6] = {MACADDRESS};
uint8_t myIP[4] = {MYIPADDR};
uint8_t myMASK[4] = {MYIPMASK};
uint8_t myDNS[4] = {MYDNS};
uint8_t myGW[4] = {MYGW};

char server[] = "111.111.111.111"; //IP DO SEU SERVIDOR PHP

// Initialise Client
EthernetClient client;

void setup() 
{
    Serial.begin(9600);

 
        Ethernet.begin(mac,myIP,myDNS,myGW,myMASK);
 

    // give the Ethernet shield a second to initialize
    delay(1000);
    Serial.println("connecting...");

  
}

void loop()
{
 int level = analogRead(SOUND_PIN);
  int dig = digitalRead(SOUND_PIN_DIG);
  
   client.connect(server, 80);

        Serial.println("connected");
        // Make a HTTP request
        client.print("GET /server_php/dados.php?data=");
        client.print(level);
        client.print("&alerta=");
        client.println(dig);
        client.println("Host: 172.18.14.5");
        client.println("Connection: close");
        client.println();

        
    

}
