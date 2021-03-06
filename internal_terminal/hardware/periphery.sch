EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L solar_system_terminal_board-rescue:GND #PWR066
U 1 1 5543A3D7
P 4200 1950
F 0 "#PWR066" H 4200 1700 50  0001 C CNN
F 1 "GND" H 4200 1800 50  0000 C CNN
F 2 "" H 4200 1950 60  0000 C CNN
F 3 "" H 4200 1950 60  0000 C CNN
	1    4200 1950
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR067
U 1 1 5543A3F4
P 4400 1300
F 0 "#PWR067" H 4400 1150 50  0001 C CNN
F 1 "+5V" H 4400 1440 50  0000 C CNN
F 2 "" H 4400 1300 60  0000 C CNN
F 3 "" H 4400 1300 60  0000 C CNN
	1    4400 1300
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:BSS138 Q502
U 1 1 5543B3C1
P 6600 1500
F 0 "Q502" H 6800 1575 50  0000 L CNN
F 1 "BSS138" H 6800 1500 50  0000 L CNN
F 2 "Housings_SOT-23_SOT-143_TSOT-6:SOT-23_Handsoldering" H 6800 1425 50  0000 L CIN
F 3 "" H 6600 1500 50  0000 L CNN
	1    6600 1500
	0    -1   1    0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:BSS138 Q501
U 1 1 5543B3C7
P 6250 1900
F 0 "Q501" H 6450 1975 50  0000 L CNN
F 1 "BSS138" H 6450 1900 50  0000 L CNN
F 2 "Housings_SOT-23_SOT-143_TSOT-6:SOT-23_Handsoldering" H 6450 1825 50  0000 L CIN
F 3 "" H 6250 1900 50  0000 L CNN
	1    6250 1900
	0    -1   1    0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R502
U 1 1 5543B3CD
P 6100 1350
F 0 "R502" V 6180 1350 50  0000 C CNN
F 1 "10k" V 6100 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6030 1350 30  0001 C CNN
F 3 "" H 6100 1350 30  0000 C CNN
	1    6100 1350
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R501
U 1 1 5543B3D3
P 5900 1350
F 0 "R501" V 5980 1350 50  0000 C CNN
F 1 "10k" V 5900 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5830 1350 30  0001 C CNN
F 3 "" H 5900 1350 30  0000 C CNN
	1    5900 1350
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R503
U 1 1 5543B3D9
P 6900 1350
F 0 "R503" V 6980 1350 50  0000 C CNN
F 1 "10k" V 6900 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6830 1350 30  0001 C CNN
F 3 "" H 6900 1350 30  0000 C CNN
	1    6900 1350
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R504
U 1 1 5543B3DF
P 7100 1350
F 0 "R504" V 7180 1350 50  0000 C CNN
F 1 "10k" V 7100 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7030 1350 30  0001 C CNN
F 3 "" H 7100 1350 30  0000 C CNN
	1    7100 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 1700 6300 1100
Wire Wire Line
	6900 1100 6900 1200
Connection ~ 6900 1100
Wire Wire Line
	6650 1300 6650 1100
Connection ~ 6650 1100
Wire Wire Line
	5900 1500 5900 2000
Wire Wire Line
	6100 1500 6100 1600
Connection ~ 6100 1600
Wire Wire Line
	6450 2000 6900 2000
Wire Wire Line
	6900 2000 6900 1500
Wire Wire Line
	6800 1600 7100 1600
Wire Wire Line
	7100 1600 7100 1500
Wire Wire Line
	5700 1600 6100 1600
Wire Wire Line
	6100 1200 6100 1100
Wire Wire Line
	6100 1100 5900 1100
Wire Wire Line
	5900 900  5900 1100
Wire Wire Line
	5700 2000 5900 2000
Connection ~ 7100 1600
Wire Wire Line
	7200 1700 7100 1700
Wire Wire Line
	7100 1700 7100 2000
Connection ~ 6900 2000
Text GLabel 5700 1600 0    50   BiDi ~ 0
SDA
Text GLabel 5700 2000 0    50   Input ~ 0
SCL
Connection ~ 5900 2000
$Comp
L solar_system_terminal_board-rescue:GND #PWR068
U 1 1 5543B40B
P 8500 2150
F 0 "#PWR068" H 8500 1900 50  0001 C CNN
F 1 "GND" H 8500 2000 50  0000 C CNN
F 2 "" H 8500 2150 60  0000 C CNN
F 3 "" H 8500 2150 60  0000 C CNN
	1    8500 2150
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR069
U 1 1 5543B411
P 5900 900
F 0 "#PWR069" H 5900 750 50  0001 C CNN
F 1 "+5V" H 5900 1040 50  0000 C CNN
F 2 "" H 5900 900 60  0000 C CNN
F 3 "" H 5900 900 60  0000 C CNN
	1    5900 900 
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR070
U 1 1 5543B417
P 8500 900
F 0 "#PWR070" H 8500 750 50  0001 C CNN
F 1 "+5V" H 8500 1040 50  0000 C CNN
F 2 "" H 8500 900 60  0000 C CNN
F 3 "" H 8500 900 60  0000 C CNN
	1    8500 900 
	1    0    0    -1  
$EndComp
Connection ~ 5900 1100
Connection ~ 7100 1100
Wire Wire Line
	4400 1300 4400 1450
Wire Wire Line
	4200 1550 4200 1950
$Comp
L solar_system_terminal_board-rescue:23LCV1024-I_P MOD502
U 1 1 55650060
P 3300 3000
F 0 "MOD502" H 3550 3200 50  0000 C CNN
F 1 "23LCV1024-I/P" H 3600 3300 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm_LongPads" H 3300 3000 50  0001 C CNN
F 3 "" H 3300 3000 50  0000 C CNN
	1    3300 3000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR071
U 1 1 556505C6
P 4200 3450
F 0 "#PWR071" H 4200 3200 50  0001 C CNN
F 1 "GND" H 4200 3300 50  0000 C CNN
F 2 "" H 4200 3450 60  0000 C CNN
F 3 "" H 4200 3450 60  0000 C CNN
	1    4200 3450
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR072
U 1 1 556505EB
P 4400 2700
F 0 "#PWR072" H 4400 2550 50  0001 C CNN
F 1 "+5V" H 4400 2840 50  0000 C CNN
F 2 "" H 4400 2700 60  0000 C CNN
F 3 "" H 4400 2700 60  0000 C CNN
	1    4400 2700
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C502
U 1 1 55650610
P 4400 3200
F 0 "C502" H 4425 3300 50  0000 L CNN
F 1 "100n" H 4425 3100 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 4438 3050 30  0001 C CNN
F 3 "" H 4400 3200 60  0000 C CNN
	1    4400 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2900 4400 2900
Wire Wire Line
	4400 2700 4400 2900
Wire Wire Line
	4100 3200 4200 3200
Wire Wire Line
	4200 3000 4200 3200
Wire Wire Line
	4100 3000 4200 3000
Connection ~ 4200 3200
$Comp
L solar_system_terminal_board-rescue:GND #PWR073
U 1 1 55650869
P 4400 3450
F 0 "#PWR073" H 4400 3200 50  0001 C CNN
F 1 "GND" H 4400 3300 50  0000 C CNN
F 2 "" H 4400 3450 60  0000 C CNN
F 3 "" H 4400 3450 60  0000 C CNN
	1    4400 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3350 4400 3450
Connection ~ 4400 2900
Text GLabel 3000 3100 0    50   Input ~ 0
SCK
Text GLabel 3000 2900 0    50   Input ~ 0
MOSI
Text GLabel 3000 3000 0    50   Output ~ 0
MISO
Text GLabel 1950 3200 0    50   Input ~ 0
S.SRAM.CS
Wire Wire Line
	3100 2900 3000 2900
Wire Wire Line
	3100 3000 3000 3000
Wire Wire Line
	3100 3100 3000 3100
Wire Wire Line
	3100 3200 2200 3200
$Comp
L solar_system_terminal_board-rescue:DS3231 MOD503
U 1 1 55650DB2
P 3300 6100
F 0 "MOD503" H 3600 6200 50  0000 C CNN
F 1 "DS3231" H 3600 6300 50  0000 C CNN
F 2 "DS3231:DS3231_Socket_H" H 3300 6100 50  0001 C CNN
F 3 "" H 3300 6100 50  0000 C CNN
	1    3300 6100
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C504
U 1 1 556510FB
P 4400 6350
F 0 "C504" H 4425 6450 50  0000 L CNN
F 1 "100n" H 4425 6250 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 4438 6200 30  0001 C CNN
F 3 "" H 4400 6350 60  0000 C CNN
	1    4400 6350
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR074
U 1 1 55651319
P 4200 6650
F 0 "#PWR074" H 4200 6400 50  0001 C CNN
F 1 "GND" H 4200 6500 50  0000 C CNN
F 2 "" H 4200 6650 60  0000 C CNN
F 3 "" H 4200 6650 60  0000 C CNN
	1    4200 6650
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR075
U 1 1 556513BE
P 4400 5900
F 0 "#PWR075" H 4400 5750 50  0001 C CNN
F 1 "+5V" H 4400 6040 50  0000 C CNN
F 2 "" H 4400 5900 60  0000 C CNN
F 3 "" H 4400 5900 60  0000 C CNN
	1    4400 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 6400 4200 6400
Wire Wire Line
	4200 6400 4200 6650
Wire Wire Line
	4100 6100 4400 6100
Wire Wire Line
	4400 5900 4400 6100
$Comp
L solar_system_terminal_board-rescue:GND #PWR076
U 1 1 55652402
P 4400 6650
F 0 "#PWR076" H 4400 6400 50  0001 C CNN
F 1 "GND" H 4400 6500 50  0000 C CNN
F 2 "" H 4400 6650 60  0000 C CNN
F 3 "" H 4400 6650 60  0000 C CNN
	1    4400 6650
	1    0    0    -1  
$EndComp
Connection ~ 4400 6100
Wire Wire Line
	4400 6500 4400 6650
Text GLabel 3000 6100 0    50   BiDi ~ 0
SDA
Text GLabel 3000 6200 0    50   Input ~ 0
SCL
Text GLabel 3000 6300 0    50   Input ~ 0
RTC.SQW
NoConn ~ 3100 6400
Wire Wire Line
	3000 6100 3100 6100
Wire Wire Line
	3000 6200 3100 6200
Wire Wire Line
	3000 6300 3100 6300
$Comp
L solar_system_terminal_board-rescue:BMP180 MOD505
U 1 1 55653482
P 7400 1600
F 0 "MOD505" H 7700 1700 50  0000 C CNN
F 1 "BMP180" H 7700 1800 50  0000 C CNN
F 2 "BMP180:BMP180_Socket_H" H 7400 1600 50  0001 C CNN
F 3 "" H 7400 1600 50  0000 C CNN
	1    7400 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1900 8300 1900
Wire Wire Line
	6300 1100 6650 1100
Wire Wire Line
	8500 900  8500 1600
$Comp
L solar_system_terminal_board-rescue:nRF24L01 MOD504
U 1 1 556575E1
P 3650 4500
F 0 "MOD504" H 3650 4650 60  0000 C CNN
F 1 "nRF24L01" H 3650 4750 60  0000 C CNN
F 2 "nRF24L01:nRF24L01" H 3650 4500 60  0001 C CNN
F 3 "" H 3650 4500 60  0000 C CNN
	1    3650 4500
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR077
U 1 1 55657AB4
P 8300 2150
F 0 "#PWR077" H 8300 1900 50  0001 C CNN
F 1 "GND" H 8300 2000 50  0000 C CNN
F 2 "" H 8300 2150 60  0000 C CNN
F 3 "" H 8300 2150 60  0000 C CNN
	1    8300 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 1900 8300 2150
$Comp
L solar_system_terminal_board-rescue:C C506
U 1 1 55657DEF
P 8500 1900
F 0 "C506" H 8525 2000 50  0000 L CNN
F 1 "100n" H 8525 1800 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 8538 1750 30  0001 C CNN
F 3 "" H 8500 1900 60  0000 C CNN
	1    8500 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 2050 8500 2150
Connection ~ 8500 1600
$Comp
L solar_system_terminal_board-rescue:C C503
U 1 1 5565A1AD
P 4400 5150
F 0 "C503" H 4425 5250 50  0000 L CNN
F 1 "100n" H 4425 5050 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 4438 5000 30  0001 C CNN
F 3 "" H 4400 5150 60  0000 C CNN
	1    4400 5150
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR078
U 1 1 5565A1B3
P 4200 5350
F 0 "#PWR078" H 4200 5100 50  0001 C CNN
F 1 "GND" H 4200 5200 50  0000 C CNN
F 2 "" H 4200 5350 60  0000 C CNN
F 3 "" H 4200 5350 60  0000 C CNN
	1    4200 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4800 4200 4800
Wire Wire Line
	4200 4800 4200 5350
Wire Wire Line
	4100 4500 4400 4500
Wire Wire Line
	4400 4100 4400 4500
$Comp
L solar_system_terminal_board-rescue:GND #PWR079
U 1 1 5565A1C3
P 4400 5350
F 0 "#PWR079" H 4400 5100 50  0001 C CNN
F 1 "GND" H 4400 5200 50  0000 C CNN
F 2 "" H 4400 5350 60  0000 C CNN
F 3 "" H 4400 5350 60  0000 C CNN
	1    4400 5350
	1    0    0    -1  
$EndComp
Connection ~ 4400 4500
Wire Wire Line
	4400 5300 4400 5350
Text GLabel 4500 4600 2    50   Output ~ 0
MISO
Text GLabel 4500 4700 2    50   Output ~ 0
RADIO.IRQ/JTAG.TDO
Text GLabel 3050 4500 0    50   Input ~ 0
RADIO.CE/JTAG.TMS
Text GLabel 1950 4600 0    50   Input ~ 0
RADIO.CSN/JTAG.TCK
Text GLabel 3050 4700 0    50   Input ~ 0
SCK
Text GLabel 3050 4800 0    50   Input ~ 0
MOSI
Wire Wire Line
	3050 4500 3200 4500
Wire Wire Line
	1950 4600 2100 4600
Wire Wire Line
	3050 4700 3200 4700
Wire Wire Line
	3050 4800 3200 4800
Wire Wire Line
	4100 4600 4500 4600
Wire Wire Line
	4100 4700 4500 4700
$Comp
L solar_system_terminal_board-rescue:+3.3V #PWR080
U 1 1 5565BC56
P 4400 4100
F 0 "#PWR080" H 4400 3950 50  0001 C CNN
F 1 "+3.3V" H 4400 4240 50  0000 C CNN
F 2 "" H 4400 4100 60  0000 C CNN
F 3 "" H 4400 4100 60  0000 C CNN
	1    4400 4100
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:DHT22 MOD501
U 1 1 5565BFA4
P 3300 1450
F 0 "MOD501" H 3600 1600 50  0000 C CNN
F 1 "DHT22" H 3600 1700 50  0000 C CNN
F 2 "AM2302:AM2302_Socket_H" H 3300 1450 50  0001 C CNN
F 3 "" H 3300 1450 50  0000 C CNN
	1    3300 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 1550 4200 1550
$Comp
L solar_system_terminal_board-rescue:C C501
U 1 1 5565EE99
P 4400 1700
F 0 "C501" H 4425 1800 50  0000 L CNN
F 1 "100n" H 4425 1600 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 4438 1550 30  0001 C CNN
F 3 "" H 4400 1700 60  0000 C CNN
	1    4400 1700
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR081
U 1 1 5565EF4B
P 4400 1950
F 0 "#PWR081" H 4400 1700 50  0001 C CNN
F 1 "GND" H 4400 1800 50  0000 C CNN
F 2 "" H 4400 1950 60  0000 C CNN
F 3 "" H 4400 1950 60  0000 C CNN
	1    4400 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1450 4100 1450
Wire Wire Line
	4400 1950 4400 1850
Connection ~ 4400 1450
Text GLabel 3000 1450 0    60   BiDi ~ 0
DHT22.DATA
Wire Wire Line
	3000 1450 3100 1450
$Comp
L solar_system_terminal_board-rescue:XPort MOD506
U 1 1 55B3F2BB
P 8200 3800
F 0 "MOD506" H 8500 3950 50  0000 C CNN
F 1 "XPort" H 8500 4050 50  0000 C CNN
F 2 "Lantronix:XPort" H 8200 3800 50  0001 C CNN
F 3 "" H 8200 3800 50  0000 C CNN
	1    8200 3800
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C508
U 1 1 55B41DAB
P 9350 5000
F 0 "C508" H 9375 5100 50  0000 L CNN
F 1 "100n" H 9375 4900 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 9388 4850 30  0001 C CNN
F 3 "" H 9350 5000 60  0000 C CNN
	1    9350 5000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR082
U 1 1 55B41DB1
P 9150 5200
F 0 "#PWR082" H 9150 4950 50  0001 C CNN
F 1 "GND" H 9150 5050 50  0000 C CNN
F 2 "" H 9150 5200 60  0000 C CNN
F 3 "" H 9150 5200 60  0000 C CNN
	1    9150 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 4100 9150 4100
Wire Wire Line
	9150 4100 9150 5200
Wire Wire Line
	9050 3800 9350 3800
Wire Wire Line
	9350 3400 9350 3800
$Comp
L solar_system_terminal_board-rescue:GND #PWR083
U 1 1 55B41DBB
P 9350 5200
F 0 "#PWR083" H 9350 4950 50  0001 C CNN
F 1 "GND" H 9350 5050 50  0000 C CNN
F 2 "" H 9350 5200 60  0000 C CNN
F 3 "" H 9350 5200 60  0000 C CNN
	1    9350 5200
	1    0    0    -1  
$EndComp
Connection ~ 9350 3800
Wire Wire Line
	9350 5150 9350 5200
Text GLabel 9450 3900 2    50   Input ~ 0
TXD1
Text GLabel 9450 4000 2    50   Output ~ 0
RXD1
Wire Wire Line
	9050 3900 9450 3900
Wire Wire Line
	9050 4000 9450 4000
$Comp
L solar_system_terminal_board-rescue:+3.3V #PWR084
U 1 1 55B41DC7
P 9350 3400
F 0 "#PWR084" H 9350 3250 50  0001 C CNN
F 1 "+3.3V" H 9350 3540 50  0000 C CNN
F 2 "" H 9350 3400 60  0000 C CNN
F 3 "" H 9350 3400 60  0000 C CNN
	1    9350 3400
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R506
U 1 1 55B43AC7
P 7850 3600
F 0 "R506" V 7930 3600 50  0000 C CNN
F 1 "10k" V 7850 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7780 3600 30  0001 C CNN
F 3 "" H 7850 3600 30  0000 C CNN
	1    7850 3600
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C505
U 1 1 55B43ACE
P 7850 5000
F 0 "C505" H 7875 5100 50  0000 L CNN
F 1 "100n" H 7875 4900 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 7888 4850 30  0001 C CNN
F 3 "" H 7850 5000 60  0000 C CNN
	1    7850 5000
	-1   0    0    1   
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR085
U 1 1 55B43AD5
P 7850 5200
F 0 "#PWR085" H 7850 4950 50  0001 C CNN
F 1 "GND" H 7850 5050 50  0000 C CNN
F 2 "" H 7850 5200 60  0000 C CNN
F 3 "" H 7850 5200 60  0000 C CNN
	1    7850 5200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R505
U 1 1 55B43AE1
P 7600 5000
F 0 "R505" V 7680 5000 50  0000 C CNN
F 1 "300R" V 7600 5000 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7530 5000 30  0001 C CNN
F 3 "" H 7600 5000 30  0000 C CNN
	1    7600 5000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:SW_PUSH RESET501
U 1 1 55B43AE8
P 7600 4500
F 0 "RESET501" H 7750 4610 50  0000 C CNN
F 1 "SW_PUSH" H 7600 4420 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_Tactile_SPST_Angled" H 7600 4500 60  0001 C CNN
F 3 "" H 7600 4500 60  0000 C CNN
	1    7600 4500
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR086
U 1 1 55B43AEF
P 7600 5200
F 0 "#PWR086" H 7600 4950 50  0001 C CNN
F 1 "GND" H 7600 5050 50  0000 C CNN
F 2 "" H 7600 5200 60  0000 C CNN
F 3 "" H 7600 5200 60  0000 C CNN
	1    7600 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 3450 7850 3400
Wire Wire Line
	7850 5150 7850 5200
Wire Wire Line
	7850 3750 7850 3800
Connection ~ 7850 3800
Wire Wire Line
	7600 3400 7600 3450
Wire Wire Line
	7600 3750 7600 3800
Wire Wire Line
	7600 4800 7600 4850
Wire Wire Line
	7600 5150 7600 5200
Connection ~ 7600 3800
$Comp
L solar_system_terminal_board-rescue:D D501
U 1 1 55B43B06
P 7600 3600
F 0 "D501" H 7600 3700 50  0000 C CNN
F 1 "D" H 7600 3500 50  0000 C CNN
F 2 "Diodes_SMD:Diode-MiniMELF_Handsoldering" H 7600 3600 60  0001 C CNN
F 3 "" H 7600 3600 60  0000 C CNN
	1    7600 3600
	0    1    1    0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:+3.3V #PWR087
U 1 1 55B447AD
P 7850 3400
F 0 "#PWR087" H 7850 3250 50  0001 C CNN
F 1 "+3.3V" H 7850 3540 50  0000 C CNN
F 2 "" H 7850 3400 60  0000 C CNN
F 3 "" H 7850 3400 60  0000 C CNN
	1    7850 3400
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+3.3V #PWR088
U 1 1 55B4481E
P 7600 3400
F 0 "#PWR088" H 7600 3250 50  0001 C CNN
F 1 "+3.3V" H 7600 3540 50  0000 C CNN
F 2 "" H 7600 3400 60  0000 C CNN
F 3 "" H 7600 3400 60  0000 C CNN
	1    7600 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 3800 7850 3800
$Comp
L solar_system_terminal_board-rescue:CONN_01X03 P501
U 1 1 55B3F170
P 7300 4000
F 0 "P501" H 7300 4200 50  0000 C CNN
F 1 "CONN_01X03" V 7400 4000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 7300 4000 60  0001 C CNN
F 3 "" H 7300 4000 60  0000 C CNN
	1    7300 4000
	-1   0    0    1   
$EndComp
Wire Wire Line
	7500 3900 8000 3900
Wire Wire Line
	7500 4000 8000 4000
Wire Wire Line
	7500 4100 8000 4100
$Comp
L solar_system_terminal_board-rescue:CP C510
U 1 1 55B4FA2E
P 9700 5000
F 0 "C510" H 9725 5100 50  0000 L CNN
F 1 "10u" H 9725 4900 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 9738 4850 30  0001 C CNN
F 3 "" H 9700 5000 60  0000 C CNN
	1    9700 5000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR089
U 1 1 55B5078F
P 9700 5200
F 0 "#PWR089" H 9700 4950 50  0001 C CNN
F 1 "GND" H 9700 5050 50  0000 C CNN
F 2 "" H 9700 5200 60  0000 C CNN
F 3 "" H 9700 5200 60  0000 C CNN
	1    9700 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 5150 9700 5200
Wire Wire Line
	9700 4850 9700 4750
Wire Wire Line
	9700 4750 9350 4750
Connection ~ 9350 4750
$Comp
L solar_system_terminal_board-rescue:CP C509
U 1 1 55B5246A
P 4700 5150
F 0 "C509" H 4725 5250 50  0000 L CNN
F 1 "10u" H 4725 5050 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 4738 5000 30  0001 C CNN
F 3 "" H 4700 5150 60  0000 C CNN
	1    4700 5150
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR090
U 1 1 55B52769
P 4700 5350
F 0 "#PWR090" H 4700 5100 50  0001 C CNN
F 1 "GND" H 4700 5200 50  0000 C CNN
F 2 "" H 4700 5350 60  0000 C CNN
F 3 "" H 4700 5350 60  0000 C CNN
	1    4700 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 5300 4700 5350
Wire Wire Line
	4700 5000 4700 4900
Wire Wire Line
	4700 4900 4400 4900
Connection ~ 4400 4900
Wire Wire Line
	7100 1100 7100 1200
Wire Wire Line
	8300 1100 8300 1700
Wire Wire Line
	8300 1700 8200 1700
Wire Wire Line
	8200 1600 8500 1600
$Comp
L solar_system_terminal_board-rescue:R R508
U 1 1 55F2015C
P 2200 2950
F 0 "R508" V 2280 2950 50  0000 C CNN
F 1 "10k" V 2200 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2130 2950 30  0001 C CNN
F 3 "" H 2200 2950 30  0000 C CNN
	1    2200 2950
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R507
U 1 1 55F2026F
P 2100 4350
F 0 "R507" V 2180 4350 50  0000 C CNN
F 1 "10k" V 2100 4350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2030 4350 30  0001 C CNN
F 3 "" H 2100 4350 30  0000 C CNN
	1    2100 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3100 2200 3200
Connection ~ 2200 3200
Wire Wire Line
	2100 4500 2100 4600
Connection ~ 2100 4600
$Comp
L solar_system_terminal_board-rescue:+5V #PWR091
U 1 1 55F21473
P 2200 2700
F 0 "#PWR091" H 2200 2550 50  0001 C CNN
F 1 "+5V" H 2200 2840 50  0000 C CNN
F 2 "" H 2200 2700 60  0000 C CNN
F 3 "" H 2200 2700 60  0000 C CNN
	1    2200 2700
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR092
U 1 1 55F214D2
P 2100 4100
F 0 "#PWR092" H 2100 3950 50  0001 C CNN
F 1 "+5V" H 2100 4240 50  0000 C CNN
F 2 "" H 2100 4100 60  0000 C CNN
F 3 "" H 2100 4100 60  0000 C CNN
	1    2100 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2700 2200 2800
Wire Wire Line
	2100 4100 2100 4200
Wire Wire Line
	6900 1100 7100 1100
Wire Wire Line
	6650 1100 6900 1100
Wire Wire Line
	6100 1600 6400 1600
Wire Wire Line
	7100 1600 7200 1600
Wire Wire Line
	6900 2000 7100 2000
Wire Wire Line
	5900 2000 6050 2000
Wire Wire Line
	5900 1100 5900 1200
Wire Wire Line
	7100 1100 8300 1100
Wire Wire Line
	4200 3200 4200 3450
Wire Wire Line
	4400 2900 4400 3050
Wire Wire Line
	4400 6100 4400 6200
Wire Wire Line
	8500 1600 8500 1750
Wire Wire Line
	4400 4500 4400 4900
Wire Wire Line
	4400 1450 4400 1550
Wire Wire Line
	9350 3800 9350 4750
Wire Wire Line
	7850 3800 7850 4850
Wire Wire Line
	7850 3800 8000 3800
Wire Wire Line
	7600 3800 7600 4200
Wire Wire Line
	9350 4750 9350 4850
Wire Wire Line
	4400 4900 4400 5000
Wire Wire Line
	2200 3200 1950 3200
Wire Wire Line
	2100 4600 3200 4600
$EndSCHEMATC
