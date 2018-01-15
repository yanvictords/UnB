<CsoundSynthesizer>
<CsOptions>
-W -odac
</CsOptions>
<CsInstruments>

sr = 44100 
kr=441
ksmps = 100
nchnls = 2

instr 1
ifreq1 = cpspch(p4)
ifreq2= ifreq1*2
ifreq3 = ifreq1*3 
ifreq4 = ifreq1*4
ifreq5 = ifreq1*5


a1 rand 10000, 127

ares1 reson a1, ifreq1, (ifreq1 * 0.001)
ares2 reson a1, ifreq2, (ifreq2 * 0.001)
ares3 reson a1, ifreq3, (ifreq3 * 0.001)
ares4 reson a1, ifreq4, (ifreq4 * 0.001)
ares5 reson a1, ifreq5, (ifreq5 * 0.001)



afmix = (ares1 + ares2 + ares3 + ares4 + ares5)/5



afsig 	balance afmix, a1
kamp linen 2, 0.1*p3, p3, 0.1*p3
afinal = (afsig * kamp)

outs afinal, 1 - afinal

endin


</CsInstruments>
<CsScore>
f1 0 4096 10 1

i1 0 2 8.00
e
</CsScore>
</CsoundSynthesizer>
<bsbPanel>
 <label>Widgets</label>
 <objectName/>
 <x>100</x>
 <y>100</y>
 <width>320</width>
 <height>240</height>
 <visible>true</visible>
 <uuid/>
 <bgcolor mode="nobackground">
  <r>255</r>
  <g>255</g>
  <b>255</b>
 </bgcolor>
</bsbPanel>
<bsbPresets>
</bsbPresets>
