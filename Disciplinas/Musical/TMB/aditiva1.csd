<CsoundSynthesizer>
<CsOptions>
-W -odac
</CsOptions>
<CsInstruments>

sr = 44100
kr = 441
ksmps = 100
nchnls = 1

instr 1

iamp1 = ampdb(p4)
iamp2 = iamp1*p6
iamp3 = iamp1*p7
iamp4 = iamp1*p8
iamp5 = iamp1*p9


ifreq1 = cpspch(p5)
ifreq2 = ifreq1*2
ifreq3 = ifreq1*3
ifreq4 = ifreq1*4
ifreq5 = ifreq1*5


kamp1 linen iamp1, p3 * 0.1, p3, p3*0.9
kamp2 linen iamp2,p3 * 0.3, p3, p3*0.7
kamp3 linen iamp3,p3 * 02, p3, p3*0.6
kamp4 linen iamp4,p3 * 0.1, p3, p3*0.3
kamp5 linen iamp5,p3 * 0.2, p3, p3*0.01

a1 oscil kamp1, ifreq1, 1
a2 oscil kamp2, ifreq2, 1
a3 oscil kamp3, ifreq3, 1
a4 oscil kamp4, ifreq4, 1
a5 oscil kamp5, ifreq5, 1

asaida = (a1+a2+a3+a4+a5)/5
out asaida
endin

</CsInstruments>
<CsScore>
f1 0 4096 10 1

i1 0 2 90 8.00 1 1 1 2
i1 + 2 90 8.02 1 1 1 2
i1 + 2 90 8.04 1 1 1 2
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
