#include <IRLibSendBase.h>    
#include <IRLib_HashRaw.h>    

IRsendRaw mySender;
void setup() {
 Serial.begin(9600);
 int dataIn = Serial.read(); // to read the input data of from the user of the serial monitor
Serial.println(F("kies 1 van de onderstaande getallen of letters om de airco te besturen"));
Serial.println(F(" bij het invoeren van:       wordt:"));
Serial.println(F("                       1     de airco aangemaakt"));
Serial.println(F("                       2     de airco uitgemaakt"));
Serial.println(F("                       a     de temperatuur ingesteld op 16 graden celcius"));
Serial.println(F("                       b     de temperatuur ingesteld op 17 graden celcius"));
Serial.println(F("                       c     de temperatuur ingesteld op 18 graden celcius"));
Serial.println(F("                       d     de temperatuur ingesteld op 19 graden celcius"));
Serial.println(F("                       e     de temperatuur ingesteld op 20 graden celcius"));
Serial.println(F("                       f     de temperatuur ingesteld op 21 graden celcius"));
Serial.println(F("                       g     de temperatuur ingesteld op 22 graden celcius"));
Serial.println(F("                       h     de temperatuur ingesteld op 23 graden celcius"));
Serial.println(F("                       i     de temperatuur ingesteld op 24 graden celcius"));
Serial.println(F("                       j     de temperatuur ingesteld op 25 graden celcius"));
Serial.println(F("                       k     de temperatuur ingesteld op 26 graden celcius"));
Serial.println(F("                       l     de temperatuur ingesteld op 27 graden celcius"));
Serial.println(F("                       m     de temperatuur ingesteld op 28 graden celcius"));
Serial.println(F("                       n     de temperatuur ingesteld op 29 graden celcius"));
Serial.println(F("                       o     de temperatuur ingesteld op 30 graden celcius"));
Serial.println(F("                       p     de temperatuur ingesteld op 31 graden celcius"));
Serial.println(F("                       q     de temperatuur ingesteld op 32 graden celcius"));

}
// rawcode voor het aanmaken van de airco
#define RAW_DATA_LEN 198
uint16_t rawDataOn[RAW_DATA_LEN]={
  5982, 7502, 438, 1746, 450, 1746, 378, 1818, 
  434, 1770, 434, 1766, 434, 1746, 426, 1742, 
  434, 1766, 434, 682, 458, 646, 438, 698, 
  434, 698, 438, 678, 398, 706, 438, 678, 
  454, 650, 406, 1794, 434, 1738, 438, 1726, 
  470, 1746, 398, 1778, 486, 1734, 438, 1762, 
  438, 1714, 426, 706, 438, 698, 438, 650, 
  402, 702, 438, 654, 426, 674, 438, 698, 
  438, 650, 402, 1794, 434, 1738, 438, 1718, 
  454, 1742, 402, 1794, 434, 1766, 442, 1758, 
  442, 1738, 462, 670, 382, 726, 438, 678, 
  458, 646, 438, 694, 442, 694, 438, 646, 
  438, 670, 442, 1738, 458, 674, 434, 674, 
  438, 1758, 442, 646, 434, 1714, 462, 1762, 
  438, 1738, 462, 674, 378, 1790, 438, 1734, 
  442, 646, 434, 1762, 414, 722, 442, 674, 
  458, 642, 418, 1762, 462, 1738, 462, 1758, 
  442, 1738, 458, 1742, 378, 726, 438, 1762, 
  438, 1758, 438, 678, 426, 702, 418, 694, 
  438, 674, 402, 702, 438, 1738, 462, 650, 
  426, 702, 414, 722, 442, 1710, 458, 674, 
  382, 1790, 438, 694, 442, 1738, 458, 678, 
  378, 726, 438, 1758, 438, 678, 434, 1734, 
  434, 674, 438, 1762, 438, 646, 434, 1762, 
  414, 1758, 438, 7478, 430, 1000};

// rawcode voor het uitmaken van de airco
  #define RAW_DATA_LEN 198
uint16_t rawDataOff[RAW_DATA_LEN]={
  6026, 7482, 458, 1722, 454, 1766, 438, 1742, 
  458, 1722, 394, 1802, 434, 1742, 458, 1742, 
  426, 1722, 454, 682, 458, 702, 434, 626, 
  434, 674, 434, 706, 418, 662, 458, 702, 
  410, 702, 374, 1802, 454, 1742, 442, 1758, 
  438, 1742, 422, 1750, 454, 1770, 434, 1718, 
  430, 1770, 430, 682, 474, 630, 434, 706, 
  426, 654, 434, 726, 410, 654, 450, 654, 
  458, 678, 454, 1750, 418, 1758, 450, 1746, 
  430, 1770, 454, 1770, 434, 1698, 390, 1806, 
  458, 1738, 458, 702, 434, 654, 422, 686, 
  454, 658, 450, 658, 450, 682, 430, 682, 
  454, 650, 458, 1718, 458, 1766, 434, 634, 
  390, 1806, 450, 706, 430, 1722, 450, 1730, 
  410, 1786, 446, 710, 430, 706, 430, 1702, 
  386, 738, 426, 1774, 426, 690, 414, 690, 
  406, 682, 442, 1758, 414, 1754, 398, 1774, 
  422, 1734, 414, 1754, 394, 714, 422, 1758, 
  442, 1758, 410, 718, 414, 694, 418, 670, 
  410, 694, 418, 698, 438, 1762, 410, 694, 
  394, 694, 438, 694, 410, 1758, 422, 714, 
  422, 1730, 414, 690, 418, 1754, 418, 694, 
  418, 686, 418, 1782, 418, 694, 438, 1734, 
  414, 714, 394, 1806, 418, 670, 438, 1758, 
  418, 1778, 418, 7514, 394, 1000};

// rawcode voor het instellen van de airco op 16 graden celcius
  #define RAW_DATA_LEN 198
uint16_t rawData16[RAW_DATA_LEN]={
  5974, 7482, 422, 1778, 446, 1778, 398, 1778, 
  430, 1770, 446, 1698, 454, 1722, 446, 1710, 
  466, 1698, 454, 706, 422, 666, 446, 682, 
  398, 710, 426, 662, 422, 682, 402, 626, 
  482, 710, 398, 1778, 450, 1770, 426, 1750, 
  446, 1754, 426, 1726, 470, 1722, 430, 1770, 
  422, 1754, 446, 690, 446, 658, 430, 702, 
  426, 598, 510, 658, 426, 710, 426, 662, 
  422, 682, 422, 710, 426, 638, 442, 1754, 
  482, 1690, 446, 1778, 398, 1778, 446, 1702, 
  442, 1754, 454, 1770, 422, 1754, 446, 662, 
  446, 658, 426, 662, 422, 710, 450, 682, 
  426, 682, 426, 1754, 422, 678, 430, 682, 
  426, 1750, 446, 658, 398, 1778, 446, 1726, 
  446, 1754, 422, 714, 446, 1726, 446, 1750, 
  454, 678, 426, 1750, 422, 682, 398, 710, 
  426, 690, 446, 1754, 442, 1730, 442, 1726, 
  446, 1754, 446, 1750, 450, 642, 466, 1726, 
  418, 1774, 426, 710, 426, 686, 450, 654, 
  426, 682, 426, 658, 426, 1750, 482, 646, 
  430, 658, 422, 710, 426, 1770, 426, 710, 
  426, 1750, 446, 662, 422, 1750, 454, 702, 
  426, 686, 450, 1750, 450, 654, 458, 1714, 
  426, 686, 450, 1750, 446, 654, 458, 1742, 
  426, 1750, 450, 7482, 450, 1000};

// rawcode voor het instellen van de airco op 17 graden celcius
  #define RAW_DATA_LEN 198
uint16_t rawData17[RAW_DATA_LEN]={
  5954, 7530, 434, 1762, 442, 1758, 438, 1742, 
  434, 1762, 410, 1786, 442, 1734, 438, 1714, 
  430, 1738, 438, 722, 414, 674, 434, 670, 
  414, 718, 414, 650, 406, 746, 422, 714, 
  418, 670, 410, 1762, 410, 1790, 438, 1734, 
  438, 1762, 438, 1762, 438, 1738, 406, 1762, 
  442, 1758, 438, 698, 438, 698, 406, 674, 
  442, 714, 422, 694, 434, 670, 418, 670, 
  438, 694, 382, 1790, 386, 774, 418, 1730, 
  442, 1758, 442, 1734, 430, 1738, 442, 1758, 
  442, 1730, 446, 690, 410, 1738, 410, 746, 
  422, 710, 426, 642, 378, 722, 446, 690, 
  442, 666, 414, 1758, 446, 714, 422, 666, 
  382, 1790, 410, 694, 446, 1730, 442, 1758, 
  406, 1738, 438, 694, 446, 1774, 426, 1726, 
  442, 690, 362, 1786, 446, 662, 446, 686, 
  366, 742, 426, 706, 426, 1754, 442, 1726, 
  366, 1826, 394, 1806, 426, 682, 426, 1754, 
  442, 1726, 366, 1830, 422, 710, 422, 714, 
  422, 662, 390, 714, 422, 1778, 422, 694, 
  442, 658, 422, 714, 422, 1774, 422, 666, 
  414, 1782, 390, 722, 418, 1778, 446, 666, 
  442, 666, 438, 1762, 434, 698, 442, 1778, 
  422, 642, 438, 1782, 414, 714, 394, 1806, 
  418, 1754, 418, 7490, 442, 1000};

// rawcode voor het instellen van de airco op 18 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData18[RAW_DATA_LEN]={
  5998, 7486, 398, 1778, 450, 1750, 458, 1742, 
  478, 1718, 458, 1726, 438, 1778, 370, 1802, 
  454, 1746, 458, 702, 458, 626, 370, 762, 
  458, 650, 458, 658, 366, 714, 454, 658, 
  446, 686, 422, 1774, 430, 1746, 454, 1770, 
  454, 1722, 478, 1674, 390, 1778, 454, 1746, 
  478, 1722, 478, 658, 446, 634, 450, 710, 
  434, 654, 410, 718, 426, 710, 434, 698, 
  430, 658, 366, 1806, 454, 678, 454, 1722, 
  450, 1730, 406, 1762, 446, 1774, 426, 1774, 
  426, 1750, 450, 690, 438, 1734, 386, 718, 
  446, 714, 422, 690, 410, 694, 422, 666, 
  438, 694, 362, 1814, 386, 766, 422, 714, 
  422, 1754, 442, 662, 390, 1810, 422, 1750, 
  418, 1758, 442, 694, 438, 1758, 386, 1782, 
  422, 666, 442, 1758, 442, 658, 450, 686, 
  422, 694, 442, 1754, 442, 658, 426, 1774, 
  422, 1750, 422, 1758, 438, 662, 394, 1806, 
  418, 1782, 418, 718, 418, 1758, 442, 670, 
  434, 674, 434, 670, 442, 1758, 410, 674, 
  438, 666, 442, 678, 426, 1786, 410, 722, 
  418, 1782, 414, 670, 438, 1762, 410, 694, 
  414, 674, 434, 1762, 410, 694, 414, 1786, 
  386, 750, 386, 1762, 410, 698, 382, 1818, 
  382, 1838, 362, 7546, 402, 1000};

// rawcode voor het instellen van de airco op 19 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData19[RAW_DATA_LEN]={
  5990, 7486, 434, 1766, 430, 1770, 430, 1774, 
  418, 1754, 450, 1750, 426, 1774, 450, 1750, 
  450, 1726, 438, 690, 426, 662, 450, 686, 
  442, 638, 446, 662, 454, 686, 410, 690, 
  430, 706, 430, 1750, 446, 1750, 446, 1734, 
  406, 1810, 426, 1746, 422, 1778, 422, 1754, 
  446, 1758, 438, 690, 390, 718, 418, 698, 
  438, 662, 422, 670, 438, 694, 414, 690, 
  418, 718, 418, 1778, 422, 694, 386, 1782, 
  414, 1786, 418, 1778, 418, 1738, 434, 1734, 
  386, 1810, 418, 718, 418, 1758, 438, 574, 
  482, 746, 418, 718, 418, 666, 386, 722, 
  418, 694, 438, 1762, 438, 666, 414, 694, 
  418, 1762, 434, 666, 450, 1750, 418, 1734, 
  438, 1762, 438, 694, 386, 1786, 470, 1726, 
  418, 694, 442, 1726, 414, 722, 418, 670, 
  438, 666, 418, 714, 418, 670, 442, 1758, 
  410, 1754, 446, 1754, 422, 666, 438, 1762, 
  414, 1754, 418, 1778, 418, 1782, 418, 670, 
  434, 666, 418, 694, 414, 1766, 434, 666, 
  414, 694, 418, 698, 414, 1782, 414, 718, 
  414, 1782, 422, 666, 442, 1758, 438, 662, 
  422, 690, 418, 1758, 438, 694, 414, 1782, 
  390, 718, 414, 1762, 438, 670, 410, 1758, 
  414, 1786, 390, 7542, 390, 1000};

// rawcode voor het instellen van de airco op 20 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData20[RAW_DATA_LEN]={
  5962, 7478, 462, 1734, 410, 1790, 466, 1734, 
  438, 1758, 442, 1758, 442, 1742, 458, 1734, 
  410, 1786, 470, 690, 418, 670, 438, 642, 
  442, 670, 438, 642, 446, 686, 418, 698, 
  438, 662, 418, 1762, 438, 1758, 442, 1710, 
  438, 1730, 474, 1726, 442, 1758, 442, 1754, 
  446, 1706, 414, 742, 418, 690, 418, 694, 
  442, 666, 418, 666, 442, 694, 386, 718, 
  418, 646, 466, 1734, 434, 718, 446, 1730, 
  442, 1758, 442, 1710, 462, 1730, 390, 1782, 
  442, 1758, 442, 694, 442, 1706, 466, 690, 
  418, 690, 418, 666, 418, 718, 418, 666, 
  442, 662, 394, 1782, 442, 670, 438, 698, 
  438, 1706, 470, 686, 418, 1734, 442, 1734, 
  462, 1706, 446, 714, 414, 1758, 442, 1758, 
  442, 694, 414, 1730, 474, 686, 418, 694, 
  442, 662, 422, 1774, 422, 1730, 442, 694, 
  442, 1734, 438, 1758, 438, 714, 446, 1754, 
  418, 1778, 422, 694, 414, 718, 414, 1754, 
  418, 670, 414, 722, 414, 1750, 418, 694, 
  418, 698, 426, 678, 442, 1758, 414, 694, 
  418, 1782, 438, 642, 438, 1734, 442, 694, 
  442, 674, 434, 1758, 438, 670, 438, 1778, 
  418, 698, 414, 1782, 418, 686, 418, 1782, 
  398, 1798, 418, 7494, 414, 1000};

// rawcode voor het instellen van de airco op 21 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData21[RAW_DATA_LEN]={
  5990, 7506, 438, 1742, 458, 1742, 450, 1718, 
  434, 1738, 438, 1766, 434, 1718, 374, 1794, 
  430, 1742, 430, 686, 446, 658, 430, 706, 
  426, 658, 398, 734, 458, 678, 426, 662, 
  418, 710, 434, 1766, 426, 1774, 426, 1774, 
  426, 1754, 446, 1750, 418, 1750, 458, 1742, 
  426, 1754, 446, 690, 446, 686, 394, 710, 
  426, 662, 418, 686, 426, 662, 446, 686, 
  394, 714, 422, 1778, 422, 662, 418, 1778, 
  426, 1750, 446, 1750, 422, 1754, 446, 1758, 
  442, 1702, 446, 690, 442, 1778, 422, 694, 
  442, 658, 422, 690, 422, 690, 442, 638, 
  446, 666, 442, 1734, 466, 658, 422, 714, 
  422, 1710, 466, 686, 422, 1750, 418, 1758, 
  442, 1730, 446, 686, 422, 1726, 446, 1754, 
  446, 662, 446, 1750, 422, 686, 422, 666, 
  446, 682, 454, 682, 422, 1774, 426, 690, 
  446, 1726, 418, 1774, 450, 658, 426, 1754, 
  446, 1726, 418, 1774, 426, 682, 426, 1726, 
  446, 686, 422, 682, 426, 1774, 426, 690, 
  418, 682, 426, 710, 422, 1774, 426, 662, 
  422, 1770, 426, 682, 426, 1754, 442, 694, 
  418, 682, 402, 1798, 398, 690, 422, 1774, 
  422, 682, 422, 1750, 426, 690, 442, 1754, 
  422, 1746, 422, 7510, 426, 1000};

// rawcode voor het instellen van de airco op 22 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData22[RAW_DATA_LEN]={
  5990, 7466, 446, 1754, 446, 1778, 426, 1750, 
  446, 1758, 442, 1734, 410, 1806, 394, 1782, 
  446, 1778, 422, 690, 446, 690, 386, 718, 
  422, 690, 446, 662, 394, 714, 422, 690, 
  446, 658, 426, 1774, 422, 1778, 422, 1754, 
  446, 1726, 390, 1758, 446, 1774, 426, 1754, 
  446, 1754, 446, 686, 390, 742, 426, 710, 
  422, 666, 414, 714, 426, 686, 422, 662, 
  390, 722, 442, 1754, 446, 690, 446, 1754, 
  414, 1754, 394, 1782, 446, 1754, 446, 1726, 
  446, 1702, 414, 742, 422, 1778, 422, 690, 
  446, 638, 418, 690, 446, 690, 442, 638, 
  450, 658, 450, 1750, 446, 686, 394, 742, 
  422, 1726, 446, 690, 442, 1702, 418, 1806, 
  422, 1754, 446, 710, 422, 1706, 438, 1782, 
  390, 718, 422, 1774, 426, 662, 390, 742, 
  422, 710, 426, 1754, 446, 686, 414, 690, 
  426, 1774, 422, 1774, 426, 662, 442, 1750, 
  426, 1746, 426, 690, 446, 1754, 446, 1750, 
  446, 682, 426, 686, 422, 1754, 446, 690, 
  414, 686, 426, 710, 426, 1726, 446, 654, 
  426, 1774, 426, 662, 446, 1754, 418, 682, 
  426, 666, 442, 1754, 446, 686, 394, 1802, 
  422, 686, 426, 1754, 442, 690, 414, 1754, 
  422, 1778, 422, 7510, 422, 1000};

// rawcode voor het instellen van de airco op 23 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData23[RAW_DATA_LEN]={
  6058, 7402, 478, 1718, 430, 1742, 550, 1650, 
  522, 1678, 514, 1666, 470, 1726, 430, 1766, 
  522, 1678, 518, 618, 542, 574, 442, 662, 
  518, 590, 514, 594, 430, 682, 546, 538, 
  446, 658, 546, 1654, 514, 1686, 542, 1638, 
  486, 1710, 446, 1722, 546, 1626, 518, 1638, 
  446, 1722, 438, 718, 522, 570, 422, 710, 
  474, 634, 538, 574, 450, 654, 510, 602, 
  542, 542, 426, 1770, 438, 698, 546, 1626, 
  502, 1646, 450, 1746, 506, 1694, 518, 1654, 
  514, 1686, 510, 606, 442, 1750, 470, 642, 
  518, 614, 462, 618, 550, 562, 542, 574, 
  446, 658, 542, 1654, 514, 574, 474, 682, 
  406, 1766, 514, 594, 514, 1686, 458, 1718, 
  446, 1722, 522, 618, 538, 1654, 514, 1690, 
  462, 618, 506, 1690, 514, 622, 510, 578, 
  446, 658, 510, 626, 510, 574, 426, 682, 
  510, 1686, 510, 1642, 446, 658, 514, 1658, 
  510, 1690, 506, 1674, 478, 1714, 450, 1718, 
  470, 670, 506, 602, 426, 1746, 430, 678, 
  510, 602, 450, 658, 434, 1762, 506, 630, 
  502, 1666, 498, 614, 430, 1742, 506, 602, 
  506, 606, 442, 1750, 442, 670, 506, 1690, 
  506, 610, 446, 1722, 466, 642, 506, 1690, 
  506, 1646, 446, 7482, 434, 1000};


// rawcode voor het instellen van de airco op 24 graden celcius:
#define RAW_DATA_LEN 198
uint16_t rawData24[RAW_DATA_LEN]={
  5938, 7518, 458, 1766, 434, 1718, 422, 1722, 
  434, 1742, 458, 1742, 458, 1722, 470, 1726, 
  398, 1774, 454, 702, 434, 650, 430, 678, 
  434, 654, 394, 710, 430, 658, 454, 678, 
  374, 730, 434, 1766, 430, 1750, 450, 1718, 
  398, 1754, 450, 1770, 430, 1770, 430, 1750, 
  450, 1746, 406, 726, 454, 682, 430, 682, 
  450, 654, 430, 706, 426, 686, 450, 658, 
  398, 734, 426, 1770, 430, 686, 450, 1718, 
  398, 1798, 434, 1766, 430, 1770, 430, 1750, 
  450, 1750, 446, 686, 394, 1778, 454, 678, 
  430, 686, 446, 654, 430, 682, 426, 686, 
  418, 686, 426, 1770, 430, 662, 446, 682, 
  426, 1770, 430, 662, 446, 1754, 446, 1746, 
  398, 1774, 422, 710, 430, 1770, 430, 1750, 
  446, 658, 458, 1738, 430, 706, 430, 654, 
  422, 710, 458, 1742, 430, 1766, 430, 1726, 
  446, 682, 398, 1774, 426, 710, 426, 1750, 
  450, 1750, 450, 682, 426, 678, 430, 658, 
  450, 1746, 398, 710, 430, 1766, 430, 658, 
  422, 682, 430, 706, 430, 1750, 446, 654, 
  454, 1718, 430, 686, 446, 1722, 422, 682, 
  430, 686, 450, 1750, 446, 654, 458, 1714, 
  430, 686, 450, 1718, 426, 682, 426, 1770, 
  430, 1722, 450, 7482, 426, 1000};


// rawcode voor het instellen van de airco op 25 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData25[RAW_DATA_LEN]={
  5962, 7498, 442, 1758, 442, 1758, 446, 1734, 
  438, 1758, 414, 1782, 446, 1754, 446, 1754, 
  450, 1750, 446, 690, 394, 726, 434, 714, 
  422, 638, 418, 714, 422, 666, 446, 682, 
  398, 690, 446, 1750, 450, 1754, 446, 1730, 
  414, 1782, 450, 1722, 446, 1730, 446, 1698, 
  450, 1722, 450, 690, 446, 658, 394, 718, 
  446, 690, 446, 662, 390, 742, 422, 710, 
  426, 662, 390, 1806, 422, 710, 426, 1754, 
  446, 1750, 450, 1730, 466, 1702, 450, 1722, 
  446, 1754, 446, 690, 446, 1730, 414, 694, 
  442, 690, 446, 638, 418, 738, 422, 714, 
  422, 662, 390, 1782, 450, 662, 446, 690, 
  442, 1726, 394, 738, 426, 1726, 446, 1754, 
  446, 1730, 414, 738, 426, 1726, 446, 1750, 
  450, 686, 394, 1750, 450, 662, 446, 662, 
  394, 714, 422, 690, 446, 1698, 418, 1782, 
  474, 658, 422, 1754, 446, 634, 450, 1750, 
  446, 1730, 442, 1754, 446, 658, 398, 710, 
  426, 1774, 426, 658, 394, 1802, 422, 686, 
  426, 690, 442, 690, 394, 1798, 430, 682, 
  426, 1754, 446, 654, 450, 1702, 446, 690, 
  446, 654, 430, 1770, 426, 682, 426, 1754, 
  446, 654, 426, 1774, 426, 706, 430, 1770, 
  426, 1754, 446, 7482, 394, 1000};

// rawcode voor het instellen van de airco op 26 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData26[RAW_DATA_LEN]={
  5962, 7518, 426, 1774, 426, 1726, 446, 1730, 
  414, 1782, 450, 1770, 430, 1750, 450, 1750, 
  450, 1750, 446, 686, 394, 738, 426, 710, 
  426, 658, 394, 742, 426, 662, 446, 686, 
  394, 690, 446, 1754, 450, 1750, 446, 1754, 
  414, 1758, 418, 1754, 450, 1726, 446, 1722, 
  398, 1774, 426, 710, 426, 638, 414, 738, 
  426, 662, 450, 686, 394, 734, 430, 662, 
  446, 686, 394, 1778, 450, 658, 450, 1750, 
  450, 1722, 394, 1778, 426, 1750, 450, 1770, 
  430, 1750, 450, 658, 394, 1778, 450, 706, 
  430, 658, 394, 738, 426, 682, 426, 686, 
  394, 690, 450, 1770, 430, 686, 446, 634, 
  446, 1774, 430, 658, 450, 1730, 462, 1754, 
  370, 1778, 450, 706, 430, 1746, 450, 1730, 
  470, 654, 430, 1770, 426, 662, 450, 682, 
  398, 686, 450, 1746, 454, 654, 398, 1798, 
  458, 654, 426, 1750, 450, 654, 430, 1746, 
  450, 1770, 430, 706, 430, 1750, 450, 650, 
  430, 1770, 430, 658, 450, 1726, 470, 654, 
  430, 678, 430, 686, 418, 1774, 430, 678, 
  430, 1770, 430, 686, 446, 1718, 430, 706, 
  430, 702, 430, 1750, 450, 654, 430, 1766, 
  426, 710, 430, 1722, 450, 678, 426, 1746, 
  430, 1770, 426, 7506, 430, 1000};

// rawcode voor het instellen van de airco op 27 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData27[RAW_DATA_LEN]={
  5910, 7546, 482, 1742, 454, 1702, 362, 1810, 
  450, 1750, 478, 1718, 482, 1722, 474, 1726, 
  446, 1730, 390, 766, 430, 702, 458, 606, 
  390, 766, 430, 678, 454, 658, 366, 738, 
  458, 634, 442, 1734, 386, 1782, 454, 1746, 
  478, 1742, 454, 1722, 454, 1750, 410, 1762, 
  390, 1806, 458, 678, 478, 634, 362, 718, 
  482, 630, 450, 682, 366, 742, 454, 658, 
  450, 686, 362, 1810, 446, 686, 454, 1722, 
  474, 1726, 442, 1726, 430, 1742, 458, 1742, 
  454, 1722, 450, 686, 366, 1806, 450, 682, 
  454, 658, 442, 662, 434, 654, 450, 686, 
  366, 738, 458, 1718, 478, 634, 410, 718, 
  430, 1722, 478, 658, 450, 1698, 418, 1750, 
  482, 1742, 454, 658, 450, 1730, 430, 1734, 
  450, 706, 458, 1694, 450, 686, 366, 738, 
  434, 654, 414, 718, 398, 706, 434, 1766, 
  430, 658, 366, 1826, 434, 674, 434, 1746, 
  450, 1750, 366, 1830, 366, 1826, 430, 678, 
  434, 1746, 446, 690, 366, 1798, 430, 706, 
  430, 662, 414, 718, 422, 1774, 426, 686, 
  450, 1722, 450, 662, 418, 1774, 430, 658, 
  442, 642, 446, 1774, 426, 658, 450, 1750, 
  414, 690, 426, 1774, 422, 710, 426, 1726, 
  414, 1782, 386, 7546, 418, 1000};

// rawcode voor het instellen van de airco op 28 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData28[RAW_DATA_LEN]={
  5938, 7518, 482, 1742, 438, 1714, 366, 1802, 
  458, 1742, 458, 1742, 442, 1738, 418, 1758, 
  394, 1798, 458, 702, 458, 654, 454, 650, 
  434, 702, 462, 606, 390, 734, 458, 630, 
  454, 678, 374, 1822, 438, 1738, 458, 1694, 
  418, 1782, 370, 1774, 486, 1690, 458, 1722, 
  438, 1750, 438, 698, 462, 626, 370, 734, 
  458, 630, 450, 654, 434, 674, 462, 654, 
  414, 666, 482, 1738, 462, 630, 366, 1778, 
  454, 1766, 462, 1738, 462, 1738, 458, 1670, 
  394, 1774, 462, 698, 462, 1670, 438, 662, 
  486, 626, 454, 650, 434, 674, 462, 654, 
  418, 682, 434, 1746, 482, 626, 450, 682, 
  426, 1746, 462, 674, 434, 1714, 374, 1794, 
  438, 1762, 462, 674, 458, 1718, 450, 1718, 
  434, 678, 458, 1738, 434, 654, 398, 706, 
  438, 678, 450, 1746, 370, 1798, 438, 670, 
  462, 654, 418, 1746, 434, 702, 442, 1710, 
  458, 1742, 446, 686, 402, 730, 462, 1734, 
  442, 1758, 438, 650, 374, 1818, 438, 674, 
  434, 650, 374, 758, 434, 1762, 438, 654, 
  450, 1746, 374, 730, 434, 1762, 438, 678, 
  454, 650, 402, 1794, 434, 658, 450, 1750, 
  446, 654, 430, 1770, 430, 658, 450, 1750, 
  418, 1750, 426, 7506, 434, 1000};


// rawcode voor het instellen van de airco op 29 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData29[RAW_DATA_LEN]={
  5946, 7514, 434, 1762, 462, 1738, 438, 1742, 
  450, 1750, 374, 1822, 434, 1766, 434, 1766, 
  434, 1742, 458, 678, 418, 714, 434, 674, 
  434, 682, 390, 710, 434, 654, 454, 682, 
  370, 734, 434, 1766, 434, 1742, 458, 1722, 
  438, 1750, 438, 1714, 482, 1718, 454, 1746, 
  450, 1726, 394, 758, 434, 674, 434, 682, 
  418, 662, 458, 654, 450, 654, 430, 678, 
  434, 682, 418, 1778, 370, 710, 458, 1718, 
  454, 1694, 394, 1826, 430, 1746, 458, 1714, 
  458, 1742, 454, 678, 374, 1802, 450, 682, 
  434, 678, 446, 658, 438, 698, 434, 678, 
  454, 650, 434, 1766, 438, 650, 454, 654, 
  394, 1798, 438, 698, 434, 1742, 458, 1742, 
  450, 1698, 394, 758, 438, 1738, 482, 1718, 
  458, 678, 450, 1718, 402, 734, 434, 698, 
  438, 650, 374, 758, 434, 1738, 434, 682, 
  418, 682, 434, 1738, 438, 678, 450, 1718, 
  374, 1822, 434, 1762, 438, 698, 438, 1762, 
  438, 1742, 422, 678, 430, 1742, 438, 678, 
  454, 650, 434, 698, 438, 1734, 438, 674, 
  378, 1790, 414, 678, 454, 1746, 450, 650, 
  434, 674, 438, 1742, 454, 678, 374, 1794, 
  406, 682, 454, 1746, 450, 650, 434, 1762, 
  434, 1766, 434, 7498, 434, 1000};

// rawcode voor het instellen van de airco op 30 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData30[RAW_DATA_LEN]={
  6026, 7482, 402, 1798, 430, 1770, 430, 1750, 
  450, 1702, 414, 1802, 426, 1754, 450, 1750, 
  450, 1750, 450, 682, 398, 710, 426, 686, 
  454, 654, 394, 738, 426, 710, 426, 658, 
  394, 738, 430, 1750, 450, 1770, 430, 1750, 
  450, 1726, 418, 1798, 402, 1778, 450, 1770, 
  430, 1726, 450, 682, 394, 738, 426, 706, 
  430, 634, 418, 738, 426, 662, 450, 682, 
  394, 714, 426, 1750, 450, 658, 422, 1774, 
  398, 1802, 426, 1770, 430, 1750, 450, 1702, 
  442, 1750, 426, 706, 430, 1726, 446, 654, 
  430, 658, 450, 658, 398, 686, 450, 686, 
  450, 630, 454, 1746, 450, 642, 470, 630, 
  450, 1750, 450, 706, 430, 1750, 450, 1718, 
  394, 1782, 454, 702, 430, 1750, 446, 1750, 
  454, 650, 426, 1774, 426, 662, 450, 682, 
  394, 714, 426, 1770, 430, 658, 422, 662, 
  450, 706, 430, 1722, 446, 682, 430, 1742, 
  430, 1746, 454, 686, 446, 1726, 418, 1774, 
  430, 1770, 430, 638, 442, 1746, 430, 678, 
  430, 686, 446, 682, 426, 1746, 430, 682, 
  454, 1746, 450, 654, 430, 1766, 430, 658, 
  454, 678, 398, 1798, 430, 682, 430, 1746, 
  450, 686, 446, 1722, 430, 702, 430, 1766, 
  434, 1746, 454, 7482, 450, 1000};

// rawcode voor het instellen van de airco op 31 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData31[RAW_DATA_LEN]={
  6046, 7438, 394, 1802, 426, 1794, 438, 1738, 
  486, 1718, 454, 1698, 394, 1822, 434, 1766, 
  434, 1766, 434, 682, 418, 682, 438, 654, 
  450, 654, 426, 658, 458, 682, 446, 654, 
  438, 698, 434, 1746, 450, 1730, 466, 1750, 
  374, 1822, 434, 1766, 434, 1718, 454, 1718, 
  374, 1798, 430, 706, 430, 654, 398, 706, 
  434, 634, 414, 714, 430, 658, 450, 682, 
  374, 734, 430, 1766, 434, 682, 418, 1750, 
  426, 1770, 434, 1766, 434, 1766, 434, 1746, 
  450, 1718, 430, 706, 430, 1718, 454, 630, 
  426, 734, 430, 702, 434, 654, 370, 758, 
  434, 654, 454, 1746, 422, 682, 434, 702, 
  434, 1694, 418, 710, 434, 1766, 434, 1718, 
  446, 1722, 402, 730, 434, 1766, 434, 1766, 
  434, 650, 374, 1822, 438, 698, 434, 682, 
  454, 650, 430, 702, 434, 658, 450, 678, 
  374, 758, 434, 1718, 454, 682, 394, 1774, 
  434, 1762, 438, 1762, 434, 1766, 434, 1742, 
  458, 1714, 374, 758, 434, 1738, 438, 678, 
  422, 678, 410, 726, 438, 1762, 438, 678, 
  418, 1746, 434, 698, 438, 1762, 438, 678, 
  450, 650, 438, 1762, 438, 654, 454, 1742, 
  422, 678, 438, 1762, 434, 658, 450, 1742, 
  398, 1770, 434, 7502, 434, 1000};

// rawcode voor het instellen van de airco op 32 graden celcius
#define RAW_DATA_LEN 198
uint16_t rawData32[RAW_DATA_LEN]={
  6002, 7454, 458, 1722, 390, 1806, 426, 1770, 
  462, 1738, 486, 1714, 466, 1738, 454, 1722, 
  394, 1822, 406, 730, 462, 574, 502, 682, 
  430, 678, 462, 626, 370, 734, 462, 626, 
  418, 662, 486, 1714, 486, 1738, 462, 1714, 
  458, 1722, 390, 1774, 462, 1734, 462, 1674, 
  390, 1774, 462, 694, 466, 622, 374, 734, 
  462, 626, 454, 678, 398, 642, 526, 654, 
  454, 626, 458, 1738, 490, 626, 454, 1742, 
  422, 1754, 398, 1798, 462, 1710, 486, 1714, 
  482, 1718, 454, 678, 374, 1802, 458, 674, 
  458, 558, 514, 686, 462, 674, 462, 650, 
  450, 630, 462, 1738, 486, 626, 446, 658, 
  438, 1762, 462, 674, 458, 1670, 394, 1794, 
  438, 1738, 486, 674, 458, 1718, 454, 1694, 
  426, 706, 462, 1734, 462, 626, 370, 734, 
  462, 650, 458, 1722, 470, 1750, 370, 1822, 
  434, 1718, 486, 670, 438, 626, 422, 1794, 
  434, 1742, 458, 654, 458, 674, 374, 734, 
  462, 626, 370, 1794, 438, 1762, 462, 626, 
  458, 646, 430, 702, 466, 1734, 438, 650, 
  374, 1822, 406, 698, 442, 1758, 438, 678, 
  422, 678, 414, 1786, 438, 650, 458, 1742, 
  370, 730, 442, 1758, 438, 694, 442, 1710, 
  374, 1822, 402, 7530, 438, 1000};





void loop() {
   if (Serial.available() > 0) { //reads the input of the user from the serial monitor
     int dataIn = Serial.read();
  
  switch (dataIn) {// the rawcodes of the airco are send depending on the input of the user

      case '1':
mySender.send(rawDataOn,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F(" airco is aan "));
 break;
    
     case '2':
mySender.send(rawDataOff,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F(" airco is uit "));
break;
    
    case 'a':   
mySender.send(rawData16,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco  temperatuur is 16"));  
break;
    
   case 'b':
mySender.send(rawData17,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 17"));
break;

  case 'c':
mySender.send(rawData18,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 18"));
break;

 case 'd':
mySender.send(rawData19,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 19"));
break;

case 'e':
mySender.send(rawData20,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 20"));
break;

case 'f':
mySender.send(rawData21,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 21"));
break;

case 'g':
mySender.send(rawData22,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 22"));
break;

case 'h':
mySender.send(rawData23,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 23"));
break;

case 'i':
mySender.send(rawData24,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 24"));
break;

case 'j':
mySender.send(rawData25,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 25"));
break;

case 'k':
mySender.send(rawData26,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 26"));
break;

case 'l':
mySender.send(rawData27,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 27"));
break;

case 'm':
mySender.send(rawData28,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 28"));
break;

case 'n':
mySender.send(rawData29,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 29"));
break;

case 'o':
mySender.send(rawData30,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 30"));
break;

 case 'p':
mySender.send(rawData31,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 31"));
break;

 case 'q':
mySender.send(rawData32,RAW_DATA_LEN,38);//Pass the buffer,length, optionally frequency
Serial.println(F("de airco temperatuur is 32"));
break;
  }
 
}
}

  


 
