EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
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
L solar_system_terminal_board-rescue:LT1129CST-3.3 U301
U 1 1 553F3812
P 5200 4800
F 0 "U301" H 4950 5000 40  0000 C CNN
F 1 "LT1129CST-3.3" H 5350 5000 40  0000 C CNN
F 2 "SMD_Packages:SOT-223" H 5200 4900 35  0000 C CIN
F 3 "" H 5200 4800 60  0000 C CNN
	1    5200 4800
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C302
U 1 1 553F393D
P 4550 2750
F 0 "C302" H 4575 2850 50  0000 L CNN
F 1 "100n" H 4575 2650 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 4588 2600 30  0001 C CNN
F 3 "" H 4550 2750 60  0000 C CNN
	1    4550 2750
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR018
U 1 1 553F39AF
P 5200 3050
F 0 "#PWR018" H 5200 2800 50  0001 C CNN
F 1 "GND" H 5200 2900 50  0000 C CNN
F 2 "" H 5200 3050 60  0000 C CNN
F 3 "" H 5200 3050 60  0000 C CNN
	1    5200 3050
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR019
U 1 1 553F39C6
P 4550 3050
F 0 "#PWR019" H 4550 2800 50  0001 C CNN
F 1 "GND" H 4550 2900 50  0000 C CNN
F 2 "" H 4550 3050 60  0000 C CNN
F 3 "" H 4550 3050 60  0000 C CNN
	1    4550 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 2500 4550 2500
Wire Wire Line
	4550 2300 4550 2500
Connection ~ 4550 2500
Wire Wire Line
	4550 2900 4550 3050
$Comp
L solar_system_terminal_board-rescue:C C306
U 1 1 553F3BAC
P 6100 2750
F 0 "C306" H 6125 2850 50  0000 L CNN
F 1 "100n" H 6125 2650 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 6138 2600 30  0001 C CNN
F 3 "" H 6100 2750 60  0000 C CNN
	1    6100 2750
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:CP C307
U 1 1 553F3BF7
P 6350 2750
F 0 "C307" H 6375 2850 50  0000 L CNN
F 1 "22u" H 6375 2650 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 6388 2600 30  0001 C CNN
F 3 "" H 6350 2750 60  0000 C CNN
	1    6350 2750
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:LED-RESCUE-solar_system_terminal_board D303
U 1 1 553F3EFA
P 6650 2800
F 0 "D303" H 6650 2900 50  0000 C CNN
F 1 "LED" H 6650 2700 50  0000 C CNN
F 2 "LEDs:LED-1206" H 6650 2800 60  0001 C CNN
F 3 "" H 6650 2800 60  0000 C CNN
	1    6650 2800
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR020
U 1 1 553F3F4E
P 6650 2300
F 0 "#PWR020" H 6650 2150 50  0001 C CNN
F 1 "+5V" H 6650 2440 50  0000 C CNN
F 2 "" H 6650 2300 60  0000 C CNN
F 3 "" H 6650 2300 60  0000 C CNN
	1    6650 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2500 5700 2500
Wire Wire Line
	6000 2500 6100 2500
Wire Wire Line
	6650 2300 6650 2500
Connection ~ 6650 2500
Wire Wire Line
	6350 2600 6350 2500
Connection ~ 6350 2500
Wire Wire Line
	6100 2300 6100 2500
Connection ~ 6100 2500
$Comp
L solar_system_terminal_board-rescue:GND #PWR021
U 1 1 553F4001
P 6650 3500
F 0 "#PWR021" H 6650 3250 50  0001 C CNN
F 1 "GND" H 6650 3350 50  0000 C CNN
F 2 "" H 6650 3500 60  0000 C CNN
F 3 "" H 6650 3500 60  0000 C CNN
	1    6650 3500
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR022
U 1 1 553F401E
P 6350 3050
F 0 "#PWR022" H 6350 2800 50  0001 C CNN
F 1 "GND" H 6350 2900 50  0000 C CNN
F 2 "" H 6350 3050 60  0000 C CNN
F 3 "" H 6350 3050 60  0000 C CNN
	1    6350 3050
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR023
U 1 1 553F403B
P 6100 3050
F 0 "#PWR023" H 6100 2800 50  0001 C CNN
F 1 "GND" H 6100 2900 50  0000 C CNN
F 2 "" H 6100 3050 60  0000 C CNN
F 3 "" H 6100 3050 60  0000 C CNN
	1    6100 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 2900 6100 3050
Wire Wire Line
	6350 2900 6350 3050
Wire Wire Line
	6650 3000 6650 3050
$Comp
L solar_system_terminal_board-rescue:CONN_01X02 P301
U 1 1 553F4173
P 3800 2550
F 0 "P301" H 3800 2700 50  0000 C CNN
F 1 "CONN_01X02" V 3900 2550 50  0000 C CNN
F 2 "Connect:AK300-2" H 3800 2550 60  0001 C CNN
F 3 "" H 3800 2550 60  0000 C CNN
	1    3800 2550
	-1   0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR024
U 1 1 553F42EE
P 4150 3050
F 0 "#PWR024" H 4150 2800 50  0001 C CNN
F 1 "GND" H 4150 2900 50  0000 C CNN
F 2 "" H 4150 3050 60  0000 C CNN
F 3 "" H 4150 3050 60  0000 C CNN
	1    4150 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2500 4150 2500
Wire Wire Line
	4000 2600 4150 2600
Wire Wire Line
	4150 2600 4150 3050
$Comp
L solar_system_terminal_board-rescue:GND #PWR025
U 1 1 553F5383
P 5200 5200
F 0 "#PWR025" H 5200 4950 50  0001 C CNN
F 1 "GND" H 5200 5050 50  0000 C CNN
F 2 "" H 5200 5200 60  0000 C CNN
F 3 "" H 5200 5200 60  0000 C CNN
	1    5200 5200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C301
U 1 1 553F540B
P 4550 5000
F 0 "C301" H 4575 5100 50  0000 L CNN
F 1 "100n" H 4575 4900 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 4588 4850 30  0001 C CNN
F 3 "" H 4550 5000 60  0000 C CNN
	1    4550 5000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR026
U 1 1 553F5411
P 4550 5200
F 0 "#PWR026" H 4550 4950 50  0001 C CNN
F 1 "GND" H 4550 5050 50  0000 C CNN
F 2 "" H 4550 5200 60  0000 C CNN
F 3 "" H 4550 5200 60  0000 C CNN
	1    4550 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4750 4550 4750
Wire Wire Line
	4550 4650 4550 4750
Wire Wire Line
	4550 5150 4550 5200
$Comp
L solar_system_terminal_board-rescue:+5V #PWR027
U 1 1 553F541A
P 4550 4650
F 0 "#PWR027" H 4550 4500 50  0001 C CNN
F 1 "+5V" H 4550 4790 50  0000 C CNN
F 2 "" H 4550 4650 60  0000 C CNN
F 3 "" H 4550 4650 60  0000 C CNN
	1    4550 4650
	1    0    0    -1  
$EndComp
Connection ~ 4550 4750
$Comp
L solar_system_terminal_board-rescue:C C305
U 1 1 553F57DD
P 5850 5000
F 0 "C305" H 5875 5100 50  0000 L CNN
F 1 "100n" H 5875 4900 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 5888 4850 30  0001 C CNN
F 3 "" H 5850 5000 60  0000 C CNN
	1    5850 5000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR028
U 1 1 553F583D
P 5850 5200
F 0 "#PWR028" H 5850 4950 50  0001 C CNN
F 1 "GND" H 5850 5050 50  0000 C CNN
F 2 "" H 5850 5200 60  0000 C CNN
F 3 "" H 5850 5200 60  0000 C CNN
	1    5850 5200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+3.3V #PWR029
U 1 1 553F5858
P 5850 4650
F 0 "#PWR029" H 5850 4500 50  0001 C CNN
F 1 "+3.3V" H 5850 4790 50  0000 C CNN
F 2 "" H 5850 4650 60  0000 C CNN
F 3 "" H 5850 4650 60  0000 C CNN
	1    5850 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 4750 5850 4750
Wire Wire Line
	5850 4650 5850 4750
Connection ~ 5850 4750
Wire Wire Line
	5850 5150 5850 5200
Wire Wire Line
	5200 5100 5200 5200
$Comp
L solar_system_terminal_board-rescue:PWR_FLAG #FLG030
U 1 1 55406969
P 6100 2300
F 0 "#FLG030" H 6100 2395 50  0001 C CNN
F 1 "PWR_FLAG" H 6100 2480 50  0000 C CNN
F 2 "" H 6100 2300 60  0000 C CNN
F 3 "" H 6100 2300 60  0000 C CNN
	1    6100 2300
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:-15V #PWR311
U 1 1 554ACFA9
P 5700 3550
F 0 "#PWR311" H 5700 3650 50  0001 C CNN
F 1 "-15V" H 5700 3700 50  0000 C CNN
F 2 "" H 5700 3550 60  0000 C CNN
F 3 "" H 5700 3550 60  0000 C CNN
	1    5700 3550
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C303
U 1 1 554AD380
P 4700 3900
F 0 "C303" H 4725 4000 50  0000 L CNN
F 1 "100n" H 4725 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 4738 3750 30  0001 C CNN
F 3 "" H 4700 3900 60  0000 C CNN
	1    4700 3900
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:C C304
U 1 1 554AD386
P 5700 3900
F 0 "C304" H 5725 4000 50  0000 L CNN
F 1 "100n" H 5725 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 5738 3750 30  0001 C CNN
F 3 "" H 5700 3900 60  0000 C CNN
	1    5700 3900
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR031
U 1 1 554AD38C
P 4700 4100
F 0 "#PWR031" H 4700 3850 50  0001 C CNN
F 1 "GND" H 4700 3950 50  0000 C CNN
F 2 "" H 4700 4100 60  0000 C CNN
F 3 "" H 4700 4100 60  0000 C CNN
	1    4700 4100
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR032
U 1 1 554AD392
P 5700 4100
F 0 "#PWR032" H 5700 3850 50  0001 C CNN
F 1 "GND" H 5700 3950 50  0000 C CNN
F 2 "" H 5700 4100 60  0000 C CNN
F 3 "" H 5700 4100 60  0000 C CNN
	1    5700 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3650 4700 3650
Wire Wire Line
	4700 3550 4700 3650
Wire Wire Line
	5600 3650 5700 3650
Wire Wire Line
	5700 3550 5700 3650
Wire Wire Line
	4700 4050 4700 4100
Wire Wire Line
	5700 4050 5700 4100
$Comp
L solar_system_terminal_board-rescue:GND #PWR033
U 1 1 554AD3A0
P 5200 4100
F 0 "#PWR033" H 5200 3850 50  0001 C CNN
F 1 "GND" H 5200 3950 50  0000 C CNN
F 2 "" H 5200 4100 60  0000 C CNN
F 3 "" H 5200 4100 60  0000 C CNN
	1    5200 4100
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:+5V #PWR034
U 1 1 554AD3A7
P 4700 3550
F 0 "#PWR034" H 4700 3400 50  0001 C CNN
F 1 "+5V" H 4700 3690 50  0000 C CNN
F 2 "" H 4700 3550 60  0000 C CNN
F 3 "" H 4700 3550 60  0000 C CNN
	1    4700 3550
	1    0    0    -1  
$EndComp
Connection ~ 5700 3650
Connection ~ 4700 3650
$Comp
L solar_system_terminal_board-rescue:+12V #PWR035
U 1 1 5547DC91
P 4550 2300
AR Path="/5547DC91" Ref="#PWR035"  Part="1" 
AR Path="/553F377E/5547DC91" Ref="#PWR035"  Part="1" 
F 0 "#PWR035" H 4550 2150 50  0001 C CNN
F 1 "+12V" H 4550 2450 50  0000 C CNN
F 2 "" H 4550 2300 60  0000 C CNN
F 3 "" H 4550 2300 60  0000 C CNN
	1    4550 2300
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:AMBM_DC2 SUP301
U 1 1 555D022E
P 5200 2500
F 0 "SUP301" H 5200 2650 60  0000 C CNN
F 1 "AMBM_DC2" H 5200 2750 60  0000 C CNN
F 2 "AMBM_dc-dc:DC2_Socket_H" H 5200 2500 60  0001 C CNN
F 3 "" H 5200 2500 60  0000 C CNN
	1    5200 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 2900 5200 3050
Wire Wire Line
	5200 4050 5200 4100
$Comp
L solar_system_terminal_board-rescue:AMBM_DCN01 SUP302
U 1 1 555D2EB8
P 5200 3650
F 0 "SUP302" H 5200 3800 60  0000 C CNN
F 1 "AMBM_DCN01" H 5200 3900 60  0000 C CNN
F 2 "AMBM_dc-dc:DC2_Socket_H" H 5200 3650 60  0001 C CNN
F 3 "" H 5200 3650 60  0000 C CNN
	1    5200 3650
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:D D301
U 1 1 5561D0E4
P 4300 2500
F 0 "D301" H 4300 2600 50  0000 C CNN
F 1 "D" H 4300 2400 50  0000 C CNN
F 2 "Diodes_SMD:Diode-MiniMELF_Handsoldering" H 4300 2500 60  0001 C CNN
F 3 "" H 4300 2500 60  0000 C CNN
	1    4300 2500
	-1   0    0    1   
$EndComp
$Comp
L solar_system_terminal_board-rescue:D D302
U 1 1 5561D132
P 5850 2500
F 0 "D302" H 5850 2600 50  0000 C CNN
F 1 "D" H 5850 2400 50  0000 C CNN
F 2 "Diodes_SMD:Diode-MiniMELF_Handsoldering" H 5850 2500 60  0001 C CNN
F 3 "" H 5850 2500 60  0000 C CNN
	1    5850 2500
	-1   0    0    1   
$EndComp
$Comp
L solar_system_terminal_board-rescue:PWR_FLAG #FLG036
U 1 1 5581B3CD
P 7200 2300
F 0 "#FLG036" H 7200 2395 50  0001 C CNN
F 1 "PWR_FLAG" H 7200 2480 50  0000 C CNN
F 2 "" H 7200 2300 60  0000 C CNN
F 3 "" H 7200 2300 60  0000 C CNN
	1    7200 2300
	1    0    0    -1  
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR037
U 1 1 5581B3F4
P 7200 3050
F 0 "#PWR037" H 7200 2800 50  0001 C CNN
F 1 "GND" H 7200 2900 50  0000 C CNN
F 2 "" H 7200 3050 60  0000 C CNN
F 3 "" H 7200 3050 60  0000 C CNN
	1    7200 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 3050 7200 2300
$Comp
L solar_system_terminal_board-rescue:R R301
U 1 1 55B5D1A3
P 6650 3200
F 0 "R301" V 6730 3200 50  0000 C CNN
F 1 "1k5" V 6650 3200 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6580 3200 30  0001 C CNN
F 3 "" H 6650 3200 30  0000 C CNN
	1    6650 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 3350 6650 3500
$Comp
L solar_system_terminal_board-rescue:PWR_FLAG #FLG038
U 1 1 55B6805E
P 4700 2100
F 0 "#FLG038" H 4700 2195 50  0001 C CNN
F 1 "PWR_FLAG" H 4700 2280 50  0000 C CNN
F 2 "" H 4700 2100 60  0000 C CNN
F 3 "" H 4700 2100 60  0000 C CNN
	1    4700 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2100 4700 2500
Connection ~ 4700 2500
$Comp
L solar_system_terminal_board-rescue:LED-RESCUE-solar_system_terminal_board D304
U 1 1 55B871A6
P 6250 5000
F 0 "D304" H 6250 5100 50  0000 C CNN
F 1 "LED" H 6250 4900 50  0000 C CNN
F 2 "LEDs:LED-1206" H 6250 5000 60  0001 C CNN
F 3 "" H 6250 5000 60  0000 C CNN
	1    6250 5000
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_terminal_board-rescue:GND #PWR039
U 1 1 55B871AC
P 6250 5700
F 0 "#PWR039" H 6250 5450 50  0001 C CNN
F 1 "GND" H 6250 5550 50  0000 C CNN
F 2 "" H 6250 5700 60  0000 C CNN
F 3 "" H 6250 5700 60  0000 C CNN
	1    6250 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 5200 6250 5250
$Comp
L solar_system_terminal_board-rescue:R R302
U 1 1 55B871B3
P 6250 5400
F 0 "R302" V 6330 5400 50  0000 C CNN
F 1 "820R" V 6250 5400 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6180 5400 30  0001 C CNN
F 3 "" H 6250 5400 30  0000 C CNN
	1    6250 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 5550 6250 5700
Wire Wire Line
	6250 4750 6250 4800
Wire Wire Line
	4550 2500 4700 2500
Wire Wire Line
	4550 2500 4550 2600
Wire Wire Line
	6650 2500 6650 2600
Wire Wire Line
	6350 2500 6650 2500
Wire Wire Line
	6100 2500 6350 2500
Wire Wire Line
	6100 2500 6100 2600
Wire Wire Line
	4550 4750 4550 4850
Wire Wire Line
	5850 4750 6250 4750
Wire Wire Line
	5850 4750 5850 4850
Wire Wire Line
	5700 3650 5700 3750
Wire Wire Line
	4700 3650 4700 3750
Wire Wire Line
	4700 2500 4800 2500
$EndSCHEMATC
