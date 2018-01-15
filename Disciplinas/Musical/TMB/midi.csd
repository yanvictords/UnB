<CsoundSynthesizer>

<CsOptions>
; ===============================================================
; Para usar o Csound como sintetizador independente,
; controlado por eventos MIDI, indicamos um dispositivo a ser
; usado para entrada de dados e selecionamos a saida direta do audio:
; -M[n] = determina qual dispositivo de entrada MIDI sera ouvido
; -odac = tocar direto na placa de som
; ===============================================================
-M1 -odac	
</CsOptions>

<CsInstruments>
sr = 44100
kr = 4410
ksmps = 10
nchnls = 2

; ===============================================================
; Mapeamos os canais MIDI para os intrumentos da orquestra
; ===============================================================
massign 0,0		; desliga todos os canais
massign 1,1		; canal 1 > instrumento 1
massign 2,2

; ===============================================================
;   ********* Instrumento simples controlado por MIDI *********
; ===============================================================
instr 1 
	; =========================================================
	; ...capturamos a altura da nota gerada pelo evento MIDI,
	; convertendo para a frequencia correspondente:
	; =========================================================
	ifreq cpsmidi
	; =========================================================
	; ...capturamos a intensidade de ataque da nota(0-127), 
	; convertendo para a amplitude correspondente (o parametro 
	; fornecido determina o limite da escala de intensidade 
	; apos a conversao:
	; =========================================================
	iamp ampmidi 20000
	; =========================================================
	; ...capturamos um determinado controlador MIDI,  armazenando
	; os valores em um sinal de controle para utilizarmos em algum
	; parametro da sintese:
	; =========================================================
	kpan midictrl 10
	kpan = kpan / 127
	; =========================================================
	; ...criamos uma envoltoria de amplitude com o comando 'linenr'
	; para conseguir controlar o ataque e decaimento da nota,
	; independente da sua duracao, e evitar os estalos no inicio
	; e fim da mesma. Os parametros devem ser ajustados 
	; cuidadosamente recomenda-se utilizar que o  decaimento 
	; (terceiro parametro de 'linenr') seja um valor maior que 0.
	; =========================================================
	kamp linenr iamp, 0.005, 1, 0.01
	; =========================================================
	; ...aplicamos a envoltoria de amplitude na entrada do oscilador
	; =========================================================
	asig oscil kamp, ifreq * 0.5 , 2
	; =========================================================
	; ...aplicamos o sinal de controle gerado pelos eventos MIDI
	; como fator de distribuicao so sinal no estereo
	; =========================================================
	outs asig * kpan, asig  * (1-kpan)
	
	;outs asig, asig
endin

; ===============================================================
;   ********* Instrumento simples controlado por MIDI *********
; ===============================================================
instr 2
	; =========================================================
	; ...capturamos a altura da nota gerada pelo evento MIDI,
	; convertendo para a frequencia correspondente:
	; =========================================================
	ifreq cpsmidi
	; =========================================================
	; ...capturamos a intensidade de ataque da nota(0-127), 
	; convertendo para a amplitude correspondente (o parametro 
	; fornecido determina o limite da escala de intensidade 
	; apos a conversao:
	; =========================================================
	iamp ampmidi 20000
	; =========================================================
	; ...capturamos um determinado controlador MIDI,  armazenando
	; os valores em um sinal de controle para utilizarmos em algum
	; parametro da sintese:
	; =========================================================
	kbend pchbend 0, 2
	
	; =========================================================
	; ...criamos uma envoltoria de amplitude com o comando 'linenr'
	; para conseguir controlar o ataque e decaimento da nota,
	; independente da sua duracao, e evitar os estalos no inicio
	; e fim da mesma. Os parametros devem ser ajustados 
	; cuidadosamente recomenda-se utilizar que o  decaimento 
	; (terceiro parametro de 'linenr') seja um valor maior que 0.
	; =========================================================
	kamp linenr iamp, 0.8, 0.1, 0.008
	; =========================================================
	; ...aplicamos a envoltoria de amplitude na entrada do oscilador
	; =========================================================
	amod	oscil kbend, 0.137 * ifreq, 3
	aport oscil kamp, ifreq*amod, 2
	outs aport, aport
endin
</CsInstruments>


<CsScore>
; ===============================================================
; Na partitura, alem das tabelas de funcao utilizadas pelo
; instrumento, utilizamos o comando f0 para informar ao Csound
; o tempo (em segundos) que ele deve permanecer ativo para
; receber eventos MIDI
; ===============================================================
f0 3600
f1 0 4096 10 .1 .2 .3 .4 .5
f2 0 4096 10 .5 .4 .3 .2 .1
f3 0 4096 10 1

</CsScore>


</CsoundSynthesizer>
