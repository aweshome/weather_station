EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 4
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
L solar_system_external_unit_board_2-rescue:USB-MINI-B CON201
U 1 1 57636200
P 7950 2700
F 0 "CON201" H 7700 3150 60  0000 C CNN
F 1 "USB-MINI-B" H 7900 2200 60  0000 C CNN
F 2 "My_modules:USB_Mini-B_mod" H 7950 2700 60  0001 C CNN
F 3 "" H 7950 2700 60  0000 C CNN
	1    7950 2700
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:NCP1117ST33T3G-RESCUE-solar_system_external_unit_board_2 U201
U 1 1 57636207
P 5100 2450
F 0 "U201" H 5100 2700 40  0000 C CNN
F 1 "NCP1117ST33T3G" H 5100 2650 40  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 5100 2450 60  0001 C CNN
F 3 "" H 5100 2450 60  0000 C CNN
	1    5100 2450
	-1   0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:JUMPER JP201
U 1 1 5763620E
P 3900 2400
F 0 "JP201" H 3900 2550 60  0000 C CNN
F 1 "JUMPER" H 3900 2320 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 3900 2400 60  0001 C CNN
F 3 "~" H 3900 2400 60  0000 C CNN
	1    3900 2400
	-1   0    0    -1  
$EndComp
Text GLabel 6700 2550 0    50   BiDi ~ 0
uC:USB_D-
Text GLabel 6700 2700 0    50   BiDi ~ 0
uC:USB_D+
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR01
U 1 1 57636219
P 7100 3650
F 0 "#PWR01" H 7100 3650 30  0001 C CNN
F 1 "GND" H 7100 3580 30  0001 C CNN
F 2 "" H 7100 3650 60  0000 C CNN
F 3 "" H 7100 3650 60  0000 C CNN
	1    7100 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 3000 7100 3000
Wire Wire Line
	7100 1400 7100 1500
Wire Wire Line
	5500 2400 5600 2400
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR02
U 1 1 57636222
P 5100 3650
F 0 "#PWR02" H 5100 3650 30  0001 C CNN
F 1 "GND" H 5100 3580 30  0001 C CNN
F 2 "" H 5100 3650 60  0000 C CNN
F 3 "" H 5100 3650 60  0000 C CNN
	1    5100 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 2700 5100 3000
$Comp
L power:VCC #PWR03
U 1 1 57636229
P 3300 2300
F 0 "#PWR03" H 3300 2400 30  0001 C CNN
F 1 "VCC" H 3300 2400 30  0000 C CNN
F 2 "" H 3300 2300 60  0000 C CNN
F 3 "" H 3300 2300 60  0000 C CNN
	1    3300 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2400 4300 2400
Wire Wire Line
	3300 2400 3500 2400
$Comp
L solar_system_external_unit_board_2-rescue:LED-RESCUE-solar_system_external_unit_board_2 D202
U 1 1 57636231
P 4300 2700
F 0 "D202" H 4300 2800 50  0000 C CNN
F 1 "LED" H 4300 2600 50  0000 C CNN
F 2 "LEDs:LED_1206" H 4300 2700 60  0001 C CNN
F 3 "~" H 4300 2700 60  0000 C CNN
	1    4300 2700
	0    1    1    0   
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:R-RESCUE-solar_system_external_unit_board_2 R201
U 1 1 57636238
P 4300 3250
F 0 "R201" V 4380 3250 40  0000 C CNN
F 1 "330R" V 4307 3251 40  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 4230 3250 30  0001 C CNN
F 3 "~" H 4300 3250 30  0000 C CNN
	1    4300 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2500 4300 2400
Connection ~ 4300 2400
Wire Wire Line
	4300 2900 4300 3000
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR04
U 1 1 57636242
P 4300 3650
F 0 "#PWR04" H 4300 3650 30  0001 C CNN
F 1 "GND" H 4300 3580 30  0001 C CNN
F 2 "" H 4300 3650 60  0000 C CNN
F 3 "" H 4300 3650 60  0000 C CNN
	1    4300 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3650 4300 3500
$Comp
L solar_system_external_unit_board_2-rescue:C-RESCUE-solar_system_external_unit_board_2 C201
U 1 1 57636249
P 3300 3000
AR Path="/57636249" Ref="C201"  Part="1" 
AR Path="/57633339/57636249" Ref="C201"  Part="1" 
F 0 "C201" H 3300 3100 40  0000 L CNN
F 1 "C" H 3306 2915 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 3338 2850 30  0000 C CNN
F 3 "~" H 3300 3000 60  0000 C CNN
	1    3300 3000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:CP-RESCUE-solar_system_external_unit_board_2 C202
U 1 1 57636250
P 3500 3000
F 0 "C202" H 3550 3100 40  0000 L CNN
F 1 "10u" H 3550 2900 40  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 3600 2850 30  0001 C CNN
F 3 "~" H 3500 3000 300 0000 C CNN
	1    3500 3000
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR05
U 1 1 57636257
P 3500 3650
F 0 "#PWR05" H 3500 3650 30  0001 C CNN
F 1 "GND" H 3500 3580 30  0001 C CNN
F 2 "" H 3500 3650 60  0000 C CNN
F 3 "" H 3500 3650 60  0000 C CNN
	1    3500 3650
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR06
U 1 1 5763625D
P 3300 3650
F 0 "#PWR06" H 3300 3650 30  0001 C CNN
F 1 "GND" H 3300 3580 30  0001 C CNN
F 2 "" H 3300 3650 60  0000 C CNN
F 3 "" H 3300 3650 60  0000 C CNN
	1    3300 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3200 3300 3650
Wire Wire Line
	3500 3200 3500 3650
Connection ~ 3500 2400
Wire Wire Line
	3300 2300 3300 2400
Wire Wire Line
	3500 2800 3500 2400
Connection ~ 3300 2400
$Comp
L solar_system_external_unit_board_2-rescue:C-RESCUE-solar_system_external_unit_board_2 C203
U 1 1 57636269
P 4600 2700
AR Path="/57636269" Ref="C203"  Part="1" 
AR Path="/57633339/57636269" Ref="C203"  Part="1" 
F 0 "C203" H 4600 2800 40  0000 L CNN
F 1 "C" H 4606 2615 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 4638 2550 30  0000 C CNN
F 3 "~" H 4600 2700 60  0000 C CNN
	1    4600 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2500 4600 2400
Connection ~ 4600 2400
Wire Wire Line
	4600 2900 4600 3000
Wire Wire Line
	4600 3000 5100 3000
Connection ~ 5100 3000
$Comp
L solar_system_external_unit_board_2-rescue:C-RESCUE-solar_system_external_unit_board_2 C204
U 1 1 57636275
P 5600 2700
AR Path="/57636275" Ref="C204"  Part="1" 
AR Path="/57633339/57636275" Ref="C204"  Part="1" 
F 0 "C204" H 5600 2800 40  0000 L CNN
F 1 "C" H 5606 2615 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 5638 2550 30  0000 C CNN
F 3 "~" H 5600 2700 60  0000 C CNN
	1    5600 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2400 5600 2500
Wire Wire Line
	5600 3000 5600 2900
$Comp
L solar_system_external_unit_board_2-rescue:CP-RESCUE-solar_system_external_unit_board_2 C205
U 1 1 5763627E
P 5800 2700
F 0 "C205" H 5850 2800 40  0000 L CNN
F 1 "22u" H 5850 2600 40  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:TantalC_SizeB_EIA-3528_HandSoldering" H 5900 2550 30  0001 C CNN
F 3 "~" H 5800 2700 300 0000 C CNN
	1    5800 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3000 5800 2900
Connection ~ 5600 3000
Connection ~ 5600 2400
Wire Wire Line
	5800 2300 5800 2400
Connection ~ 5800 2400
Wire Wire Line
	6700 2550 7400 2550
Wire Wire Line
	6700 2700 7400 2700
NoConn ~ 7400 2850
$Comp
L power:PWR_FLAG #FLG07
U 1 1 57781B38
P 5800 2300
F 0 "#FLG07" H 5800 2570 30  0001 C CNN
F 1 "PWR_FLAG" H 5800 2530 30  0000 C CNN
F 2 "" H 5800 2300 60  0000 C CNN
F 3 "" H 5800 2300 60  0000 C CNN
	1    5800 2300
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG08
U 1 1 57788552
P 9700 2300
F 0 "#FLG08" H 9700 2570 30  0001 C CNN
F 1 "PWR_FLAG" H 9700 2530 30  0000 C CNN
F 2 "" H 9700 2300 60  0000 C CNN
F 3 "" H 9700 2300 60  0000 C CNN
	1    9700 2300
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR09
U 1 1 5778857B
P 9700 3650
F 0 "#PWR09" H 9700 3650 30  0001 C CNN
F 1 "GND" H 9700 3580 30  0001 C CNN
F 2 "" H 9700 3650 60  0000 C CNN
F 3 "" H 9700 3650 60  0000 C CNN
	1    9700 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 2300 9700 3650
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR010
U 1 1 57786577
P 9400 3650
F 0 "#PWR010" H 9400 3650 30  0001 C CNN
F 1 "GND" H 9400 3580 30  0001 C CNN
F 2 "" H 9400 3650 60  0000 C CNN
F 3 "" H 9400 3650 60  0000 C CNN
	1    9400 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 2400 8700 2400
Wire Wire Line
	8500 2550 8700 2550
Wire Wire Line
	8500 2850 8700 2850
Wire Wire Line
	8700 3000 8500 3000
$Comp
L solar_system_external_unit_board_2-rescue:R-RESCUE-solar_system_external_unit_board_2 R202
U 1 1 57786DC7
P 9050 2550
F 0 "R202" V 9130 2550 40  0000 C CNN
F 1 "1M" V 9057 2551 40  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 8980 2550 30  0001 C CNN
F 3 "~" H 9050 2550 30  0000 C CNN
	1    9050 2550
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:C-RESCUE-solar_system_external_unit_board_2 C206
U 1 1 57786E60
P 9050 2850
AR Path="/57786E60" Ref="C206"  Part="1" 
AR Path="/57633339/57786E60" Ref="C206"  Part="1" 
F 0 "C206" H 9050 2950 40  0000 L CNN
F 1 "4n7" H 9056 2765 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 9088 2700 30  0000 C CNN
F 3 "~" H 9050 2850 60  0000 C CNN
	1    9050 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	8700 2400 8700 2550
Connection ~ 8700 2850
Connection ~ 8700 2550
Wire Wire Line
	9300 2550 9400 2550
Wire Wire Line
	9400 2550 9400 2850
Wire Wire Line
	9400 2850 9250 2850
Connection ~ 9400 2850
$Comp
L power:VCC #PWR011
U 1 1 57787B6E
P 6500 1400
F 0 "#PWR011" H 6500 1500 30  0001 C CNN
F 1 "VCC" H 6500 1500 30  0000 C CNN
F 2 "" H 6500 1400 60  0000 C CNN
F 3 "" H 6500 1400 60  0000 C CNN
	1    6500 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D201
U 1 1 577D6705
P 6750 1500
F 0 "D201" H 6750 1600 50  0000 C CNN
F 1 "D_Schottky" H 6750 1400 50  0000 C CNN
F 2 "Diodes_SMD:MiniMELF_Handsoldering" H 6750 1500 50  0001 C CNN
F 3 "" H 6750 1500 50  0000 C CNN
	1    6750 1500
	1    0    0    -1  
$EndComp
Connection ~ 7100 3000
Wire Wire Line
	7300 1400 7300 2400
Connection ~ 7300 2400
$Comp
L solar_system_external_unit_board_2-rescue:CONN_4 P201
U 1 1 57E84B84
P 7150 1050
F 0 "P201" V 7100 1050 50  0000 C CNN
F 1 "CONN_4" V 7200 1050 50  0000 C CNN
F 2 "w_conn_pt-1,5:pt_1,5-4-3,5-h" H 7150 1050 60  0001 C CNN
F 3 "" H 7150 1050 60  0000 C CNN
	1    7150 1050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7200 1400 7200 1500
Wire Wire Line
	7200 1500 7100 1500
Connection ~ 7100 1500
Wire Wire Line
	7000 1400 7000 1500
Wire Wire Line
	7000 1500 6900 1500
Wire Wire Line
	6600 1500 6500 1500
Wire Wire Line
	6500 1500 6500 1400
$Comp
L solar_system_external_unit_board_2-rescue:CONN_2 P202
U 1 1 58031DCB
P 7700 1050
F 0 "P202" V 7650 1050 40  0000 C CNN
F 1 "CONN_2" V 7750 1050 40  0000 C CNN
F 2 "w_conn_pt-1,5:pt_1,5-2-3,5-h" H 7700 1050 60  0001 C CNN
F 3 "" H 7700 1050 60  0000 C CNN
	1    7700 1050
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR012
U 1 1 58032025
P 7600 1500
F 0 "#PWR012" H 7600 1500 30  0001 C CNN
F 1 "GND" H 7600 1430 30  0001 C CNN
F 2 "" H 7600 1500 60  0000 C CNN
F 3 "" H 7600 1500 60  0000 C CNN
	1    7600 1500
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR013
U 1 1 5803207B
P 7800 1500
F 0 "#PWR013" H 7800 1500 30  0001 C CNN
F 1 "GND" H 7800 1430 30  0001 C CNN
F 2 "" H 7800 1500 60  0000 C CNN
F 3 "" H 7800 1500 60  0000 C CNN
	1    7800 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 1400 7600 1500
Wire Wire Line
	7800 1400 7800 1500
Wire Wire Line
	4300 2400 4600 2400
Wire Wire Line
	3500 2400 3600 2400
Wire Wire Line
	3300 2400 3300 2800
Wire Wire Line
	4600 2400 4700 2400
Wire Wire Line
	5100 3000 5100 3650
Wire Wire Line
	5100 3000 5600 3000
Wire Wire Line
	5600 3000 5800 3000
Wire Wire Line
	5600 2400 5800 2400
Wire Wire Line
	5800 2400 5800 2500
Wire Wire Line
	5800 2400 7300 2400
Wire Wire Line
	8700 2850 8850 2850
Wire Wire Line
	8700 2850 8700 3000
Wire Wire Line
	8700 2550 8800 2550
Wire Wire Line
	8700 2550 8700 2850
Wire Wire Line
	9400 2850 9400 3650
Wire Wire Line
	7100 3000 7100 3650
Wire Wire Line
	7300 2400 7400 2400
Wire Wire Line
	7100 1500 7100 3000
$EndSCHEMATC
