<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.1.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="no" active="no"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="librarie">
<packages>
<package name="DIL40">
<description>&lt;B&gt;Dual In Line&lt;/B&gt;</description>
<wire x1="-26.416" y1="-1.27" x2="-26.416" y2="-6.604" width="0.1524" layer="21"/>
<wire x1="-26.416" y1="1.27" x2="-26.416" y2="-1.27" width="0.1524" layer="21" curve="-180"/>
<wire x1="26.416" y1="-6.604" x2="26.416" y2="6.604" width="0.1524" layer="21"/>
<wire x1="-26.416" y1="6.604" x2="-26.416" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-26.416" y1="6.604" x2="26.416" y2="6.604" width="0.1524" layer="21"/>
<wire x1="-26.416" y1="-6.604" x2="26.416" y2="-6.604" width="0.1524" layer="21"/>
<pad name="1" x="-24.13" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-21.59" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-19.05" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="-16.51" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="-13.97" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="-11.43" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="-8.89" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="-6.35" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="9" x="-3.81" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="10" x="-1.27" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="11" x="1.27" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="12" x="3.81" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="13" x="6.35" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="14" x="8.89" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="15" x="11.43" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="16" x="13.97" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="17" x="16.51" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="18" x="19.05" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="19" x="21.59" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="20" x="24.13" y="-7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="21" x="24.13" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="22" x="21.59" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="23" x="19.05" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="24" x="16.51" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="25" x="13.97" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="26" x="11.43" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="27" x="8.89" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="28" x="6.35" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="29" x="3.81" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="30" x="1.27" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="31" x="-1.27" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="32" x="-3.81" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="33" x="-6.35" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="34" x="-8.89" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="35" x="-11.43" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="36" x="-13.97" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="37" x="-16.51" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="38" x="-19.05" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="39" x="-21.59" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<pad name="40" x="-24.13" y="7.62" drill="0.8128" shape="long" rot="R90"/>
<text x="-26.67" y="-6.35" size="1.778" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="-21.59" y="-2.2352" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="32-I/O-M8535-P">
<wire x1="-15.24" y1="43.18" x2="15.24" y2="43.18" width="0.254" layer="94"/>
<wire x1="15.24" y1="43.18" x2="15.24" y2="-48.26" width="0.254" layer="94"/>
<wire x1="15.24" y1="-48.26" x2="-15.24" y2="-48.26" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-48.26" x2="-15.24" y2="43.18" width="0.254" layer="94"/>
<text x="-15.24" y="43.942" size="1.778" layer="95">&gt;NAME</text>
<text x="-15.24" y="-50.8" size="1.778" layer="96">&gt;VALUE</text>
<pin name="(ADC7)PA7" x="20.32" y="40.64" length="middle" rot="R180"/>
<pin name="(ADC6)PA6" x="20.32" y="38.1" length="middle" rot="R180"/>
<pin name="(ADC5)PA5" x="20.32" y="35.56" length="middle" rot="R180"/>
<pin name="(ADC4)PA4" x="20.32" y="33.02" length="middle" rot="R180"/>
<pin name="(ADC3)PA3" x="20.32" y="30.48" length="middle" rot="R180"/>
<pin name="(ADC2)PA2" x="20.32" y="27.94" length="middle" rot="R180"/>
<pin name="(ADC1)PA1" x="20.32" y="25.4" length="middle" rot="R180"/>
<pin name="(ADC0)PA0" x="20.32" y="22.86" length="middle" rot="R180"/>
<pin name="(SCK)PB7" x="20.32" y="17.78" length="middle" rot="R180"/>
<pin name="(MISO)PB6" x="20.32" y="15.24" length="middle" rot="R180"/>
<pin name="(MOSI)PB5" x="20.32" y="12.7" length="middle" rot="R180"/>
<pin name="(SS)PB4" x="20.32" y="10.16" length="middle" rot="R180"/>
<pin name="(AIN1/INT2)PB3" x="20.32" y="7.62" length="middle" rot="R180"/>
<pin name="(AIN0/OC0)PB2" x="20.32" y="5.08" length="middle" rot="R180"/>
<pin name="(T1)PB1" x="20.32" y="2.54" length="middle" rot="R180"/>
<pin name="(T0/XCK)PB0" x="20.32" y="0" length="middle" rot="R180"/>
<pin name="(TOSC2)PC7" x="20.32" y="-5.08" length="middle" rot="R180"/>
<pin name="(TOSC1)PC6" x="20.32" y="-7.62" length="middle" rot="R180"/>
<pin name="PC5" x="20.32" y="-10.16" length="middle" rot="R180"/>
<pin name="PC4" x="20.32" y="-12.7" length="middle" rot="R180"/>
<pin name="PC3" x="20.32" y="-15.24" length="middle" rot="R180"/>
<pin name="PC2" x="20.32" y="-17.78" length="middle" rot="R180"/>
<pin name="(SDA)PC1" x="20.32" y="-20.32" length="middle" rot="R180"/>
<pin name="(SCL)PC0" x="20.32" y="-22.86" length="middle" rot="R180"/>
<pin name="GND@1" x="-20.32" y="17.78" length="middle" direction="pwr"/>
<pin name="AVCC" x="-20.32" y="20.32" length="middle" direction="pwr"/>
<pin name="AREF" x="-20.32" y="22.86" length="middle" direction="pas"/>
<pin name="XTAL1" x="-20.32" y="27.94" length="middle"/>
<pin name="XTAL2" x="-20.32" y="33.02" length="middle"/>
<pin name="VCC" x="-20.32" y="12.7" length="middle" direction="pwr"/>
<pin name="GND" x="-20.32" y="10.16" length="middle" direction="pwr"/>
<pin name="RESET" x="-20.32" y="40.64" length="middle" direction="in" function="dot"/>
<pin name="(RXD)PD0" x="20.32" y="-45.72" length="middle" rot="R180"/>
<pin name="(TXD)PD1" x="20.32" y="-43.18" length="middle" rot="R180"/>
<pin name="(INT0)PD2" x="20.32" y="-40.64" length="middle" rot="R180"/>
<pin name="(INT1)PD3" x="20.32" y="-38.1" length="middle" rot="R180"/>
<pin name="(OC1B)PD4" x="20.32" y="-35.56" length="middle" rot="R180"/>
<pin name="(OC1A)PD5" x="20.32" y="-33.02" length="middle" rot="R180"/>
<pin name="(ICP)PD6" x="20.32" y="-30.48" length="middle" rot="R180"/>
<pin name="(OC2)PD7" x="20.32" y="-27.94" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MEGA8535-P" prefix="IC">
<description>&lt;b&gt;MICROCONTROLLER&lt;/b&gt;&lt;p&gt;
8 Kbytes FLASH&lt;br&gt;
512 bytes SRAM&lt;br&gt;
512 bytes EEPROM&lt;br&gt;
USART&lt;br&gt;
8-channel 10 bit ADC&lt;p&gt;
Source: avr.lbr</description>
<gates>
<gate name="G$1" symbol="32-I/O-M8535-P" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DIL40">
<connects>
<connect gate="G$1" pin="(ADC0)PA0" pad="40"/>
<connect gate="G$1" pin="(ADC1)PA1" pad="39"/>
<connect gate="G$1" pin="(ADC2)PA2" pad="38"/>
<connect gate="G$1" pin="(ADC3)PA3" pad="37"/>
<connect gate="G$1" pin="(ADC4)PA4" pad="36"/>
<connect gate="G$1" pin="(ADC5)PA5" pad="35"/>
<connect gate="G$1" pin="(ADC6)PA6" pad="34"/>
<connect gate="G$1" pin="(ADC7)PA7" pad="33"/>
<connect gate="G$1" pin="(AIN0/OC0)PB2" pad="3"/>
<connect gate="G$1" pin="(AIN1/INT2)PB3" pad="4"/>
<connect gate="G$1" pin="(ICP)PD6" pad="20"/>
<connect gate="G$1" pin="(INT0)PD2" pad="16"/>
<connect gate="G$1" pin="(INT1)PD3" pad="17"/>
<connect gate="G$1" pin="(MISO)PB6" pad="7"/>
<connect gate="G$1" pin="(MOSI)PB5" pad="6"/>
<connect gate="G$1" pin="(OC1A)PD5" pad="19"/>
<connect gate="G$1" pin="(OC1B)PD4" pad="18"/>
<connect gate="G$1" pin="(OC2)PD7" pad="21"/>
<connect gate="G$1" pin="(RXD)PD0" pad="14"/>
<connect gate="G$1" pin="(SCK)PB7" pad="8"/>
<connect gate="G$1" pin="(SCL)PC0" pad="22"/>
<connect gate="G$1" pin="(SDA)PC1" pad="23"/>
<connect gate="G$1" pin="(SS)PB4" pad="5"/>
<connect gate="G$1" pin="(T0/XCK)PB0" pad="1"/>
<connect gate="G$1" pin="(T1)PB1" pad="2"/>
<connect gate="G$1" pin="(TOSC1)PC6" pad="28"/>
<connect gate="G$1" pin="(TOSC2)PC7" pad="29"/>
<connect gate="G$1" pin="(TXD)PD1" pad="15"/>
<connect gate="G$1" pin="AREF" pad="32"/>
<connect gate="G$1" pin="AVCC" pad="30"/>
<connect gate="G$1" pin="GND" pad="11"/>
<connect gate="G$1" pin="GND@1" pad="31"/>
<connect gate="G$1" pin="PC2" pad="24"/>
<connect gate="G$1" pin="PC3" pad="25"/>
<connect gate="G$1" pin="PC4" pad="26"/>
<connect gate="G$1" pin="PC5" pad="27"/>
<connect gate="G$1" pin="RESET" pad="9"/>
<connect gate="G$1" pin="VCC" pad="10"/>
<connect gate="G$1" pin="XTAL1" pad="13"/>
<connect gate="G$1" pin="XTAL2" pad="12"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="ATMEGA8535-16PU" constant="no"/>
<attribute name="OC_FARNELL" value="9171444" constant="no"/>
<attribute name="OC_NEWARK" value="01M6909" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="IC1" library="librarie" deviceset="MEGA8535-P" device=""/>
<part name="IC2" library="librarie" deviceset="MEGA8535-P" device=""/>
<part name="IC3" library="librarie" deviceset="MEGA8535-P" device=""/>
<part name="IC4" library="librarie" deviceset="MEGA8535-P" device=""/>
<part name="IC5" library="librarie" deviceset="MEGA8535-P" device=""/>
<part name="IC6" library="librarie" deviceset="MEGA8535-P" device=""/>
<part name="IC7" library="librarie" deviceset="MEGA8535-P" device=""/>
<part name="IC8" library="librarie" deviceset="MEGA8535-P" device=""/>
<part name="IC9" library="librarie" deviceset="MEGA8535-P" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<text x="91.44" y="-99.06" size="1.778" layer="97" rot="R180">PWM</text>
<text x="91.44" y="-109.22" size="1.778" layer="97" rot="R180">Charlieplexing</text>
</plain>
<instances>
<instance part="IC1" gate="G$1" x="35.56" y="53.34"/>
<instance part="IC2" gate="G$1" x="35.56" y="-55.88"/>
<instance part="IC3" gate="G$1" x="35.56" y="-154.94"/>
<instance part="IC4" gate="G$1" x="35.56" y="-254"/>
<instance part="IC5" gate="G$1" x="35.56" y="-353.06"/>
<instance part="IC6" gate="G$1" x="35.56" y="-452.12"/>
<instance part="IC7" gate="G$1" x="35.56" y="-551.18"/>
<instance part="IC8" gate="G$1" x="35.56" y="-650.24"/>
<instance part="IC9" gate="G$1" x="35.56" y="-749.3"/>
</instances>
<busses>
<bus name="SCK,MISO,MOSI,SS0,SS1,SS2,SS3,SS4,SS5,SS6,SS7">
<segment>
<label x="58.42" y="99.06" size="1.778" layer="95" rot="R90"/>
<wire x1="58.42" y1="96.52" x2="58.42" y2="-739.14" width="0.762" layer="92"/>
</segment>
</bus>
<bus name="USB_D-,USB_D+,USB_5V,GND">
<segment>
<wire x1="60.96" y1="0" x2="60.96" y2="96.52" width="0.762" layer="92"/>
<label x="60.96" y="99.06" size="1.778" layer="95" rot="R90"/>
<wire x1="60.96" y1="0" x2="35.56" y2="0" width="0.762" layer="92"/>
</segment>
</bus>
<bus name="VCC,GND,AVCC,AREF">
<segment>
<wire x1="10.16" y1="96.52" x2="10.16" y2="0" width="0.762" layer="92"/>
<label x="10.16" y="99.06" size="1.778" layer="95" rot="R90"/>
<wire x1="10.16" y1="0" x2="10.16" y2="-739.14" width="0.762" layer="92"/>
<wire x1="10.16" y1="0" x2="25.4" y2="0" width="0.762" layer="92"/>
</segment>
</bus>
<bus name="B$1">
<segment>
<wire x1="60.96" y1="-33.02" x2="60.96" y2="-2.54" width="0.762" layer="92"/>
<wire x1="60.96" y1="-2.54" x2="198.12" y2="-2.54" width="0.762" layer="92"/>
</segment>
</bus>
<bus name="B$2">
<segment>
<wire x1="66.04" y1="-60.96" x2="66.04" y2="-81.28" width="0.762" layer="92"/>
<wire x1="66.04" y1="-81.28" x2="200.66" y2="-81.28" width="0.762" layer="92"/>
<wire x1="200.66" y1="-81.28" x2="200.66" y2="-5.08" width="0.762" layer="92"/>
</segment>
</bus>
<bus name="S0_PB0,S0_PB1,S0_PB3,S0_PD0,S0_PD1,S0_PD2,S0_PD3,S0_PD4,S0_PD6">
<segment>
<wire x1="60.96" y1="-48.26" x2="60.96" y2="-106.68" width="0.762" layer="92"/>
<wire x1="60.96" y1="-106.68" x2="91.44" y2="-106.68" width="0.762" layer="92"/>
<label x="93.98" y="-109.22" size="1.778" layer="95"/>
</segment>
</bus>
<bus name="S0_0C0,S0_0C1A,S0_0C2">
<segment>
<wire x1="63.5" y1="-50.8" x2="63.5" y2="-104.14" width="0.762" layer="92"/>
<wire x1="63.5" y1="-104.14" x2="91.44" y2="-104.14" width="0.762" layer="92"/>
<label x="93.98" y="-104.14" size="1.778" layer="95"/>
</segment>
</bus>
</busses>
<nets>
<net name="SCK" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="(SCK)PB7"/>
<wire x1="55.88" y1="71.12" x2="58.42" y2="71.12" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC9" gate="G$1" pin="(SCK)PB7"/>
<wire x1="55.88" y1="-731.52" x2="58.42" y2="-731.52" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC8" gate="G$1" pin="(SCK)PB7"/>
<wire x1="55.88" y1="-632.46" x2="58.42" y2="-632.46" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC7" gate="G$1" pin="(SCK)PB7"/>
<wire x1="55.88" y1="-533.4" x2="58.42" y2="-533.4" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC6" gate="G$1" pin="(SCK)PB7"/>
<wire x1="55.88" y1="-434.34" x2="58.42" y2="-434.34" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC5" gate="G$1" pin="(SCK)PB7"/>
<wire x1="55.88" y1="-335.28" x2="58.42" y2="-335.28" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC4" gate="G$1" pin="(SCK)PB7"/>
<wire x1="55.88" y1="-236.22" x2="58.42" y2="-236.22" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC3" gate="G$1" pin="(SCK)PB7"/>
<wire x1="55.88" y1="-137.16" x2="58.42" y2="-137.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="(SCK)PB7"/>
<wire x1="55.88" y1="-38.1" x2="58.42" y2="-38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MISO" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="(MISO)PB6"/>
<wire x1="55.88" y1="68.58" x2="58.42" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC9" gate="G$1" pin="(MISO)PB6"/>
<wire x1="55.88" y1="-734.06" x2="58.42" y2="-734.06" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC8" gate="G$1" pin="(MISO)PB6"/>
<wire x1="55.88" y1="-635" x2="58.42" y2="-635" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC7" gate="G$1" pin="(MISO)PB6"/>
<wire x1="55.88" y1="-535.94" x2="58.42" y2="-535.94" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC6" gate="G$1" pin="(MISO)PB6"/>
<wire x1="55.88" y1="-436.88" x2="58.42" y2="-436.88" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC5" gate="G$1" pin="(MISO)PB6"/>
<wire x1="55.88" y1="-337.82" x2="58.42" y2="-337.82" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC4" gate="G$1" pin="(MISO)PB6"/>
<wire x1="55.88" y1="-238.76" x2="58.42" y2="-238.76" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC3" gate="G$1" pin="(MISO)PB6"/>
<wire x1="55.88" y1="-139.7" x2="58.42" y2="-139.7" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="(MISO)PB6"/>
<wire x1="55.88" y1="-40.64" x2="58.42" y2="-40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MOSI" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="(MOSI)PB5"/>
<wire x1="55.88" y1="66.04" x2="58.42" y2="66.04" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC9" gate="G$1" pin="(MOSI)PB5"/>
<wire x1="58.42" y1="-736.6" x2="55.88" y2="-736.6" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC8" gate="G$1" pin="(MOSI)PB5"/>
<wire x1="55.88" y1="-637.54" x2="58.42" y2="-637.54" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC7" gate="G$1" pin="(MOSI)PB5"/>
<wire x1="55.88" y1="-538.48" x2="58.42" y2="-538.48" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC6" gate="G$1" pin="(MOSI)PB5"/>
<wire x1="55.88" y1="-439.42" x2="58.42" y2="-439.42" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC5" gate="G$1" pin="(MOSI)PB5"/>
<wire x1="55.88" y1="-340.36" x2="58.42" y2="-340.36" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC4" gate="G$1" pin="(MOSI)PB5"/>
<wire x1="55.88" y1="-241.3" x2="58.42" y2="-241.3" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC3" gate="G$1" pin="(MOSI)PB5"/>
<wire x1="55.88" y1="-142.24" x2="58.42" y2="-142.24" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="(MOSI)PB5"/>
<wire x1="55.88" y1="-43.18" x2="58.42" y2="-43.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SS0" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="(SCL)PC0"/>
<wire x1="55.88" y1="30.48" x2="58.42" y2="30.48" width="0.1524" layer="91"/>
<label x="63.5" y="30.48" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="(SS)PB4"/>
<wire x1="55.88" y1="-45.72" x2="58.42" y2="-45.72" width="0.1524" layer="91"/>
<label x="63.5" y="-45.72" size="1.778" layer="95"/>
</segment>
</net>
<net name="SS1" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="(SDA)PC1"/>
<wire x1="55.88" y1="33.02" x2="58.42" y2="33.02" width="0.1524" layer="91"/>
<label x="63.5" y="33.02" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="IC3" gate="G$1" pin="(SS)PB4"/>
<wire x1="55.88" y1="-144.78" x2="58.42" y2="-144.78" width="0.1524" layer="91"/>
<label x="60.96" y="-144.78" size="1.778" layer="95"/>
</segment>
</net>
<net name="SS2" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="PC2"/>
<wire x1="55.88" y1="35.56" x2="58.42" y2="35.56" width="0.1524" layer="91"/>
<label x="63.5" y="35.56" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="IC4" gate="G$1" pin="(SS)PB4"/>
<wire x1="55.88" y1="-243.84" x2="58.42" y2="-243.84" width="0.1524" layer="91"/>
<label x="60.96" y="-243.84" size="1.778" layer="95"/>
</segment>
</net>
<net name="SS3" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="PC3"/>
<wire x1="55.88" y1="38.1" x2="58.42" y2="38.1" width="0.1524" layer="91"/>
<label x="63.5" y="38.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="IC5" gate="G$1" pin="(SS)PB4"/>
<wire x1="55.88" y1="-342.9" x2="58.42" y2="-342.9" width="0.1524" layer="91"/>
<label x="60.96" y="-342.9" size="1.778" layer="95"/>
</segment>
</net>
<net name="SS4" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="PC4"/>
<wire x1="55.88" y1="40.64" x2="58.42" y2="40.64" width="0.1524" layer="91"/>
<label x="63.5" y="40.64" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="IC6" gate="G$1" pin="(SS)PB4"/>
<wire x1="55.88" y1="-441.96" x2="58.42" y2="-441.96" width="0.1524" layer="91"/>
<label x="60.96" y="-441.96" size="1.778" layer="95"/>
</segment>
</net>
<net name="SS5" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="PC5"/>
<wire x1="55.88" y1="43.18" x2="58.42" y2="43.18" width="0.1524" layer="91"/>
<label x="63.5" y="43.18" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="IC7" gate="G$1" pin="(SS)PB4"/>
<wire x1="55.88" y1="-541.02" x2="58.42" y2="-541.02" width="0.1524" layer="91"/>
<label x="60.96" y="-541.02" size="1.778" layer="95"/>
</segment>
</net>
<net name="SS6" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="(TOSC1)PC6"/>
<wire x1="55.88" y1="45.72" x2="58.42" y2="45.72" width="0.1524" layer="91"/>
<label x="63.5" y="45.72" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="IC8" gate="G$1" pin="(SS)PB4"/>
<wire x1="55.88" y1="-640.08" x2="58.42" y2="-640.08" width="0.1524" layer="91"/>
<label x="60.96" y="-640.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="SS7" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="(TOSC2)PC7"/>
<wire x1="55.88" y1="48.26" x2="58.42" y2="48.26" width="0.1524" layer="91"/>
<label x="63.5" y="48.26" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="IC9" gate="G$1" pin="(SS)PB4"/>
<wire x1="55.88" y1="-739.14" x2="58.42" y2="-739.14" width="0.1524" layer="91"/>
<label x="60.96" y="-739.14" size="1.778" layer="95"/>
</segment>
</net>
<net name="USB_D+" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="(INT0)PD2"/>
<wire x1="55.88" y1="12.7" x2="60.96" y2="12.7" width="0.1524" layer="91"/>
<label x="63.5" y="12.7" size="1.778" layer="95"/>
</segment>
</net>
<net name="USB_D-" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="(INT1)PD3"/>
<wire x1="55.88" y1="15.24" x2="60.96" y2="15.24" width="0.1524" layer="91"/>
<label x="63.5" y="15.24" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="IC9" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="-739.14" x2="10.16" y2="-739.14" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC9" gate="G$1" pin="GND@1"/>
<wire x1="15.24" y1="-731.52" x2="10.16" y2="-731.52" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC8" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="-640.08" x2="10.16" y2="-640.08" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC8" gate="G$1" pin="GND@1"/>
<wire x1="15.24" y1="-632.46" x2="10.16" y2="-632.46" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC7" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="-541.02" x2="10.16" y2="-541.02" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC7" gate="G$1" pin="GND@1"/>
<wire x1="15.24" y1="-533.4" x2="10.16" y2="-533.4" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC6" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="-441.96" x2="10.16" y2="-441.96" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC6" gate="G$1" pin="GND@1"/>
<wire x1="15.24" y1="-434.34" x2="10.16" y2="-434.34" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC5" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="-342.9" x2="10.16" y2="-342.9" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC5" gate="G$1" pin="GND@1"/>
<wire x1="15.24" y1="-335.28" x2="10.16" y2="-335.28" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC4" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="-243.84" x2="10.16" y2="-243.84" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC4" gate="G$1" pin="GND@1"/>
<wire x1="15.24" y1="-236.22" x2="10.16" y2="-236.22" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC3" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="-144.78" x2="10.16" y2="-144.78" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC3" gate="G$1" pin="GND@1"/>
<wire x1="15.24" y1="-137.16" x2="10.16" y2="-137.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="-45.72" x2="10.16" y2="-45.72" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="GND@1"/>
<wire x1="15.24" y1="-38.1" x2="10.16" y2="-38.1" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC1" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="63.5" x2="10.16" y2="63.5" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC1" gate="G$1" pin="GND@1"/>
<wire x1="15.24" y1="71.12" x2="10.16" y2="71.12" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="35.56" y1="0" x2="25.4" y2="0" width="0.1524" layer="91"/>
<label x="27.94" y="-2.54" size="1.778" layer="95"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="IC9" gate="G$1" pin="VCC"/>
<wire x1="15.24" y1="-736.6" x2="10.16" y2="-736.6" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC8" gate="G$1" pin="VCC"/>
<wire x1="15.24" y1="-637.54" x2="10.16" y2="-637.54" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC7" gate="G$1" pin="VCC"/>
<wire x1="15.24" y1="-538.48" x2="10.16" y2="-538.48" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC6" gate="G$1" pin="VCC"/>
<wire x1="15.24" y1="-439.42" x2="10.16" y2="-439.42" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC5" gate="G$1" pin="VCC"/>
<wire x1="15.24" y1="-340.36" x2="10.16" y2="-340.36" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC4" gate="G$1" pin="VCC"/>
<wire x1="15.24" y1="-241.3" x2="10.16" y2="-241.3" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC3" gate="G$1" pin="VCC"/>
<wire x1="15.24" y1="-142.24" x2="10.16" y2="-142.24" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="VCC"/>
<wire x1="15.24" y1="-43.18" x2="10.16" y2="-43.18" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC1" gate="G$1" pin="VCC"/>
<wire x1="15.24" y1="66.04" x2="10.16" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="AVCC" class="0">
<segment>
<pinref part="IC9" gate="G$1" pin="AVCC"/>
<wire x1="15.24" y1="-728.98" x2="10.16" y2="-728.98" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC8" gate="G$1" pin="AVCC"/>
<wire x1="15.24" y1="-629.92" x2="10.16" y2="-629.92" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC7" gate="G$1" pin="AVCC"/>
<wire x1="15.24" y1="-530.86" x2="10.16" y2="-530.86" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC6" gate="G$1" pin="AVCC"/>
<wire x1="15.24" y1="-431.8" x2="10.16" y2="-431.8" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC5" gate="G$1" pin="AVCC"/>
<wire x1="15.24" y1="-332.74" x2="10.16" y2="-332.74" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC4" gate="G$1" pin="AVCC"/>
<wire x1="15.24" y1="-233.68" x2="10.16" y2="-233.68" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC3" gate="G$1" pin="AVCC"/>
<wire x1="15.24" y1="-134.62" x2="10.16" y2="-134.62" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="AVCC"/>
<wire x1="15.24" y1="-35.56" x2="10.16" y2="-35.56" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC1" gate="G$1" pin="AVCC"/>
<wire x1="15.24" y1="73.66" x2="10.16" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="AREF" class="0">
<segment>
<pinref part="IC9" gate="G$1" pin="AREF"/>
<wire x1="15.24" y1="-726.44" x2="10.16" y2="-726.44" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC8" gate="G$1" pin="AREF"/>
<wire x1="15.24" y1="-627.38" x2="10.16" y2="-627.38" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC7" gate="G$1" pin="AREF"/>
<wire x1="15.24" y1="-528.32" x2="10.16" y2="-528.32" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC6" gate="G$1" pin="AREF"/>
<wire x1="15.24" y1="-429.26" x2="10.16" y2="-429.26" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC5" gate="G$1" pin="AREF"/>
<wire x1="15.24" y1="-330.2" x2="10.16" y2="-330.2" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC4" gate="G$1" pin="AREF"/>
<wire x1="15.24" y1="-231.14" x2="10.16" y2="-231.14" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC3" gate="G$1" pin="AREF"/>
<wire x1="15.24" y1="-132.08" x2="10.16" y2="-132.08" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="AREF"/>
<wire x1="15.24" y1="-33.02" x2="10.16" y2="-33.02" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC1" gate="G$1" pin="AREF"/>
<wire x1="15.24" y1="76.2" x2="10.16" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="S0_PD0" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(RXD)PD0"/>
<wire x1="55.88" y1="-101.6" x2="60.96" y2="-101.6" width="0.1524" layer="91"/>
<label x="66.04" y="-101.6" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_PD1" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(TXD)PD1"/>
<wire x1="55.88" y1="-99.06" x2="60.96" y2="-99.06" width="0.1524" layer="91"/>
<label x="66.04" y="-99.06" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_PD2" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(INT0)PD2"/>
<wire x1="55.88" y1="-96.52" x2="60.96" y2="-96.52" width="0.1524" layer="91"/>
<label x="66.04" y="-96.52" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_PD3" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(INT1)PD3"/>
<wire x1="55.88" y1="-93.98" x2="60.96" y2="-93.98" width="0.1524" layer="91"/>
<label x="66.04" y="-93.98" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_PD4" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(OC1B)PD4"/>
<wire x1="55.88" y1="-91.44" x2="60.96" y2="-91.44" width="0.1524" layer="91"/>
<label x="66.04" y="-91.44" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_PD6" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(ICP)PD6"/>
<wire x1="55.88" y1="-86.36" x2="60.96" y2="-86.36" width="0.1524" layer="91"/>
<label x="66.04" y="-86.36" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_PB3" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(AIN1/INT2)PB3"/>
<wire x1="55.88" y1="-48.26" x2="60.96" y2="-48.26" width="0.1524" layer="91"/>
<label x="66.04" y="-48.26" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_PB1" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(T1)PB1"/>
<wire x1="55.88" y1="-53.34" x2="60.96" y2="-53.34" width="0.1524" layer="91"/>
<label x="66.04" y="-53.34" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_PB0" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(T0/XCK)PB0"/>
<wire x1="55.88" y1="-55.88" x2="60.96" y2="-55.88" width="0.1524" layer="91"/>
<label x="66.04" y="-55.88" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_0C2" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(OC2)PD7"/>
<wire x1="55.88" y1="-83.82" x2="63.5" y2="-83.82" width="0.1524" layer="91"/>
<label x="66.04" y="-83.82" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_0C1A" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(OC1A)PD5"/>
<wire x1="55.88" y1="-88.9" x2="63.5" y2="-88.9" width="0.1524" layer="91"/>
<label x="66.04" y="-88.9" size="1.778" layer="95"/>
</segment>
</net>
<net name="S0_0C0" class="0">
<segment>
<pinref part="IC2" gate="G$1" pin="(AIN0/OC0)PB2"/>
<wire x1="55.88" y1="-50.8" x2="63.5" y2="-50.8" width="0.1524" layer="91"/>
<label x="66.04" y="-50.8" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
