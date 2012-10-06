EESchema Schematic File Version 2  date sam. 06 oct. 2012 19:37:23 CEST
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
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "6 oct 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5950 2800 5950 2650
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
Wire Wire Line
	3350 3100 3550 3100
Wire Wire Line
	4250 3450 5150 3450
Wire Wire Line
	4150 3650 5150 3650
Wire Wire Line
	4050 3850 5150 3850
Wire Wire Line
	3900 4050 5150 4050
Wire Wire Line
	5150 4050 5150 4000
Wire Wire Line
	6750 3650 6850 3650
Wire Wire Line
	3350 3800 3900 3800
Wire Wire Line
	3350 3900 3500 3900
Wire Wire Line
	3350 4000 3500 4000
Wire Wire Line
	3500 4000 3500 4150
$Comp
L GND #PWR02
U 1 1 50706369
P 3500 4150
F 0 "#PWR02" H 3500 4150 30  0001 C CNN
F 1 "GND" H 3500 4080 30  0001 C CNN
	1    3500 4150
	1    0    0    -1  
$EndComp
Text Label 3550 3100 0    60   ~ 0
Vcc
Text Label 3550 3200 0    60   ~ 0
outa
Text Label 3500 3900 0    60   ~ 0
outb
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
Wire Wire Line
	6700 4550 6700 4750
Wire Wire Line
	6700 4750 7100 4750
Wire Wire Line
	7100 4350 7100 4250
Text Label 7100 4250 0    60   ~ 0
Vcc
$Comp
L PWR_FLAG #FLG03
U 1 1 507063E1
P 3350 3100
F 0 "#FLG03" H 3350 3195 30  0001 C CNN
F 1 "PWR_FLAG" H 3350 3280 30  0000 C CNN
	1    3350 3100
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG04
U 1 1 507063F1
P 3350 4000
F 0 "#FLG04" H 3350 4095 30  0001 C CNN
F 1 "PWR_FLAG" H 3350 4180 30  0000 C CNN
	1    3350 4000
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
Wire Wire Line
	6750 3200 6750 3500
Connection ~ 6750 3300
Connection ~ 6750 3400
Wire Wire Line
	6750 3400 6850 3400
Wire Wire Line
	6750 3800 6750 4100
Connection ~ 6750 3900
Connection ~ 6750 4000
Wire Wire Line
	6750 3900 6850 3900
Wire Wire Line
	5800 2800 6100 2800
Connection ~ 5900 2800
Connection ~ 5950 2800
Connection ~ 6000 2800
Wire Wire Line
	5650 4550 6700 4550
Connection ~ 5750 4550
Wire Wire Line
	5950 4550 5950 4650
Connection ~ 5850 4550
Connection ~ 5950 4550
Connection ~ 6050 4550
Connection ~ 6150 4550
Connection ~ 6250 4550
Wire Wire Line
	4150 3650 4150 3500
Wire Wire Line
	4150 3500 3350 3500
Wire Wire Line
	4250 3300 4250 3450
Wire Wire Line
	3350 3200 3550 3200
Wire Wire Line
	4250 3300 3350 3300
Wire Wire Line
	3350 3400 4550 3400
Wire Wire Line
	4550 3400 4550 3300
Wire Wire Line
	4550 3300 5150 3300
Wire Wire Line
	3900 3800 3900 4050
Wire Wire Line
	4050 3850 4050 3700
Wire Wire Line
	4050 3700 3350 3700
Wire Wire Line
	3350 3600 3500 3600
Text Label 3500 3600 0    60   ~ 0
cs
$EndSCHEMATC
