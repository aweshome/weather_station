EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
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
L solar_system_terminal_board-rescue:PC817 U404
U 1 1 553F5EEB
P 7050 1800
F 0 "U404" H 6850 2000 50  0000 L CNN
F 1 "PC817" H 7050 2000 50  0000 L CNN
F 2 "Housings_DIP:DIP-4_W7.62mm_LongPads" H 6850 1600 50  0000 L CIN
F 3 "" H 7050 1800 50  0000 L CNN
	1    7050 1800
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R401
U 1 1 553F5F8F
P 6500 1700
F 0 "R401" V 6580 1700 50  0000 C CNN
F 1 "160R" V 6500 1700 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6430 1700 30  0001 C CNN
F 3 "" H 6500 1700 30  0000 C CNN
	1    6500 1700
	0    1    1    0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R402
U 1 1 553F5FD0
P 7450 2450
F 0 "R402" V 7530 2450 50  0000 C CNN
F 1 "100k" V 7450 2450 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7380 2450 30  0001 C CNN
F 3 "" H 7450 2450 30  0000 C CNN
	1    7450 2450
	-1   0    0    1   
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R403
U 1 1 553F6108
P 7850 1250
F 0 "R403" V 7930 1250 50  0000 C CNN
F 1 "10R" V 7850 1250 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7780 1250 30  0001 C CNN
F 3 "" H 7850 1250 30  0000 C CNN
	1    7850 1250
	-1   0    0    1   
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR040
U 1 1 553F620B
P 7450 2750
F 0 "#PWR040" H 7450 2500 50  0001 C CNN
F 1 "GND" H 7450 2600 50  0000 C CNN
F 2 "" H 7450 2750 60  0000 C CNN
F 3 "" H 7450 2750 60  0000 C CNN
	1    7450 2750
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR041
U 1 1 553F6222
P 7850 2750
F 0 "#PWR041" H 7850 2500 50  0001 C CNN
F 1 "GND" H 7850 2600 50  0000 C CNN
F 2 "" H 7850 2750 60  0000 C CNN
F 3 "" H 7850 2750 60  0000 C CNN
	1    7850 2750
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR042
U 1 1 553F6237
P 6700 2750
F 0 "#PWR042" H 6700 2500 50  0001 C CNN
F 1 "GND" H 6700 2600 50  0000 C CNN
F 2 "" H 6700 2750 60  0000 C CNN
F 3 "" H 6700 2750 60  0000 C CNN
	1    6700 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 1700 6750 1700
Wire Wire Line
	6700 2750 6700 1900
Wire Wire Line
	6700 1900 6750 1900
Wire Wire Line
	7450 2750 7450 2600
Wire Wire Line
	7450 2300 7450 1900
Wire Wire Line
	7350 1900 7450 1900
Connection ~ 7450 1900
Wire Wire Line
	7850 1550 7850 1650
$Comp
L solar_system_terminal_board-rescue:POT-RESCUE-solar_system_terminal_board RV401
U 1 1 553F645D
P 8700 1900
F 0 "RV401" H 8700 1800 50  0000 C CNN
F 1 "POT" H 8700 1900 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_3296W_3-8Zoll_Inline_ScrewUp" H 8700 1900 60  0001 C CNN
F 3 "" H 8700 1900 60  0000 C CNN
	1    8700 1900
	0    1    -1   0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR043
U 1 1 553F64FE
P 8700 2750
F 0 "#PWR043" H 8700 2500 50  0001 C CNN
F 1 "GND" H 8700 2600 50  0000 C CNN
F 2 "" H 8700 2750 60  0000 C CNN
F 3 "" H 8700 2750 60  0000 C CNN
	1    8700 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 2150 8700 2750
Wire Wire Line
	7850 2600 7850 2750
Wire Wire Line
	7850 2050 7850 2300
Wire Wire Line
	8700 1000 8700 1650
Wire Wire Line
	7450 1000 7450 1700
Wire Wire Line
	7450 1700 7350 1700
Wire Wire Line
	8850 1900 9000 1900
Text GLabel 9000 1900 2    50   Output ~ 0
LCD.VEE
Wire Wire Line
	6250 1700 6350 1700
$Comp
L solar_system_terminal_board-rescue:CONN_01X02 P401
U 1 1 553F6C8C
P 8100 1500
F 0 "P401" H 8100 1650 50  0000 C CNN
F 1 "CONN_01X02" V 8200 1500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x02" H 8100 1500 60  0001 C CNN
F 3 "" H 8100 1500 60  0000 C CNN
	1    8100 1500
	1    0    0    1   
$EndComp
Wire Wire Line
	7850 1000 7850 1100
Text GLabel 8050 3950 0    50   Input ~ 0
LCD.S
Text GLabel 8050 4050 0    50   Input ~ 0
LCD.CP1
Text GLabel 8050 4150 0    50   Input ~ 0
LCD.CP2
Wire Wire Line
	8050 3950 9800 3950
Wire Wire Line
	8050 4050 9800 4050
Wire Wire Line
	8050 4150 9800 4150
Text GLabel 8050 4550 0    50   Input ~ 0
LCD.VEE
Text GLabel 8050 4250 0    50   Input ~ 0
LCD.DISP
Wire Wire Line
	8050 4550 8150 4550
Wire Wire Line
	8050 4250 9100 4250
Text GLabel 6250 1700 0    50   Input ~ 0
LCD.ILUM
$Comp
L solar_system_terminal_board-rescue:+5V #PWR044
U 1 1 5540D828
P 8400 3850
F 0 "#PWR044" H 8400 3700 50  0001 C CNN
F 1 "+5V" H 8400 3990 50  0000 C CNN
F 2 "" H 8400 3850 60  0000 C CNN
F 3 "" H 8400 3850 60  0000 C CNN
	1    8400 3850
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:R R405
U 1 1 5540D848
P 8150 4850
F 0 "R405" V 8230 4850 50  0000 C CNN
F 1 "10k" V 8150 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 8080 4850 30  0001 C CNN
F 3 "" H 8150 4850 30  0000 C CNN
	1    8150 4850
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C404
U 1 1 5540D884
P 8650 4850
F 0 "C404" H 8675 4950 50  0000 L CNN
F 1 "100n" H 8675 4750 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 8688 4700 30  0001 C CNN
F 3 "" H 8650 4850 60  0000 C CNN
	1    8650 4850
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:CP C403
U 1 1 5540D8BF
P 8400 4850
F 0 "C403" H 8425 4950 50  0000 L CNN
F 1 "10u" H 8425 4750 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 8438 4700 30  0001 C CNN
F 3 "" H 8400 4850 60  0000 C CNN
	1    8400 4850
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR045
U 1 1 5540E3A7
P 8150 5100
F 0 "#PWR045" H 8150 4850 50  0001 C CNN
F 1 "GND" H 8150 4950 50  0000 C CNN
F 2 "" H 8150 5100 60  0000 C CNN
F 3 "" H 8150 5100 60  0000 C CNN
	1    8150 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 4700 8150 4550
Connection ~ 8150 4550
Wire Wire Line
	8150 5100 8150 5000
Wire Wire Line
	8400 3850 8400 4350
$Comp
L solar_system_terminal_board-rescue:GND #PWR046
U 1 1 5540EFBD
P 8850 5100
F 0 "#PWR046" H 8850 4850 50  0001 C CNN
F 1 "GND" H 8850 4950 50  0000 C CNN
F 2 "" H 8850 5100 60  0000 C CNN
F 3 "" H 8850 5100 60  0000 C CNN
	1    8850 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 4450 8850 4450
Wire Wire Line
	8850 4450 8850 5100
$Comp
L solar_system_terminal_board-rescue:GND #PWR047
U 1 1 5540F7B6
P 8650 5100
F 0 "#PWR047" H 8650 4850 50  0001 C CNN
F 1 "GND" H 8650 4950 50  0000 C CNN
F 2 "" H 8650 5100 60  0000 C CNN
F 3 "" H 8650 5100 60  0000 C CNN
	1    8650 5100
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR048
U 1 1 5540F7DF
P 8400 5100
F 0 "#PWR048" H 8400 4850 50  0001 C CNN
F 1 "GND" H 8400 4950 50  0000 C CNN
F 2 "" H 8400 5100 60  0000 C CNN
F 3 "" H 8400 5100 60  0000 C CNN
	1    8400 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 5000 8400 5100
Wire Wire Line
	8650 5000 8650 5100
Wire Wire Line
	8650 4700 8650 4350
Connection ~ 8650 4350
Wire Wire Line
	8400 4350 8650 4350
Connection ~ 8400 4350
Wire Wire Line
	9650 5350 9800 5350
Wire Wire Line
	9650 5250 9800 5250
Wire Wire Line
	9650 5150 9800 5150
Wire Wire Line
	9650 5050 9800 5050
Wire Wire Line
	9650 4950 9800 4950
Wire Wire Line
	9650 4850 9800 4850
Wire Wire Line
	9650 4750 9800 4750
Wire Wire Line
	9650 4650 9800 4650
$Comp
L solar_system_terminal_board-rescue:74LS393 U401
U 1 1 55407817
P 2500 1700
F 0 "U401" H 2650 1950 60  0000 C CNN
F 1 "74LS393" H 2700 1450 60  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2500 1700 60  0001 C CNN
F 3 "" H 2500 1700 60  0000 C CNN
	1    2500 1700
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:74LS393 U401
U 2 1 55407898
P 2500 2600
F 0 "U401" H 2650 2850 60  0000 C CNN
F 1 "74LS393" H 2700 2350 60  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2500 2600 60  0001 C CNN
F 3 "" H 2500 2600 60  0000 C CNN
	2    2500 2600
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:74LS393 U402
U 1 1 55407902
P 2500 3500
F 0 "U402" H 2650 3750 60  0000 C CNN
F 1 "74LS393" H 2700 3250 60  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2500 3500 60  0001 C CNN
F 3 "" H 2500 3500 60  0000 C CNN
	1    2500 3500
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:74LS393 U402
U 2 1 55407975
P 2500 4400
F 0 "U402" H 2650 4650 60  0000 C CNN
F 1 "74LS393" H 2700 4150 60  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm_LongPads" H 2500 4400 60  0001 C CNN
F 3 "" H 2500 4400 60  0000 C CNN
	2    2500 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 4550 1800 4550
Wire Wire Line
	1600 1850 1600 2750
Wire Wire Line
	1500 1850 1600 1850
Wire Wire Line
	1800 2750 1600 2750
Connection ~ 1600 2750
Wire Wire Line
	1800 3650 1600 3650
Connection ~ 1600 3650
Wire Wire Line
	3300 1850 3300 2150
Wire Wire Line
	3300 2150 1700 2150
Wire Wire Line
	1700 2150 1700 2450
Wire Wire Line
	1700 2450 1800 2450
Wire Wire Line
	3300 2750 3300 3050
Wire Wire Line
	3300 3050 1700 3050
Wire Wire Line
	1700 3050 1700 3350
Wire Wire Line
	1700 3350 1800 3350
Wire Wire Line
	3200 3650 3300 3650
Wire Wire Line
	3300 3650 3300 3950
Wire Wire Line
	3300 3950 1700 3950
Wire Wire Line
	1700 3950 1700 4250
Wire Wire Line
	1700 4250 1800 4250
Text GLabel 1500 1850 0    50   Input ~ 0
P.SRAM.CCLR
Text GLabel 1500 1550 0    50   Input ~ 0
LCD.CP2
Wire Wire Line
	1800 1550 1500 1550
Connection ~ 1600 1850
$Comp
L solar_system_terminal_board-rescue:+5V #PWR049
U 1 1 55415431
P 2500 1450
F 0 "#PWR049" H 2500 1300 50  0001 C CNN
F 1 "+5V" H 2500 1590 50  0000 C CNN
F 2 "" H 2500 1450 60  0000 C CNN
F 3 "" H 2500 1450 60  0000 C CNN
	1    2500 1450
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR050
U 1 1 55415A06
P 2500 2350
F 0 "#PWR050" H 2500 2200 50  0001 C CNN
F 1 "+5V" H 2500 2490 50  0000 C CNN
F 2 "" H 2500 2350 60  0000 C CNN
F 3 "" H 2500 2350 60  0000 C CNN
	1    2500 2350
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR051
U 1 1 55415E13
P 2500 3250
F 0 "#PWR051" H 2500 3100 50  0001 C CNN
F 1 "+5V" H 2500 3390 50  0000 C CNN
F 2 "" H 2500 3250 60  0000 C CNN
F 3 "" H 2500 3250 60  0000 C CNN
	1    2500 3250
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR052
U 1 1 55415E44
P 2500 4150
F 0 "#PWR052" H 2500 4000 50  0001 C CNN
F 1 "+5V" H 2500 4290 50  0000 C CNN
F 2 "" H 2500 4150 60  0000 C CNN
F 3 "" H 2500 4150 60  0000 C CNN
	1    2500 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 1450 2500 1500
Wire Wire Line
	2500 2350 2500 2400
Wire Wire Line
	2500 3250 2500 3300
Wire Wire Line
	2500 4150 2500 4200
$Comp
L solar_system_terminal_board-rescue:GND #PWR053
U 1 1 554178C3
P 2500 1950
F 0 "#PWR053" H 2500 1700 50  0001 C CNN
F 1 "GND" H 2500 1800 50  0000 C CNN
F 2 "" H 2500 1950 60  0000 C CNN
F 3 "" H 2500 1950 60  0000 C CNN
	1    2500 1950
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR054
U 1 1 554180F8
P 2500 2850
F 0 "#PWR054" H 2500 2600 50  0001 C CNN
F 1 "GND" H 2500 2700 50  0000 C CNN
F 2 "" H 2500 2850 60  0000 C CNN
F 3 "" H 2500 2850 60  0000 C CNN
	1    2500 2850
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR055
U 1 1 554185FC
P 2500 3750
F 0 "#PWR055" H 2500 3500 50  0001 C CNN
F 1 "GND" H 2500 3600 50  0000 C CNN
F 2 "" H 2500 3750 60  0000 C CNN
F 3 "" H 2500 3750 60  0000 C CNN
	1    2500 3750
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR056
U 1 1 554188EC
P 2500 4650
F 0 "#PWR056" H 2500 4400 50  0001 C CNN
F 1 "GND" H 2500 4500 50  0000 C CNN
F 2 "" H 2500 4650 60  0000 C CNN
F 3 "" H 2500 4650 60  0000 C CNN
	1    2500 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 4650 2500 4600
Wire Wire Line
	2500 3750 2500 3700
Wire Wire Line
	2500 2800 2500 2850
Wire Wire Line
	2500 1900 2500 1950
$Comp
L solar_system_terminal_board-rescue:MS628128-RESCUE-solar_system_terminal_board U403
U 1 1 5541A243
P 5800 5700
AR Path="/5541A243" Ref="U403"  Part="1" 
AR Path="/553F5EE0/5541A243" Ref="U403"  Part="1" 
F 0 "U403" H 5800 6900 60  0000 C CNN
F 1 "MS628128" H 5870 4500 60  0000 C CNN
F 2 "Housings_DIP:DIP-32_W15.24mm_LongPads" H 5800 5700 60  0001 C CNN
F 3 "" H 5800 5700 60  0000 C CNN
	1    5800 5700
	1    0    0    -1  
$EndComp
Connection ~ 3300 1850
Connection ~ 3300 2750
Wire Wire Line
	3200 1550 3500 1550
Wire Wire Line
	3500 1550 3500 4650
Wire Wire Line
	3500 4650 5100 4650
Wire Wire Line
	3200 1650 3600 1650
Wire Wire Line
	3600 1650 3600 4750
Wire Wire Line
	3600 4750 5100 4750
Wire Wire Line
	3200 1750 3700 1750
Wire Wire Line
	3700 1750 3700 4850
Wire Wire Line
	3700 4850 5100 4850
Wire Wire Line
	3200 1850 3300 1850
Wire Wire Line
	3800 1850 3800 4950
Wire Wire Line
	3800 4950 5100 4950
Wire Wire Line
	3200 2450 3900 2450
Wire Wire Line
	3900 2450 3900 5050
Wire Wire Line
	3900 5050 5100 5050
Wire Wire Line
	3200 2550 4000 2550
Wire Wire Line
	4000 2550 4000 5150
Wire Wire Line
	4000 5150 5100 5150
Wire Wire Line
	3200 2650 4100 2650
Wire Wire Line
	4100 2650 4100 5250
Wire Wire Line
	4100 5250 5100 5250
Wire Wire Line
	3200 2750 3300 2750
Wire Wire Line
	4200 2750 4200 5350
Wire Wire Line
	4200 5350 5100 5350
Wire Wire Line
	3200 3350 4300 3350
Wire Wire Line
	4300 3350 4300 5450
Wire Wire Line
	4300 5450 5100 5450
Wire Wire Line
	3200 3450 4400 3450
Wire Wire Line
	4400 3450 4400 5550
Wire Wire Line
	4400 5550 5100 5550
Wire Wire Line
	3200 3550 4500 3550
Wire Wire Line
	4500 3550 4500 5650
Wire Wire Line
	4500 5650 5100 5650
Wire Wire Line
	5100 5750 4600 5750
Wire Wire Line
	4600 5750 4600 3650
Connection ~ 3300 3650
Wire Wire Line
	3200 4250 4700 4250
Wire Wire Line
	4700 4250 4700 5850
Wire Wire Line
	4700 5850 5100 5850
Wire Wire Line
	3200 4350 4800 4350
Wire Wire Line
	4800 4350 4800 5950
Wire Wire Line
	4800 5950 5100 5950
Wire Wire Line
	3200 4450 4900 4450
Wire Wire Line
	4900 4450 4900 6050
Wire Wire Line
	4900 6050 5100 6050
Wire Wire Line
	3200 4550 5000 4550
Wire Wire Line
	5000 4550 5000 6150
Wire Wire Line
	5000 6150 5100 6150
$Comp
L solar_system_terminal_board-rescue:GND #PWR057
U 1 1 5542813C
P 5000 7000
F 0 "#PWR057" H 5000 6750 50  0001 C CNN
F 1 "GND" H 5000 6850 50  0000 C CNN
F 2 "" H 5000 7000 60  0000 C CNN
F 3 "" H 5000 7000 60  0000 C CNN
	1    5000 7000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR058
U 1 1 5542816F
P 5800 7000
F 0 "#PWR058" H 5800 6750 50  0001 C CNN
F 1 "GND" H 5800 6850 50  0000 C CNN
F 2 "" H 5800 7000 60  0000 C CNN
F 3 "" H 5800 7000 60  0000 C CNN
	1    5800 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 6450 5000 6450
Wire Wire Line
	5000 6450 5000 6650
Wire Wire Line
	5100 6650 5000 6650
Connection ~ 5000 6650
Wire Wire Line
	5800 6850 5800 7000
$Comp
L solar_system_terminal_board-rescue:+5V #PWR059
U 1 1 55429257
P 5800 3700
F 0 "#PWR059" H 5800 3550 50  0001 C CNN
F 1 "+5V" H 5800 3840 50  0000 C CNN
F 2 "" H 5800 3700 60  0000 C CNN
F 3 "" H 5800 3700 60  0000 C CNN
	1    5800 3700
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR060
U 1 1 55429E2E
P 4900 6450
F 0 "#PWR060" H 4900 6300 50  0001 C CNN
F 1 "+5V" H 4900 6590 50  0000 C CNN
F 2 "" H 4900 6450 60  0000 C CNN
F 3 "" H 4900 6450 60  0000 C CNN
	1    4900 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 6550 4900 6550
Wire Wire Line
	4900 6550 4900 6450
$Comp
L solar_system_terminal_board-rescue:C C401
U 1 1 5542D372
P 6300 4050
F 0 "C401" H 6325 4150 50  0000 L CNN
F 1 "100n" H 6325 3950 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 6338 3900 30  0001 C CNN
F 3 "" H 6300 4050 60  0000 C CNN
	1    6300 4050
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:CP C402
U 1 1 5542D40C
P 6600 4050
F 0 "C402" H 6625 4150 50  0000 L CNN
F 1 "10u" H 6625 3950 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 6638 3900 30  0001 C CNN
F 3 "" H 6600 4050 60  0000 C CNN
	1    6600 4050
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR061
U 1 1 5542F36B
P 6300 4300
F 0 "#PWR061" H 6300 4050 50  0001 C CNN
F 1 "GND" H 6300 4150 50  0000 C CNN
F 2 "" H 6300 4300 60  0000 C CNN
F 3 "" H 6300 4300 60  0000 C CNN
	1    6300 4300
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR062
U 1 1 5542F586
P 6600 4300
F 0 "#PWR062" H 6600 4050 50  0001 C CNN
F 1 "GND" H 6600 4150 50  0000 C CNN
F 2 "" H 6600 4300 60  0000 C CNN
F 3 "" H 6600 4300 60  0000 C CNN
	1    6600 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3700 5800 3800
Wire Wire Line
	6600 3800 6600 3900
Wire Wire Line
	5800 3800 6300 3800
Connection ~ 5800 3800
Wire Wire Line
	6300 3900 6300 3800
Connection ~ 6300 3800
Wire Wire Line
	6300 4200 6300 4300
Wire Wire Line
	6600 4200 6600 4300
Text GLabel 4800 6750 0    50   Input ~ 0
P.SRAM.WE
Wire Wire Line
	4800 6750 5100 6750
Text GLabel 6600 4650 2    50   3State ~ 0
LCD.D0
Text GLabel 6600 4750 2    50   3State ~ 0
LCD.D1
Text GLabel 6600 4850 2    50   3State ~ 0
LCD.D2
Text GLabel 6600 4950 2    50   3State ~ 0
LCD.D3
Text GLabel 6600 5050 2    50   3State ~ 0
LCD.D4
Text GLabel 6600 5150 2    50   3State ~ 0
LCD.D5
Text GLabel 6600 5250 2    50   3State ~ 0
LCD.D6
Text GLabel 6600 5350 2    50   3State ~ 0
LCD.D7
Wire Wire Line
	6500 4650 6600 4650
Wire Wire Line
	6500 4750 6600 4750
Wire Wire Line
	6500 4850 6600 4850
Wire Wire Line
	6500 4950 6600 4950
Wire Wire Line
	6500 5050 6600 5050
Wire Wire Line
	6500 5150 6600 5150
Wire Wire Line
	6500 5250 6600 5250
Wire Wire Line
	6500 5350 6600 5350
$Comp
L solar_system_terminal_board-rescue:-15V #PWR424
U 1 1 554ADCD0
P 8700 1000
F 0 "#PWR424" H 8700 1100 50  0001 C CNN
F 1 "-15V" H 8700 1150 50  0000 C CNN
F 2 "" H 8700 1000 60  0000 C CNN
F 3 "" H 8700 1000 60  0000 C CNN
	1    8700 1000
	1    0    0    -1  
$EndComp
Text GLabel 4800 6250 0    50   Input ~ 0
P.SRAM.A16
Wire Wire Line
	4800 6250 5100 6250
$Comp
L solar_system_terminal_board-rescue:+12V #PWR063
U 1 1 5547E528
P 7450 1000
AR Path="/5547E528" Ref="#PWR063"  Part="1" 
AR Path="/553F5EE0/5547E528" Ref="#PWR063"  Part="1" 
F 0 "#PWR063" H 7450 850 50  0001 C CNN
F 1 "+12V" H 7450 1150 50  0000 C CNN
F 2 "" H 7450 1000 60  0000 C CNN
F 3 "" H 7450 1000 60  0000 C CNN
	1    7450 1000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+12V #PWR064
U 1 1 5547E73E
P 7850 1000
AR Path="/5547E73E" Ref="#PWR064"  Part="1" 
AR Path="/553F5EE0/5547E73E" Ref="#PWR064"  Part="1" 
F 0 "#PWR064" H 7850 850 50  0001 C CNN
F 1 "+12V" H 7850 1150 50  0000 C CNN
F 2 "" H 7850 1000 60  0000 C CNN
F 3 "" H 7850 1000 60  0000 C CNN
	1    7850 1000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:BSS138 Q401
U 1 1 55489063
P 7750 1850
F 0 "Q401" H 7950 1925 50  0000 L CNN
F 1 "BSS138" H 7950 1850 50  0000 L CNN
F 2 "Housings_SOT-23_SOT-143_TSOT-6:SOT-23_Handsoldering" H 7950 1775 50  0000 L CIN
F 3 "" H 7750 1850 50  0000 L CNN
	1    7750 1850
	1    0    0    -1  
$EndComp
Text GLabel 9650 4650 0    50   Input ~ 0
LCD.D7
Text GLabel 9650 4750 0    50   Input ~ 0
LCD.D6
Text GLabel 9650 4850 0    50   Input ~ 0
LCD.D5
Text GLabel 9650 4950 0    50   Input ~ 0
LCD.D4
Text GLabel 9650 5050 0    50   Input ~ 0
LCD.D3
Text GLabel 9650 5150 0    50   Input ~ 0
LCD.D2
Text GLabel 9650 5250 0    50   Input ~ 0
LCD.D1
Text GLabel 9650 5350 0    50   Input ~ 0
LCD.D0
$Comp
L solar_system_terminal_board-rescue:R R406
U 1 1 555A738E
P 9100 4850
F 0 "R406" V 9180 4850 50  0000 C CNN
F 1 "10k" V 9100 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 9030 4850 30  0001 C CNN
F 3 "" H 9100 4850 30  0000 C CNN
	1    9100 4850
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR065
U 1 1 555A7394
P 9100 5100
F 0 "#PWR065" H 9100 4850 50  0001 C CNN
F 1 "GND" H 9100 4950 50  0000 C CNN
F 2 "" H 9100 5100 60  0000 C CNN
F 3 "" H 9100 5100 60  0000 C CNN
	1    9100 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 5100 9100 5000
Wire Wire Line
	9100 4700 9100 4250
Connection ~ 9100 4250
$Comp
L solar_system_terminal_board-rescue:R R404
U 1 1 557DEE7D
P 7850 2450
F 0 "R404" V 7930 2450 50  0000 C CNN
F 1 "0R" V 7850 2450 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7780 2450 30  0001 C CNN
F 3 "" H 7850 2450 30  0000 C CNN
	1    7850 2450
	-1   0    0    1   
$EndComp
$Comp
L solar_system_terminal_board-rescue:CONN_01X15 P402
U 1 1 55409C3E
P 10000 4650
F 0 "P402" H 10000 5450 50  0000 C CNN
F 1 "CONN_01X15" V 10100 4650 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x15" H 10000 4650 60  0001 C CNN
F 3 "" H 10000 4650 60  0000 C CNN
	1    10000 4650
	1    0    0    1   
$EndComp
Wire Wire Line
	7900 1550 7850 1550
Wire Wire Line
	7900 1450 7850 1450
Wire Wire Line
	7850 1450 7850 1400
Wire Wire Line
	7450 1900 7550 1900
Wire Wire Line
	8150 4550 9800 4550
Wire Wire Line
	8650 4350 9800 4350
Wire Wire Line
	8400 4350 8400 4700
Wire Wire Line
	1600 2750 1600 3650
Wire Wire Line
	1600 3650 1600 4550
Wire Wire Line
	1600 1850 1800 1850
Wire Wire Line
	3300 1850 3800 1850
Wire Wire Line
	3300 2750 4200 2750
Wire Wire Line
	3300 3650 4600 3650
Wire Wire Line
	5000 6650 5000 7000
Wire Wire Line
	5800 3800 5800 4550
Wire Wire Line
	6300 3800 6600 3800
Wire Wire Line
	9100 4250 9800 4250
$EndSCHEMATC
