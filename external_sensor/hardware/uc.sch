EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
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
L solar_system_external_unit_board_2-rescue:C-RESCUE-solar_system_external_unit_board_2 C401
U 1 1 57638017
P 1200 2200
AR Path="/57638017" Ref="C401"  Part="1" 
AR Path="/57636FA1/57638017" Ref="C401"  Part="1" 
F 0 "C401" H 1200 2300 40  0000 L CNN
F 1 "C" H 1206 2115 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 1238 2050 30  0000 C CNN
F 3 "~" H 1200 2200 60  0000 C CNN
	1    1200 2200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:C-RESCUE-solar_system_external_unit_board_2 C402
U 1 1 5763801E
P 1400 2200
AR Path="/5763801E" Ref="C402"  Part="1" 
AR Path="/57636FA1/5763801E" Ref="C402"  Part="1" 
F 0 "C402" H 1400 2300 40  0000 L CNN
F 1 "C" H 1406 2115 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 1438 2050 30  0000 C CNN
F 3 "~" H 1400 2200 60  0000 C CNN
	1    1400 2200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:C-RESCUE-solar_system_external_unit_board_2 C403
U 1 1 57638025
P 1600 2200
AR Path="/57638025" Ref="C403"  Part="1" 
AR Path="/57636FA1/57638025" Ref="C403"  Part="1" 
F 0 "C403" H 1600 2300 40  0000 L CNN
F 1 "C" H 1606 2115 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 1638 2050 30  0000 C CNN
F 3 "~" H 1600 2200 60  0000 C CNN
	1    1600 2200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:C-RESCUE-solar_system_external_unit_board_2 C404
U 1 1 5763802C
P 1800 2200
AR Path="/5763802C" Ref="C404"  Part="1" 
AR Path="/57636FA1/5763802C" Ref="C404"  Part="1" 
F 0 "C404" H 1800 2300 40  0000 L CNN
F 1 "C" H 1806 2115 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 1838 2050 30  0000 C CNN
F 3 "~" H 1800 2200 60  0000 C CNN
	1    1800 2200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:C-RESCUE-solar_system_external_unit_board_2 C405
U 1 1 57638033
P 2000 2200
AR Path="/57638033" Ref="C405"  Part="1" 
AR Path="/57636FA1/57638033" Ref="C405"  Part="1" 
F 0 "C405" H 2000 2300 40  0000 L CNN
F 1 "C" H 2006 2115 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 2038 2050 30  0000 C CNN
F 3 "~" H 2000 2200 60  0000 C CNN
	1    2000 2200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:C-RESCUE-solar_system_external_unit_board_2 C406
U 1 1 5763803A
P 2200 2200
AR Path="/5763803A" Ref="C406"  Part="1" 
AR Path="/57636FA1/5763803A" Ref="C406"  Part="1" 
F 0 "C406" H 2200 2300 40  0000 L CNN
F 1 "C" H 2206 2115 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 2238 2050 30  0000 C CNN
F 3 "~" H 2200 2200 60  0000 C CNN
	1    2200 2200
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR023
U 1 1 57638041
P 2200 2600
F 0 "#PWR023" H 2200 2600 30  0001 C CNN
F 1 "GND" H 2200 2530 30  0001 C CNN
F 2 "" H 2200 2600 60  0000 C CNN
F 3 "" H 2200 2600 60  0000 C CNN
	1    2200 2600
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR024
U 1 1 57638047
P 2200 1800
F 0 "#PWR024" H 2200 1900 30  0001 C CNN
F 1 "VCC" H 2200 1900 30  0000 C CNN
F 2 "" H 2200 1800 60  0000 C CNN
F 3 "" H 2200 1800 60  0000 C CNN
	1    2200 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2400 1200 2500
Wire Wire Line
	1200 2500 1400 2500
Wire Wire Line
	2200 2400 2200 2500
Wire Wire Line
	1200 2000 1200 1900
Wire Wire Line
	1200 1900 1400 1900
Wire Wire Line
	2200 1800 2200 1900
Connection ~ 2200 1900
Wire Wire Line
	2000 2000 2000 1900
Connection ~ 2000 1900
Wire Wire Line
	1800 2000 1800 1900
Connection ~ 1800 1900
Wire Wire Line
	1600 2000 1600 1900
Connection ~ 1600 1900
Wire Wire Line
	1400 2000 1400 1900
Connection ~ 1400 1900
Wire Wire Line
	1400 2400 1400 2500
Connection ~ 1400 2500
Wire Wire Line
	1600 2400 1600 2500
Connection ~ 1600 2500
Wire Wire Line
	1800 2400 1800 2500
Connection ~ 1800 2500
Wire Wire Line
	2000 2400 2000 2500
Connection ~ 2000 2500
Connection ~ 2200 2500
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR025
U 1 1 57638065
P 1000 6700
F 0 "#PWR025" H 1000 6700 30  0001 C CNN
F 1 "GND" H 1000 6630 30  0001 C CNN
F 2 "" H 1000 6700 60  0000 C CNN
F 3 "" H 1000 6700 60  0000 C CNN
	1    1000 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 5600 1000 6000
Wire Wire Line
	1000 6000 1300 6000
Text GLabel 2600 6000 2    50   Input ~ 0
uC:FLIP_SW
Wire Wire Line
	2300 6000 2600 6000
$Comp
L atmel:ATXMEGA128A3U-A IC401
U 1 1 576383CA
P 5400 4250
F 0 "IC401" H 4550 5850 40  0000 L BNN
F 1 "ATXMEGA128A3U-A" H 5750 2550 40  0000 L BNN
F 2 "Housings_QFP:TQFP-64_14x14mm_Pitch0.8mm" H 5400 4250 35  0001 C CIN
F 3 "" H 5400 4250 60  0000 C CNN
	1    5400 4250
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR026
U 1 1 576383D1
P 5150 6350
F 0 "#PWR026" H 5150 6350 30  0001 C CNN
F 1 "GND" H 5150 6280 30  0001 C CNN
F 2 "" H 5150 6350 60  0000 C CNN
F 3 "" H 5150 6350 60  0000 C CNN
	1    5150 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 6000 5150 6100
Wire Wire Line
	5150 6100 5250 6100
Wire Wire Line
	5650 6100 5650 6000
Connection ~ 5150 6100
Wire Wire Line
	5550 6000 5550 6100
Connection ~ 5550 6100
Wire Wire Line
	5450 6000 5450 6100
Connection ~ 5450 6100
Wire Wire Line
	5350 6000 5350 6100
Connection ~ 5350 6100
Wire Wire Line
	5250 6000 5250 6100
Connection ~ 5250 6100
$Comp
L power:VCC #PWR027
U 1 1 576383E3
P 5150 2350
F 0 "#PWR027" H 5150 2450 30  0001 C CNN
F 1 "VCC" H 5150 2450 30  0000 C CNN
F 2 "" H 5150 2350 60  0000 C CNN
F 3 "" H 5150 2350 60  0000 C CNN
	1    5150 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 2350 5150 2450
Wire Wire Line
	5150 2450 5250 2450
Wire Wire Line
	5750 2450 5750 2550
Connection ~ 5150 2450
Wire Wire Line
	5550 2350 5550 2450
Connection ~ 5550 2450
Wire Wire Line
	5450 2550 5450 2450
Connection ~ 5450 2450
Wire Wire Line
	5350 2550 5350 2450
Connection ~ 5350 2450
Wire Wire Line
	5250 2550 5250 2450
Connection ~ 5250 2450
Text GLabel 4300 5600 0    50   BiDi ~ 0
uC:USB_D-
Text GLabel 4300 5700 0    50   BiDi ~ 0
uC:USB_D+
Wire Wire Line
	4300 5600 4400 5600
Wire Wire Line
	4300 5700 4400 5700
$Comp
L power:PWR_FLAG #FLG028
U 1 1 576383F9
P 5550 2350
F 0 "#FLG028" H 5550 2445 30  0001 C CNN
F 1 "PWR_FLAG" H 5550 2530 30  0000 C CNN
F 2 "" H 5550 2350 60  0000 C CNN
F 3 "" H 5550 2350 60  0000 C CNN
	1    5550 2350
	1    0    0    -1  
$EndComp
Text GLabel 4300 2850 0    50   Input ~ 0
uC:RST/PDI_CLK
Wire Wire Line
	4300 2850 4400 2850
Text GLabel 4300 5050 0    50   Input ~ 0
uC:FLIP_SW
Wire Wire Line
	4300 5050 4400 5050
$Comp
L solar_system_external_unit_board_2-rescue:CONN_3X2 P402
U 1 1 5776DD9B
P 9600 1200
F 0 "P402" H 9600 1450 50  0000 C CNN
F 1 "PDI" H 9600 1050 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03" H 9600 1200 60  0001 C CNN
F 3 "" H 9600 1200 60  0000 C CNN
	1    9600 1200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR029
U 1 1 5776E680
P 10100 950
F 0 "#PWR029" H 10100 1050 30  0001 C CNN
F 1 "VCC" H 10100 1050 30  0000 C CNN
F 2 "" H 10100 950 60  0000 C CNN
F 3 "" H 10100 950 60  0000 C CNN
	1    10100 950 
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR030
U 1 1 5776E6B5
P 10100 1350
F 0 "#PWR030" H 10100 1350 30  0001 C CNN
F 1 "GND" H 10100 1280 30  0001 C CNN
F 2 "" H 10100 1350 60  0000 C CNN
F 3 "" H 10100 1350 60  0000 C CNN
	1    10100 1350
	1    0    0    -1  
$EndComp
NoConn ~ 10000 1150
NoConn ~ 9200 1150
Text GLabel 4300 2950 0    50   Input ~ 0
uC:PDI_DATA
Wire Wire Line
	4300 2950 4400 2950
Text GLabel 9100 1250 0    50   Input ~ 0
uC:RST/PDI_CLK
Text GLabel 9100 1050 0    50   Input ~ 0
uC:PDI_DATA
Wire Wire Line
	9100 1050 9200 1050
Wire Wire Line
	9100 1250 9200 1250
Wire Wire Line
	10000 1050 10100 1050
Wire Wire Line
	10100 1050 10100 950 
Wire Wire Line
	10000 1250 10100 1250
Wire Wire Line
	10100 1250 10100 1350
Text GLabel 6500 5150 2    50   Input ~ 0
nRF_MISO
Text GLabel 6500 4750 2    50   Output ~ 0
nRF_IRQ
Text GLabel 6500 4850 2    50   Output ~ 0
nRF_CE
Text GLabel 6500 4950 2    50   Output ~ 0
nRF_CSN
Text GLabel 6500 5250 2    50   Output ~ 0
nRF_SCK
Text GLabel 6500 5050 2    50   Output ~ 0
nRF_MOSI
Text GLabel 6500 4650 2    50   Output ~ 0
nRF_PWR
Wire Wire Line
	6400 5250 6500 5250
Wire Wire Line
	6400 5150 6500 5150
Wire Wire Line
	6400 5050 6500 5050
Wire Wire Line
	6400 4950 6500 4950
Wire Wire Line
	6400 4850 6500 4850
Wire Wire Line
	6400 4750 6500 4750
Wire Wire Line
	6400 4650 6500 4650
Text GLabel 4300 3900 0    50   BiDi ~ 0
DHT_DATA
$Comp
L solar_system_external_unit_board_2-rescue:LED-RESCUE-solar_system_external_unit_board_2 D401
U 1 1 577844C8
P 3500 4750
F 0 "D401" H 3500 4850 50  0000 C CNN
F 1 "LED" H 3500 4650 50  0000 C CNN
F 2 "LEDs:LED_1206" H 3500 4750 60  0001 C CNN
F 3 "~" H 3500 4750 60  0000 C CNN
	1    3500 4750
	1    0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:R-RESCUE-solar_system_external_unit_board_2 R401
U 1 1 577844CF
P 4050 4750
F 0 "R401" V 4130 4750 40  0000 C CNN
F 1 "330R" V 4057 4751 40  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 3980 4750 30  0001 C CNN
F 3 "~" H 4050 4750 30  0000 C CNN
	1    4050 4750
	0    -1   -1   0   
$EndComp
NoConn ~ 4400 3700
NoConn ~ 4400 3800
NoConn ~ 4400 4000
NoConn ~ 4400 4100
NoConn ~ 4400 4200
NoConn ~ 4400 4300
NoConn ~ 4400 4400
NoConn ~ 4400 4650
NoConn ~ 4400 4850
NoConn ~ 4400 4950
NoConn ~ 4400 5150
NoConn ~ 4400 5250
NoConn ~ 4400 5400
NoConn ~ 4400 5500
NoConn ~ 6400 5400
NoConn ~ 6400 5500
NoConn ~ 6400 5600
NoConn ~ 6400 5700
$Comp
L solar_system_external_unit_board_2-rescue:SPST SW401
U 1 1 5779155C
P 1800 5600
F 0 "SW401" H 1800 5700 50  0000 C CNN
F 1 "RESET" H 1800 5500 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_Tactile_SPST_Angled" H 1800 5600 50  0001 C CNN
F 3 "" H 1800 5600 50  0000 C CNN
	1    1800 5600
	-1   0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:SPST SW402
U 1 1 577915D1
P 1800 6000
F 0 "SW402" H 1800 6100 50  0000 C CNN
F 1 "FLIP" H 1800 5900 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_Tactile_SPST_Angled" H 1800 6000 50  0001 C CNN
F 3 "" H 1800 6000 50  0000 C CNN
	1    1800 6000
	-1   0    0    -1  
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:CONN_9 P401
U 1 1 57937AAC
P 7250 4000
F 0 "P401" V 7200 4000 60  0000 C CNN
F 1 "PORT B" V 7300 4000 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x09" H 7250 4000 60  0001 C CNN
F 3 "" H 7250 4000 60  0000 C CNN
	1    7250 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3900 4400 3900
NoConn ~ 4400 4550
Text GLabel 2600 5600 2    50   Output ~ 0
uC:RST/PDI_CLK
Wire Wire Line
	2300 5600 2600 5600
Wire Wire Line
	1300 5600 1000 5600
Connection ~ 1000 6000
NoConn ~ 4400 3450
NoConn ~ 4400 3550
Wire Wire Line
	6400 3700 6900 3700
Wire Wire Line
	6400 3800 6900 3800
Wire Wire Line
	6400 3900 6900 3900
Wire Wire Line
	6400 4000 6900 4000
Wire Wire Line
	6400 4100 6900 4100
Wire Wire Line
	6400 4200 6900 4200
Wire Wire Line
	6400 4300 6900 4300
Wire Wire Line
	6400 4400 6900 4400
NoConn ~ 6400 2850
NoConn ~ 6400 2950
NoConn ~ 6400 3050
NoConn ~ 6400 3150
NoConn ~ 6400 3250
NoConn ~ 6400 3350
NoConn ~ 6400 3450
NoConn ~ 6400 3550
NoConn ~ 6400 4550
Wire Wire Line
	3200 4750 3300 4750
Wire Wire Line
	3700 4750 3800 4750
Wire Wire Line
	4300 4750 4400 4750
$Comp
L power:VCC #PWR031
U 1 1 57953AD2
P 3200 4650
F 0 "#PWR031" H 3200 4750 30  0001 C CNN
F 1 "VCC" H 3200 4750 30  0000 C CNN
F 2 "" H 3200 4650 60  0000 C CNN
F 3 "" H 3200 4650 60  0000 C CNN
	1    3200 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 4650 3200 4750
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR032
U 1 1 57F90E60
P 6800 3500
F 0 "#PWR032" H 6800 3500 30  0001 C CNN
F 1 "GND" H 6800 3430 30  0001 C CNN
F 2 "" H 6800 3500 60  0000 C CNN
F 3 "" H 6800 3500 60  0000 C CNN
	1    6800 3500
	-1   0    0    1   
$EndComp
Wire Wire Line
	6800 3500 6800 3600
Wire Wire Line
	6800 3600 6900 3600
$Comp
L solar_system_external_unit_board_2-rescue:CONN_1 P407
U 1 1 5803EAAA
P 2200 3100
F 0 "P407" H 2280 3100 40  0000 C CNN
F 1 "CONN_1" H 2150 3140 30  0001 C CNN
F 2 "Wire_Pads:SolderWirePad_single_0-8mmDrill" H 2200 3100 60  0001 C CNN
F 3 "" H 2200 3100 60  0000 C CNN
	1    2200 3100
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:CONN_1 P406
U 1 1 5803EB3D
P 2000 3100
F 0 "P406" H 2080 3100 40  0000 C CNN
F 1 "CONN_1" H 1950 3140 30  0001 C CNN
F 2 "Wire_Pads:SolderWirePad_single_0-8mmDrill" H 2000 3100 60  0001 C CNN
F 3 "" H 2000 3100 60  0000 C CNN
	1    2000 3100
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:CONN_1 P405
U 1 1 5803EB82
P 1800 3100
F 0 "P405" H 1880 3100 40  0000 C CNN
F 1 "CONN_1" H 1750 3140 30  0001 C CNN
F 2 "Wire_Pads:SolderWirePad_single_0-8mmDrill" H 1800 3100 60  0001 C CNN
F 3 "" H 1800 3100 60  0000 C CNN
	1    1800 3100
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:CONN_1 P404
U 1 1 5803EBCA
P 1600 3100
F 0 "P404" H 1680 3100 40  0000 C CNN
F 1 "CONN_1" H 1550 3140 30  0001 C CNN
F 2 "Wire_Pads:SolderWirePad_single_0-8mmDrill" H 1600 3100 60  0001 C CNN
F 3 "" H 1600 3100 60  0000 C CNN
	1    1600 3100
	0    -1   -1   0   
$EndComp
$Comp
L solar_system_external_unit_board_2-rescue:CONN_1 P403
U 1 1 5803EC15
P 1400 3100
F 0 "P403" H 1480 3100 40  0000 C CNN
F 1 "CONN_1" H 1350 3140 30  0001 C CNN
F 2 "Wire_Pads:SolderWirePad_single_0-8mmDrill" H 1400 3100 60  0001 C CNN
F 3 "" H 1400 3100 60  0000 C CNN
	1    1400 3100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1400 3250 1400 3350
Wire Wire Line
	1400 3350 1600 3350
Wire Wire Line
	2200 3250 2200 3350
Wire Wire Line
	2000 3250 2000 3350
Connection ~ 2000 3350
Wire Wire Line
	1800 3250 1800 3350
Connection ~ 1800 3350
Wire Wire Line
	1600 3250 1600 3350
Connection ~ 1600 3350
$Comp
L solar_system_external_unit_board_2-rescue:GND-RESCUE-solar_system_external_unit_board_2 #PWR033
U 1 1 5803EE42
P 2200 3450
F 0 "#PWR033" H 2200 3450 30  0001 C CNN
F 1 "GND" H 2200 3380 30  0001 C CNN
F 2 "" H 2200 3450 60  0000 C CNN
F 3 "" H 2200 3450 60  0000 C CNN
	1    2200 3450
	1    0    0    -1  
$EndComp
Connection ~ 2200 3350
Wire Wire Line
	2200 1900 2200 2000
Wire Wire Line
	2000 1900 2200 1900
Wire Wire Line
	1800 1900 2000 1900
Wire Wire Line
	1600 1900 1800 1900
Wire Wire Line
	1400 1900 1600 1900
Wire Wire Line
	1400 2500 1600 2500
Wire Wire Line
	1600 2500 1800 2500
Wire Wire Line
	1800 2500 2000 2500
Wire Wire Line
	2000 2500 2200 2500
Wire Wire Line
	2200 2500 2200 2600
Wire Wire Line
	5150 6100 5150 6350
Wire Wire Line
	5550 6100 5650 6100
Wire Wire Line
	5450 6100 5550 6100
Wire Wire Line
	5350 6100 5450 6100
Wire Wire Line
	5250 6100 5350 6100
Wire Wire Line
	5150 2450 5150 2550
Wire Wire Line
	5550 2450 5750 2450
Wire Wire Line
	5550 2450 5550 2550
Wire Wire Line
	5450 2450 5550 2450
Wire Wire Line
	5350 2450 5450 2450
Wire Wire Line
	5250 2450 5350 2450
Wire Wire Line
	1000 6000 1000 6700
Wire Wire Line
	2000 3350 2200 3350
Wire Wire Line
	1800 3350 2000 3350
Wire Wire Line
	1600 3350 1800 3350
Wire Wire Line
	2200 3350 2200 3450
$EndSCHEMATC
