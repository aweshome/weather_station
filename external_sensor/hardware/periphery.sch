EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
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
L dht22:AM2302 MOD302
U 1 1 57636A8D
P 6550 2750
F 0 "MOD302" H 6850 2900 50  0000 C CNN
F 1 "AM2302" H 6850 3000 50  0000 C CNN
F 2 "My_modules:AM2302_Naked_H" H 6550 2750 50  0001 C CNN
F 3 "" H 6550 2750 50  0000 C CNN
	1    6550 2750
	1    0    0    -1  
$EndComp
$Comp
L nrf24l01:nRF24L01 MOD301
U 1 1 57636A94
P 3050 4650
F 0 "MOD301" H 3050 4800 60  0000 C CNN
F 1 "NRF24L01" H 3050 4900 60  0000 C CNN
F 2 "My_modules:nRF24L01" H 3050 4650 60  0001 C CNN
F 3 "" H 3050 4650 60  0000 C CNN
	1    3050 4650
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR014
U 1 1 57636A9B
P 7450 3100
F 0 "#PWR014" H 7450 3100 30  0001 C CNN
F 1 "GND" H 7450 3030 30  0001 C CNN
F 2 "" H 7450 3100 60  0000 C CNN
F 3 "" H 7450 3100 60  0000 C CNN
	1    7450 3100
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR015
U 1 1 57636AA1
P 3600 5450
F 0 "#PWR015" H 3600 5450 30  0001 C CNN
F 1 "GND" H 3600 5380 30  0001 C CNN
F 2 "" H 3600 5450 60  0000 C CNN
F 3 "" H 3600 5450 60  0000 C CNN
	1    3600 5450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR016
U 1 1 57636AA7
P 7450 2500
F 0 "#PWR016" H 7450 2600 30  0001 C CNN
F 1 "VCC" H 7450 2600 30  0000 C CNN
F 2 "" H 7450 2500 60  0000 C CNN
F 3 "" H 7450 2500 60  0000 C CNN
	1    7450 2500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR017
U 1 1 57636AAD
P 3600 3600
F 0 "#PWR017" H 3600 3700 30  0001 C CNN
F 1 "VCC" H 3600 3700 30  0000 C CNN
F 2 "" H 3600 3600 60  0000 C CNN
F 3 "" H 3600 3600 60  0000 C CNN
	1    3600 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2750 7350 2750
Wire Wire Line
	7450 2500 7450 2750
Wire Wire Line
	7350 2850 7450 2850
Wire Wire Line
	7450 2850 7450 3100
Wire Wire Line
	3500 4650 3600 4650
Wire Wire Line
	3500 4950 3600 4950
Wire Wire Line
	3600 4950 3600 5450
$Comp
L solar_system_external_unit_board_2-rescue:CP-RESCUE-solar_system_external_unit_board_2 C302
U 1 1 57636ABB
P 7600 2800
F 0 "C302" H 7650 2900 40  0000 L CNN
F 1 "10u" H 7650 2700 40  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 7700 2650 30  0001 C CNN
F 3 "~" H 7600 2800 300 0000 C CNN
	1    7600 2800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR018
U 1 1 57636AC2
P 7600 2500
F 0 "#PWR018" H 7600 2600 30  0001 C CNN
F 1 "VCC" H 7600 2600 30  0000 C CNN
F 2 "" H 7600 2500 60  0000 C CNN
F 3 "" H 7600 2500 60  0000 C CNN
	1    7600 2500
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR019
U 1 1 57636AC8
P 7600 3100
F 0 "#PWR019" H 7600 3100 30  0001 C CNN
F 1 "GND" H 7600 3030 30  0001 C CNN
F 2 "" H 7600 3100 60  0000 C CNN
F 3 "" H 7600 3100 60  0000 C CNN
	1    7600 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 2600 7600 2500
Wire Wire Line
	7600 3000 7600 3100
$Comp
L solar_system_external_unit_board_2-rescue:CP-RESCUE-solar_system_external_unit_board_2 C301
U 1 1 57636AD0
P 4200 4950
F 0 "C301" H 4250 5050 40  0000 L CNN
F 1 "10u" H 4250 4850 40  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 4300 4800 30  0001 C CNN
F 3 "~" H 4200 4950 300 0000 C CNN
	1    4200 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 5150 4200 5450
Text GLabel 3600 4750 2    50   Output ~ 0
nRF_MISO
Text GLabel 3600 4850 2    50   Output ~ 0
nRF_IRQ
Wire Wire Line
	3500 4750 3600 4750
Wire Wire Line
	3500 4850 3600 4850
Text GLabel 2500 4650 0    50   Input ~ 0
nRF_CE
Text GLabel 2500 4750 0    50   Input ~ 0
nRF_CSN
Text GLabel 2500 4850 0    50   Input ~ 0
nRF_SCK
Text GLabel 2500 4950 0    50   Input ~ 0
nRF_MOSI
Wire Wire Line
	2500 4650 2600 4650
Wire Wire Line
	2500 4750 2600 4750
Wire Wire Line
	2500 4850 2600 4850
Wire Wire Line
	2500 4950 2600 4950
Text GLabel 6250 2750 0    50   BiDi ~ 0
DHT_DATA
Wire Wire Line
	6250 2750 6350 2750
$Comp
L Device:R R301
U 1 1 57772C65
P 2950 4100
F 0 "R301" V 3030 4100 50  0000 C CNN
F 1 "100R" V 2950 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 2880 4100 50  0001 C CNN
F 3 "" H 2950 4100 50  0000 C CNN
	1    2950 4100
	0    1    1    0   
$EndComp
$Comp
L Device:R R302
U 1 1 577730AF
P 3200 3850
F 0 "R302" V 3280 3850 50  0000 C CNN
F 1 "100k" V 3200 3850 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3130 3850 50  0001 C CNN
F 3 "" H 3200 3850 50  0000 C CNN
	1    3200 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 4100 3200 4100
Text GLabel 2500 4100 0    50   Input ~ 0
nRF_PWR
Wire Wire Line
	2500 4100 2800 4100
$Comp
L power:PWR_FLAG #FLG020
U 1 1 57788765
P 4200 4450
F 0 "#FLG020" H 4200 4720 30  0001 C CNN
F 1 "PWR_FLAG" H 4200 4680 30  0000 C CNN
F 2 "" H 4200 4450 60  0000 C CNN
F 3 "" H 4200 4450 60  0000 C CNN
	1    4200 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3900 3600 3600
Wire Wire Line
	3200 4000 3200 4100
Connection ~ 3200 4100
Wire Wire Line
	3600 4300 3600 4650
Wire Wire Line
	4200 4450 4200 4650
Connection ~ 3600 4650
$Comp
L power:VCC #PWR021
U 1 1 5778A70F
P 3200 3600
F 0 "#PWR021" H 3200 3700 30  0001 C CNN
F 1 "VCC" H 3200 3700 30  0000 C CNN
F 2 "" H 3200 3600 60  0000 C CNN
F 3 "" H 3200 3600 60  0000 C CNN
	1    3200 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 3700 3200 3600
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR022
U 1 1 5778AD44
P 4200 5450
F 0 "#PWR022" H 4200 5450 30  0001 C CNN
F 1 "GND" H 4200 5380 30  0001 C CNN
F 2 "" H 4200 5450 60  0000 C CNN
F 3 "" H 4200 5450 60  0000 C CNN
	1    4200 5450
	1    0    0    -1  
$EndComp
Connection ~ 4200 4650
$Comp
L Device:Q_PMOS_GSD Q301
U 1 1 5778042B
P 3500 4100
F 0 "Q301" H 3800 4150 50  0000 R CNN
F 1 "Q_PMOS_GSD" H 4150 4050 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3700 4200 50  0001 C CNN
F 3 "" H 3500 4100 50  0000 C CNN
	1    3500 4100
	1    0    0    1   
$EndComp
Wire Wire Line
	3200 4100 3300 4100
Wire Wire Line
	3600 4650 4200 4650
Wire Wire Line
	4200 4650 4200 4750
$EndSCHEMATC
