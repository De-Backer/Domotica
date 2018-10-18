EESchema Schematic File Version 4
LIBS:module_8x_100VDC_16A_out-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Transistor_FET:IRF540N Q1
U 1 1 5BB7B7B0
P 2950 2050
F 0 "Q1" H 3156 2096 50  0000 L CNN
F 1 "IRF540N" H 3156 2005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 3200 1975 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 2950 2050 50  0001 L CNN
	1    2950 2050
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 5BB7B838
P 3150 2400
F 0 "R10" V 2943 2400 50  0000 C CNN
F 1 "R" V 3034 2400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3080 2400 50  0001 C CNN
F 3 "~" H 3150 2400 50  0001 C CNN
	1    3150 2400
	0    1    1    0   
$EndComp
$Comp
L Isolator:PC847 U1
U 1 1 5BB7BA1E
P 3850 1950
F 0 "U1" H 3850 2275 50  0000 C CNN
F 1 "PC847" H 3850 2184 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 3650 1750 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 3850 1950 50  0001 L CNN
	1    3850 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5BB7BA88
P 4400 1850
F 0 "R1" V 4193 1850 50  0000 C CNN
F 1 "330R" V 4284 1850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4330 1850 50  0001 C CNN
F 3 "~" H 4400 1850 50  0001 C CNN
	1    4400 1850
	0    1    1    0   
$EndComp
$Comp
L Device:LED D1
U 1 1 5BB7BB53
P 4400 2050
F 0 "D1" H 4392 1795 50  0000 C CNN
F 1 "LED" H 4392 1886 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 4400 2050 50  0001 C CNN
F 3 "~" H 4400 2050 50  0001 C CNN
	1    4400 2050
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 1850 4150 1850
Wire Wire Line
	4250 2050 4150 2050
Wire Wire Line
	3150 2050 3350 2050
Wire Wire Line
	2850 2250 2850 2400
Wire Wire Line
	2850 2400 3000 2400
Wire Wire Line
	3300 2400 3350 2400
Wire Wire Line
	3350 2400 3350 2050
Connection ~ 3350 2050
Wire Wire Line
	3350 2050 3550 2050
$Comp
L Connector:Conn_01x10_Male J1
U 1 1 5BB7BCF1
P 10150 3000
F 0 "J1" H 10123 2973 50  0000 R CNN
F 1 "Conn_01x10_Male" H 10123 2882 50  0000 R CNN
F 2 "Connector_JST:JST_XH_B10B-XH-A_1x10_P2.50mm_Vertical" H 10150 3000 50  0001 C CNN
F 3 "~" H 10150 3000 50  0001 C CNN
	1    10150 3000
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x09_Male J2
U 1 1 5BB7BFF2
P 900 3650
F 0 "J2" H 1006 4228 50  0000 C CNN
F 1 "Conn_01x09_Male" H 1006 4137 50  0000 C CNN
F 2 "Connector_Phoenix_MSTB:PhoenixContact_MSTBVA_2,5_9-G-5,08_1x09_P5.08mm_Vertical" H 900 3650 50  0001 C CNN
F 3 "~" H 900 3650 50  0001 C CNN
	1    900  3650
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRF540N Q2
U 1 1 5BB7C6F7
P 2950 3000
F 0 "Q2" H 3156 3046 50  0000 L CNN
F 1 "IRF540N" H 3156 2955 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 3200 2925 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 2950 3000 50  0001 L CNN
	1    2950 3000
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 5BB7C6FD
P 3150 3350
F 0 "R11" V 2943 3350 50  0000 C CNN
F 1 "R" V 3034 3350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3080 3350 50  0001 C CNN
F 3 "~" H 3150 3350 50  0001 C CNN
	1    3150 3350
	0    1    1    0   
$EndComp
$Comp
L Isolator:PC847 U1
U 2 1 5BB7C703
P 3850 2900
F 0 "U1" H 3850 3225 50  0000 C CNN
F 1 "PC847" H 3850 3134 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 3650 2700 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 3850 2900 50  0001 L CNN
	2    3850 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5BB7C709
P 4400 2800
F 0 "R2" V 4193 2800 50  0000 C CNN
F 1 "330R" V 4284 2800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4330 2800 50  0001 C CNN
F 3 "~" H 4400 2800 50  0001 C CNN
	1    4400 2800
	0    1    1    0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5BB7C70F
P 4400 3000
F 0 "D2" H 4392 2745 50  0000 C CNN
F 1 "LED" H 4392 2836 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 4400 3000 50  0001 C CNN
F 3 "~" H 4400 3000 50  0001 C CNN
	1    4400 3000
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 2800 4150 2800
Wire Wire Line
	4250 3000 4150 3000
Wire Wire Line
	3150 3000 3350 3000
Wire Wire Line
	2850 3200 2850 3350
Wire Wire Line
	2850 3350 3000 3350
Wire Wire Line
	3300 3350 3350 3350
Wire Wire Line
	3350 3350 3350 3000
Connection ~ 3350 3000
Wire Wire Line
	3350 3000 3550 3000
$Comp
L Transistor_FET:IRF540N Q3
U 1 1 5BB7CA40
P 2950 4100
F 0 "Q3" H 3156 4146 50  0000 L CNN
F 1 "IRF540N" H 3156 4055 50  0000 L CNN
F 2 "LIB:TO-220-3_Horizontal_TabUp_no_hole" H 3200 4025 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 2950 4100 50  0001 L CNN
	1    2950 4100
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5BB7CA47
P 3150 4450
F 0 "R12" V 2943 4450 50  0000 C CNN
F 1 "R" V 3034 4450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3080 4450 50  0001 C CNN
F 3 "~" H 3150 4450 50  0001 C CNN
	1    3150 4450
	0    1    1    0   
$EndComp
$Comp
L Isolator:PC847 U1
U 3 1 5BB7CA4E
P 3850 4000
F 0 "U1" H 3850 4325 50  0000 C CNN
F 1 "PC847" H 3850 4234 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 3650 3800 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 3850 4000 50  0001 L CNN
	3    3850 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5BB7CA55
P 4400 3900
F 0 "R3" V 4193 3900 50  0000 C CNN
F 1 "330R" V 4284 3900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4330 3900 50  0001 C CNN
F 3 "~" H 4400 3900 50  0001 C CNN
	1    4400 3900
	0    1    1    0   
$EndComp
$Comp
L Device:LED D3
U 1 1 5BB7CA5C
P 4400 4100
F 0 "D3" H 4392 3845 50  0000 C CNN
F 1 "LED" H 4392 3936 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 4400 4100 50  0001 C CNN
F 3 "~" H 4400 4100 50  0001 C CNN
	1    4400 4100
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 3900 4150 3900
Wire Wire Line
	4250 4100 4150 4100
Wire Wire Line
	3150 4100 3350 4100
Wire Wire Line
	2850 4300 2850 4450
Wire Wire Line
	2850 4450 3000 4450
Wire Wire Line
	3300 4450 3350 4450
Wire Wire Line
	3350 4450 3350 4100
Connection ~ 3350 4100
Wire Wire Line
	3350 4100 3550 4100
$Comp
L Transistor_FET:IRF540N Q4
U 1 1 5BB7CF68
P 2950 5050
F 0 "Q4" H 3156 5096 50  0000 L CNN
F 1 "IRF540N" H 3156 5005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 3200 4975 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 2950 5050 50  0001 L CNN
	1    2950 5050
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R13
U 1 1 5BB7CF6F
P 3150 5400
F 0 "R13" V 2943 5400 50  0000 C CNN
F 1 "R" V 3034 5400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3080 5400 50  0001 C CNN
F 3 "~" H 3150 5400 50  0001 C CNN
	1    3150 5400
	0    1    1    0   
$EndComp
$Comp
L Isolator:PC847 U1
U 4 1 5BB7CF76
P 3850 4950
F 0 "U1" H 3850 5275 50  0000 C CNN
F 1 "PC847" H 3850 5184 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 3650 4750 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 3850 4950 50  0001 L CNN
	4    3850 4950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5BB7CF7D
P 4400 4850
F 0 "R4" V 4193 4850 50  0000 C CNN
F 1 "330R" V 4284 4850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4330 4850 50  0001 C CNN
F 3 "~" H 4400 4850 50  0001 C CNN
	1    4400 4850
	0    1    1    0   
$EndComp
$Comp
L Device:LED D4
U 1 1 5BB7CF84
P 4400 5050
F 0 "D4" H 4392 4795 50  0000 C CNN
F 1 "LED" H 4392 4886 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 4400 5050 50  0001 C CNN
F 3 "~" H 4400 5050 50  0001 C CNN
	1    4400 5050
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 4850 4150 4850
Wire Wire Line
	4250 5050 4150 5050
Wire Wire Line
	3150 5050 3350 5050
Wire Wire Line
	2850 5250 2850 5400
Wire Wire Line
	2850 5400 3000 5400
Wire Wire Line
	3300 5400 3350 5400
Wire Wire Line
	3350 5400 3350 5050
Connection ~ 3350 5050
Wire Wire Line
	3350 5050 3550 5050
$Comp
L Transistor_FET:IRF540N Q5
U 1 1 5BB7D5FE
P 6000 1950
F 0 "Q5" H 6206 1996 50  0000 L CNN
F 1 "IRF540N" H 6206 1905 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 6250 1875 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 6000 1950 50  0001 L CNN
	1    6000 1950
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R14
U 1 1 5BB7D605
P 6200 2300
F 0 "R14" V 5993 2300 50  0000 C CNN
F 1 "R" V 6084 2300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6130 2300 50  0001 C CNN
F 3 "~" H 6200 2300 50  0001 C CNN
	1    6200 2300
	0    1    1    0   
$EndComp
$Comp
L Isolator:PC847 U2
U 1 1 5BB7D60C
P 6900 1850
F 0 "U2" H 6900 2175 50  0000 C CNN
F 1 "PC847" H 6900 2084 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 6700 1650 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 6900 1850 50  0001 L CNN
	1    6900 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5BB7D613
P 7450 1750
F 0 "R5" V 7243 1750 50  0000 C CNN
F 1 "330R" V 7334 1750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7380 1750 50  0001 C CNN
F 3 "~" H 7450 1750 50  0001 C CNN
	1    7450 1750
	0    1    1    0   
$EndComp
$Comp
L Device:LED D5
U 1 1 5BB7D61A
P 7450 1950
F 0 "D5" H 7442 1695 50  0000 C CNN
F 1 "LED" H 7442 1786 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 7450 1950 50  0001 C CNN
F 3 "~" H 7450 1950 50  0001 C CNN
	1    7450 1950
	-1   0    0    1   
$EndComp
Wire Wire Line
	7300 1750 7200 1750
Wire Wire Line
	7300 1950 7200 1950
Wire Wire Line
	6200 1950 6400 1950
Wire Wire Line
	5900 2150 5900 2300
Wire Wire Line
	5900 2300 6050 2300
Wire Wire Line
	6350 2300 6400 2300
Wire Wire Line
	6400 2300 6400 1950
Connection ~ 6400 1950
Wire Wire Line
	6400 1950 6600 1950
$Comp
L Transistor_FET:IRF540N Q6
U 1 1 5BB7DE68
P 6100 2900
F 0 "Q6" H 6306 2946 50  0000 L CNN
F 1 "IRF540N" H 6306 2855 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 6350 2825 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 6100 2900 50  0001 L CNN
	1    6100 2900
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R15
U 1 1 5BB7DE6F
P 6300 3250
F 0 "R15" V 6093 3250 50  0000 C CNN
F 1 "R" V 6184 3250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6230 3250 50  0001 C CNN
F 3 "~" H 6300 3250 50  0001 C CNN
	1    6300 3250
	0    1    1    0   
$EndComp
$Comp
L Isolator:PC847 U2
U 2 1 5BB7DE76
P 7000 2800
F 0 "U2" H 7000 3125 50  0000 C CNN
F 1 "PC847" H 7000 3034 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 6800 2600 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 7000 2800 50  0001 L CNN
	2    7000 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5BB7DE7D
P 7550 2700
F 0 "R6" V 7343 2700 50  0000 C CNN
F 1 "330R" V 7434 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7480 2700 50  0001 C CNN
F 3 "~" H 7550 2700 50  0001 C CNN
	1    7550 2700
	0    1    1    0   
$EndComp
$Comp
L Device:LED D6
U 1 1 5BB7DE84
P 7550 2900
F 0 "D6" H 7542 2645 50  0000 C CNN
F 1 "LED" H 7542 2736 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 7550 2900 50  0001 C CNN
F 3 "~" H 7550 2900 50  0001 C CNN
	1    7550 2900
	-1   0    0    1   
$EndComp
Wire Wire Line
	7400 2700 7300 2700
Wire Wire Line
	7400 2900 7300 2900
Wire Wire Line
	6300 2900 6500 2900
Wire Wire Line
	6000 3100 6000 3250
Wire Wire Line
	6000 3250 6150 3250
Wire Wire Line
	6450 3250 6500 3250
Wire Wire Line
	6500 3250 6500 2900
Connection ~ 6500 2900
Wire Wire Line
	6500 2900 6700 2900
$Comp
L Transistor_FET:IRF540N Q7
U 1 1 5BB7E9C6
P 6050 3800
F 0 "Q7" H 6256 3846 50  0000 L CNN
F 1 "IRF540N" H 6256 3755 50  0000 L CNN
F 2 "LIB:TO-220-3_Horizontal_TabUp_no_hole" H 6300 3725 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 6050 3800 50  0001 L CNN
	1    6050 3800
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 5BB7E9CD
P 6250 4150
F 0 "R16" V 6043 4150 50  0000 C CNN
F 1 "R" V 6134 4150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6180 4150 50  0001 C CNN
F 3 "~" H 6250 4150 50  0001 C CNN
	1    6250 4150
	0    1    1    0   
$EndComp
$Comp
L Isolator:PC847 U2
U 3 1 5BB7E9D4
P 6950 3700
F 0 "U2" H 6950 4025 50  0000 C CNN
F 1 "PC847" H 6950 3934 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 6750 3500 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 6950 3700 50  0001 L CNN
	3    6950 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5BB7E9DB
P 7500 3600
F 0 "R7" V 7293 3600 50  0000 C CNN
F 1 "330R" V 7384 3600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7430 3600 50  0001 C CNN
F 3 "~" H 7500 3600 50  0001 C CNN
	1    7500 3600
	0    1    1    0   
$EndComp
$Comp
L Device:LED D7
U 1 1 5BB7E9E2
P 7500 3800
F 0 "D7" H 7492 3545 50  0000 C CNN
F 1 "LED" H 7492 3636 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 7500 3800 50  0001 C CNN
F 3 "~" H 7500 3800 50  0001 C CNN
	1    7500 3800
	-1   0    0    1   
$EndComp
Wire Wire Line
	7350 3600 7250 3600
Wire Wire Line
	7350 3800 7250 3800
Wire Wire Line
	6250 3800 6450 3800
Wire Wire Line
	5950 4000 5950 4150
Wire Wire Line
	5950 4150 6100 4150
Wire Wire Line
	6400 4150 6450 4150
Wire Wire Line
	6450 4150 6450 3800
Connection ~ 6450 3800
Wire Wire Line
	6450 3800 6650 3800
$Comp
L Transistor_FET:IRF540N Q8
U 1 1 5BB7F8DC
P 6000 4800
F 0 "Q8" H 6206 4846 50  0000 L CNN
F 1 "IRF540N" H 6206 4755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 6250 4725 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 6000 4800 50  0001 L CNN
	1    6000 4800
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R17
U 1 1 5BB7F8E3
P 6200 5150
F 0 "R17" V 5993 5150 50  0000 C CNN
F 1 "R" V 6084 5150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6130 5150 50  0001 C CNN
F 3 "~" H 6200 5150 50  0001 C CNN
	1    6200 5150
	0    1    1    0   
$EndComp
$Comp
L Isolator:PC847 U2
U 4 1 5BB7F8EA
P 6900 4700
F 0 "U2" H 6900 5025 50  0000 C CNN
F 1 "PC847" H 6900 4934 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_LongPads" H 6700 4500 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 6900 4700 50  0001 L CNN
	4    6900 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5BB7F8F1
P 7450 4600
F 0 "R8" V 7243 4600 50  0000 C CNN
F 1 "330R" V 7334 4600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7380 4600 50  0001 C CNN
F 3 "~" H 7450 4600 50  0001 C CNN
	1    7450 4600
	0    1    1    0   
$EndComp
$Comp
L Device:LED D8
U 1 1 5BB7F8F8
P 7450 4800
F 0 "D8" H 7442 4545 50  0000 C CNN
F 1 "LED" H 7442 4636 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm_Clear" H 7450 4800 50  0001 C CNN
F 3 "~" H 7450 4800 50  0001 C CNN
	1    7450 4800
	-1   0    0    1   
$EndComp
Wire Wire Line
	7300 4600 7200 4600
Wire Wire Line
	7300 4800 7200 4800
Wire Wire Line
	6200 4800 6400 4800
Wire Wire Line
	5900 5000 5900 5150
Wire Wire Line
	5900 5150 6050 5150
Wire Wire Line
	6350 5150 6400 5150
Wire Wire Line
	6400 5150 6400 4800
Connection ~ 6400 4800
Wire Wire Line
	6400 4800 6600 4800
$Comp
L Device:R R9
U 1 1 5BB848A7
P 9800 4000
F 0 "R9" H 9870 4046 50  0000 L CNN
F 1 "R" H 9870 3955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 9730 4000 50  0001 C CNN
F 3 "~" H 9800 4000 50  0001 C CNN
	1    9800 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener_Small D9
U 1 1 5BB84AF2
P 9800 4350
F 0 "D9" V 9754 4418 50  0000 L CNN
F 1 "9V1" V 9845 4418 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" V 9800 4350 50  0001 C CNN
F 3 "~" V 9800 4350 50  0001 C CNN
	1    9800 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	9800 4150 9800 4200
Wire Wire Line
	9950 3500 9800 3500
Wire Wire Line
	9800 3500 9800 3850
Wire Bus Line
	9600 800  8100 800 
Connection ~ 8100 800 
Wire Bus Line
	8100 800  4850 800 
Wire Bus Line
	1600 5800 2000 5800
Connection ~ 2000 5800
Wire Bus Line
	2000 5800 5200 5800
Wire Bus Line
	5200 5800 9200 5800
Connection ~ 5200 5800
Entry Wire Line
	9200 4400 9300 4500
Entry Wire Line
	9200 4100 9300 4200
Wire Wire Line
	9300 4200 9800 4200
Connection ~ 9800 4200
Wire Wire Line
	9800 4200 9800 4250
Wire Wire Line
	9300 4500 9800 4500
Wire Wire Line
	9800 4500 9800 4450
Entry Wire Line
	1500 3250 1600 3350
Entry Wire Line
	1500 3350 1600 3450
Entry Wire Line
	1500 3450 1600 3550
Entry Wire Line
	1500 3550 1600 3650
Entry Wire Line
	1500 3650 1600 3750
Entry Wire Line
	1500 3750 1600 3850
Entry Wire Line
	1500 3850 1600 3950
Entry Wire Line
	1500 3950 1600 4050
Entry Wire Line
	1500 4050 1600 4150
Entry Wire Line
	2000 1500 2100 1600
Entry Wire Line
	2000 1650 2100 1750
Entry Wire Line
	2000 2300 2100 2400
Entry Wire Line
	2000 2550 2100 2650
Entry Wire Line
	2000 2700 2100 2800
Entry Wire Line
	2000 3250 2100 3350
Entry Wire Line
	2000 3600 2100 3700
Entry Wire Line
	2000 3750 2100 3850
Entry Wire Line
	2000 4350 2100 4450
Entry Wire Line
	2000 4550 2100 4650
Entry Wire Line
	2000 4700 2100 4800
Entry Wire Line
	2000 5300 2100 5400
Entry Wire Line
	4750 5050 4850 5150
Entry Wire Line
	4750 4850 4850 4950
Entry Wire Line
	4750 4100 4850 4200
Entry Wire Line
	4750 3900 4850 4000
Entry Wire Line
	4750 3000 4850 3100
Entry Wire Line
	4750 2800 4850 2900
Entry Wire Line
	4750 2050 4850 2150
Entry Wire Line
	4750 1850 4850 1950
Entry Wire Line
	5200 1350 5300 1450
Entry Wire Line
	5200 1550 5300 1650
Entry Wire Line
	5200 2200 5300 2300
Entry Wire Line
	5200 2400 5300 2500
Entry Wire Line
	5200 2550 5300 2650
Entry Wire Line
	5200 3150 5300 3250
Entry Wire Line
	5200 3350 5300 3450
Entry Wire Line
	5200 3500 5300 3600
Entry Wire Line
	5200 4050 5300 4150
Entry Wire Line
	5200 4250 5300 4350
Entry Wire Line
	5200 4400 5300 4500
Entry Wire Line
	5200 5050 5300 5150
Entry Wire Line
	8000 4800 8100 4900
Entry Wire Line
	8000 4600 8100 4700
Entry Wire Line
	8000 3800 8100 3900
Entry Wire Line
	8000 3600 8100 3700
Entry Wire Line
	8000 2900 8100 3000
Entry Wire Line
	8000 2700 8100 2800
Entry Wire Line
	8000 1950 8100 2050
Entry Wire Line
	8000 1750 8100 1850
Entry Wire Line
	9600 2500 9700 2600
Entry Wire Line
	9600 2600 9700 2700
Entry Wire Line
	9600 2700 9700 2800
Entry Wire Line
	9600 2800 9700 2900
Entry Wire Line
	9600 2900 9700 3000
Entry Wire Line
	9600 3000 9700 3100
Entry Wire Line
	9600 3100 9700 3200
Entry Wire Line
	9600 3200 9700 3300
Entry Wire Line
	9600 3300 9700 3400
Wire Wire Line
	9950 2600 9700 2600
Wire Wire Line
	9950 2700 9700 2700
Wire Wire Line
	9950 2800 9700 2800
Wire Wire Line
	9950 2900 9700 2900
Wire Wire Line
	9950 3000 9700 3000
Wire Wire Line
	9950 3100 9700 3100
Wire Wire Line
	9950 3200 9700 3200
Wire Wire Line
	9950 3300 9700 3300
Wire Wire Line
	9950 3400 9700 3400
Text Label 9750 2600 0    50   ~ 0
GNDD
Text Label 9750 2700 0    50   ~ 0
GPB0
Text Label 9750 2800 0    50   ~ 0
GPB1
Text Label 9750 2900 0    50   ~ 0
GPB2
Text Label 9750 3000 0    50   ~ 0
GPB3
Text Label 9750 3100 0    50   ~ 0
GPB4
Text Label 9750 3200 0    50   ~ 0
GPB5
Text Label 9750 3300 0    50   ~ 0
GPB6
Text Label 9750 3400 0    50   ~ 0
GPB7
Wire Wire Line
	7600 4800 8000 4800
Wire Wire Line
	7600 4600 8000 4600
Wire Wire Line
	7650 3800 8000 3800
Wire Wire Line
	7650 3600 8000 3600
Wire Wire Line
	7700 2900 8000 2900
Wire Wire Line
	7700 2700 8000 2700
Wire Wire Line
	7600 1950 8000 1950
Wire Wire Line
	7600 1750 8000 1750
Wire Wire Line
	4550 1850 4750 1850
Wire Wire Line
	4550 2050 4750 2050
Wire Wire Line
	4550 2800 4750 2800
Wire Wire Line
	4550 3000 4750 3000
Wire Wire Line
	4550 3900 4750 3900
Wire Wire Line
	4550 4100 4750 4100
Wire Wire Line
	4550 4850 4750 4850
Wire Wire Line
	4550 5050 4750 5050
Wire Wire Line
	2100 5400 2850 5400
Connection ~ 2850 5400
Wire Wire Line
	2850 4850 2850 4800
Wire Wire Line
	2850 4800 2100 4800
Wire Wire Line
	2100 4650 3550 4650
Wire Wire Line
	3550 4650 3550 4850
Wire Wire Line
	2100 4450 2850 4450
Connection ~ 2850 4450
Wire Wire Line
	2850 3900 2850 3850
Wire Wire Line
	2850 3850 2100 3850
Wire Wire Line
	2100 3700 3550 3700
Wire Wire Line
	3550 3700 3550 3900
Wire Wire Line
	2100 3350 2850 3350
Connection ~ 2850 3350
Wire Wire Line
	3550 2800 3550 2650
Wire Wire Line
	3550 2650 2100 2650
Wire Wire Line
	2100 2800 2850 2800
Wire Wire Line
	2100 2400 2850 2400
Connection ~ 2850 2400
Wire Wire Line
	2100 1600 3550 1600
Wire Wire Line
	3550 1600 3550 1850
Wire Wire Line
	2100 1750 2850 1750
Wire Wire Line
	2850 1750 2850 1850
Wire Wire Line
	5300 1450 6600 1450
Wire Wire Line
	6600 1450 6600 1750
Wire Wire Line
	5300 1650 5900 1650
Wire Wire Line
	5900 1650 5900 1750
Wire Wire Line
	5300 2300 5900 2300
Connection ~ 5900 2300
Wire Wire Line
	5300 2500 6700 2500
Wire Wire Line
	6700 2500 6700 2700
Wire Wire Line
	5300 2650 6000 2650
Wire Wire Line
	6000 2650 6000 2700
Wire Wire Line
	5300 3250 6000 3250
Connection ~ 6000 3250
Wire Wire Line
	5300 3450 6650 3450
Wire Wire Line
	6650 3450 6650 3600
Wire Wire Line
	5300 3600 5950 3600
Wire Wire Line
	5300 4150 5950 4150
Connection ~ 5950 4150
Wire Wire Line
	5300 4350 6600 4350
Wire Wire Line
	6600 4350 6600 4600
Wire Wire Line
	5300 4500 5900 4500
Wire Wire Line
	5900 4500 5900 4600
Wire Wire Line
	5300 5150 5900 5150
Connection ~ 5900 5150
Wire Wire Line
	1500 3250 1100 3250
Wire Wire Line
	1500 3350 1100 3350
Wire Wire Line
	1500 3450 1100 3450
Wire Wire Line
	1500 3550 1100 3550
Wire Wire Line
	1500 3650 1100 3650
Wire Wire Line
	1500 3750 1100 3750
Wire Wire Line
	1500 3850 1100 3850
Wire Wire Line
	1500 3950 1100 3950
Wire Wire Line
	1500 4050 1100 4050
Text Label 8000 1950 2    50   ~ 0
GNDD
Text Label 8000 2900 2    50   ~ 0
GNDD
Text Label 8000 3800 2    50   ~ 0
GNDD
Text Label 8000 4800 2    50   ~ 0
GNDD
Text Label 4750 5050 2    50   ~ 0
GNDD
Text Label 4750 4100 2    50   ~ 0
GNDD
Text Label 4750 3000 2    50   ~ 0
GNDD
Text Label 4750 2050 2    50   ~ 0
GNDD
Text Label 4750 1850 2    50   ~ 0
GPB0
Text Label 4750 2800 2    50   ~ 0
GPB1
Text Label 4750 3900 2    50   ~ 0
GPB2
Text Label 4750 4850 2    50   ~ 0
GPB3
Text Label 8000 1750 2    50   ~ 0
GPB4
Text Label 8000 2700 2    50   ~ 0
GPB5
Text Label 8000 3600 2    50   ~ 0
GPB6
Text Label 8000 4600 2    50   ~ 0
GPB7
Text Label 1500 4050 2    50   ~ 0
PWR_GND
Text Label 2100 2400 0    50   ~ 0
PWR_GND
Text Label 2100 3350 0    50   ~ 0
PWR_GND
Text Label 2100 4450 0    50   ~ 0
PWR_GND
Text Label 2100 5400 0    50   ~ 0
PWR_GND
Text Label 5300 5150 0    50   ~ 0
PWR_GND
Text Label 5300 4150 0    50   ~ 0
PWR_GND
Text Label 5300 3250 0    50   ~ 0
PWR_GND
Text Label 5300 2300 0    50   ~ 0
PWR_GND
Text Label 9300 4500 0    50   ~ 0
PWR_GND
Text Label 9300 4200 0    50   ~ 0
+9V
Text Label 5300 1450 0    50   ~ 0
+9V
Text Label 5300 2500 0    50   ~ 0
+9V
Text Label 5300 3450 0    50   ~ 0
+9V
Text Label 5300 4350 0    50   ~ 0
+9V
Text Label 2100 1600 0    50   ~ 0
+9V
Text Label 2100 2650 0    50   ~ 0
+9V
Text Label 2100 3700 0    50   ~ 0
+9V
Text Label 2100 4650 0    50   ~ 0
+9V
Text Label 9900 3500 2    50   ~ 0
+24V
Text Label 1500 3250 2    50   ~ 0
out0
Text Label 1500 3350 2    50   ~ 0
out1
Text Label 1500 3450 2    50   ~ 0
out2
Text Label 1500 3550 2    50   ~ 0
out3
Text Label 1500 3650 2    50   ~ 0
out4
Text Label 1500 3750 2    50   ~ 0
out5
Text Label 1500 3850 2    50   ~ 0
out6
Text Label 1500 3950 2    50   ~ 0
out7
Text Label 2100 1750 0    50   ~ 0
out0
Text Label 2100 2800 0    50   ~ 0
out1
Text Label 2100 3850 0    50   ~ 0
out2
Text Label 2100 4800 0    50   ~ 0
out3
Text Label 5300 1650 0    50   ~ 0
out4
Text Label 5300 2650 0    50   ~ 0
out5
Text Label 5300 3600 0    50   ~ 0
out6
Text Label 5300 4500 0    50   ~ 0
out7
Wire Bus Line
	9200 4050 9200 5800
Wire Bus Line
	8100 800  8100 4900
Wire Bus Line
	1600 3200 1600 5800
Wire Bus Line
	9600 800  9600 3500
Wire Bus Line
	2000 1400 2000 5800
Wire Bus Line
	4850 800  4850 5250
Wire Bus Line
	5200 1300 5200 5800
$EndSCHEMATC
