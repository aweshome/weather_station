EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
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
L solar_system_terminal_board-rescue:ATMEGA1284-P IC201
U 1 1 553F25E6
P 3600 4850
F 0 "IC201" H 2750 6730 40  0000 L BNN
F 1 "ATMEGA1284-P" H 4000 2900 40  0000 L BNN
F 2 "Housings_DIP:DIP-40_W15.24mm_LongPads" H 3600 4850 30  0000 C CIN
F 3 "" H 3600 4850 60  0000 C CNN
	1    3600 4850
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:Crystal Y201
U 1 1 553F25ED
P 2450 3750
F 0 "Y201" H 2450 3900 50  0000 C CNN
F 1 "Crystal" H 2450 3600 50  0000 C CNN
F 2 "Crystals:Crystal_HC49-U_Horizontal_Typ1" H 2450 3750 60  0001 C CNN
F 3 "" H 2450 3750 60  0000 C CNN
	1    2450 3750
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C202
U 1 1 553F25F4
P 2100 3550
F 0 "C202" H 2125 3650 50  0000 L CNN
F 1 "22p" H 2125 3450 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 2138 3400 30  0001 C CNN
F 3 "" H 2100 3550 60  0000 C CNN
	1    2100 3550
	0    1    1    0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C203
U 1 1 553F25FB
P 2100 3950
F 0 "C203" H 2125 4050 50  0000 L CNN
F 1 "22p" H 2125 3850 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 2138 3800 30  0001 C CNN
F 3 "" H 2100 3950 60  0000 C CNN
	1    2100 3950
	0    1    1    0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR01
U 1 1 553F2602
P 2450 4900
F 0 "#PWR01" H 2450 4650 50  0001 C CNN
F 1 "GND" H 2450 4750 50  0000 C CNN
F 2 "" H 2450 4900 60  0000 C CNN
F 3 "" H 2450 4900 60  0000 C CNN
	1    2450 4900
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR02
U 1 1 553F2608
P 1800 4200
F 0 "#PWR02" H 1800 3950 50  0001 C CNN
F 1 "GND" H 1800 4050 50  0000 C CNN
F 2 "" H 1800 4200 60  0000 C CNN
F 3 "" H 1800 4200 60  0000 C CNN
	1    1800 4200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR03
U 1 1 553F260E
P 3400 2000
F 0 "#PWR03" H 3400 1850 50  0001 C CNN
F 1 "+5V" H 3400 2140 50  0000 C CNN
F 2 "" H 3400 2000 60  0000 C CNN
F 3 "" H 3400 2000 60  0000 C CNN
	1    3400 2000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:INDUCTOR L201
U 1 1 553F261A
P 3800 2050
F 0 "L201" V 3750 2050 50  0000 C CNN
F 1 "10u" V 3900 2050 50  0000 C CNN
F 2 "Inductors_NEOSID:Neosid_Inductor_SM-NE45_SMD1812" H 3800 2050 60  0001 C CNN
F 3 "" H 3800 2050 60  0000 C CNN
	1    3800 2050
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C206
U 1 1 553F2621
P 3200 2450
F 0 "C206" H 3225 2550 50  0000 L CNN
F 1 "100n" H 3225 2350 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 3238 2300 30  0001 C CNN
F 3 "" H 3200 2450 60  0000 C CNN
	1    3200 2450
	-1   0    0    1   
$EndComp
$Comp
L solar_system_terminal_board-rescue:CP C205
U 1 1 553F2628
P 2950 2450
F 0 "C205" H 2650 2550 50  0000 L CNN
F 1 "10u" H 2700 2350 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 2988 2300 30  0001 C CNN
F 3 "" H 2950 2450 60  0000 C CNN
	1    2950 2450
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C207
U 1 1 553F262F
P 3950 2450
F 0 "C207" H 3975 2550 50  0000 L CNN
F 1 "100n" H 3975 2350 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 3988 2300 30  0001 C CNN
F 3 "" H 3950 2450 60  0000 C CNN
	1    3950 2450
	-1   0    0    1   
$EndComp
$Comp
L solar_system_terminal_board-rescue:CP C208
U 1 1 553F2636
P 4200 2450
F 0 "C208" H 4225 2550 50  0000 L CNN
F 1 "10u" H 4225 2350 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 4238 2300 30  0001 C CNN
F 3 "" H 4200 2450 60  0000 C CNN
	1    4200 2450
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR04
U 1 1 553F2653
P 2950 2700
F 0 "#PWR04" H 2950 2450 50  0001 C CNN
F 1 "GND" H 2950 2550 50  0000 C CNN
F 2 "" H 2950 2700 60  0000 C CNN
F 3 "" H 2950 2700 60  0000 C CNN
	1    2950 2700
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR05
U 1 1 553F2659
P 3200 2700
F 0 "#PWR05" H 3200 2450 50  0001 C CNN
F 1 "GND" H 3200 2550 50  0000 C CNN
F 2 "" H 3200 2700 60  0000 C CNN
F 3 "" H 3200 2700 60  0000 C CNN
	1    3200 2700
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR06
U 1 1 553F265F
P 3950 2700
F 0 "#PWR06" H 3950 2450 50  0001 C CNN
F 1 "GND" H 3950 2550 50  0000 C CNN
F 2 "" H 3950 2700 60  0000 C CNN
F 3 "" H 3950 2700 60  0000 C CNN
	1    3950 2700
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR07
U 1 1 553F2665
P 4200 2700
F 0 "#PWR07" H 4200 2450 50  0001 C CNN
F 1 "GND" H 4200 2550 50  0000 C CNN
F 2 "" H 4200 2700 60  0000 C CNN
F 3 "" H 4200 2700 60  0000 C CNN
	1    4200 2700
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C204
U 1 1 553F2670
P 2450 4650
F 0 "C204" H 2475 4750 50  0000 L CNN
F 1 "100n" H 2475 4550 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 2488 4500 30  0001 C CNN
F 3 "" H 2450 4650 60  0000 C CNN
	1    2450 4650
	-1   0    0    1   
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR08
U 1 1 553F267A
P 3400 6900
F 0 "#PWR08" H 3400 6650 50  0001 C CNN
F 1 "GND" H 3400 6750 50  0000 C CNN
F 2 "" H 3400 6900 60  0000 C CNN
F 3 "" H 3400 6900 60  0000 C CNN
	1    3400 6900
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR09
U 1 1 553F2680
P 3600 6900
F 0 "#PWR09" H 3600 6650 50  0001 C CNN
F 1 "GND" H 3600 6750 50  0000 C CNN
F 2 "" H 3600 6900 60  0000 C CNN
F 3 "" H 3600 6900 60  0000 C CNN
	1    3600 6900
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R202
U 1 1 553F2688
P 1550 2950
F 0 "R202" V 1630 2950 50  0000 C CNN
F 1 "10k" V 1550 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1480 2950 30  0001 C CNN
F 3 "" H 1550 2950 30  0000 C CNN
	1    1550 2950
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C201
U 1 1 553F268F
P 1550 3350
F 0 "C201" H 1575 3450 50  0000 L CNN
F 1 "100n" H 1575 3250 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 1588 3200 30  0001 C CNN
F 3 "" H 1550 3350 60  0000 C CNN
	1    1550 3350
	-1   0    0    1   
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR010
U 1 1 553F2696
P 1550 4200
F 0 "#PWR010" H 1550 3950 50  0001 C CNN
F 1 "GND" H 1550 4050 50  0000 C CNN
F 2 "" H 1550 4200 60  0000 C CNN
F 3 "" H 1550 4200 60  0000 C CNN
	1    1550 4200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR011
U 1 1 553F269C
P 1550 2750
F 0 "#PWR011" H 1550 2600 50  0001 C CNN
F 1 "+5V" H 1550 2890 50  0000 C CNN
F 2 "" H 1550 2750 60  0000 C CNN
F 3 "" H 1550 2750 60  0000 C CNN
	1    1550 2750
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R201
U 1 1 553F26AE
P 1300 4000
F 0 "R201" V 1380 4000 50  0000 C CNN
F 1 "330R" V 1300 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1230 4000 30  0001 C CNN
F 3 "" H 1300 4000 30  0000 C CNN
	1    1300 4000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:SW_PUSH RESET201
U 1 1 553F26B5
P 1300 3500
F 0 "RESET201" H 1450 3610 50  0000 C CNN
F 1 "SW_PUSH" H 1300 3420 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_Tactile_SPST_Angled" H 1300 3500 60  0001 C CNN
F 3 "" H 1300 3500 60  0000 C CNN
	1    1300 3500
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR012
U 1 1 553F26BC
P 1300 4200
F 0 "#PWR012" H 1300 3950 50  0001 C CNN
F 1 "GND" H 1300 4050 50  0000 C CNN
F 2 "" H 1300 4200 60  0000 C CNN
F 3 "" H 1300 4200 60  0000 C CNN
	1    1300 4200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR013
U 1 1 553F26C2
P 1300 2750
F 0 "#PWR013" H 1300 2600 50  0001 C CNN
F 1 "+5V" H 1300 2890 50  0000 C CNN
F 2 "" H 1300 2750 60  0000 C CNN
F 3 "" H 1300 2750 60  0000 C CNN
	1    1300 2750
	1    0    0    -1  
$EndComp
Text GLabel 4700 4550 2    50   Output ~ 0
MOSI
Text GLabel 4700 4650 2    50   Input ~ 0
MISO
Text GLabel 4700 4750 2    50   Output ~ 0
SCK
Text GLabel 4700 4950 2    50   Output ~ 0
SCL
Text GLabel 4700 5050 2    50   BiDi ~ 0
SDA
Text GLabel 4700 4150 2    50   Input ~ 0
LCD.CP2
Text GLabel 4700 4250 2    50   Input ~ 0
RTC.SQW
Text GLabel 4700 5150 2    50   Output ~ 0
RADIO.CSN/JTAG.TCK
Text GLabel 4700 5250 2    50   Output ~ 0
RADIO.CE/JTAG.TMS
Text GLabel 4700 5550 2    50   Output ~ 0
P.SRAM.CCLR
Text GLabel 4700 5650 2    50   Output ~ 0
P.SRAM.WE
Text GLabel 4700 5850 2    50   Input ~ 0
LCD.CP2
Text GLabel 4700 6250 2    50   Output ~ 0
LCD.DISP
Text GLabel 4700 6050 2    50   Input ~ 0
RXD1
Text GLabel 4700 6150 2    50   Output ~ 0
TXD1
Text GLabel 4700 6350 2    50   Output ~ 0
LCD.CP1
Text GLabel 4700 6450 2    50   Output ~ 0
LCD.S
Text GLabel 4700 6550 2    50   Output ~ 0
LCD.CP2
Wire Wire Line
	2250 3550 2450 3550
Wire Wire Line
	2450 3550 2450 3600
Wire Wire Line
	2450 3900 2450 3950
Connection ~ 2450 3550
Connection ~ 2450 3950
Wire Wire Line
	2250 3950 2450 3950
Wire Wire Line
	1950 3550 1800 3550
Wire Wire Line
	1800 3550 1800 3950
Wire Wire Line
	1800 3950 1950 3950
Connection ~ 1800 3950
Wire Wire Line
	3400 2000 3400 2050
Wire Wire Line
	2950 2050 3200 2050
Connection ~ 3400 2050
Wire Wire Line
	3600 2150 3950 2150
Wire Wire Line
	4200 2050 4200 2150
Wire Wire Line
	3200 2300 3200 2050
Connection ~ 3200 2050
Wire Wire Line
	3950 2300 3950 2150
Connection ~ 3950 2150
Connection ~ 4200 2150
Wire Wire Line
	4200 2600 4200 2700
Wire Wire Line
	3950 2600 3950 2700
Wire Wire Line
	3200 2600 3200 2700
Wire Wire Line
	2950 2600 2950 2700
Wire Wire Line
	2450 4250 2450 4350
Wire Wire Line
	2450 4800 2450 4900
Wire Wire Line
	3600 6900 3600 6850
Wire Wire Line
	3400 6900 3400 6850
Wire Wire Line
	1550 2800 1550 2750
Wire Wire Line
	1550 3500 1550 4200
Wire Wire Line
	1550 3100 1550 3150
Wire Wire Line
	1200 3150 1300 3150
Connection ~ 1550 3150
Wire Wire Line
	1300 2750 1300 2800
Wire Wire Line
	1300 3100 1300 3150
Wire Wire Line
	1300 3800 1300 3850
Wire Wire Line
	1300 4150 1300 4200
Connection ~ 1300 3150
Wire Wire Line
	4600 4550 4700 4550
Wire Wire Line
	4600 4650 4700 4650
Wire Wire Line
	4600 4750 4700 4750
Wire Wire Line
	4600 4950 4700 4950
Wire Wire Line
	4600 5050 4700 5050
Wire Wire Line
	4600 4150 4700 4150
Wire Wire Line
	4600 4250 4700 4250
Wire Wire Line
	4600 4450 4700 4450
Wire Wire Line
	4600 5150 4700 5150
Wire Wire Line
	4600 5250 4700 5250
Wire Wire Line
	4600 5350 4700 5350
Wire Wire Line
	4600 5450 4700 5450
Wire Wire Line
	4600 5550 4700 5550
Wire Wire Line
	4600 5650 4700 5650
Wire Wire Line
	4600 5850 4700 5850
Wire Wire Line
	4600 6050 4700 6050
Wire Wire Line
	4600 6150 4700 6150
Wire Wire Line
	4600 6350 4700 6350
Wire Wire Line
	4600 6450 4700 6450
Wire Wire Line
	4600 6550 4700 6550
Wire Wire Line
	4600 6250 4700 6250
Wire Wire Line
	4600 5950 4700 5950
Text GLabel 1200 3150 0    60   Input ~ 0
RESET
Wire Wire Line
	2950 2300 2950 2050
Wire Wire Line
	4200 2050 4100 2050
Text GLabel 4700 4450 2    50   Output ~ 0
LCD.ILUM
Wire Wire Line
	2100 4350 2450 4350
Wire Wire Line
	4700 4050 4600 4050
Text GLabel 4700 3150 2    50   Output ~ 0
A0
Text GLabel 4700 3250 2    50   Output ~ 0
A1
Text GLabel 4700 3350 2    50   Output ~ 0
A2
Text GLabel 4700 3450 2    50   Output ~ 0
A3
Text GLabel 4700 3550 2    50   Output ~ 0
A4
Text GLabel 4700 3650 2    50   Output ~ 0
A5
Text GLabel 4700 3750 2    50   Output ~ 0
A6
Text GLabel 4700 3850 2    50   Output ~ 0
A7
Wire Wire Line
	4600 3150 4700 3150
Wire Wire Line
	4600 3250 4700 3250
Wire Wire Line
	4600 3350 4700 3350
Wire Wire Line
	4600 3450 4700 3450
Wire Wire Line
	4600 3550 4700 3550
Wire Wire Line
	4600 3650 4700 3650
Wire Wire Line
	4600 3750 4700 3750
Wire Wire Line
	4600 3850 4700 3850
Wire Wire Line
	3600 2850 3600 2150
$Comp
L solar_system_terminal_board-rescue:PWR_FLAG #FLG014
U 1 1 554B5D65
P 2450 4250
F 0 "#FLG014" H 2450 4345 50  0001 C CNN
F 1 "PWR_FLAG" H 2450 4430 50  0000 C CNN
F 2 "" H 2450 4250 60  0000 C CNN
F 3 "" H 2450 4250 60  0000 C CNN
	1    2450 4250
	1    0    0    -1  
$EndComp
Connection ~ 2450 4350
$Comp
L solar_system_terminal_board-rescue:PWR_FLAG #FLG015
U 1 1 554B6360
P 4300 2000
F 0 "#FLG015" H 4300 2095 50  0001 C CNN
F 1 "PWR_FLAG" H 4300 2180 50  0000 C CNN
F 2 "" H 4300 2000 60  0000 C CNN
F 3 "" H 4300 2000 60  0000 C CNN
	1    4300 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2150 4300 2000
Text GLabel 4700 5450 2    50   Output ~ 0
JTAG.TDI
Text GLabel 4700 4050 2    50   Output ~ 0
S.SRAM.CS
Text GLabel 4700 5350 2    50   Input ~ 0
RADIO.IRQ/JTAG.TDO
Text GLabel 7250 5250 0    50   Input ~ 0
A0
Text GLabel 7250 4950 0    50   Input ~ 0
A1
Text GLabel 7250 4650 0    50   Input ~ 0
A2
Text GLabel 7250 3450 0    50   Input ~ 0
A3
Text GLabel 7250 3150 0    50   Input ~ 0
A4
Text GLabel 7250 2850 0    50   Input ~ 0
A5
Text GLabel 7250 1650 0    50   Input ~ 0
A6
Text GLabel 7250 1350 0    50   Input ~ 0
A7
Wire Wire Line
	7250 5250 9250 5250
Wire Wire Line
	7250 4950 9250 4950
Wire Wire Line
	7250 4650 9250 4650
Wire Wire Line
	7250 3150 9250 3150
Wire Wire Line
	7250 2850 9250 2850
Wire Wire Line
	7250 3450 9250 3450
Wire Wire Line
	7250 1650 9250 1650
Wire Wire Line
	7250 1350 9250 1350
Text GLabel 9250 1350 2    50   Output ~ 0
LCD.D7
Text GLabel 9250 1650 2    50   Output ~ 0
LCD.D6
Text GLabel 9250 2850 2    50   Output ~ 0
LCD.D5
Text GLabel 9250 3150 2    50   Output ~ 0
LCD.D4
Text GLabel 9250 3450 2    50   Output ~ 0
LCD.D3
Text GLabel 9250 4650 2    50   Output ~ 0
LCD.D2
Text GLabel 9250 4950 2    50   Output ~ 0
LCD.D1
Text GLabel 9250 5250 2    50   Output ~ 0
LCD.D0
$Comp
L solar_system_terminal_board-rescue:D D201
U 1 1 5561D46B
P 1300 2950
F 0 "D201" H 1300 3050 50  0000 C CNN
F 1 "D" H 1300 2850 50  0000 C CNN
F 2 "Diodes_SMD:Diode-MiniMELF_Handsoldering" H 1300 2950 60  0001 C CNN
F 3 "" H 1300 2950 60  0000 C CNN
	1    1300 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 4350 4700 4350
Text GLabel 4700 4350 2    60   BiDi ~ 0
DHT22.DATA
Text GLabel 4700 5950 2    50   Output ~ 0
P.SRAM.A16
$Comp
L solar_system_terminal_board-rescue:CONN_01X01 P201
U 1 1 55EA2D5A
P 4600 1000
F 0 "P201" H 4600 1100 50  0000 C CNN
F 1 "CONN_01X01" V 4700 1000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01" H 4600 1000 60  0001 C CNN
F 3 "" H 4600 1000 60  0000 C CNN
	1    4600 1000
	1    0    0    -1  
$EndComp
Text GLabel 3700 1000 0    50   Input ~ 0
JTAG.TDI
Wire Wire Line
	3700 1000 4400 1000
$Comp
L solar_system_terminal_board-rescue:CONN_01X01 P202
U 1 1 55EA5905
P 2100 4850
F 0 "P202" H 2100 4950 50  0000 C CNN
F 1 "CONN_01X01" V 2200 4850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01" H 2100 4850 60  0001 C CNN
F 3 "" H 2100 4850 60  0000 C CNN
	1    2100 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	2100 4650 2100 4350
$Comp
L solar_system_terminal_board-rescue:CONN_02X03 ISP201
U 1 1 55EB6034
P 2000 1450
F 0 "ISP201" H 2000 1650 50  0000 C CNN
F 1 "CONN_02X03" H 2000 1250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_2x03" H 2000 250 60  0001 C CNN
F 3 "" H 2000 250 60  0000 C CNN
	1    2000 1450
	1    0    0    -1  
$EndComp
Text GLabel 2350 1450 2    50   Input ~ 0
MOSI
Text GLabel 1650 1350 0    50   Output ~ 0
MISO
Text GLabel 1650 1450 0    50   Input ~ 0
SCK
Text GLabel 1650 1550 0    50   Input ~ 0
RESET
$Comp
L solar_system_terminal_board-rescue:+5V #PWR016
U 1 1 55EB68FF
P 2350 1250
F 0 "#PWR016" H 2350 1100 50  0001 C CNN
F 1 "+5V" H 2350 1390 50  0000 C CNN
F 2 "" H 2350 1250 60  0000 C CNN
F 3 "" H 2350 1250 60  0000 C CNN
	1    2350 1250
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR017
U 1 1 55EB6943
P 2350 1650
F 0 "#PWR017" H 2350 1400 50  0001 C CNN
F 1 "GND" H 2350 1500 50  0000 C CNN
F 2 "" H 2350 1650 60  0000 C CNN
F 3 "" H 2350 1650 60  0000 C CNN
	1    2350 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 1350 1750 1350
Wire Wire Line
	1650 1450 1750 1450
Wire Wire Line
	1650 1550 1750 1550
Wire Wire Line
	2250 1350 2350 1350
Wire Wire Line
	2350 1350 2350 1250
Wire Wire Line
	2250 1450 2350 1450
Wire Wire Line
	2250 1550 2350 1550
Wire Wire Line
	2350 1550 2350 1650
Wire Wire Line
	2450 3550 2600 3550
Wire Wire Line
	2450 3950 2600 3950
Wire Wire Line
	1800 3950 1800 4200
Wire Wire Line
	3400 2050 3400 2850
Wire Wire Line
	3400 2050 3500 2050
Wire Wire Line
	3200 2050 3400 2050
Wire Wire Line
	3950 2150 4200 2150
Wire Wire Line
	4200 2150 4200 2300
Wire Wire Line
	4200 2150 4300 2150
Wire Wire Line
	1550 3150 1550 3200
Wire Wire Line
	1550 3150 2600 3150
Wire Wire Line
	1300 3150 1550 3150
Wire Wire Line
	1300 3150 1300 3200
Wire Wire Line
	2450 4350 2450 4500
Wire Wire Line
	2450 4350 2600 4350
$EndSCHEMATC
