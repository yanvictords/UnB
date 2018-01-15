<CsoundSynthesizer>
<CsOptions>
-W -odac

</CsOptions>
<CsInstruments>

sr = 44100
kr = 441
ksmps = 100
nchnls = 2
garvbsig init 0  ; 
instr 1 
idur = p3
iamp = ampdb(p4)
ifreq = cpspch(p5) 
ibalance = p6        ; estéreo: 1=left, .5=center, 0=right 
irvbgain = p7
imodfreq = ifreq * 0.235 ; 0.123 0.235 0.347 0.666 0.999
imodgain = ifreq * 0.314

kamp linen 0.7, 0.02, p3, p3*0.5

amod oscil imodgain, imodfreq, 1
aport oscil iamp, ifreq + amod, 1
arampsig = kamp * aport
outs arampsig * ibalance, arampsig * (1- ibalance)
garvbsig = garvbsig + arampsig * irvbgain 
endin 

instr 99                            ; reverberação global 
irvbtime = p4 
asig reverb garvbsig, irvbtime       ; coloca o sinal global no reverb 
outs asig, asig 
garvbsig = 0 ; then clear it 
endin 


</CsInstruments>
<CsScore>
f1 0 4096 10 1

;ins strt 	dur 	rvbtime
i99 	0 	20 		5.0 

;ins 	ini 	dur 	amp  	freq	balance		reverb
i1 	0 	1.0 	85	8.00	1.0			0.05
i1 	2 	. 	85	8.02	0.8			.
i1 	4 	. 	85	8.04	0.6			.
i1 	6 	. 	85	8.05	0.4			.
i1 	8 	1.0 	85	8.07	0.2			.
i1 	10 	1.0 	85	9.00	0.0			.
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
