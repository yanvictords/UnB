<Csound
Synthesizer>
<CsOptions>
-W -o dac
</CsOptions>
<CsInstruments>

sr = 44100
kr = 441
ksmps = 100
nchnls = 1

instr 1

iampport = ampdb(p4)
ifreqport = cpspch(p5)
iampmod= p6
ifreqmod = p7


kmod linen iampmod, p3*0.2, p3, p3*0.2

amod oscil kmod, ifreqmod, 1 


aport oscil iampport, ifreqport+amod, 1

out aport
endin


</CsInstruments>
<CsScore>

f1 0  2048 10 1 0 .3 0 .2 0 .14 0 .111 ; Quadrada
;p1 p2 p3 p4   p5     p6 p7
i1    0   2   100 8.00 100 400
i1 + 2 100 8.02 . .
i1 . 2 100 8.04 . .
i1 . 2 100 8.05 . .
i1 . 2 100 8.07 . .
i1 . 2 100 8.09 . .
i1 . 2 100 8.11 . .
i1 . 2 100 9.00 . .

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
