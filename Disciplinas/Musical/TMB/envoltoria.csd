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

	ifreq = cpspch(p4)
	iamp = ampdb(p5)
	idur = p3

	k1 line iamp, idur, 0
	k2 line 0, idur, iamp
	a1 oscil k1, ifreq, p6
	a2 oscil k2, ifreq, p7
	asinal = (a1 + a2)/2

	kamp linen 1.0, 0.05, p3, p3 * 0.1

	asaida = kamp * asinal
	out asaida

endin
</CsInstruments>


<CsScore>
f1 0 4096 10 1 1 1 .5 .5 .5 .3 .2 .1
f2 0 4096 10 1 .1 .2 .2 .4 .5 .6 .7
f3 0 2048 10 1 ; Seno
f4 0 2048 10 1 .5 .3 .25 2 .167 .14 .125 .111 ; Dente-de-Serra
f5 0  2048 10 1 0 .3 0 .2 0 .14 0 .111 ; Quadrada
f6 0 2048 10 1 1 1 1 .7 .5 .3 .1 ; Pulso




i1	0	1	8.00	90	1	2
i1	+	.	8.02	.	1	2
i1	.	.	8.04	.	1	2
i1	.	.	8.00	.	2	3
i1	.	.	8.02	.	2	3
i1	.	.	8.04	.	2	3
i1	.	.	8.00	.	3	4	
i1	.	.	8.02	.	3	4
i1	.	.	8.04	.	3	4
i1	.	.	8.00	.	4	5
i1	.	.	8.02	.	4	5
i1	.	.	8.04	.	4	5
i1	.	.	8.00	.	5	6
i1	.	.	8.02	.	5	6
i1	.	.	8.04	.	5	6
i1	.	.	8.00	.	6	1	
i1	.	.	8.02	.	6	1
i1	.	.	8.04	.	6	1

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
