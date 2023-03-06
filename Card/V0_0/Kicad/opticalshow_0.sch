EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Optical show Wemos Mini card"
Date "2023-02-09"
Rev "0.00"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 5400 3150
NoConn ~ 4600 3050
NoConn ~ 4600 3150
$Comp
L power:+3V3 #PWR04
U 1 1 61BE574C
P 5100 1700
F 0 "#PWR04" H 5100 1550 50  0001 C CNN
F 1 "+3V3" H 5150 1850 50  0000 C CNN
F 2 "" H 5100 1700 50  0001 C CNN
F 3 "" H 5100 1700 50  0001 C CNN
	1    5100 1700
	1    0    0    -1  
$EndComp
Text Notes 5250 5900 0    98   ~ 0
PCB holes
$Comp
L Mechanical:MountingHole H2
U 1 1 6220BD61
P 5750 6150
F 0 "H2" H 5850 6196 50  0000 L CNN
F 1 "Hole" H 5850 6105 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 5750 6150 50  0001 C CNN
F 3 "~" H 5750 6150 50  0001 C CNN
	1    5750 6150
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 6220B557
P 5300 6150
F 0 "H1" H 5400 6196 50  0000 L CNN
F 1 "Hole" H 5400 6105 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 5300 6150 50  0001 C CNN
F 3 "~" H 5300 6150 50  0001 C CNN
	1    5300 6150
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:WeMos_D1_mini U1
U 1 1 614DE584
P 5000 3150
F 0 "U1" H 4550 2350 50  0000 C CNN
F 1 "WeMos_D1_mini" H 4600 2250 50  0000 C CNN
F 2 "Module:WEMOS_D1_mini_light" H 5000 2000 50  0001 C CNN
F 3 "https://wiki.wemos.cc/products:d1:d1_mini#documentation" H 3150 2000 50  0001 C CNN
	1    5000 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3950 5000 4050
NoConn ~ 5400 2850
NoConn ~ 5400 2950
NoConn ~ 5400 3050
NoConn ~ 5400 3550
$Comp
L Switch:SW_Push_Dual SW1
U 1 1 62789D52
P 6100 3700
F 0 "SW1" H 6100 3850 50  0000 C CNN
F 1 "SW_Push_Dual" H 6100 3200 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6100 3900 50  0001 C CNN
F 3 "~" H 6100 3900 50  0001 C CNN
	1    6100 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3900 5700 3900
Wire Wire Line
	5700 3700 5900 3700
Wire Wire Line
	6300 3700 6450 3700
Wire Wire Line
	6450 3700 6450 3900
Wire Wire Line
	6300 3900 6450 3900
Connection ~ 6450 3900
Wire Wire Line
	6450 3900 6450 4050
Wire Wire Line
	5100 2350 5100 1850
Wire Wire Line
	6550 1850 5100 1850
Connection ~ 5100 1850
Wire Wire Line
	5100 1850 5100 1700
Wire Wire Line
	5550 1950 5550 2650
Wire Wire Line
	5550 2650 5400 2650
$Comp
L power:GND #PWR05
U 1 1 621ABC4B
P 5000 4350
F 0 "#PWR05" H 5000 4100 50  0001 C CNN
F 1 "GND" H 5005 4177 50  0000 C CNN
F 2 "" H 5000 4350 50  0001 C CNN
F 3 "" H 5000 4350 50  0001 C CNN
	1    5000 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 627A7318
P 6300 2300
F 0 "#PWR02" H 6300 2050 50  0001 C CNN
F 1 "GND" H 6305 2127 50  0000 C CNN
F 2 "" H 6300 2300 50  0001 C CNN
F 3 "" H 6300 2300 50  0001 C CNN
	1    6300 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4350 5000 4050
Connection ~ 5000 4050
$Comp
L power:GND #PWR01
U 1 1 627B2564
P 2900 2200
F 0 "#PWR01" H 2900 1950 50  0001 C CNN
F 1 "GND" H 2905 2027 50  0000 C CNN
F 2 "" H 2900 2200 50  0001 C CNN
F 3 "" H 2900 2200 50  0001 C CNN
	1    2900 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 1950 2900 1950
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 627B43B4
P 3300 1950
F 0 "#FLG0102" H 3300 2025 50  0001 C CNN
F 1 "PWR_FLAG" H 3300 2123 50  0000 C CNN
F 2 "" H 3300 1950 50  0001 C CNN
F 3 "~" H 3300 1950 50  0001 C CNN
	1    3300 1950
	-1   0    0    1   
$EndComp
Wire Wire Line
	2900 1950 3300 1950
Connection ~ 2900 1950
$Comp
L Device:D D1
U 1 1 627C02C3
P 4150 1850
F 0 "D1" H 4150 1633 50  0000 C CNN
F 1 "D" H 4150 1724 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P2.54mm_Vertical_AnodeUp" H 4150 1850 50  0001 C CNN
F 3 "~" H 4150 1850 50  0001 C CNN
	1    4150 1850
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 627C86EF
P 4600 1700
F 0 "#FLG0101" H 4600 1775 50  0001 C CNN
F 1 "PWR_FLAG" H 4600 1873 50  0000 C CNN
F 2 "" H 4600 1700 50  0001 C CNN
F 3 "~" H 4600 1700 50  0001 C CNN
	1    4600 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1700 4600 1850
Wire Wire Line
	4900 1850 4900 2350
$Comp
L Switch:SW_Push_Dual SW2
U 1 1 63E59DD2
P 9100 3350
F 0 "SW2" H 9100 3635 50  0000 C CNN
F 1 "SW_Push_Dual" H 9100 3544 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 9100 3550 50  0001 C CNN
F 3 "~" H 9100 3550 50  0001 C CNN
	1    9100 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3350 8700 3350
Wire Wire Line
	8900 3550 8700 3550
Wire Wire Line
	8700 3550 8700 3350
Connection ~ 8700 3350
Wire Wire Line
	8700 3350 8900 3350
Wire Wire Line
	9300 3350 9450 3350
Wire Wire Line
	9450 3350 9450 3550
Wire Wire Line
	9300 3550 9450 3550
Connection ~ 9450 3550
Wire Wire Line
	9450 3550 9450 4050
Wire Wire Line
	5400 3450 5700 3450
Wire Wire Line
	5700 3450 5700 3700
Connection ~ 5700 3700
Wire Wire Line
	5700 3700 5700 3900
NoConn ~ 4600 2750
NoConn ~ 5400 2750
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 63E65818
P 2450 1850
F 0 "J1" H 2400 1600 50  0000 L CNN
F 1 "Conn_01x02" H 2250 1450 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-5.0-H_1x02_P5.00mm_Horizontal" H 2450 1850 50  0001 C CNN
F 3 "~" H 2450 1850 50  0001 C CNN
	1    2450 1850
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 63E6672F
P 6750 1950
F 0 "J2" H 6700 1700 50  0000 L CNN
F 1 "Conn_01x03" H 6700 1600 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-3-5.0-H_1x03_P5.00mm_Horizontal" H 6750 1950 50  0001 C CNN
F 3 "~" H 6750 1950 50  0001 C CNN
	1    6750 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 1950 2900 2200
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 63E6E69C
P 7200 3650
F 0 "J4" H 7150 3450 50  0000 L CNN
F 1 "Conn_01x02" H 7150 3350 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-5.0-H_1x02_P5.00mm_Horizontal" H 7200 3650 50  0001 C CNN
F 3 "~" H 7200 3650 50  0001 C CNN
	1    7200 3650
	1    0    0    -1  
$EndComp
Connection ~ 6450 4050
Wire Wire Line
	6450 4050 5000 4050
Wire Wire Line
	6450 4050 6900 4050
Wire Wire Line
	5700 3450 6900 3450
Wire Wire Line
	6900 3450 6900 3650
Wire Wire Line
	6900 3650 7000 3650
Connection ~ 5700 3450
Wire Wire Line
	7000 3750 6900 3750
Wire Wire Line
	6900 3750 6900 4050
Wire Wire Line
	6900 4050 9450 4050
Connection ~ 6900 4050
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 63E7F30B
P 9800 2600
F 0 "J3" H 9750 2350 50  0000 L CNN
F 1 "Conn_01x02" H 9750 2250 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-5.0-H_1x02_P5.00mm_Horizontal" H 9800 2600 50  0001 C CNN
F 3 "~" H 9800 2600 50  0001 C CNN
	1    9800 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 3350 9450 2700
Wire Wire Line
	9450 2700 9600 2700
Connection ~ 9450 3350
Wire Wire Line
	8700 3350 8700 2600
Wire Wire Line
	8700 2600 9600 2600
Wire Wire Line
	6550 1950 5550 1950
Wire Wire Line
	6550 2050 6300 2050
Wire Wire Line
	6300 2050 6300 2300
Text Notes 2150 1850 0    50   ~ 0
5Vdc
Text Notes 2150 2000 0    50   ~ 0
0Vdc
Connection ~ 4600 1850
Wire Wire Line
	4600 1850 4900 1850
Wire Wire Line
	4300 1850 4600 1850
$Comp
L Device:Fuse F1
U 1 1 63E8B60D
P 3700 1850
F 0 "F1" V 3503 1850 50  0000 C CNN
F 1 "Fuse 0,5 A" V 3594 1850 50  0000 C CNN
F 2 "Fuse:Fuseholder_Cylinder-5x20mm_Schurter_0031_8201_Horizontal_Open" V 3630 1850 50  0001 C CNN
F 3 "~" H 3700 1850 50  0001 C CNN
	1    3700 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	4000 1850 3850 1850
Wire Wire Line
	3550 1850 2650 1850
$Comp
L Device:R_POT RV1
U 1 1 63E930E6
P 7750 1950
F 0 "RV1" H 7680 1904 50  0000 R CNN
F 1 "R_POT" H 7680 1995 50  0000 R CNN
F 2 "" H 7750 1950 50  0001 C CNN
F 3 "~" H 7750 1950 50  0001 C CNN
	1    7750 1950
	-1   0    0    1   
$EndComp
NoConn ~ 7600 1950
NoConn ~ 7750 1800
NoConn ~ 7750 2100
Wire Notes Line
	6800 1950 7600 1950
Wire Notes Line
	6800 1850 7500 1850
Wire Notes Line
	7500 1850 7500 1700
Wire Notes Line
	7500 1700 7750 1700
Wire Notes Line
	7750 1700 7750 1800
Wire Notes Line
	6800 2050 7500 2050
Wire Notes Line
	7500 2050 7500 2200
Wire Notes Line
	7500 2200 7750 2200
Wire Notes Line
	7750 2200 7750 2100
Text Notes 9950 2700 0    50   ~ 0
External Push Button
Text Notes 8200 2000 0    50   ~ 0
External Pot. 5K
Text Notes 7350 3750 0    50   ~ 0
External Push Button
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 63E7D030
P 7250 2700
F 0 "J5" H 7200 2500 50  0000 L CNN
F 1 "Conn_01x02" H 7200 2400 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-5.0-H_1x02_P5.00mm_Horizontal" H 7250 2700 50  0001 C CNN
F 3 "~" H 7250 2700 50  0001 C CNN
	1    7250 2700
	1    0    0    -1  
$EndComp
Text Notes 7400 2800 0    50   ~ 0
To leds
$Comp
L power:GND #PWR?
U 1 1 63E7F8FF
P 7000 3000
F 0 "#PWR?" H 7000 2750 50  0001 C CNN
F 1 "GND" H 7005 2827 50  0000 C CNN
F 2 "" H 7000 3000 50  0001 C CNN
F 3 "" H 7000 3000 50  0001 C CNN
	1    7000 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 3000 7000 2800
Wire Wire Line
	7000 2800 7050 2800
Wire Wire Line
	5400 3250 6650 3250
Wire Wire Line
	6650 3250 6650 2700
Wire Wire Line
	6650 2700 7050 2700
$EndSCHEMATC
