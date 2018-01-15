<CsoundSynthesizer>

<CsOptions>
-W -o dac
</CsOptions>


<CsInstruments>
sr = 44100
kr = 441
ksmps = 100
nchnls = 1


instr 1
	iFport = cpspch(p4)
	iFnext = cpspch(p5)
	
	iAport = ampdb(p6)


	kFreqPort linseg iFport, p3*0.85,iFport,p3*0.15,iFnext
	kFmod = kFreqPort * 0.9
	kFreqLine linseg 0, p3*0.05, 1000, p3*0.95, 0


	
	amod 	oscil	kFreqLine, kFmod, 1
	aport	oscil	iAport, kFreqPort + amod, 1
	
	
	
	
	kamp linen 1.0, 0.05, p3, p3* 0.02
	aout = kamp * aport
	out aout
	endin
</CsInstruments>


<CsScore>
f1 0 4096 10 1

i1 0 1.5 	8.07 8.00 80
i1 + 0.5 	8.05 8.04 80
i1 . . 	8.04 8.02 80
i1 . . 	8.02 8.04 80
i1 . . 	8.04 8.05 80
i1 . . 	8.05 8.07 80
i1 . 1 	8.07 7.07 80
i1 . . 	8.07 7.07 80
i1 . . 	8.07 7.07 80

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
