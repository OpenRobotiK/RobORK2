EESchema Schematic File Version 2  date 12/10/2012 19:14:29
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Carte_PontH-cache
LIBS:test
LIBS:robot 2013-cache
LIBS:vnh2sp30-e
LIBS:PontH_V01-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "12 oct 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 8350 2900 0    60   ~ 0
INa
$Comp
L CONN_5 P?
U 1 1 50784F9C
P 9100 3000
F 0 "P?" V 9050 3000 50  0000 C CNN
F 1 "CONN_5" V 9150 3000 50  0000 C CNN
	1    9100 3000
	1    0    0    -1  
$EndComp
Connection ~ 5950 2100
Wire Wire Line
	7550 2100 4200 2100
Wire Wire Line
	4200 2100 4200 2300
Wire Wire Line
	4200 3300 5150 3300
Connection ~ 7350 2450
Wire Wire Line
	7350 2450 7600 2450
Wire Wire Line
	7600 2450 7600 2550
Wire Wire Line
	7700 3700 7500 3700
Wire Wire Line
	7500 3700 7500 3900
Wire Wire Line
	4650 3450 5150 3450
Wire Wire Line
	3350 3600 3500 3600
Wire Wire Line
	3350 3200 3550 3200
Connection ~ 6250 4550
Connection ~ 6150 4550
Connection ~ 6050 4550
Connection ~ 5950 4550
Connection ~ 5850 4550
Wire Wire Line
	5950 4550 5950 4650
Connection ~ 5750 4550
Wire Wire Line
	5650 4550 6700 4550
Connection ~ 6000 2800
Connection ~ 5950 2800
Connection ~ 5900 2800
Wire Wire Line
	5800 2800 6100 2800
Connection ~ 6750 4000
Connection ~ 6750 3900
Wire Wire Line
	6750 3800 6750 4100
Wire Wire Line
	6750 3400 6850 3400
Connection ~ 6750 3400
Connection ~ 6750 3300
Wire Wire Line
	6750 3200 6750 3500
Wire Wire Line
	7100 4350 7100 4250
Wire Wire Line
	7100 4750 6700 4750
Wire Wire Line
	6700 4750 6700 4550
Wire Wire Line
	3500 4150 3500 4000
Wire Wire Line
	3500 4000 3350 4000
Wire Wire Line
	3350 3900 3500 3900
Wire Wire Line
	6750 3650 6850 3650
Wire Wire Line
	5150 4000 4650 4000
Wire Wire Line
	5150 3650 4650 3650
Wire Wire Line
	7700 3500 6850 3500
Wire Wire Line
	6850 3500 6850 3400
Wire Wire Line
	7500 3900 6750 3900
Wire Wire Line
	7550 2300 7350 2300
Wire Wire Line
	7350 2300 7350 2750
Wire Wire Line
	5950 2100 5950 2800
Wire Wire Line
	5150 3850 4200 3850
Wire Wire Line
	4200 3850 4200 2800
Connection ~ 4200 3300
$Comp
L R R1
U 1 1 50784EF5
P 4200 2550
F 0 "R1" V 4280 2550 50  0000 C CNN
F 1 "3k3" V 4200 2550 50  0000 C CNN
	1    4200 2550
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P?
U 1 1 507845E2
P 7900 2200
F 0 "P?" V 7850 2200 40  0000 C CNN
F 1 "CONN_2" V 7950 2200 40  0000 C CNN
	1    7900 2200
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P?
U 1 1 507845CF
P 8050 3600
F 0 "P?" V 8000 3600 40  0000 C CNN
F 1 "CONN_2" V 8100 3600 40  0000 C CNN
	1    8050 3600
	1    0    0    -1  
$EndComp
Text Label 4650 4000 0    60   ~ 0
INb
Text Label 4650 3650 0    60   ~ 0
PWM
Text Label 4650 3450 0    60   ~ 0
INa
$Comp
L GND #PWR01
U 1 1 507061DF
P 5950 4650
F 0 "#PWR01" H 5950 4650 30  0001 C CNN
F 1 "GND" H 5950 4580 30  0001 C CNN
	1    5950 4650
	1    0    0    -1  
$EndComp
Text Label 5950 2650 0    60   ~ 0
Vcc
$Comp
L CONN_10 P1
U 1 1 5070620F
P 3000 3550
F 0 "P1" V 2950 3550 60  0000 C CNN
F 1 "CONN_10" V 3050 3550 60  0000 C CNN
	1    3000 3550
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR02
U 1 1 50706369
P 7350 2750
F 0 "#PWR02" H 7350 2750 30  0001 C CNN
F 1 "GND" H 7350 2680 30  0001 C CNN
	1    7350 2750
	1    0    0    -1  
$EndComp
Text Label 7400 2100 0    60   ~ 0
Vcc
Text Label 6850 3400 0    60   ~ 0
outa
Text Label 6850 3650 0    60   ~ 0
cs
Text Label 6850 3900 0    60   ~ 0
outb
$Comp
L DIODESCH D1
U 1 1 50706378
P 7100 4550
F 0 "D1" H 7100 4650 40  0000 C CNN
F 1 "DIODESCH" H 7100 4450 40  0000 C CNN
	1    7100 4550
	0    -1   -1   0   
$EndComp
Text Label 7100 4250 0    60   ~ 0
Vcc
$Comp
L PWR_FLAG #FLG03
U 1 1 507063E1
P 6600 2100
F 0 "#FLG03" H 6600 2195 30  0001 C CNN
F 1 "PWR_FLAG" H 6600 2280 30  0000 C CNN
	1    6600 2100
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG04
U 1 1 507063F1
P 7600 2550
F 0 "#FLG04" H 7600 2645 30  0001 C CNN
F 1 "PWR_FLAG" H 7600 2730 30  0000 C CNN
	1    7600 2550
	-1   0    0    1   
$EndComp
$Comp
L VNH2SP30-E H1
U 1 1 507069AB
P 5950 3650
F 0 "H1" H 5950 3600 60  0000 C CNN
F 1 "VNH2SP30-E" H 5950 3700 60  0000 C CNN
	1    5950 3650
	1    0    0    -1  
$EndComp
Text Label 8350 2800 0    60   ~ 0
cs
$EndSCHEMATC
