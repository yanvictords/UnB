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

iamp = ampdb(p4)
ifreq = cpspch(p5
ifreq2 = ifreq*2
ifreq3 = ifreq*3



kamp linen iamp, p3*0.5, p3, p3*0.5

a1 oscil kamp, ifreq, 1
a2 oscil kamp, ifreq2, 1
a3 oscil kamp, ifreq3, 1



out (a1 + a2 + a3)/3

endin

</CsInstruments>
<CsScore>

f1 0 4096 10 1 1 1 .5 .5 .5 .3 .2 .1

i1 0 2 90 8.00



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
