EESchema Schematic File Version 2  date mer. 26 sept. 2012 17:44:52 CEST
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
LIBS:robot 2013-cache
EELAYER 43  0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "26 sep 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L VNH2SP30-E H?
U 1 1 5063095E
P 5850 3800
F 0 "H?" H 5850 3750 60  0000 C CNN
F 1 "VNH2SP30-E" H 5850 3850 60  0000 C CNN
	1    5850 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 4700 6150 4700
Connection ~ 5650 4700
Connection ~ 5750 4700
Connection ~ 5950 4700
Connection ~ 6050 4700
$Comp
L R R?
U 1 1 506317C7
P 1500 2500
F 0 "R?" V 1580 2500 50  0000 C CNN
F 1 "1k" V 1500 2500 50  0000 C CNN
	1    1500 2500
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 506317E6
P 1500 3550
F 0 "R?" V 1580 3550 50  0000 C CNN
F 1 "1k" V 1500 3550 50  0000 C CNN
	1    1500 3550
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 506317F8
P 1850 2150
F 0 "R?" V 1930 2150 50  0000 C CNN
F 1 "3,3k" V 1850 2150 50  0000 C CNN
	1    1850 2150
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 50631840
P 1850 3250
F 0 "R?" V 1930 3250 50  0000 C CNN
F 1 "3,3k" V 1850 3250 50  0000 C CNN
	1    1850 3250
	-1   0    0    1   
$EndComp
Wire Wire Line
	1750 2500 2050 2500
Wire Wire Line
	1850 2500 1850 2400
Wire Wire Line
	1750 3550 2050 3550
Wire Wire Line
	1850 3550 1850 3500
Wire Wire Line
	1850 3000 1850 2900
Wire Wire Line
	1850 1900 1850 1800
Wire Wire Line
	1250 2500 1100 2500
Wire Wire Line
	1250 3550 1150 3550
Connection ~ 1850 2500
Connection ~ 1850 3550
Text Label 1850 1800 0    60   ~ 0
+5V
Text Label 1850 2900 0    60   ~ 0
+5V
$Comp
L R R?
U 1 1 50631988
P 4700 3600
F 0 "R?" V 4780 3600 50  0000 C CNN
F 1 "1k" V 4700 3600 50  0000 C CNN
	1    4700 3600
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5063198E
P 4700 4150
F 0 "R?" V 4780 4150 50  0000 C CNN
F 1 "1k" V 4700 4150 50  0000 C CNN
	1    4700 4150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4950 3600 5050 3600
Wire Wire Line
	4950 4150 5050 4150
Wire Wire Line
	4450 3600 4350 3600
Wire Wire Line
	4450 4150 4350 4150
Wire Wire Line
	6650 3450 6650 3650
Connection ~ 6650 3550
Wire Wire Line
	6650 3550 6800 3550
Wire Wire Line
	6650 3950 6650 4150
Connection ~ 6650 4050
Wire Wire Line
	6650 4050 6800 4050
$Comp
L R R?
U 1 1 50631AB3
P 7850 3800
F 0 "R?" V 7930 3800 50  0000 C CNN
F 1 "10k" V 7850 3800 50  0000 C CNN
	1    7850 3800
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 50631AC2
P 7450 4100
F 0 "R?" V 7530 4100 50  0000 C CNN
F 1 "1,5k" V 7450 4100 50  0000 C CNN
	1    7450 4100
	-1   0    0    1   
$EndComp
Wire Wire Line
	6650 3800 7600 3800
Wire Wire Line
	7450 3800 7450 3850
Connection ~ 7450 3800
$Comp
L GND #PWR?
U 1 1 50631BAF
P 7450 4450
F 0 "#PWR?" H 7450 4450 30  0001 C CNN
F 1 "GND" H 7450 4380 30  0001 C CNN
	1    7450 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 4350 7450 4450
$Comp
L C C?
U 1 1 50631BF6
P 8250 4050
F 0 "C?" H 8300 4150 50  0000 L CNN
F 1 "33n" H 8300 3950 50  0000 L CNN
	1    8250 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3800 8500 3800
Wire Wire Line
	8250 3800 8250 3850
Wire Wire Line
	8250 4250 8250 4350
$Comp
L GND #PWR?
U 1 1 50631C4D
P 8250 4350
F 0 "#PWR?" H 8250 4350 30  0001 C CNN
F 1 "GND" H 8250 4280 30  0001 C CNN
	1    8250 4350
	1    0    0    -1  
$EndComp
Connection ~ 8250 3800
$Comp
L R R?
U 1 1 50631CBE
P 4700 3800
F 0 "R?" V 4780 3800 50  0000 C CNN
F 1 "1k" V 4700 3800 50  0000 C CNN
	1    4700 3800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4950 3800 5050 3800
Wire Wire Line
	4450 3800 4350 3800
Wire Wire Line
	5750 2950 5950 2950
Connection ~ 5850 2950
Wire Wire Line
	5850 2950 5850 2850
Text Label 5850 2850 0    60   ~ 0
Vcc
$Comp
L CAPAPOL C?
U 1 1 50631DA3
P 6350 5100
F 0 "C?" H 6400 5200 50  0000 L CNN
F 1 "CAPAPOL" H 6400 5000 50  0000 L CNN
	1    6350 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 5300 8050 5300
Wire Wire Line
	6150 4700 6150 5300
Wire Wire Line
	6350 4900 6350 4850
Text Label 6350 4850 0    60   ~ 0
Vcc
$Comp
L DIODESCH D?
U 1 1 50631EDC
P 7200 5100
F 0 "D?" H 7200 5200 40  0000 C CNN
F 1 "DIODESCH" H 7200 5000 40  0000 C CNN
	1    7200 5100
	0    -1   -1   0   
$EndComp
Connection ~ 6350 5300
$Comp
L R R?
U 1 1 50632036
P 6950 4900
F 0 "R?" V 7030 4900 50  0000 C CNN
F 1 "100k" V 6950 4900 50  0000 C CNN
	1    6950 4900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6350 4900 6700 4900
Wire Wire Line
	7200 4900 7500 4900
$Comp
L MOSFET_N Q?
U 1 1 5063218F
P 7950 5100
F 0 "Q?" H 7960 5270 60  0000 R CNN
F 1 "MOSFET_N" H 7960 4950 60  0000 R CNN
	1    7950 5100
	1    0    0    -1  
$EndComp
Connection ~ 7200 5300
Wire Wire Line
	7500 4900 7500 5100
Wire Wire Line
	7500 5100 7750 5100
Wire Wire Line
	8050 4900 8050 4800
Wire Wire Line
	8050 4800 8250 4800
Wire Wire Line
	8250 4800 8250 4850
$Comp
L GND #PWR?
U 1 1 50632269
P 8250 4850
F 0 "#PWR?" H 8250 4850 30  0001 C CNN
F 1 "GND" H 8250 4780 30  0001 C CNN
	1    8250 4850
	1    0    0    -1  
$EndComp
$EndSCHEMATC
