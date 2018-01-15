<CsoundSynthesizer>
<CsOptions>
-odac -d -O null
</CsOptions>
<CsInstruments>
; ====================
sr = 44100
kr = 441
ksmps = 100
nchnls = 1
; ====================

; =======================================
instr 1 ; (short atack, long release)

iharm1 = p4
iharm2 = iharm1*p5
iharm3 = iharm1*p6
iharm4 = iharm1*p7
iharm5 = iharm1*p8

kamp1 linen iharm1, p3*0.1, p3, p3*0.9
kamp2 linen iharm2, p3*0.1, p3, p3*0.6
kamp3 linen iharm3, p3*0.1, p3, p3*0.8
kamp4 linen iharm4, p3*0.1, p3, p3*0.2
kamp5 linen iharm5, p3*0.1, p3, p3*0.1


amod oscil p10, p11, 1

ifreq1 = cpspch(p9)
ifreq2 = ifreq1*2
ifreq3 = ifreq1*3
ifreq4 = ifreq1*4
ifreq5 = ifreq1*5

a1 oscil kamp1, ifreq1+amod, 1
a2 oscil kamp2, ifreq2, 1
a3 oscil kamp3, ifreq3, 1
a4 oscil kamp4, ifreq4, 1
a5 oscil kamp5, ifreq5, 1

out a1+a2+a3+a4+a5

endin
; =======================================
</CsInstruments>
<CsScore>
; ========================================
; Function Tables:
; ========================================
f1 0 4096 10 1 
i1 0 0.25 20000 0 1 1 0 8.00 ;5000 1760
i1 + . . . . . . 8.04 ;8 200
i1 . . . . . . . 8.07 ;20000 200
i1 . . . . . . . 8.04 ;20000 200
i1 . 5 10000 . . 1 1 8.00 ;20000 200
e
; ========================================

; ========================================
; VOICE: 0, Instr.: 0
; ========================================



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
