sr = 44100
ksmps = 32
nchnls = 2
0dbfs  = 1

instr 1

ichnls = ftchnls(2)
ifreq = cpspch(p4)
print ifreq

 kamp linen p5, p3*0.1, p3, p3*0.3

   asigL, asigR loscil kamp, ifreq/(2*262.2), 1, 1
 outs asigL, asigR

endin


instr 2

ichnls = ftchnls(2)
ifreq = cpspch(p4)

kamp linen p5, p3*0.1, p3, p3*0.1

	asigL, asigR loscil kamp, ifreq/786, 2, 1
outs asigL, asigR

endin


instr 3

ichnls = ftchnls(2)
ifreq = cpspch(p4)

kamp linen p5, p3*0.01, p3, p3*0.6

	asigL, asigR loscil kamp, ifreq/196.5, 3, 1
outs asigL, asigR

endin

