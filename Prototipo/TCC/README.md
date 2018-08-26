# TRABALHO FINAL DE GRADUAÇÃO
Todos os códigos, com exceção do arquivo "dns_refletor.c", foram feitos por mim: Yan Victor dos Santos. <br />
A ferramenta é capaz por detectar a presença de possíveis refletores em ataques DDoS volumétricos. <br />

O programa "dns_refletor.c" atua como refletor, executando uma QUERY para um servidor DNS via terminal. O pacote é repassado ao analisador da ferramenta implementada, que logo detecta a presença do refletor. Diversas outras funcionalidades podem ser vistas nos arquivos .h's. <br />

Para executar cada programa:<br />
chmod 755 make.sh<br />
./make.sh<br />
./ddosDetector<br />
~> Digite um IP de qualquer servidor DNS válido para executar a query (ex.: 8.8.8.8, 8.8.4.4, etc.)<br />
 <br />

Ambiente: Linux.

Orientação: João José Costa Gondim
Universidade de Brasília - 2018/1 ~ 2019/1
